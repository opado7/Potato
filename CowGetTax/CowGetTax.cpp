#include <stdio.h>
#include <iostream>

int CowGetTax(int num) {

	if (num > 100000) return 45;
	else if (num > 50000) return 42;
	else if (num > 30000) return 38;
	else if (num > 15000) return 35;
	else if (num > 8800) return 24;
	else if (num > 4600) return 15;
	else return 6;
}

int main()
{

	char go;

	while (true) {

		int salary = 0;
		std::cout << "�ҵ漼�� ����Ͻðڽ��ϱ�? y/n ";
		std::cin >> go;

		switch (go)
		{

		case 'y':
			std::cout << "���� �� �ҵ��� �Է��Ͻʽÿ�.(����: ��): ";
			std::cin >> salary;
			if (salary < 1200) {
				std::cout << "����, ���� �ȳ��ŵ� �Ǽ���." << std::endl;
				break;
			}
			std::cout << "�ҵ漼�� " << CowGetTax(salary) << "% �Դϴ�." << std::endl;
			break;

		case 'n':
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return 0;

		default:
			std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
			break;
		}
		std::cout << '\n';
	}

}