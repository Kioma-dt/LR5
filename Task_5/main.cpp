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

	long long** a = new long long* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long long[n];
	}
	std::cout << "Введите двумерный массив:\n";
	Enter2DArray(a, m, n);

	unsigned int n_elements = countElements(a, m, n);
	if (n_elements == 0) {
		std::cout << "В массиве нет нечетных элементов в четных столбцах\n";
	}
	else {
		long long* elements = new long long[n_elements];
		findElements(a, m, n, elements);
		std::cout << "Нечетные элементы массива в четных столбцах:\n";
		OutputArray(elements, n_elements);
		std::cout << "\nСреднее арифметическое нечетных элементов массива в четных столбцах: " << countArithmeticMean(elements, n_elements) << '\n';
		delete[] elements;
	}

	Delete2DArray(a, m);

	repeat();

	_CrtDumpMemoryLeaks();
}