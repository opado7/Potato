#include <stdio.h>
#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	//2�ǹ�� ���
	print_odd();
	cout << endl;

	//n�� ��� ����ϱ�
	//n = ���� �ϳ� �Է¹޾Ƽ� ���
	int num = 0;
	cout << "����� ����� ����: ";
	cin >> num;

	write_odd(num);
	cout << endl;

	//0~100 ���� 2�� ��� ������ ���
	print_two();
	
	//abcdef�� �ݴ�� ���
	wchar_t szwchar[20] = L"abcdef";

	reverse(szwchar);

	//wchar_t ������ ���� �Է� �ޱ�
	wchar_t szwcharinput[20] = L"";
	cout << "���ڿ��� �Է��Ͽ� a�� ���� ��� -> ";
	wscanf_s(L"%ls", szwcharinput, (unsigned)_countof(szwchar));

	cout << count_a(szwcharinput) << endl;
}