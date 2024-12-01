#include <cmath>

extern "C" __declspec(dllexport) bool existElement(long double* a, long long n) {
	if (n == 1) {
		return sin(a[0]) > 0;
	}
	else if (n % 2 == 0){
		return (existElement(a, n / 2) || existElement(&a[n / 2], n / 2));
	}
	else {
		return (existElement(a, n / 2 + 1) || existElement(&a[n / 2 + 1], n / 2));
	}
}
