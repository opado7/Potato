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
	//cbase* ����Ʈ�� ĳ�����ϱ� ������ �̷��� ������ �Ұ���

	/*
	* �⺻ ĳ���� ���
	* ������ cbase* �����Ϳ� �޸𸮸� cchild1* ������ �޸� Ʋ�� ���� �о�´�.
	*/
	cchild1* pchild1 = (cchild1*)pbase;
	pchild1->printb();

	/*
	* �Ʒ��� ���� ����Ʈ�� �߸� ����Ű�� �Ǽ��� ������ ��� ������ �߻��� �� �ִ�.
	* ������ int*�� �޸𸮸� cchild*�� ���߸� ���� ���� �ʾ� ���߿� �����߻�����
	* �׷����� �����Ͽ��� ������ ���� ���߿� ã�� �ſ� ����
	*/

	int* a = new int (0);
	

	/*
	* static_cast : ����ĳ����(������ �ܰ迡�� ��ȯ)
	* ���� int* �����Ϳ� �޸𸮸� cchild*�� ���߷��� �ϸ� ������ ���� �߻�
	* pchild1 = static_cast<cchild1*>(a);
	* ����"�߸��� ���� ��ȯ�Դϴ�"�� �ٷ� ���
	* cbase*�� ĳ���ý� ���������� ������ ����
	*/
	pchild1 = (cchild1*)a;
	pchild1 = static_cast<cchild1*>(pbase);

	/*
	* static_cast�� �θ��� ���¸� Ȯ��,
	*  ������ �ܰ迡�� ����ǹǷ� � ���°� �������� �� �� ����
	* �ڽ��� �ٸ��� Ȯ������ �ʱ� ������ ����x �����Ϲ���x ���������� �����
	* ��� ������ �߻��Ǵ��� Ȯ�� x
	* 
	*/
	cbase* pbase2 = new cchild1;
	cchild2* pchild2 = static_cast<cchild2*>(pbase2);
	pchild2->printb();
	/*
	* printb = 1078523331�� �����µ�, float�� int������ ���� ����� ��Ű�� �ٶ���
	* 3.14f�� int������ ���� ��µ�
	* �Ʒ� float -> int ���̶� ����
	*/


	float fvalue = 3.14f;
	int* pi = (int*)&fvalue;
	printf("pi = %d\n", *pi);

	delete pbase;
	delete a;
	delete pbase2;
}