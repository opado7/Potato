#include <iostream>
#include <stdio.h>

void Butitem(int* Money, int price)
{
	/*
	* int* Money�� �޸� ������ �Ͼ�� ����
	* �޸𸮿� ȿ������ ����, ������ ������ ��
	*/
	*Money -= price;

}

enum ePhoneType //���ڿ��� ���Ž�Ű�� ���������� 0, 1, 2�� ���� ��ȣ�� �ο���
{
	iphone,
	galaxys23,
	galaxyfold,
	galaxyz
};

struct stphoneshop
{
	int iphonecnt;
	int galaxys23;
	int galaxyfold;
	int galaxyz;

	void printphonenum()
	{
		printf("iphone = %d, s23 = %d, fold = %d, Z = %d\n", iphonecnt, galaxys23, galaxyfold, galaxyz);
	}
};

void buyphone(ePhoneType phonetype, stphoneshop* pps)
{
	switch (phonetype)
	{
	case ePhoneType::iphone:
		pps->iphonecnt--; //����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case ePhoneType::galaxys23:
		pps->galaxys23--;
		break;
	case ePhoneType::galaxyfold:
		pps->galaxyfold--;
		break;
	case ePhoneType::galaxyz:
		pps->galaxyz--;
		break;
	default:
		break;
	}
}

void printnumber(const int* number)
{
	//������ �ּ� ���� ������ �� �ִ�.
	//number = nullptr;
	printf("number = %d\n", *number);
}

void printnumber2(const int& number)
{
	printf("number = %d\n", number);
}

void printphoneshop(const stphoneshop* ps)
{
	printf("iphone = %d\n", ps->iphonecnt);
}

void printphoneshop(const stphoneshop& ps)
{
	printf("iphonecnt = %d\n", ps.iphonecnt);
}

int main()
{
	int a = 0;//4byte
	int b = 0;

	/*
	* ������ Ȱ���ϴ� ����
	* �޸𸮿� ȿ������ ����, ������ ������ ����
	* int* pa = ������ ������ ����(pa�� ���ִ� �ּҿ� int���� ũ�� ��ŭ ���� �ϰڴ�.)
	* nullptr = ������ ������ �ʱ�ȭ��(�ּҰ��� �������)
	* �������� ũ��(x32 = 4byte, x64 = 8byte)
	*/

	int* pa = nullptr;
	pa = &a;//a�ּҰ��� pa�� ����
	//���۷��� ����(�ּҰ� ����Ű�°�)
	b = *pa;//b�� pa�� ����Ű�� �ִ� �ּҰ��� ����
	*pa = 10; //pa�� ����Ű�� �ִ� �ּҿ� ���� 10���� ����

	//int num1 = 0;
	//int num2 = 0;
	//int* pnum = nullptr;

	//pnum = &num1;
	//printf("pnum= %d\n", *pnum);
	//*pnum = 20;
	//printf("pnum= %d\n", *pnum);
	//pnum = &num2;
	//printf("pnum= %d\n", *pnum);
	//*pnum = 30;
	//printf("pnum= %d\n", *pnum);

	//std::cout << num1 << ", " << num2 << std::endl; //20, 30

	//int money = 10000;

	//Butitem(&money, 1000);
	//printf("money = %d\n", money);

	stphoneshop stps;
	stps.iphonecnt = 100;
	stps.galaxys23 = 100;
	stps.galaxyfold = 100;
	stps.galaxyz = 100;

	//buyphone(iphone, &stps);

	//stps.printphonenum();

	////---�迭---

	//int arrint[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	//int* pint = nullptr;//pint�� ���ִ� �ּҿ� int���� ũ�� ��ŭ ���� �ϰڴ�.

	//pint = arrint;
	//printf("%d\n", *pint);
	//pint += 1; //���� �ö󰡴°��� �ƴ� ���� �迭�� ����Ų��. arrint[0] -> arrint[1]
	//printf("%d\n", *pint);

	//short arrs[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	//pint = (int*)arrs;//(int*)�� ����Ͽ� int*�� ������ ����ȯ(Cast)
	//pint += 1;//pint�� int*�̹Ƿ� int(4Byte)��ŭ ���� �ּҰ��� ����
	//short* ps = (short*)pint;//int(4Byte)��ŭ �̵��� �ּ� ���� Short(2Byte) 2�� �̵��� ��
	//printf("ps=%d\n", *ps);

	int arr[10] = { 11, 24, 8, 53, 6, 33, 27, 99, 7, 31 };
	int save, save_s;

	for (int i = 0; i < 10; i++)
	{
		save = arr[i];
		save_s = i;

		for (int j = i + 1; j < 10; j++)
		{
			if (save > arr[j])
			{
				save = arr[j];
				save_s = j;
			}
		}
			arr[save_s] = arr[i];
			arr[i] = save;
	}

	for (int i = 0; i < 10; i++)
			{
				std::cout << arr[i] << " ";
			}

	std::cout << std::endl;
	//const ���ȭ
	const int cint = 100;
	
	int value = 0;
	int value2 = 0;
	int* pvalue = &value;

	/*
	* const int* pvalue = &value; <- �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	* int const* pvalue = &value; <- �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	* int* const pvalue = &value; <- �����Ͱ� ����Ű�� ���� ���� ����, ������ �� ���� �Ұ�, ���� ����
	* const int* const pvalue = &value; <- �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����
	* int const* const pvalue = &value; <- �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����
	*/

	*pvalue = 2;
	pvalue = &value2;

	printf("pvalue = %d\n", *pvalue);

	printnumber(&value);
	printnumber2(value);

	printphoneshop(&stps);

}