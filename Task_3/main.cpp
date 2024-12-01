#include <iostream>
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "Russian");

	menu(0);

	unsigned int n, k;
	std::cout << "������� n: ";
	n = CheckUnsigned();
	std::cout << "������� k: ";
	k = CheckUnsigned();

	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[k];
	}
	std::cout << "������� ��������� ������ a:\n";
	Enter2DArray(a, n, k);

	unsigned int size_diagonal = countEvenDiagonal(a, n, k);
	if (size_diagonal != 0) {
		long long* diagonal = new long long[size_diagonal];
		findEvenDiagonal(a, n, k, diagonal);

		std::cout << "������ �������� �� ������� ���������:\n";
		OutputArray(diagonal, size_diagonal);
		std::cout << '\n' << "������������ ������ ��������� �� ������� ���������: " << multiplyArray(diagonal, size_diagonal) << '\n';

		delete[] diagonal;
	}
	else {
		std::cout << "�� ������� ��������� ��� ������ ���������\n";
	}

	Delete2DArray(a, n);

	repeat();

	_CrtDumpMemoryLeaks();
}

