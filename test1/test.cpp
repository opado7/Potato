#include <stdio.h>
#include <iostream>
#include "test.h"

using namespace std;

void reverse(wchar_t* temp)
{

	int length = wcslen(temp);
	for (int i = 0; i < length / 2; i++)
	{
		wchar_t temp1 = *(temp + i);
		wchar_t temp2 = *(temp + length - i - 1);
		*(temp + length - 1 - i) = temp1;
		*(temp + i) = temp2;
	}

	printf("abcdef의 역출력: ");
	wprintf(L"%s\n", temp);

}

int count_a(wchar_t* temp)
{
	int length = wcslen(temp);
	int num_a = 0;

	for (int i = 0; i < length; i++)
	{
		wchar_t temp2 = *(temp + i);
		if (temp2 == 97) num_a++;
	}

	return num_a;
}

void print_odd()
{
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0) cout << i << " ";
	}
}


void write_odd(int num)
{
	for (int i = 1; i <= 100; i++)
	{
		cout << num * i << " ";
	}
}

void print_two()
{
	int count = 0;

	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0) count++;
	}
	cout << "0부터 100까지 2의 배수의 갯수: " << count << endl;
}