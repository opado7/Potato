#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <Windows.h>
#include <locale>
#include <iomanip>
#include <iostream>
#include <random>
#include "card.h"
using namespace std;

const int MIN_BET = 0;

card::card(cardmark mark, int num) :m_mark(mark), m_num(num) {}

std::string card::getmarkstr() {
	switch (m_mark)
	{
	case Clover:
		return "Clover";
		break;
	case Heart:
		return "Heart";
		break;
	case Dia:
		return "Dia";
		break;
	case Spade:
		return "Spade";
		break;
	}
	return "None";
}

void card::printcard() {
	printf("%s[%d]\n", getmarkstr().c_str(), m_num);
}

bool save_money(long long& money) {

	ofstream edit("money.txt", ios::out);

	if (money > 0) {
		if (!(edit << money)) {
			printf("����!\n");
			edit.close();
			return false;
		}
	}

	else {
		edit << 1000000;
		printf("�������� �ʱ�ȭ �Ǿ����ϴ�.\n");
		return false;
	}

	cout << "�������� ����Ǿ����ϴ�." << '\n';
	return true;
}

void print_money(long long& money) {
	std::locale custom_locale("");
	std::cout.imbue(custom_locale);

	std::cout  << "���� ������ : " << std::put_money(money) << '\n';
}

void win_money(long long& money, int bet) {

	std::locale custom_locale("");
	std::cout.imbue(custom_locale);

	money += bet * 2;
	std::cout << "�¸�!" << "\n";
	print_money(money);

}

void lose_money(long long& money, int bet) {

	std::locale custom_locale("");
	std::cout.imbue(custom_locale);
	
	money -= bet;
	if (money < 0) money = 0;
	std::cout << "�й�.." << "\n";
	print_money(money);


}

bool compare_card(const card& card1, const card& card2) {

	if (card1.m_num > card2.m_num) return true;
	else if (card1.m_num < card2.m_num) return false;

	return int(card1.m_mark) > int(card2.m_mark);
}

int getuserinput(const string& prompt, int min, int max) {
	int value;
	do {
		cout << prompt;
		cin >> value;
	} while (value < min || value > max);
	return value;
}

void play_game()
{
	long long money = 0;
	vector<card> cards;
	ifstream readfile;
	readfile.open("money.txt");

	readfile >> money;

	std::locale custom_locale("");
	std::cout.imbue(custom_locale);

	print_money(money);

	readfile.close();

	for (int i = cardmark::Clover; i < cardmark::Max; ++i) {
		for (int j = 1; j <= 13; ++j) {
			card ccard;
			ccard.m_mark = (cardmark)i;
			ccard.m_num = j;
			cards.push_back(ccard);
		}
	}

	auto currentTime = chrono::system_clock::now();
	time_t seed = chrono::system_clock::to_time_t(currentTime);

	mt19937 rng(seed);

	while (true) {

		printf("������");

		for (int i = 0; i < 2; i++) {
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
		}

		cout << '\n';
		shuffle(cards.begin(), cards.end(), rng);

		uniform_int_distribution<int> number(1, 52);
		int random_num1 = number(rng);

		printf("������ �����մϴ�.\n");
		this_thread::sleep_for(chrono::seconds(1));
		printf("\n");

		cards[random_num1].printcard();
		int num1_mark = int(cards[random_num1].m_mark);
		int num1_num = cards[random_num1].m_num;


		printf("�� / �ٿ� |  0 / 1 ---> ");
		int updown = getuserinput("", 0, 1);

		printf("�󸶸� �����Ͻðڽ��ϱ�?  ");
		print_money(money);
		int bet = getuserinput("", MIN_BET, money);

		if (bet <= 0) {
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			continue;
		}
		else if (bet > money) {
			printf("������ �ִ� ������ ���� �� �� �����ϴ�!\n");
			continue;
		}

		printf("\n������ �� �����մϴ�.\n\n");

		int random_num2 = number(rng);
		cards[random_num2].printcard();

		int num2_mark = int(cards[random_num2].m_mark);
		int num2_num = cards[random_num2].m_num;

		if (updown == 1) {
			if (compare_card(cards[random_num1], cards[random_num2])) win_money(money, bet);
			else lose_money(money, bet);
		}
		else
		{
			if (!compare_card(cards[random_num1], cards[random_num2])) win_money(money, bet);
			else lose_money(money, bet);
		}


		if (money <= 0) {
			printf("\n---------------\n�Ļ�..\n--------------\n");
			break;
		}

		printf("��� �Ͻðڽ��ϱ�? y(0)/n(1) --> ");
		int yn = getuserinput("", 0, 1);

		if (yn == 1) break;
		else if (yn == 0) { system("cls"); continue; }
		else {
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}

		if (!save_money(money)) break;

	}

	save_money(money);
	printf("���α׷��� �����մϴ�.\n");

}