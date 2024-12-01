#include "pch.h"
#include "Functions.h"

TEST(No_Zero, Task_4) {
	unsigned int m = 3, n = 3;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

	EXPECT_EQ(countZero(a,m,n), 0);
	Delete2DArray(a, m);
}

TEST(All_Zero, Task_4) {
	unsigned int m = 3, n = 3;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	a[0][0] = 0; a[0][1] = 0; a[0][2] = 0;
	a[1][0] = 0; a[1][1] = 0; a[1][2] = 0;
	a[2][0] = 0; a[2][1] = 0; a[2][2] = 0;

	unsigned int n_zero = countZero(a, m, n);
	unsigned int** index = new unsigned int*[n_zero];
	for (int i = 0; i < n_zero; i++) {
		index[i] = new unsigned int[2];
	}
	findZero(a, m, n, index);

	for (int i = 0; i < n_zero; i++) {
		EXPECT_EQ(a[index[i][0]][index[i][1]], 0);
	}
	EXPECT_EQ(countZero(a, m, n), 9);

	Delete2DArray(index, n_zero);
	Delete2DArray(a, m);
}

TEST(Regular_Test, Task_4) {
	unsigned int m = 3, n = 3;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	a[0][0] = 3; a[0][1] = 0; a[0][2] = 2;
	a[1][0] = 0; a[1][1] = 3; a[1][2] = -1;
	a[2][0] = 5; a[2][1] = 0; a[2][2] = 0;

	unsigned int n_zero = countZero(a, m, n);
	unsigned int** index = new unsigned int* [n_zero];
	for (int i = 0; i < n_zero; i++) {
		index[i] = new unsigned int[2];
	}
	findZero(a, m, n, index);

	for (int i = 0; i < n_zero; i++) {
		EXPECT_EQ(a[index[i][0]][index[i][1]], 0);
	}
	EXPECT_EQ(countZero(a, m, n), 4);

	Delete2DArray(index, n_zero);
	Delete2DArray(a, m);
}

TEST(Reversing_Array, Task_4) {
	unsigned int m = 3, n = 3;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	a[0][0] = 2; a[0][1] = -2; a[0][2] = 1;
	a[1][0] = 0; a[1][1] = 3; a[1][2] = -20;
	a[2][0] = 10; a[2][1] = -1; a[2][2] = 40;
	long double** reversed_a = new long double* [m];
	for (int i = 0; i < m; i++) {
		reversed_a[i] = new long double[n];
	}
	reversed_a[0][0] = 40; reversed_a[0][1] = -1; reversed_a[0][2] = 10;
	reversed_a[1][0] = -20; reversed_a[1][1] = 3; reversed_a[1][2] = 0;
	reversed_a[2][0] = 1; reversed_a[2][1] = -2; reversed_a[2][2] = 2;

	long double** b = new long double* [m];
	for (int i = 0; i < m; i++) {
		b[i] = new long double[n];
	}
	reverseArray(a, m, n, b);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			EXPECT_EQ(b[i][j], reversed_a[i][j]);
		}
	}
}