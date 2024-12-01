#include <iostream>
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "Russian");

	menu(0);

	unsigned int m, n;
	std::cout << "Введите количество строк в массиве: ";
	m = CheckUnsigned();
	std::cout << "Введите количество столбцов в массиве: "; 
	n = CheckUnsigned();

	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	std::cout << "Введите двумерный массив:\n";
	Enter2DArray(a, m, n);

	long long n_zeroes = countZero(a, m, n);
	if (n_zeroes == 0) {
		std::cout << "В массиве нет нулей\n";
	}
	else {
		std::cout << "Количество нулей: " << n_zeroes << "\nПоложение нулей:\n";
		findZero(a, m, n);
	}

	long double** reversed_a = new long double* [m];
	for (int i = 0; i < m; i++) {
		reversed_a[i] = new long double[n];
	}
	reverseArray(a, m, n, reversed_a);
	std::cout << "Массив с элементами в обратном порядке: \n";
	Output2DArray(reversed_a, m, n);

	Delete2DArray(a, m);
	Delete2DArray(reversed_a, m);

	repeat();

	_CrtDumpMemoryLeaks();
}
