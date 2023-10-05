#include <iostream>
#include <stdio.h>
#include "Divide.h"
#include "Minus.h"
#include "Sum.h"
#include "Multi.h"

/*
* �Լ��̸�:sum
* �Ű�����: int a, int b
* ��ȯ�� int
* a+b
*/

/*
* �Լ�:minus
* ����:int a,int b
* �� int
* a-b
*/

//���Լ�

/*
* �Լ�:divide
* ��:int a, int b
* float
* a * b
*/

/*
* funcAverage
* ��ȯx
* int &sum, int a, int b, int c
* ���۷��� ���� sum�� a,b,c ��հ� ��ȯ
*/

void funcAverage(int& sum, int a, int b, int c)
{
	sum = (a + b + c) / 3;
}

/*
* arraysum
* int* arr, int length
* ��ȯ int
* �迭 arr�� �迭�� ���� length�� �޾� ��� �迭 �� ��ȯ
*/

int arraysum(int* arr, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return sum;
}

class cshop
{
public:
	int m_value = 0;

	virtual void printvalue(){
		printf("value = %d\n", m_value);
	}
};

class cphoneshop :public cshop
{
public:
	cphoneshop(int phonecnt, int phoneprice) :m_phonecnt(phonecnt), m_phoneprice(phoneprice){}
	
	void printvalue() override {
		printf("phone value = %d\n", m_phonecnt * m_phoneprice);
	}
	
	int m_phonecnt;
	int m_phoneprice;
};

class cfruitshop :public cshop
{
public:
	cfruitshop(int fruitcnt, int fruitprice) :m_fruitcnt(fruitcnt), m_fruitprice(fruitprice) {}
	int m_fruitcnt, m_fruitprice;

	void printvalue() override {
		printf("fruit value = %d\n", m_fruitcnt * m_fruitprice);
	}

};

int main()
{
	int a = 150;
	int b = 25;
	int c = 50;
	int value = 0;
	int prtarr[10] = { 10, 23, 54, 84, 864, 8614, 543551, 321, 843, 51313 };

	//printf�� Sum = , minus = , multi = , �� ��� ���
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);
	printf("ab Sum = %d\n", sum(a, b));
	printf("ab Minus = %d\n", minus(a, b));
	printf("ab Multi = %d\n", multi(a, b));
	printf("ab Divide = %.3f\n", divide(a, b));

	funcAverage(value, a, b, c);
	printf("abc AVG = %d\n\n", value);

	printf("Arraysum = %d\n\n", arraysum(prtarr, 10));
	
	cphoneshop phone(10,100);
	phone.printvalue();

	cfruitshop fruit(10, 100);
	fruit.printvalue();

}