#include "pch.h"
#include "Functions.h"

TEST(No_Elements, Task_3) {
	unsigned int n = 3, k = 3;
	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[k];
	}
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

	EXPECT_EQ(countEvenDiagonal(a, n, k), 0);
	Delete2DArray(a, n);
}

TEST(Multiplying, Task_3) {
	unsigned int n = 5;
	long long a[5] = { 1,-10,34,21,21 };
	long long actual_multiplying = 1 * -10 * 34 * 21 * 21;

	EXPECT_EQ(multiplyArray(a, n), actual_multiplying);
}

TEST(Not_Square, Task_3) {
	unsigned int n = 3, k = 2;
	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[k];
	}
	a[0][0] = 4; a[0][1] = 2;
	a[1][0] = 4; a[1][1] = 2;
	a[2][0] = 7; a[2][1] = 8;
	long long* actual_diagonal = new long long[2];
	actual_diagonal[0] = 4; actual_diagonal[1] = 2;
	long long actual_multiplying = 4 * 2;

	unsigned int size_diagonal = countEvenDiagonal(a, n, k);
	long long* diagonal = new long long[size_diagonal];
	findEvenDiagonal(a, n, k, diagonal);

	for (int i = 0; i < size_diagonal; i++) {
		EXPECT_EQ(diagonal[i], actual_diagonal[i]);
	}
	EXPECT_EQ(multiplyArray(diagonal, size_diagonal), actual_multiplying);

	Delete2DArray(a, n);
	delete[] actual_diagonal;
	delete[] diagonal;
}

TEST(Regular_Test, Task_3) {
	unsigned int n = 3, k = 3;
	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[k];
	}
	a[0][0] = 24; a[0][1] = 1; a[0][2] = 3;
	a[1][0] = 2; a[1][1] = -8; a[1][2] = 1;
	a[2][0] = 100; a[2][1] = 2; a[2][2] = -3;
	long long* actual_diagonal = new long long[2];
	actual_diagonal[0] = 24; actual_diagonal[1] = -8;
	long long actual_multiplying = 24 * -8;

	unsigned int size_diagonal = countEvenDiagonal(a, n, k);
	long long* diagonal = new long long[size_diagonal];
	findEvenDiagonal(a, n, k, diagonal);

	for (int i = 0; i < size_diagonal; i++) {
		EXPECT_EQ(diagonal[i], actual_diagonal[i]);
	}
	EXPECT_EQ(multiplyArray(diagonal, size_diagonal), actual_multiplying);

	Delete2DArray(a, n);
	delete[] actual_diagonal;
	delete[] diagonal;
}
