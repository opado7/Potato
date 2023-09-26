#include <stdio.h>
#include <iostream>
#include "money.h"

int g_money;
static int s_money = 0;

struct fruitShop
{
	int applea;
	int mangoa;
	int strawberrya;
	fruitShop() : applea(1000), mangoa(1000), strawberrya(1000)
	{	}

	void setfruitValue(int apple, int mango, int strawberry)
	{
		applea = apple;
		mangoa = mango;
		strawberrya = strawberry;
	}

	void print_price()
	{
		printf("apple: %d, mango: %d, strawberry: %d\n", applea, mangoa, strawberrya);
	}

};

struct phoneshop
{
	int iphonea;
	int zflipa;
	int galaxy23a;
	int galaxyfolda;

	phoneshop() : iphonea(1000), zflipa(1000), galaxy23a(1000), galaxyfolda(1000)
	{}

	void set_value(int iphone, int zflip, int galaxy23, int galaxyfold)
	{
		iphonea = iphone;
		zflipa = zflip;
		galaxy23a = galaxy23;
		galaxyfolda = galaxyfold;
	}

	void print_price()
	{
		printf("iphone: %d, zfilp: %d, galaxy23: %d, galaxyfold: %d\n", iphonea, zflipa, galaxy23a, galaxyfolda);
	}
};


int Add(int a, int b)
{
	//printf("int\n");
	return a + b;
}

float Add(float a, float b)
{
	//printf("float\n");
	return a + b;
}

double Add(double a, double b)
{
	//printf("double\n");
	return a + b;
}

int main()
{
	/*int t_money = 0;
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);

	printf("main t_money = %d \n", t_money);
	printf("main g_money = %d", g_money);*/

	Add(1, 2);
	Add(3.0f, 1.2f);
	Add(1.0, 2.4);

	int arrrint[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	arrrint[0] = 10; 
	arrrint[4] = 6;
	arrrint[9] = 32;

	/*for (int i = 0; i < 10; i++)
	{
		printf("%d: %d\n", i, arrrint[i]);
	}*/

	int num = 0;
	/*for (int value : arrrint)
	{
		printf("%d: %d\n", num, value);
		num++;
	}*/

	//±¸  Á¶Ã¼
	fruitShop shop[3];

	shop[0].setfruitValue(1000, 2000, 3000);
	shop[1].setfruitValue(1100, 2100, 3100);
	shop[2].setfruitValue(900, 1900, 2900);

	shop[0].print_price();
	shop[1].print_price();
	shop[2].print_price();

	phoneshop phone[3];

	phone[0].set_value(100, 90, 80, 150);
	phone[1].set_value(110, 100, 90, 160);
	phone[2].set_value(90, 80, 70, 140);

	phone[0].print_price();
	phone[1].print_price();
	phone[2].print_price();


	return 0;
}