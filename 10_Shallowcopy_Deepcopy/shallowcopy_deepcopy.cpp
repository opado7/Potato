#include <stdio.h>
#include <iostream>

class Cname
{

public:
	Cname(const wchar_t* name) :szname(nullptr), ten(0) {
		ten = wcslen(name) + 1;
		szname = new wchar_t[ten];
		wcscpy_s(szname, ten, name);
	}

	//��������� �� ���� �Ҵ� ������(C++)
	//�Ķ���ͷ� (const Cname& other)�� ���� �ڽ��� Ŭ���� Ÿ���� ���۷����� ������ ���������
	Cname(const Cname& other) :szname(nullptr), ten(0) {
		
		if (szname != nullptr) { 
			delete[] szname;
		}

		ten = wcslen(other.szname) + 1; 
		szname = new wchar_t[ten];
		wcscpy_s(szname, ten, other.szname);
	}

	~Cname();

	wchar_t* getname() {
		return szname;
	}

	const Cname& operator=(const Cname& other)
	{
		//szname = other.szname;//other.szname�� ����Ű�� �ִ� ���� szname�� ����Ű�� �ϰڴ�(Shallow Copy)
		//ten = other.ten;

		if (szname != nullptr) { // other�� �����ϱ� �� �ڸ����
			delete[] szname;
		}

		ten = wcslen(other.szname) + 1; //�����ؿ� ���ڿ��� ũ�⿡ �°� ���Ҵ� �� ����(Deep Copy)
		szname = new wchar_t[ten];
		wcscpy_s(szname, ten, other.szname);

		return *this;
	}

	wchar_t* szname;
	size_t ten;
};

Cname::~Cname() {
	delete[] szname;
}

int main()
{
	_wsetlocale(LC_ALL, L"korean"); //set korean

	Cname name(L"������");
	Cname name2(L"�ݰ���");
	
	name = name2; //���� ������ ó��

	Cname name3 = name;

	wprintf(L"name1=%s", name.getname());
}