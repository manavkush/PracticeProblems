#include <stdio.h>
#include <cuda.h>
#include <stdint.h>
#include <stdlib.h>
#include<sys/time.h>

#define BLOCK_SIZE 32
// Forward declaration of the matrix multiplication kernel
_global_ void MatMulKernel(int64_t* A, int64_t* B, int64_t* C,const int n);

// Matrix multiplication - Host code
// Matrix dimensions are assumed to be multiples of BLOCK_SIZE
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

    //Host to device
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    // Invoke kernel
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
    dim3 dimGrid(n / dimBlock.x, n / dimBlock.y);

    struct timespec startk, endk;
    clock_gettime(CLOCK_MONOTONIC_RAW, &startk);
    MatMulKernel << <dimGrid, dimBlock >> > (d_A, d_B, d_C, n);
    cudaDeviceSynchronize();
    clock_gettime(CLOCK_MONOTONIC_RAW, &endk);
    uint64_t delta_k = (endk.tv_sec - startk.tv_sec) * 1000000 + (endk.tv_nsec - startk.tv_nsec) / 1000;
    // dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE,1);
    // dim3 threadsPerBlock(n / dimBlock.x, n / dimBlock.y, 1);
    // MatMulKernel <<<dimBlock,threadsPerBlock>>> (d_A, d_B, d_C, n);

    // Read C from device memory
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;


    //printing Times
    printf("Kernel time in microseconds : %ld\n", delta_k);
    printf("Transfer time in microseconds : %ld\n", delta_us);
    
    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

// Matrix multiplication kernel called by MatMul()
_global_ void MatMulKernel(int64_t* A, int64_t* B, int64_t* C, const int n)
{
    // Each thread computes one element of C
    // by accumulating results into Cvalue
    float Cvalue = 0;
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    for (int e = 0; e < n; ++e)
        Cvalue += A[row * n + e]* B[e * n + col];
    C[row * n + col] = Cvalue;
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

//Taken from the previos assginment wil give the maximum error among all the instances.
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