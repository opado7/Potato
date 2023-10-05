#include <iostream>
#include <stdio.h>
#include "Divide.h"
#include "Minus.h"
#include "Sum.h"
#include "Multi.h"

/*
* 함수이름:sum
* 매개변수: int a, int b
* 반환값 int
* a+b
*/

/*
* 함수:minus
* 변수:int a,int b
* 값 int
* a-b
*/

//곱함수

/*
* 함수:divide
* 변:int a, int b
* float
* a * b
*/

/*
* funcAverage
* 반환x
* int &sum, int a, int b, int c
* 레퍼런스 변수 sum에 a,b,c 평균값 반환
*/

void funcAverage(int& sum, int a, int b, int c)
{
	sum = (a + b + c) / 3;
}

/*
* arraysum
* int* arr, int length
* 반환 int
* 배열 arr과 배열의 길이 length를 받아 모든 배열 합 반환
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

	//printf로 Sum = , minus = , multi = , 셋 결과 출력
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