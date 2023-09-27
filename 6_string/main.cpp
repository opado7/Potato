#include <stdio.h>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

unsigned int getstringlength(const wchar_t* _pstring)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pstring + i);

		if (c == '\0')
		{
			break;
		}
		++i;
	}

	return i;
}


void stringcat(wchar_t* _dest, unsigned int size, const wchar_t* _psource)
{
	int i = 0, j = 0;
	int source_len = getstringlength(_psource);
	int dest_len = getstringlength(_dest);

	if (size < getstringlength(_dest) + getstringlength(_psource) + 1)
	{
		assert(nullptr);
	}

	for (int k = 0; k < source_len; k++)
	{
		*(_dest + dest_len + k) = *(_psource + k);
	}

	wprintf(L"%s\n", _dest);
}

int Stringcmp(const wchar_t* _pleft, const wchar_t* _pright)
{
	int leftlen = getstringlength(_pleft);
	int rightlen = getstringlength(_pright);

	int nloop = (leftlen < rightlen) ? leftlen : rightlen; //가장 짧은 문자의 길이 비교

	for (int i = 0; i < nloop; i++)
	{
		if (_pleft[i] == _pright[i]) continue; //문자 같으면 크기비교 실행 안하고 for문 실행
		return (_pleft[i] > _pright[i]) ? 1 : -1;//비교 반환
	}

	if (leftlen != rightlen)//left가 길면 1, right 길면 -1
	{
		if (leftlen > rightlen) return 1;//크기비교 결과를 반환
		else return -1;
	}

	return 0;//완전 같을 시
}

int main()
{
	/*
	* multi-byte
	* 127개 아스키 코드 문자 표기, 문자에 따라 가변형으로 크기가 변경
	* 국가간의 호환이 되지 않는 방식으로 다른 시스템으로 보내면 글자 깨짐
	* 자국어 표기만을 위한 인코딩
	*/

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	char c1 = 'a';
	printf("c1 = %c\n", c1);//한글자 char 입력시 %c 사용

	char arrc1[10] = "abc한글";//영어는 1byte, 한글은 2byte
	printf("arrc1 = %s\n", arrc1);//문자열 char 입력시 %s 사용

	//와이드 문자(wide character)
	//multi-byte에 문제를 해결하기 위해 나온 유니코드 방식
	//세계의 거의 모든 문자를 표현할 수 있기 때문에 최근에 많이 사용됨
	//가장 자주 사용하는 방식은 UTF-8이 있다.

	wchar_t wc1 = L'a';//2byte, wchar_t형에 문자를 넣을때 앞에 L을 붙임
	wprintf(L"wc1= %c\n", wc1);//wchar_t를 출력할때는 wprintf를 사용, 출력 문자열 앞 L붙임
	wchar_t arrwc1[10] = L"abc한글";
	wprintf(L"arrwc1 = %s\n", arrwc1);

	wchar_t szwchar[10] = L"abcdefghi";//문자열은 기본적으로 마지막에 개행 문자가 들어가있다 '\n'
	wprintf(L"arrwc1 = %s\n", szwchar);

	wchar_t szwcharlen[20] = L"abcdefg";
	cout << wcslen(szwcharlen) << endl;//문자열 길이 출력

	wcscat_s(szwcharlen, 20, L"ppp");//문자열 붙임(iostream 필요)
	wprintf(L"szwcharlen = %s\n", szwcharlen);

	wchar_t goal[100] = L"지금 붙이고 있는 것: ";
	wchar_t a[10] = L"abcde";
	wchar_t a2[5] = L"fghi";

	stringcat(goal, 100, L"ab");

	wcscpy_s(goal, a);//앞쪽 문자열에 뒤 문자열 복사해넣음

	int result = wcscmp(a, L"abcde");//같으면 0, 앞 문자 순번이 ㅃㅏ르면 1, 뒤면 -1
	printf("result = %d\n", result);

	int test = Stringcmp(L"pweee", L"pweee");
	cout << test << endl;
}