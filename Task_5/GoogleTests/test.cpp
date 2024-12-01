#include "pch.h"
#include "Functions.h"

TEST(No_Elements, Task_5) {
	unsigned int m = 3, n = 3;
	long long ** a = new long long* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long long[n];
	}
	a[0][0] = 2; a[0][1] = 3; a[0][2] = 10;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 8; a[2][1] = 7; a[2][2] = 0;

	EXPECT_EQ(countElements(a,m,n), 0);
	Delete2DArray(a, m);
}

TEST(Arithmetic_Mean, Task_5) {
	unsigned int n = 5;
	long long a[5] = { 1,-10,34,21,21 };
	long long actual_arithmetic_mean = (1 + -10 + 34 + 21 + 21) / 5;

	EXPECT_EQ(countArithmeticMean(a, n), actual_arithmetic_mean);
}

TEST(Not_Square, Task_5) {
	unsigned int m = 2, n = 3;
	long long** a = new long long* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long long[n];
	}
	a[0][0] = 3; a[0][1] = 2; a[0][2] = 6;
	a[1][0] = 5; a[1][1] = 5; a[1][2] = 7;
	long long actual_elements[3] = { 3,5,7 };
	long long actual_arithmetic_mean = 5;

	unsigned int n_elements = countElements(a, m, n);
	long long* elements = new long long[n_elements];
	findElements(a, m, n, elements);

	for (int i = 0; i < n_elements; i++) {
		EXPECT_EQ(elements[i],actual_elements[i]);
	}
	EXPECT_EQ(countElements(a,m,n), 3);
	EXPECT_EQ(countArithmeticMean(elements, n_elements), actual_arithmetic_mean);

	delete[] elements;
	Delete2DArray(a, m);
}