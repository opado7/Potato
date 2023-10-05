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

	//복사생성자 및 복사 할당 연산자(C++)
	//파라미터로 (const Cname& other)과 같이 자신의 클래스 타입을 레퍼런스로 받으면 복사생성자
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
		//szname = other.szname;//other.szname이 가리키고 있는 곳을 szname도 가리키게 하겠다(Shallow Copy)
		//ten = other.ten;

		if (szname != nullptr) { // other를 복사하기 전 자리비움
			delete[] szname;
		}

		ten = wcslen(other.szname) + 1; //복사해올 문자열의 크기에 맞게 재할당 및 복사(Deep Copy)
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

	Cname name(L"강원기");
	Cname name2(L"금강선");
	
	name = name2; //대입 연산자 처리

	Cname name3 = name;

	wprintf(L"name1=%s", name.getname());
}