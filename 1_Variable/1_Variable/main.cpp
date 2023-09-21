#include <iostream>
#include <stdlib.h>

int main()
{
	/*
	
	1000 0000 = 맨 앞 부호 1(-) 0(+)

	int 자료형
	최초 컴퓨터에서 16bit 사용
	32bit일때 32
	64bit일때 64

	*/
	
	int a;

	unsigned ua;
	char c; // -128~127 1byte
	unsigned uc; // 0~255 1byte
	c = 128;

	// short int = short
	short s;

	float f = 0.1f;


	/*
	* 부동소수점
	* 0000 / 0000 으로 나누어질때
	* 0001 0000 = 1 이라면,
	* 0000 1000 = 0.5
	* 0000 0100 = 0.25
	* ...
	* 
	* 0000 1101 = 0.5 + 0.25 + 0.0625 = 0.8125
	* 0(부호부) / 000 0000 0(지수부) / 000 0000 0000 0000 0000 0000(가수부)
	* 21.8125 = 21(10101).8125(0.1101)
	* 101011101(218125)
	* 0.218125 -> 101011101(218125) -> 2^5
	* 0(부호부) / 000 0010 1 (지수부) / 101 0111 0100 0000 0000 0000(가수부)
	* 
	*/

	float i2 = 0;
	float f2 = 1.0f;
	i2 = (int)f2;
	f2 = (float)i2;
	f2 = float(i2);
	f2 = (float)(i2 + 1);
	i2 = int(f2) + 1;

	//연산자
	i2 = 1 + 1;
	i2 = i2 + 1;
	i2 += 1;

	float divide = 10 / 2.0f;

	float remain = 10 % 3;

	int add = 0, minus = 0;
	add++;
	minus--;

	int addR = 0, addL = 0;
	addL = ++add;
	addR = add++;
	/*
	* addR과 L엔 모두 1이 들어감
	* 절차대로 진행하기 때문에 첫줄엔 ++을 진행한 1이 들어가지만,
	* 두번째에는 1이 R에 대입되고 ++이 진행됨.
	*/

	/* 
	논리연산자
	&& = and, || = or, ! = not
	*/

	bool Result = true;
	
	Result = 0 && 20;

	//ju석, 컴파일에 포함되지 않음
	//지정한 구문 주석: Ctrl + k -> Ctrl + c
	//주석해제: Ctrl + k -> Ctrl + u


	//디버깅 단축키
	/*
	f5" 디버깅 시작, 진행
	f9: 중단점 해제, ㅐㅇ성
	f10: 디버깅중 다음구문
	f11: 디버깅중 다음 구문 진행
	shift + f5: 종료
	*/

	/*
	* 비교연산자
	* ==, !=, >, >=, <, <=
	*/

	int nResult = (10 == 11) ? 100 : 0;

	//문제 아래 time 들어있는 초 값에 분과 시간을 구해라
	unsigned int sec = 987654321; // 초

	unsigned int min = 0, hour = 0, day = 0;
	
	day = sec / 60 * 60 * 24 ;
	hour = (sec - day * 86400) / 3600;
	min = (sec - (day * 86400 + hour * 3600)) / 60;
	sec = (sec - (day * 86400 + hour * 3600 + min * 60)) % 60;
	
	std::cout << day << "일 " << hour << "시 " << min << "분 " << sec << "초 " << std::endl;

	system("pause");
}
