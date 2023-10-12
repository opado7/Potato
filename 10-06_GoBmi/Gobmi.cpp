#include <iostream>
#include <stdio.h>

float standardWeight(float height) {
	return (height - 100) * 0.9;
}

float GetBMI(float weight, float standardWeight) {
	return (weight - standardWeight) * 100 / standardWeight;
}

float measure() {

	int weight = 0, height = 0;

	std::cout << "몸무게를 입력해주세요: ";
	std::cin >> weight;

	std::cout << "키를 입력해주세요: ";
	std::cin >> height;

	int standard = standardWeight(height);
	int result = GetBMI(weight, standard);

	return result;
}

int main()
{
	char go;
	float result;


	while (true) {
		std::cout << "BMI를 계산하시겠습니까? y/n ";
		std::cin >> go;

		switch (go)
		{
		case 'y':
			result = measure();

			if (result > 20)std::cout << "bmi: " << result << " 비만입니다." << std::endl;
			else if(result > 10)std::cout << "bmi: " << result << " 과체중입니다." << std::endl;
			else std::cout << "bmi: " << result << " 정상입니다." << std::endl;

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