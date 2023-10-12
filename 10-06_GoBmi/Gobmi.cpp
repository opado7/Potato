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

	std::cout << "�����Ը� �Է����ּ���: ";
	std::cin >> weight;

	std::cout << "Ű�� �Է����ּ���: ";
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
		std::cout << "BMI�� ����Ͻðڽ��ϱ�? y/n ";
		std::cin >> go;

		switch (go)
		{
		case 'y':
			result = measure();

			if (result > 20)std::cout << "bmi: " << result << " ���Դϴ�." << std::endl;
			else if(result > 10)std::cout << "bmi: " << result << " ��ü���Դϴ�." << std::endl;
			else std::cout << "bmi: " << result << " �����Դϴ�." << std::endl;

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