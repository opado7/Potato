#include <stdio.h>
#include <iostream>
#include "Myclass.h"

struct aMyStruct
{
	int a;
};

/*
* Class(����, �ڷ���)
* Class�� ����� ���� Type�̶�� �Ѵ�.
* C�� struct�� Ȯ��� ����
* C++�� Ŭ������ �� ���� �׼���(����) ������(private, protected, public)�� ����
* �׼����� ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ���� �Ǵ� ������ ������ �����.
* ������ �����ڸ� ����Ͽ� ������ �� �Լ��� ����°� ĸ��ȭ ��� �Ѵ�.
* Class�� �ѱ۷� �����ϸ� ��Ʋ�̶�� ��, ��밡���� ��ü�� �ƴ�
* ��ü�� �����ϱ� ���� ����� ��Ÿ����.
*/


/*
* ��ü(object)
* class�� ����ؼ� �����Ȱ� ��ü��� �Ѵ�.
* class�� ������ �������� �����ǰ� �޸𸮿��� ������ ������
* 
* ��ü ���� ���α׷���
* ��ü ���� ���α׷����� ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� ���� ���� ������ ����
* ��ü���� �������� ������ ����� �з�����
* ������ ��ü�� �޽����� �ְ�ް�, �����͸� ���������� ó�� �� �� �ִ�.
*/

class cMyClass
{
	/*
	* ���� ������
	* private: �ܺ����ٺҰ�
	* protected: ����϶��� ����
	* public: ����
	*/
	//���� �����ڰ� �����ÿ� �⺻ private
	int m_b; //Ŭ���� �ȿ� ����� ������ ��� ������� �Ѵ�.

public:
	int a, c;
	/*
	* ������
	* Ŭ������ �����ɶ� ȣ��Ǵ� �Լ�
	* �������� �ʾƵ� �⺻ �����ڰ� ����
	* �����ڵ� private�� �ܺο��� ȣ��Ұ�
	* �ݵ�� public ����
	* �����ڵ� �Ķ������ ������ Ÿ�Կ� ���� �����ε� ����
	* a(avalue), m_b(0), c(0) ������� ���� �� �ʱⰪ���� ����
	*/

	cMyClass() :a(0), m_b(0), c(0)
	{
		printf("������1\n");
	}
	cMyClass(int avalue, int bvalue) :a(avalue), m_b(bvalue), c(0) 
	{
		printf("������2\n");
	}
	cMyClass(int avalue, int bvalue, int cvalue) :a(avalue), m_b(bvalue), c(cvalue)
	{
		printf("������3\n");
	}
	void printall()
	{
		printf("a = %d\n", a);
		printf("B = %d\n", m_b);
		printf("c = %d\n", c);
	}
	/*
	* �ı���
	* Ŭ������ �ı��ɶ� ȣ��Ǵ� �Լ�
	* �������� �ʾƵ� �⺻����
	* �ı��ڵ� public�� �ƴϸ� ȣ���� �Ұ���
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
		//this: Ŭ���� �ȿ��� �Լ��� ȣ���� ��� ��ü�� �ǹ�
		this->c = num;
	}

	/*
	* ������ �����ε�
	* ���Կ����� (�⺻����)
	* const cMyClass& : �������� ��ȯ�� ������
	* operator= : �����ε��� ������
	* (const cMyClass& other) : �����ʿ� �Էµ� ����
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
	//���۷��� ����
	//�޸� ������ ���� �ʰ� ������ �����Ͽ� �޸𸮸� ȿ�������� ����ϱ� ���� ������
	cMyClass my(73, 1);
	cMyClass cmy2(100, 200);

	/*
	* ������ ������ ������ ������ �ּ� ���� �����Ѵ�.
	* ������ ������ �������� ����Ű�� �ִ� �ּҰ��� �ٸ�
	*/
	int num = 100;
	int* pnum = &num; //pnum ������ �������� num�� �ּҰ��� 
	printf("&pnum != &num ? %d\n", (int(&pnum)!=int(&num)));
	aMyStruct sttest;
	aMyStruct* ptest = &sttest;

	
	my.a = 10;


	my.printb();

	my.setc(12);
	my.setc(24);
	my.setc(36);//Ʈ���� ������ �����ϱ� ���� �Լ��� �����ؼ� �����ϴ°� �⺻ ��Ģ
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


