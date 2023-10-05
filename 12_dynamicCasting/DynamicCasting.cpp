#include <stdio.h>
#include <iostream>

/*
* x64인경우 클래스 크기를 8/16/24/32 와 같이 8byte 간격으로 할당
* RTTI공간 할당 8Byte + 4Byte = 12Byte
* 12Byte 담을 수 있는 최소한의 공간은 16Byte
*/
class cbase
{
public:

	/*
	* 가상함수
	* virtual 키워드를 함수 앞에 붙여 사용
	* 자식 클래스에서 함수를 override해서 재구현 가능
	* 가상 함수가 되면 RTTI정보를 가르키는 포인터 변수 공간 8Byte(x64) 할당
	* RTTI 포인터는 해당 클래스에서 정보를 가리키게 됨
	* dynamic_cast시 클래스의 크기를 참조하는게 아니라 
	* 추가로 할당된 RTTI 포인터의 클래스 정보를 참조
	* 런타임중 동적으로 할당
	*/
	virtual void printx()
	{
		printf("x = %d", m_x);
	}
	int m_x = 10;
};

class cchild1 : public cbase
{
public:
	void printy()
	{
		printf("y = %d\n", m_y);
	}
	int m_y = 20;
};

class cchild2 : public cbase
{
public:
	void printz()
	{
		printf("z = %d\n", m_z);
	}
	int m_z = 30;
};

int main()
{
	/*
	* RTTI (Run Time Type Information / Identification)
	*/

	int64_t i64 = sizeof(cbase);

	printf("cbase size = %I64d\n", i64);
	printf("cchild size = %I64d\n", sizeof(cchild1));

	int64_t* pb = (int64_t*)new cbase;
	int64_t* pc = (int64_t*)new cchild1;

	printf("*pb[0] = %I64d, pb[1] = %d\n", pb[0], (int)pb[1]);
	printf("*pb[0] = %I64d, pb[1] = %d, pc[2] = %d\n", pb[0], (int)pb[1], (int)pc[2]);

	delete pb, pc;

	cbase* pbase[] = { new cchild1, new cchild2 };

	for (cbase* ptemp : pbase)
	{
		ptemp->printx();

		/*
		* dynamic_cast
		* <cchild1*> = 캐스팅할 클래스 타입
		* ptemp = 캐스팅(형변환)할 객체
		* cchild1* pchild = 형변환 결과 반환값(성공시 성공된 객체 반환, 실패시 nullptr) 
		*/
		cchild1* pchild = dynamic_cast<cchild1*>(ptemp);
		if (pchild == nullptr) continue;

		pchild->printy();

	}

	for (cbase* ptemp : pbase) {
		delete ptemp;
	}
}