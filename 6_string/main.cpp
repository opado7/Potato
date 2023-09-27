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

	int nloop = (leftlen < rightlen) ? leftlen : rightlen; //���� ª�� ������ ���� ��

	for (int i = 0; i < nloop; i++)
	{
		if (_pleft[i] == _pright[i]) continue; //���� ������ ũ��� ���� ���ϰ� for�� ����
		return (_pleft[i] > _pright[i]) ? 1 : -1;//�� ��ȯ
	}

	if (leftlen != rightlen)//left�� ��� 1, right ��� -1
	{
		if (leftlen > rightlen) return 1;//ũ��� ����� ��ȯ
		else return -1;
	}

	return 0;//���� ���� ��
}

int main()
{
	/*
	* multi-byte
	* 127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ ����
	* �������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���� ����
	* �ڱ��� ǥ�⸸�� ���� ���ڵ�
	*/

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	char c1 = 'a';
	printf("c1 = %c\n", c1);//�ѱ��� char �Է½� %c ���

	char arrc1[10] = "abc�ѱ�";//����� 1byte, �ѱ��� 2byte
	printf("arrc1 = %s\n", arrc1);//���ڿ� char �Է½� %s ���

	//���̵� ����(wide character)
	//multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	//������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	//���� ���� ����ϴ� ����� UTF-8�� �ִ�.

	wchar_t wc1 = L'a';//2byte, wchar_t���� ���ڸ� ������ �տ� L�� ����
	wprintf(L"wc1= %c\n", wc1);//wchar_t�� ����Ҷ��� wprintf�� ���, ��� ���ڿ� �� L����
	wchar_t arrwc1[10] = L"abc�ѱ�";
	wprintf(L"arrwc1 = %s\n", arrwc1);

	wchar_t szwchar[10] = L"abcdefghi";//���ڿ��� �⺻������ �������� ���� ���ڰ� ���ִ� '\n'
	wprintf(L"arrwc1 = %s\n", szwchar);

	wchar_t szwcharlen[20] = L"abcdefg";
	cout << wcslen(szwcharlen) << endl;//���ڿ� ���� ���

	wcscat_s(szwcharlen, 20, L"ppp");//���ڿ� ����(iostream �ʿ�)
	wprintf(L"szwcharlen = %s\n", szwcharlen);

	wchar_t goal[100] = L"���� ���̰� �ִ� ��: ";
	wchar_t a[10] = L"abcde";
	wchar_t a2[5] = L"fghi";

	stringcat(goal, 100, L"ab");

	wcscpy_s(goal, a);//���� ���ڿ��� �� ���ڿ� �����س���

	int result = wcscmp(a, L"abcde");//������ 0, �� ���� ������ �������� 1, �ڸ� -1
	printf("result = %d\n", result);

	int test = Stringcmp(L"pweee", L"pweee");
	cout << test << endl;
}