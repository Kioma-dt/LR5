#include <iostream>
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "Russian");

	menu(0);

	unsigned int n, k;
	std::cout << "Введите n: ";
	n = CheckUnsigned();
	std::cout << "Введите k: ";
	k = CheckUnsigned();

	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[k];
	}
	std::cout << "Введите двумерный массив a:\n";
	Enter2DArray(a, n, k);

	unsigned int size_diagonal = countEvenDiagonal(a, n, k);
	if (size_diagonal != 0) {
		long long* diagonal = new long long[size_diagonal];
		findEvenDiagonal(a, n, k, diagonal);

		std::cout << "Четные элементы на главной диагонали:\n";
		OutputArray(diagonal, size_diagonal);
		std::cout << '\n' << "Произведение четных элементов на главной диагонали: " << multiplyArray(diagonal, size_diagonal) << '\n';

		delete[] diagonal;
	}
	else {
		std::cout << "На главной диагонали нет четных элементов\n";
	}

	Delete2DArray(a, n);

	repeat();

	_CrtDumpMemoryLeaks();
}

