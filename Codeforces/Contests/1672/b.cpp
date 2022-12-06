#include <stdio.h>
#include <cuda.h>
#include <stdint.h>
#include <stdlib.h>
#include<sys/time.h>

#define TILE_SIZE 32

// Forward declaration of the matrix multiplication kernel
_global_ void MatMulKernel(int64_t* A, int64_t* B, int64_t* C, const int n,int64_t* time);

// Get a matrix element
_device_ int64_t GetElement(int64_t* A, int row, int col,const int n){
    return A[row * n + col];
}

// Set a matrix element
_device_ void SetElement(int64_t* A, int row, int col,int64_t value,const int n){
    A[row * n + col] = value;
}

// Get the TILE_SIZExTILE_SIZE sub-matrix Asub of A that is
// located col sub-matrices to the right and row sub-matrices down
// from the upper-left corner of A
_device_ int64_t* GetSubMatrix(int64_t* A, int row, int col,const int n)
{
    int64_t* Asub;
    // width = TILE_SIZE;
    // height = TILE_SIZE;
    //Asub.stride = A.stride;
    Asub = &A[n * TILE_SIZE * row + TILE_SIZE * col];
    return Asub;
}

// Matrix multiplication - Host code
// Matrix dimensions are assumed to be multiples of TILE_SIZE
void MatMul(int64_t* A, int64_t* B, int64_t* C, int n)
{
    // Load A and B to device memory
    int64_t* d_A;
    size_t size = n * n * sizeof(int64_t);
    cudaMalloc(&d_A, size);

    int64_t* d_B;
    cudaMalloc(&d_B, size);

    // Allocate C in device memory
    int64_t* d_C;
    cudaMalloc(&d_C, size);

    int64_t* dtime;
    cudaMalloc(&dtime, 2 * sizeof(int64_t));

    //Host to device
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    // Invoke kernel
    dim3 dimBlock(TILE_SIZE, TILE_SIZE);
    dim3 dimGrid(n / dimBlock.x, n / dimBlock.y);

    struct timespec startk, endk;
    clock_gettime(CLOCK_MONOTONIC_RAW, &startk);

    //callig kernel
    MatMulKernel << <dimGrid, dimBlock >> > (d_A, d_B, d_C, n,dtime);
    cudaDeviceSynchronize();

    clock_gettime(CLOCK_MONOTONIC_RAW, &endk);
    uint64_t delta_k = (endk.tv_sec - startk.tv_sec) * 1000000 + (endk.tv_nsec - startk.tv_nsec) / 1000;
    // dim3 dimBlock(TILE_SIZE, TILE_SIZE,1);
    // dim3 threadsPerBlock(n / dimBlock.x, n / dimBlock.y, 1);
    // MatMulKernel <<<dimBlock,threadsPerBlock>>> (d_A, d_B, d_C, n);

    // Read C from device memory
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    int64_t* time = (int64_t*)malloc(2 * sizeof(int64_t));
    cudaMemcpy(time, dtime, 2 * sizeof(int64_t), cudaMemcpyDeviceToHost);

    printf("Time for Transfer in one block in clock cycles: %ld\n", time[0]);
    printf("Time for computation in one block in clock cycles: %ld\n", time[1]);

    //printing Times
    printf("Kernel time in microseconds : %ld\n", delta_k);
    printf("Transfer time in microseconds : %ld\n", delta_us);

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

// Matrix multiplication kernel called by MatMul()
_global_ void MatMulKernel(int64_t* A, int64_t* B, int64_t* C, const int n,int64_t* time)
{
    // Block row and column
    int blockRow = blockIdx.y;
    int blockCol = blockIdx.x;

    // Each thread block computes one sub-matrix Csub of C
    int64_t* Csub = GetSubMatrix(C, blockRow, blockCol,n);

    // Each thread computes one element of Csub
    // by accumulating results into Cvalue
    int64_t Cvalue = 0;

    // Thread row and column within Csub
    int row = threadIdx.y;
    int col = threadIdx.x;

    //declare variables for timing in transfer and computation including synx
    //initializing the time matrix with 0 so as to increment it in each loop.
    clock_t start, stop;
    if ((blockRow + row) + (blockCol + col) == 0) {
        time[0] = 0;
        time[1] = 0;
    }

    // Loop over all the sub-matrices of A and B that are
    // required to compute Csub
    // Multiply each pair of sub-matrices together
    // and accumulate the results
    for (int m = 0; m < (n / TILE_SIZE); ++m) {

        // Get sub-matrix Asub of A
        int64_t* Asub = GetSubMatrix(A, blockRow, m,n);

        // Get sub-matrix Bsub of B
        int64_t* Bsub = GetSubMatrix(B, m, blockCol,n);

        // Shared memory used to store Asub and Bsub respectively
        _shared_ int64_t As[TILE_SIZE][TILE_SIZE];
        _shared_ int64_t Bs[TILE_SIZE][TILE_SIZE];

        // Load Asub and Bsub from device memory to shared memory
        // Each thread loads one element of each sub-matrix
        // Timing the transfer and storing it in time[0]
        // Only measuring the time for first thread(0,0) in first block (0,0)
        if ((blockRow + row) + (blockCol + col) == 0) {
            start = clock();
            
        }
            
        As[row][col] = GetElement(Asub, row, col, n);
        Bs[row][col] = GetElement(Bsub, row, col,n);
        
        // Synchronize to make sure the sub-matrices are loaded
        // before starting the computation
        __syncthreads();

        //stopping after sync threads so as to get time of all the transfers
        if ((blockRow + row) + (blockCol + col) == 0) {
            stop = clock();

            time[0] = time[0]+(int64_t)(stop - start);
            //printf("%ld ", time[0]);
        }
        // Multiply Asub and Bsub together

        if ((blockRow + row) + (blockCol + col) == 0)
            start = clock();

        for (int e = 0; e < TILE_SIZE; ++e)
            Cvalue += As[row][e] * Bs[e][col];

        // Synchronize to make sure that the preceding
        // computation is done before loading two new
        // sub-matrices of A and B in the next iteration
        __syncthreads();

        if ((blockRow + row) + (blockCol + col) == 0) {
            stop = clock();

            time[1] =time[1]+ (int64_t)(stop - start);
        }

    }

    // Write Csub to device memory
    // Each thread writes one element
    SetElement(Csub, row, col, Cvalue,n);
}

void init(int64_t* matr, int n) {
    srand((unsigned int)time(NULL));
    int8_t val;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            val = rand();
            matr[j * n + i] = val;
        }
    }
}

