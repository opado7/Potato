#include <stdio.h>
#include "calcFunc.h"

int main()
{
	bool istrue = true;

	while (istrue)
	{
		int num1, num2, what, loop;

		printf("1: 합 | 2: 차 | 3: 곱 | 4: 나눗셈 | 5: 나머지 | 연산할 내용: ");
		scanf_s("%d", &what);

		printf("\n");

		printf("두 수를 입력: ");
		scanf_s("%d %d", &num1, &num2);

		switch (what)
		{
		case 1:
			printf("답: %d\n", Add_num(num1, num2));
			break;
		case 2:
			printf("답: %d\n", Minus_num(num1, num2));
			break;
		case 3:
			printf("답: %d\n", Multiply_Num(num1, num2));
			break;
		case 4:
			printf("답: %f\n", Divide_num(num1, num2));
			break;
		case 5:
			printf("답: %d\n", Remain_num(num1, num2));
			break;
		default:
			break;
		}

		printf("\n계산기를 계속 사용? y = 0/n = 1 ");
		scanf_s("%d", &loop);

		if (loop == 1)
		{
			printf("계산기를 종료합니다.");
			break;
		}

		printf("\n");
	}

	return 0;
}