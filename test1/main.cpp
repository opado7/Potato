#include <stdio.h>
#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	//2의배수 출력
	print_odd();
	cout << endl;

	//n의 배수 출력하기
	//n = 숫자 하나 입력받아서 출력
	int num = 0;
	cout << "배수를 출력할 숫자: ";
	cin >> num;

	write_odd(num);
	cout << endl;

	//0~100 사이 2의 배수 갯수를 출력
	print_two();
	
	//abcdef를 반대로 출력
	wchar_t szwchar[20] = L"abcdef";

	reverse(szwchar);

	//wchar_t 형으로 문자 입력 받기
	wchar_t szwcharinput[20] = L"";
	cout << "문자열을 입력하여 a의 갯수 출력 -> ";
	wscanf_s(L"%ls", szwcharinput, (unsigned)_countof(szwchar));

	cout << count_a(szwcharinput) << endl;
}