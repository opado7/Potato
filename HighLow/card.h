#pragma once
#include <stdio.h>
#include <string>

enum cardmark {

	None = 0,
	Clover,
	Heart,
	Dia,
	Spade,
	Max

};

class card
{
public:

	card(cardmark mark = cardmark::None, int num = 0);

	std::string getmarkstr();

	void printcard();

public:
	cardmark m_mark;
	int m_num;
};

bool save_money(long long& money);
void win_money(long long& money, int bet);
void lose_money(long long& money, int bet);
bool compare_card(const card& card1, const card& card2);
void print_money(long long& money);
void play_game();
int getuserinput(const std::string& prompt, int min, int max);