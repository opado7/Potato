#include <stdio.h>
#include <iostream>
/*
* 함수형
* unsigned int : 반환 자료형
* CalculatorSum : 함수 이름
* (int x, int y): 매개변수(파라미터)
*/

int Calculator_Sum(int x, int y)
{
	return x + y;
}

int Calculator_Minus(int x, int y)
{
	return x - y;
}

int Calculator_Multiply(int x, int y)
{
	return x * y;
}

float Calculator_Divide(int x, int y)
{
	return x / y;
}

int Calculator_Remain(int x, int y)
{
	return x + y;
}

void Draw_line()
{
	printf("\n\n-----------------------------------\n\n");
}

int itsum_fac(int num)
{
	int result = 1;

	for (int i = num; i > 0; i--)
	{
		result *= i;
	}

	return result;
}

int Refact(int num)
{
	if (num == 1) return 1;

	return num * Refact(num - 1);
}

int sumto_n(int num)
{
	int result = 0;
	for (int i = 1; i <= num; i++)
	{
		result += i;
	}

	return result;
}



int main()
{
	int nResult = 0;
	float fResult = 0;
	int a = 5;
	int b = 3;

	/*printf("A = 5, B = 3");
	Draw_line();

	nResult = Calculator_Sum(a, b);
	printf("Sum Result: %d", nResult);
	Draw_line();

	nResult = Calculator_Minus(a, b);
	printf("Minus Result: %d", nResult);
	Draw_line();

	nResult = Calculator_Multiply(a, b);
	printf("Multiply Result: %d", nResult);
	Draw_line();

	nResult = Calculator_Divide(a, b);
	printf("Divide Result: %f", fResult);
	Draw_line();

	nResult = Calculator_Remain(a, b);
	printf("Remain Result: %d", nResult);
	Draw_line();*/

	//반      복문
	
	std::cout << sumto_n(5);

	return 0;
}