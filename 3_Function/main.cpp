#include <stdio.h>
/*
* �Լ���
* unsigned int : ��ȯ �ڷ���
* CalculatorSum : �Լ� �̸�
* (int x, int y): �Ű�����(�Ķ����)
*/

unsigned int Calculator_Sum(int x, int y)
{
	return x + y;
}

void CallFunction()
{
	printf("Call Function");
}

int Calculator_Minus(int x, int y)
{
	return x - y;
}

int Calculator_Multiply(int x, int y)
{
	return x * y;
}

int Calculator_Divide(int x, int y)
{
	return x / y;
}

int Calculator_Remain(int x, int y)
{
	return x % y;
}

void Draw_line()
{
	printf("\n\n-----------------------------------\n\n");
}

int main()
{
	unsigned int nResult = 0;
	int a = 5;
	int b = 3;

	printf("A = 5, B = 3");
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
	printf("Divide Result: %d", nResult);
	Draw_line();

	nResult = Calculator_Remain(a, b);
	printf("Remain Result: %d", nResult);
	Draw_line();

	CallFunction();

	return 0;
}