void matmul_naive(const int n,
    int64_t* A, int64_t* B, int64_t* C) {

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {

            C[j * n + i] = 0;
            for (int l = 0; l < n; ++l) {
                C[j * n + i] += A[j * n + l] * B[l * n + i];
            }

        }
    }

}

bool validate(const int n, int64_t* C_gpu, int64_t* Cnaive) {
    int eps = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            Cnaive[idx] = (Cnaive[idx] - C_gpu[idx]);
            if (eps < Cnaive[idx]) {
                eps = Cnaive[idx];
            }
        }
    }
    printf("%d\n", eps);

    if (eps == 0)
        return true;
    else
        return false;
}

int main(int argc, char* argv[]) {

    int64_t* A;
    int64_t* B;
    int64_t* C;
    int n = atoi(argv[1]);
    size_t size = n * n * sizeof(int64_t);

    A = (int64_t*)malloc(size);
    B = (int64_t*)malloc(size);
    C = (int64_t*)malloc(size);

    init(A, n);
    init(B, n);

    MatMul(A, B, C, n);


    // int64_t* C_Naive = (int64_t*)malloc(size);
    // matmul_naive(n, A, B, C_Naive);

    // bool validation = validate(n, C, C_Naive);
    // if (validation) {
    //     printf("Sucess\n");
    // }
    // else {
    //     printf("fail\n");
    // }
    // free(C_Naive);


    cudaDeviceSynchronize();
    printf("%s\n", cudaGetErrorString(cudaGetLastError()));

    free(A);
    free(B);
    free(C);

    return 0;
}