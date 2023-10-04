#include <stdio.h>
#include <iostream>
#include "Myclass.h"

struct aMyStruct
{
	int a;
};

/*
* Class(변수, 자료형)
* Class는 사용자 정의 Type이라고 한다.
* C의 struct에 확장된 개념
* C++의 클래스는 세 가지 액세스(접근) 지정자(private, protected, public)에 의해
* 액세스가 제어되는 멤버로 데이터 및 함수가 있는 사용자 정의 유형 또는 데이터 구조를 만든다.
* 엑세스 지정자를 사용하여 데이터 및 함수를 만드는걸 캡슐화 라고도 한다.
* Class를 한글로 번역하면 형틀이라는 뜻, 사용가능한 객체가 아님
* 객체를 생성하기 위한 모양을 나타낸다.
*/


/*
* 객체(object)
* class를 사용해서 생성된걸 객체라고 한다.
* class에 선언한 변수들이 생성되고 메모리에서 공간을 차지함
* 
* 객체 지향 프로그래밍
* 객체 지향 프로그래밍은 컴퓨터 프로그램을 명령어의 목록으로 보는 시각에서 벗어나 여러 개의 독립된 단위
* 객체들의 모임으로 구조를 만드는 패러다임
* 각각의 객체는 메시지를 주고받고, 데이터를 독립적으로 처리 할 수 있다.
*/

class cMyClass
{
	/*
	* 접근 지정자
	* private: 외부접근불가
	* protected: 상속일때만 가능
	* public: 개방
	*/
	//접근 지정자가 없을시엔 기본 private
	int m_b; //클래스 안에 선언된 변수를 멤버 변수라고 한다.

public:
	int a, c;
	/*
	* 생성자
	* 클래스가 생성될때 호출되는 함수
	* 선언하지 않아도 기본 생성자가 존재
	* 생성자도 private면 외부에서 호출불가
	* 반드시 public 선언
	* 생성자도 파라미터의 갯수와 타입에 따라 오버로드 가능
	* a(avalue), m_b(0), c(0) 방식으로 생성 시 초기값세팅 가능
	*/

	cMyClass() :a(0), m_b(0), c(0)
	{
		printf("생성자1\n");
	}
	cMyClass(int avalue, int bvalue) :a(avalue), m_b(bvalue), c(0) 
	{
		printf("생성자2\n");
	}
	cMyClass(int avalue, int bvalue, int cvalue) :a(avalue), m_b(bvalue), c(cvalue)
	{
		printf("생성자3\n");
	}
	void printall()
	{
		printf("a = %d\n", a);
		printf("B = %d\n", m_b);
		printf("c = %d\n", c);
	}
	/*
	* 파괴자
	* 클래스가 파괴될때 호출되는 함수
	* 선언하지 않아도 기본존재
	* 파괴자도 public이 아니면 호출이 불가능
	* 
	* 
	*/
	~cMyClass();

	void printb()
	{
		printf("B = %d\n", m_b);
	}

	void setc(int num)
	{
		//this: 클래스 안에서 함수를 호출한 대상 객체를 의미
		this->c = num;
	}

	/*
	* 연산자 오버로딩
	* 대입연산자 (기본생성)
	* const cMyClass& : 왼쪽으로 반환될 변수형
	* operator= : 오버로딩할 연산자
	* (const cMyClass& other) : 오른쪽에 입력될 변수
	*/

	const cMyClass& operator=(const cMyClass& other)
	{
		a = other.a;
		m_b = other.m_b;
		c = other.c;

		return *this;
	}

	const cMyClass& operator+(const cMyClass& other)
	{
		return cMyClass(a + other.a, m_b + other.m_b, c + other.c);
	}

protected:
private:

};

// c = a + b

cMyClass::~cMyClass()
{
}

int main()
{
	//레퍼런스 참조
	//메모리 복제가 되지 않고 원본을 참조하여 메모리를 효율적으로 사용하기 위한 연산자
	cMyClass my(73, 1);
	cMyClass cmy2(100, 200);

	/*
	* 포인터 참조는 포인터 변수의 주소 값을 참조한다.
	* 포인터 변수의 구조값과 가르키고 있는 주소값은 다름
	*/
	int num = 100;
	int* pnum = &num; //pnum 포인터 변수에는 num의 주소값이 
	printf("&pnum != &num ? %d\n", (int(&pnum)!=int(&num)));
	aMyStruct sttest;
	aMyStruct* ptest = &sttest;

	
	my.a = 10;


	my.printb();

	my.setc(12);
	my.setc(24);
	my.setc(36);//트그정 변수를 수정하기 위한 함수를 생성해서 개발하는게 기본 규칙
	my.setc(48);
	//myc = 10

	cMyClass2 sum(1);
	cMyClass cmy3;

	my.printall();
	cmy2.printall();

	my = cmy2;

	my.printall();
	cmy2.printall();

	cmy3 = my + cmy2;

	cmy3.printall();
}


