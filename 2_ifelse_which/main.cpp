#include <iostream>
#include <stdlib.h>
#include <bitset>

/*
* C++�� ������
* C++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ���� �� �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����
* 
* 1. ��ó��(Preprocessing)�ܰ�: #include�� #define�� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
* 2. ������(Compile)�ܰ�: ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
* 3. �����(Assemble)�ܰ�: ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
* 4. ��ŷ(Linking)�ܰ�: ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�
*/

/*
* �޸� ����
* 1. Code ����: ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
* 2. Data ����: ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
* 3. Stack ����: ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
* 4. Heap ����: malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڷ� �Ҵ�, free() �Ǵ� delete  �����ڷ� ����
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
		* %d: ��ȣ �ִ� 10���� ����
		* %l64d: ��ȣ �ִ� 10���� ����(8Byte)
		* %u: ��ȣ ���� 10���� ����(8Byte)
		* %f: ��ȣ �ִ� �Ǽ�(12.51543);
		* %e, %E: ��ȣ �ִ� �Ǽ�(1.243243e+001)
		* %i: ��ȣ �ִ� 10���� ����(10����/8����/16���� �Է� ����)
		* %x: ��ȣ ���� 16���� ����(0123456789abcdef)
		* %X: ��ȣ ���� 16���� ����(0123456789ABCDEF)
		* %o: ��ȣ ���� 8����
		* %p: ������ ���� 16������ ǥ��
		* %c: ���� ���� ���
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

	printf("Score�� �Է��ϼ��� : ");
	scanf_s("%d", &score);

	printf("Score = %d \n", score);
	printf("���� = ");

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
		printf("����");
		break;

	case 9:
		printf("����");
		break;

	default:
		printf("�ĺ�");
		break;

	}


	return 0;*/

	//1��
	//int light = 0;

	//scanf_s("%d", &light);

	//if (light) 
	//{ 
	//	printf("�Ķ�"); 
	//}
	//else if (!light)
	//{ 
	//	printf("����"); 
	//}

	//printf("\n");

	////2��
	//int ninput = 0;

	//scanf_s("%d", &ninput);

	//if (ninput > 100) 
	//{ 
	//	printf("100���� ŭ"); 
	//}
	//else 
	//{ 
	//	printf("100���� ����"); 
	//}

	//printf("\n");

	////3��
	//int myscore = 0, otherscore = 0;

	//scanf_s("%d %d", &myscore, &otherscore);

	//if (myscore > otherscore) 
	//{ 
	//	printf("3��"); 
	//}
	//else if (myscore == otherscore) 
	//{ 
	//	printf("1��"); 
	//}
	//else 
	//{ 
	//	printf("0��"); 
	//}

	//printf("\n");

	////4��
	//int ncode = 0;

	//scanf_s("%d", &ncode);

	//switch (ncode)
	//{
	//	case 1:
	//	case 3:
	//		printf("����");
	//		break;

	//	case 2:
	//	case 4:
	//		printf("����");
	//		break;

	//default:
	//	printf("�߸��Է�");
	//	break;
	//}

	//printf("\n");

	////5��
	//int ncode2 = 0;
	//scanf_s("%d", &ncode2);

	//if (ncode2 == 1 || ncode2 == 2)
	//{
	//	printf("2000�� ���� ���");
	//}
	//else if (ncode2 == 3 || ncode2 == 4)
	//{
	//	printf("2000�� ���� ���");
	//}
	//else
	//{
	//	printf("�߸��Է�");
	//}

	/*
	* ��Ʈ������
	* C++ 11�������� ���� �տ� 0b�� ���̸� 2���� ǥ�� ����
	* 2���� ǥ�� �տ� 0b�� ���δ� ( 0b01011101)
	* 8���� ǥ�� : �տ� 0�� ���� (0123)
	* 16���� ǥ�� : �տ� 0x�� ����(0xFF)
	

	int A = 0b01011101;
	int B = 0123;
	int C = 0xCD;
	printf("2����(0b01011101): %d\n", A);
	printf("8����(0123): %d\n", B);
	printf("16����(0xCD): %d\n", C);
	*/


	/*
	* ��Ʈ�����ȣ
	* ��(&): �Ѵ� 1�̸� 1, �ƴϸ� 0 -> and
	* ��(|): ���߿� �ϳ��� 1�̸� 1, �ƴϸ� 0 -> or
	* XOR(^): ���� ������ 0, �ƴϸ� 1
	* ����(~): 0�̸� 1, 1�̸� 0 -> not
	*/

	/*char bitnum = 0b1000100;
	char bitResult = 0;

	bitResult = bitnum * 0b1010101;

	std::cout << std::bitset<8>(bitResult) << std::endl;

	bitResult = ~0b11010101;

	std::cout << std::bitset<8>(bitResult) << std::endl;*/

	//��Ʈ 1�� ����
	char myreward = 0b00000000;

	myreward = myreward | LEVEL_1_REWARD_10;

	std::cout << "Myreward: " << std::bitset<8>(myreward) << std::endl;

	//��Ʈ check
	bool isEnable = false;
	isEnable = myreward & LEVEL_1_REWARD_10;

	if (isEnable) { std::cout << "Reward Check: " << isEnable << std::endl; }
	else { printf("����"); }
	

	//��Ʈ �ʱ�ȭ ����
	myreward = myreward & ~LEVEL_1_REWARD_10;
	std::cout << "Myreward: " << std::bitset<8>(myreward) << std::endl;
}