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
		std::cout << "소득세를 계산하시겠습니까? y/n ";
		std::cin >> go;

		switch (go)
		{

		case 'y':
			std::cout << "연간 총 소득을 입력하십시오.(단위: 만): ";
			std::cin >> salary;
			if (salary < 1200) {
				std::cout << "저런, 세금 안내셔도 되세요." << std::endl;
				break;
			}
			std::cout << "소득세는 " << CowGetTax(salary) << "% 입니다." << std::endl;
			break;

		case 'n':
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;

		default:
			std::cout << "잘못 입력하셨습니다." << std::endl;
			break;
		}
		std::cout << '\n';
	}

}