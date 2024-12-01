#include "pch.h"
#include "../StaticLib/Header.h"

bool CheckRoot(long double**, long double*, long double*, long long, long long);

TEST(All_Zero, Task_1) {
	long long n_a = 3, n_b = 3;
	long double a[3] = { 0,0,0 };
	long double b[3] = { 0,0,0 };

	long double** root = FindRoots(a, b, n_a, n_b);

	EXPECT_TRUE(CheckRoot(root, a, b, n_a, n_b));
}

TEST(b_Zero, Task_1) {
	long long n_a = 3, n_b = 3;
	long double a[3] = { 1,2,3 };
	long double b[3] = { 0,0,0 };

	long double** root = FindRoots(a, b, n_a, n_b);

	EXPECT_TRUE(CheckRoot(root, a, b, n_a, n_b));
}

TEST(Regular_Test, Task_1) {
	long long n_a = 3, n_b = 3;
	long double a[3] = { -2.718,3.321,-91 };
	long double b[3] = { 55,3.14,100 };

	long double** root = FindRoots(a, b, n_a, n_b);

	EXPECT_TRUE(CheckRoot(root, a, b, n_a, n_b));
}

bool CheckRoot(long double** root, long double* a, long double* b, long long n_a, long long m_b) {
	bool GoodRoots = true;
	for (int i = 0; i < n_a; i++) {
		for (int j = 0; j < m_b; j++) {
			if (a[i] == 0 && root[i][j] != 0) {
				GoodRoots = false;
			}
			else if ((a[i] * root[i][j] + b[j] < -0.00000001) || (a[i] * root[i][j] + b[j] > 0.00000001)) {
				GoodRoots = false;
			}
		}
	}

	return GoodRoots;
}