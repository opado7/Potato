#include <iostream>
#include <stdio.h>

void Butitem(int* Money, int price)
{
	/*
	* int* Money는 메모리 복제가 일어나지 않음
	* 메모리에 효율적인 관리, 데이터 참조가 편리
	*/
	*Money -= price;

}

enum ePhoneType //문자열을 열거시키면 위에서부터 0, 1, 2와 같이 번호가 부여됨
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
		pps->iphonecnt--; //포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
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
	//포인터 주소 값을 변경할 수 있다.
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
	* 포인터 활용하는 이유
	* 메모리에 효율적인 관리, 데이터 참조가 편리함
	* int* pa = 포인터 변수의 선언(pa에 들어가있는 주소에 int형의 크기 만큼 참조 하겠다.)
	* nullptr = 포인터 변수의 초기화값(주소값이 비어있음)
	* 포인터의 크기(x32 = 4byte, x64 = 8byte)
	*/

	int* pa = nullptr;
	pa = &a;//a주소값을 pa에 넣음
	//레퍼런스 참조(주소가 가르키는값)
	b = *pa;//b에 pa가 가르키고 있는 주소값을 넣음
	*pa = 10; //pa가 가르키고 있는 주소에 값을 10으로 변경

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

	////---배열---

	//int arrint[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	//int* pint = nullptr;//pint에 들어가있는 주소에 int형의 크기 만큼 참조 하겠다.

	//pint = arrint;
	//printf("%d\n", *pint);
	//pint += 1; //값이 올라가는것이 아닌 다음 배열을 가리킨다. arrint[0] -> arrint[1]
	//printf("%d\n", *pint);

	//short arrs[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	//pint = (int*)arrs;//(int*)을 사용하여 int*로 강제로 형변환(Cast)
	//pint += 1;//pint가 int*이므로 int(4Byte)만큼 다음 주소값을 참조
	//short* ps = (short*)pint;//int(4Byte)만큼 이동한 주소 값은 Short(2Byte) 2번 이동한 값
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
	//const 상수화
	const int cint = 100;
	
	int value = 0;
	int value2 = 0;
	int* pvalue = &value;

	/*
	* const int* pvalue = &value; <- 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	* int const* pvalue = &value; <- 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	* int* const pvalue = &value; <- 포인터가 가르키는 내용 수정 가능, 포인터 값 수정 불가, 참조 가능
	* const int* const pvalue = &value; <- 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
	* int const* const pvalue = &value; <- 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
	*/

	*pvalue = 2;
	pvalue = &value2;

	printf("pvalue = %d\n", *pvalue);

	printnumber(&value);
	printnumber2(value);

	printphoneshop(&stps);

}