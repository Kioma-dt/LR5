#include <iostream>

int main();
void menu(bool variant) {
	std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
	std::cout << "Задание 2. Для заданного одномерного массива a из n элементов проверить, что существует, по крайней мере, один элемент a_i, для которого выполняется условие sin a_i > 0\n";
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

