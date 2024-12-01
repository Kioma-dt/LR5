#include <iostream>
#include <cmath>
#include <Windows.h>
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	HINSTANCE load = LoadLibrary(L"DynamicLib.dll");
	typedef bool (*my_function) (long double*, long long);
	my_function existElement;
	existElement = (my_function)GetProcAddress(load, "existElement");

	menu(1);
	
	unsigned int n;
	std::cout << "Введите n: ";
	n = CheckUnsigned();

	long double* a = new long double[n];
	std::cout << "Введите массив a:\n";
	EnterArray(a, n);

	std::cout << "Синус элементов массива:\n";
	for (int i = 0; i < n; i++) {
		std::cout << sin(a[i]) << ' ';
	}
	std::cout << '\n';

	if (existElement(a, n)) {
		std::cout << "Существует\n";
	}
	else {
		std::cout << "Не существует\n";
	}

	delete[] a;
	FreeLibrary(load);

	repeat();

	_CrtDumpMemoryLeaks();
}