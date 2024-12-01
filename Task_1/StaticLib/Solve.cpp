#include <iostream>

int main();

long double** FindRoots(long double* a, long double* b, long long n_a, long long m_b) {
	long double** roots = new long double* [n_a];
	for (int i = 0; i < n_a; i++) {
		roots[i] = new long double[m_b];
	}

	for (int i = 0; i < n_a; i++) {
		for (int j = 0; j < m_b; j++) {
			if (a[i] == 0) {
				roots[i][j] = 0;
			}
			else {
				roots[i][j] = -b[j] / a[i];
			}
		}
	}

	return roots;
}


void menu(bool variant) {
	std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
	std::cout << "Задание 1. Составить программу для решения уравнения a_i * x + b_j = 0, где a_i и b_j – элементы динамических массивов, \n";
	if (variant) std::cout << "Вариант 1\n";
	std::cout << "Решение: \n";
}

void repeat() {
	std::cout << "Повторить решение?(y/n) ";
	char answer;
	std::cin >> answer;

	while (true) {
		if (answer == 'y') {
			std::cout << "----------------------\n";
			std::cin.ignore(10000, '\n');
			main();
			break;
		}
		else if (answer == 'n') {
			break;
		}
		else {
			std::cout << "Неверный символ!\n";
			std::cin.ignore(10000, '\n');
			std::cin >> answer;
		}
	}
}

unsigned int CheckUnsigned() {
	unsigned int input;
	char next;

	while (true) {
		if (std::cin >> input) {
			std::cin.get(next);
			while (next == ' ') {
				std::cin.get(next);
			}

			if (next == '\n') {
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Неверный формат ввода! Необходими ввести целое неотрицательное число!\n";
	}

	return input;
}

long double CheckArrayDouble() {
	long double input;
	char next;

	while (true) {
		if (std::cin >> input) {
			std::cin.get(next);

			if (next == '\n' || next == ' ') {
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Неверный формат ввода! Необходими ввести число!  Введите массив занаво, начиная с неверно введенного элемента\n";
	}

	return input;
}

void EnterArray(long double* a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		a[i] = CheckArrayDouble();
	}
}

void Delete2DArray(long double** a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

