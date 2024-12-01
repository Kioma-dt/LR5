#include <iostream>
#include "../StaticLib/Header.h"

int main() {
	setlocale(LC_ALL, "Russian");

	menu(1);

	unsigned int n_a, m_b;
	std::cout << "¬вежите количкство элементов массива a: ";
	n_a = CheckUnsigned();
	std::cout << "¬вежите количкство элементов массива b: ";
	m_b = CheckUnsigned();

	long double* a = new long double[n_a], *b = new long double[m_b];
	std::cout << "¬ведите массив a:\n";
	EnterArray(a, n_a);
	std::cout << "¬ведите массив b:\n";
	EnterArray(b, m_b);

	long double** roots = FindRoots(a, b, n_a, m_b);
	
	for (int i = 0; i < n_a; i++) {
		for (int j = 0; j < m_b; j++) {
			std::cout << "a = " << a[i] << "\t b = " << b[j] << "\t x = " << roots[i][j] << '\n';
		}
	}

	delete[] a;
	delete[] b;
	Delete2DArray(roots, n_a);

	repeat();
	_CrtDumpMemoryLeaks();
}