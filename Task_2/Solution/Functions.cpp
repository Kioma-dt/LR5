#include <iostream>

int main();
void menu(bool variant) {
	std::cout << "��������: ��������� ����� �������������\n������: 453503\n";
	std::cout << "������� 2. ��� ��������� ����������� ������� a �� n ��������� ���������, ��� ����������, �� ������� ����, ���� ������� a_i, ��� �������� ����������� ������� sin a_i > 0\n";
	if (variant) std::cout << "������� 1\n";
	std::cout << "�������: \n";
}

void repeat() {
	std::cout << "��������� �������?(y/n) ";
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
			std::cout << "�������� ������!\n";
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
		std::cout << "�������� ������ �����! ���������� ������ ����� ��������������� �����!\n";
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
		std::cout << "�������� ������ �����! ���������� ������ �����!  ������� ������ ������, ������� � ������� ���������� ��������\n";
	}

	return input;
}

void EnterArray(long double* a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		a[i] = CheckArrayDouble();
	}
}

