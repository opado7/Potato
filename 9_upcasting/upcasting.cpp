#include <stdio.h>

/*
* ���
* ���� Ŭ������ ����� �߰��ϰų� �������Ͽ� ���ο� Ŭ������ �����ϴ� ����� ����..
*/

class cbase
{
public:
	cbase(int x) :m_x(0)
	{
		printf("�θ�Ŭ����\n");
	}
	~cbase()
	{
		printf("�θ�Ŭ���� �Ҹ�\n");
	}
public:
	int m_x;
};

//���: Ŭ���� �ڿ� ����� �θ� Ŭ������ ����
class cchild : public cbase
{
public:
	//" : " �ڿ� �θ�Ŭ������ �־� �θ�Ŭ������ ������ ȣ��
	cchild(int x, int y) :m_y(y), cbase(x)
	{
		printf("�ڽ�Ŭ����\n");
	}

	//�ڽ� �Ҹ��� ���� ȣ�� �� �θ� �Ҹ��� ȣ���
	~cchild()
	{
		printf("�ڽ�Ŭ���� �Ҹ�\n");
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