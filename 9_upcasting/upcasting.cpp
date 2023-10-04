#include <stdio.h>

/*
* 상속
* 기존 클래스에 기능을 추가하거나 재정의하여 새로운 클래스를 정의하는 기능을 말함..
*/

class cbase
{
public:
	cbase(int x) :m_x(0)
	{
		printf("부모클래스\n");
	}
	~cbase()
	{
		printf("부모클래스 소멸\n");
	}
public:
	int m_x;
};

//상속: 클래스 뒤에 상속할 부모 클래스를 선언
class cchild : public cbase
{
public:
	//" : " 뒤에 부모클래스를 넣어 부모클래스의 생성자 호출
	cchild(int x, int y) :m_y(y), cbase(x)
	{
		printf("자식클래스\n");
	}

	//자식 소멸자 먼저 호출 후 부모 소멸자 호출됨
	~cchild()
	{
		printf("자식클래스 소멸\n");
	}
public:
	int m_y;
};

int main()
{
	cbase base(9);
	base.m_x = 100;

	cchild(9, 19);

}