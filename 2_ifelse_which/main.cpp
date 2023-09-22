#include <iostream>
#include <stdlib.h>
#include <bitset>

/*
* C++의 컴파일
* C++에서 사람이 작성한 소스코드를 컴퓨터가 읽을 수 있는 코드로 변환하여 실행할 수 있는 파일로 변환하는 과정
* 
* 1. 전처리(Preprocessing)단계: #include와 #define과 같은 전처리가 매크로들을 처리하는 단계
* 2. 컴파일(Compile)단계: 각각의 소스 파일들을 어셈블리 명령어로 변환
* 3. 어셈블(Assemble)단계: 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
* 4. 링킹(Linking)단계: 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계
*/

/*
* 메모리 영역
* 1. Code 영역: 실행할 코드가 저장되어있는 영역(기계어로 존재)
* 2. Data 영역: 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
* 3. Stack 영역: 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
* 4. Heap 영역: malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자로 할당, free() 또는 delete  연산자로 해제
*/

#define LEVEL_1_REWARD_10 0b00000001 
#define LEVEL_1_REWARD_20 0b00000010
#define LEVEL_1_REWARD_30 0b00000100
#define LEVEL_1_REWARD_40 0b00001000
#define LEVEL_1_REWARD_50 0b00010000
#define LEVEL_1_REWARD_60 0b00100000

int main()
{
	/* {
		int a = 0;
		std::cin >> a;
		std::cout << a << " and Hello World!" << std::endl;
	}*/

	{

		/*
		* %d: 부호 있는 10진수 정수
		* %l64d: 부호 있는 10진수 정수(8Byte)
		* %u: 부호 없는 10진수 정수(8Byte)
		* %f: 부호 있는 실수(12.51543);
		* %e, %E: 부호 있는 실수(1.243243e+001)
		* %i: 부호 있는 10진수 정수(10진수/8진수/16진수 입력 가능)
		* %x: 부호 없는 16진수 정수(0123456789abcdef)
		* %X: 부호 없는 16진수 정수(0123456789ABCDEF)
		* %o: 부호 없는 8진수
		* %p: 포인터 값을 16진수로 표기
		* %c: 단일 문자 출력
		*/
		/*int a = 0, b = 0;
		scanf_s("%d %d", &a, &b);
		printf("a + b = %d", a+b);*/
	}

	/*bool Result = true;

	if(Result)
	{
		printf("It's True");
	}
	else
	{
		printf("It's not True");
	}*/

	/*int score = 0;

	printf("Score를 입력하세요 : ");
	scanf_s("%d", &score);

	printf("Score = %d \n", score);
	printf("학점 = ");

	if (score >= 90)
	{
		printf("A");
	}
	else if(score >= 80)
	{
		printf("B");
	}
	else if (score >= 70)
	{
		printf("C");
	}
	else if (score >= 60)
	{
		printf("D");
	}
	else if (score >= 50)
	{
		printf("E");
	}
	else { printf("F!"); }*/

	/*int backnumber = 0;

	scanf_s("%d", &backnumber);

	switch (backnumber)
	{

	case 11:
		printf("포수");
		break;

	case 9:
		printf("투수");
		break;

	default:
		printf("후보");
		break;

	}


	return 0;*/

	//1번
	//int light = 0;

	//scanf_s("%d", &light);

	//if (light) 
	//{ 
	//	printf("파랑"); 
	//}
	//else if (!light)
	//{ 
	//	printf("빨강"); 
	//}

	//printf("\n");

	////2번
	//int ninput = 0;

	//scanf_s("%d", &ninput);

	//if (ninput > 100) 
	//{ 
	//	printf("100보다 큼"); 
	//}
	//else 
	//{ 
	//	printf("100보다 작음"); 
	//}

	//printf("\n");

	////3번
	//int myscore = 0, otherscore = 0;

	//scanf_s("%d %d", &myscore, &otherscore);

	//if (myscore > otherscore) 
	//{ 
	//	printf("3점"); 
	//}
	//else if (myscore == otherscore) 
	//{ 
	//	printf("1점"); 
	//}
	//else 
	//{ 
	//	printf("0점"); 
	//}

	//printf("\n");

	////4번
	//int ncode = 0;

	//scanf_s("%d", &ncode);

	//switch (ncode)
	//{
	//	case 1:
	//	case 3:
	//		printf("남자");
	//		break;

	//	case 2:
	//	case 4:
	//		printf("여자");
	//		break;

	//default:
	//	printf("잘못입력");
	//	break;
	//}

	//printf("\n");

	////5번
	//int ncode2 = 0;
	//scanf_s("%d", &ncode2);

	//if (ncode2 == 1 || ncode2 == 2)
	//{
	//	printf("2000년 이전 출생");
	//}
	//else if (ncode2 == 3 || ncode2 == 4)
	//{
	//	printf("2000년 이후 출생");
	//}
	//else
	//{
	//	printf("잘못입력");
	//}

	/*
	* 비트연산자
	* C++ 11버전부터 숫자 앞에 0b를 붙이면 2진법 표기 가능
	* 2진법 표기 앞에 0b를 붙인다 ( 0b01011101)
	* 8진법 표기 : 앞에 0을 붙임 (0123)
	* 16진법 표기 : 앞에 0x를 붙임(0xFF)
	

	int A = 0b01011101;
	int B = 0123;
	int C = 0xCD;
	printf("2진법(0b01011101): %d\n", A);
	printf("8진법(0123): %d\n", B);
	printf("16진법(0xCD): %d\n", C);
	*/


	/*
	* 비트연산기호
	* 곱(&): 둘다 1이면 1, 아니면 0 -> and
	* 합(|): 둘중에 하나라도 1이면 1, 아니면 0 -> or
	* XOR(^): 둘이 같으면 0, 아니면 1
	* 반전(~): 0이면 1, 1이면 0 -> not
	*/

	/*char bitnum = 0b1000100;
	char bitResult = 0;

	bitResult = bitnum * 0b1010101;

	std::cout << std::bitset<8>(bitResult) << std::endl;

	bitResult = ~0b11010101;

	std::cout << std::bitset<8>(bitResult) << std::endl;*/

	//비트 1로 설정
	char myreward = 0b00000000;

	myreward = myreward | LEVEL_1_REWARD_10;

	std::cout << "Myreward: " << std::bitset<8>(myreward) << std::endl;

	//비트 check
	bool isEnable = false;
	isEnable = myreward & LEVEL_1_REWARD_10;

	if (isEnable) { std::cout << "Reward Check: " << isEnable << std::endl; }
	else { printf("없음"); }
	

	//비트 초기화 설정
	myreward = myreward & ~LEVEL_1_REWARD_10;
	std::cout << "Myreward: " << std::bitset<8>(myreward) << std::endl;
}