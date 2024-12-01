#include <iostream>
#include "pch.h"

int main();

long long countElements(long long** a, unsigned int m, unsigned int n) {
	long long res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j += 2) {
			if (a[i][j] % 2 != 0) {
				res++;
			}
		}
	}

	return res;
}

void findElements(long long** a, unsigned int m, unsigned int n, long long* elements) {
	long long count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j += 2) {
			if (a[i][j] % 2 != 0) {
				elements[count] = a[i][j];
				count++;
			}
		}
	}
}

long double countArithmeticMean(long long* elements, unsigned int n_elements) {
	long long sum = 0;
	for (int i = 0; i < n_elements; i++) {
		sum += elements[i];
	}

	return sum / n_elements;
}

void menu(bool variant) {
	std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
	std::cout << "Задание 5. Дан двумерный динамический массив целых чисел. Создать динамический массив из элементов, расположенных в четных столбцах данного массива и имеющих нечетное значение. ";
	std::cout << "Вычислить среднее арифметическое элементов динамического массива.\n";
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

long long CheckArrayInt() {
	long long input;
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

void Enter2DArray(long long** a, unsigned int m, unsigned int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
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

