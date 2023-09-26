#include "money.h"
#include <stdio.h>

extern int g_money;
static int s_money = 0;

int addMoney(int money)
{
	int t_money = 0;
	t_money += money;
	g_money += money;

	printf("t_money = %d\n", t_money);
	printf("g_money = %d\n", s_money);

	return 0;
}

int useMoney(int money)
{
	return 0;
}