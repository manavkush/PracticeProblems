// C++ program to count set bits by pre-storing
// count set bits in nibbles.
#include <bits/stdc++.h>
using namespace std;

int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3,
						1, 2, 2, 3, 2, 3, 3, 4 };

/* Recursively get nibble of a given number
and map them in the array */
long long int countOnes(long long int num)
{
	long long int nibble = 0;
	if (0 == num)
		return num_to_bits[0];

	// Find last nibble
	nibble = num & 0xf;

	// Use pre-stored values to find count
	// in last nibble plus recursively add
	// remaining nibbles.
	return num_to_bits[nibble] + countOnes(num >> 4);
}

// Driver code
int main()
{
	int num = 31;
	cout << countSetBitsRec(num);
	return 0;
}

// This code is contributed by rathbhupendra
