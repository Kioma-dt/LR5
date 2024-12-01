#include <iostream>
#include "pch.h"

int main();

unsigned int countEvenDiagonal(long long** a, unsigned int n, unsigned int k) {
	unsigned int size_diagonal = 0;
	for (int i = 0; i < std::min(n, k); i++) {
		if (a[i][i] % 2 == 0) {
			size_diagonal++;
		}
	}

	return size_diagonal;
}

void findEvenDiagonal(long long** a, unsigned int n, unsigned int k, long long* diagonal) {
	long long count = 0;
	for (int i = 0; i < std::min(n, k); i++) {
		if (a[i][i] % 2 == 0) {
			diagonal[count] = a[i][i];
			count++;
		}
	}
}


long long multiplyArray(long long* a, unsigned int n) {
	long long res = 1;
	for (int i = 0; i < n; i++) {
		res *= a[i];
	}

	return res;
}

void menu(bool variant) {
	std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
	std::cout << "Задание 3. Дан двумерный динамический массив целых чисел a размерностью n на k. ";
	std::cout << "Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение. Вычислить произведение элементов динамического массива.\n";
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

int CheckArrayInt() {
	int input;
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
		std::cout << "Неверный формат ввода! Необходими ввести целое число!  Введите массив занаво, начиная с неверно введенного элемента\n";
	}

	return input;
}

void OutputArray(long long* a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
}

void Enter2DArray(long long** a, unsigned int n, unsigned int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			a[i][j] = CheckArrayInt();
		}
	}
}

void Delete2DArray(long long ** a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

