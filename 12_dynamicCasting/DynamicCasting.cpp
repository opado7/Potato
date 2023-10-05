#include <stdio.h>
#include <iostream>

/*
* x64�ΰ�� Ŭ���� ũ�⸦ 8/16/24/32 �� ���� 8byte �������� �Ҵ�
* RTTI���� �Ҵ� 8Byte + 4Byte = 12Byte
* 12Byte ���� �� �ִ� �ּ����� ������ 16Byte
*/
class cbase
{
public:

	/*
	* �����Լ�
	* virtual Ű���带 �Լ� �տ� �ٿ� ���
	* �ڽ� Ŭ�������� �Լ��� override�ؼ� �籸�� ����
	* ���� �Լ��� �Ǹ� RTTI������ ����Ű�� ������ ���� ���� 8Byte(x64) �Ҵ�
	* RTTI �����ʹ� �ش� Ŭ�������� ������ ����Ű�� ��
	* dynamic_cast�� Ŭ������ ũ�⸦ �����ϴ°� �ƴ϶� 
	* �߰��� �Ҵ�� RTTI �������� Ŭ���� ������ ����
	* ��Ÿ���� �������� �Ҵ�
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
		* <cchild1*> = ĳ������ Ŭ���� Ÿ��
		* ptemp = ĳ����(����ȯ)�� ��ü
		* cchild1* pchild = ����ȯ ��� ��ȯ��(������ ������ ��ü ��ȯ, ���н� nullptr) 
		*/
		cchild1* pchild = dynamic_cast<cchild1*>(ptemp);
		if (pchild == nullptr) continue;

		pchild->printy();

	}

	for (cbase* ptemp : pbase) {
		delete ptemp;
	}
}