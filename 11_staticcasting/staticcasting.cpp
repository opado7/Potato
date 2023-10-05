#include <iostream>

class cbase
{
public:
	int a = 1;

};

class cchild1 : public cbase
{
public:
	void printb();
	float b = 3.14f;
};

void cchild1::printb() {
	printf("child1::printB = %f\n", b);
}

class cchild2 : public cbase {
public:
	void printb();
	int c = 3;
};

void cchild2 :: printb() {
	printf("child2::printc = %d\n", c);
}

int main()
{
	cbase* pbase = new cchild1;
	//pbase->printb(); ( X )
	//cbase* 포인트로 캐스팅하기 때문에 이러한 접근은 불가능

	/*
	* 기본 캐스팅 방법
	* 강제로 cbase* 포인터에 메모리를 cchild1* 포인터 메모리 틀에 맞춰 읽어온다.
	*/
	cchild1* pchild1 = (cchild1*)pbase;
	pchild1->printb();

	/*
	* 아래와 같이 포인트를 잘못 가르키는 실수가 나오는 경우 문제가 발생할 수 있다.
	* 강제로 int*에 메모리를 cchild*에 맞추면 서로 맞지 않아 나중에 문제발생가능
	* 그렇지만 컴파일에선 문제가 없어 나중에 찾기 매우 힘듬
	*/

	int* a = new int (0);
	

	/*
	* static_cast : 정적캐스팅(컴파일 단계에서 반환)
	* 강제 int* 포인터에 메모리를 cchild*에 맞추려고 하면 컴파일 에러 발생
	* pchild1 = static_cast<cchild1*>(a);
	* 에러"잘못된 형식 변환입니다"가 바로 출력
	* cbase*를 캐스팅시 정상적으로 컴파일 가능
	*/
	pchild1 = (cchild1*)a;
	pchild1 = static_cast<cchild1*>(pbase);

	/*
	* static_cast는 부모의 형태만 확인,
	*  컴파일 단계에서 실행되므로 어떤 형태가 들어오는지 알 수 없음
	* 자식이 다르면 확인하지 않기 때문에 에러x 컴파일문제x 정상적으로 빌드됨
	* 어디서 문제가 발생되는지 확인 x
	* 
	*/
	cbase* pbase2 = new cchild1;
	cchild2* pchild2 = static_cast<cchild2*>(pbase2);
	pchild2->printb();
	/*
	* printb = 1078523331이 나오는데, float를 int형으로 강제 입출력 시키는 바람에
	* 3.14f의 int형태의 값이 출력됨
	* 아래 float -> int 식이랑 동일
	*/


	float fvalue = 3.14f;
	int* pi = (int*)&fvalue;
	printf("pi = %d\n", *pi);

	delete pbase;
	delete a;
	delete pbase2;
}