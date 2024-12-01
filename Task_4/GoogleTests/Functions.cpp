#include <iostream>
#include "pch.h"

int main();

long long countZero(long double** a, unsigned int m, unsigned int n) {
	long long res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				res++;
			}
		}
	}

	return res;
}

void findZero(long double** a, unsigned int m, unsigned int n, unsigned int** index) {
	unsigned int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				//std::cout << i << "-ая строка, " << j << "-ый столбец;\n";
				index[count][0] = i;
				index[count][1] = j;
				count++;
			}
		}
	}
}

void reverseArray(long double** a, unsigned int m, unsigned int n, long double** reversed_a) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			reversed_a[i][j] = a[m - i - 1][n - j - 1];
		}
	}
}

void menu(bool variant) {
	std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
	std::cout << "Задание 4. Создать двумерный динамический массив вещественных чисел. Определить, встречаются ли среди них элементы с нулевым значением. ";
	std::cout << "Если встречаются такие элементы, то определить их индексы и общее количество. Переставить элементы этого массива в обратном порядке и вывести на экран.\n";
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

void Output2DArray(long double** a, unsigned int m, unsigned int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void Enter2DArray(long double** a, unsigned int m, unsigned int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = CheckArrayDouble();
		}
	}
}

void Delete2DArray(long double** a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}
void Delete2DArray(unsigned int** a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

