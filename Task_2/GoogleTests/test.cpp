#include "pch.h"
#include <Windows.h>
#include <cmath>

bool CheckElements(long double*, long long);
HINSTANCE load = LoadLibrary(L"DynamicLib.dll");
typedef bool (*my_function) (long double*, long long);
my_function existElement = (my_function)GetProcAddress(load, "existElement");

TEST(No_Elements, Task_2) {
	long long n = 5;
	long double a[5] = { -1,-2,-3,4,5 };

	EXPECT_EQ(existElement(a,n), CheckElements(a,n));
}

TEST(Last_Element, Task_2) {
	long long n = 5;
	long double a[5] = { -1,-2,-3,4,7 };

	EXPECT_EQ(existElement(a, n), CheckElements(a, n));
}

TEST(First_Element, Task_2) {
	long long n = 5;
	long double a[5] = { 1,-2,-3,4,6 };

	EXPECT_EQ(existElement(a, n), CheckElements(a, n));
}

TEST(Regular_Test, Task_2) {
	long long n = 5;
	long double a[5] = { -2,3.1,3.16,100 };

	EXPECT_EQ(existElement(a, n), CheckElements(a, n));
	FreeLibrary(load);
}

bool CheckElements(long double* a, long long n) {
	for (int i = 0; i < n; i++) {
		if (sin(a[i]) > 0) {
			return 1;
		}
	}

	return 0;
}
