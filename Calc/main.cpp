#include <stdio.h>
#include "calcFunc.h"

int main()
{
	bool istrue = true;

	while (istrue)
	{
		int num1, num2, what, loop;

		printf("1: �� | 2: �� | 3: �� | 4: ������ | 5: ������ | ������ ����: ");
		scanf_s("%d", &what);

		printf("\n");

		printf("�� ���� �Է�: ");
		scanf_s("%d %d", &num1, &num2);

		switch (what)
		{
		case 1:
			printf("��: %d\n", Add_num(num1, num2));
			break;
		case 2:
			printf("��: %d\n", Minus_num(num1, num2));
			break;
		case 3:
			printf("��: %d\n", Multiply_Num(num1, num2));
			break;
		case 4:
			printf("��: %f\n", Divide_num(num1, num2));
			break;
		case 5:
			printf("��: %d\n", Remain_num(num1, num2));
			break;
		default:
			break;
		}

		printf("\n���⸦ ��� ���? y = 0/n = 1 ");
		scanf_s("%d", &loop);

		if (loop == 1)
		{
			printf("���⸦ �����մϴ�.");
			break;
		}

		printf("\n");
	}

	return 0;
}