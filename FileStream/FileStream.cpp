#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct stTest
{
	string m_name;
	int m_math;
	int m_eng;
	int m_lang;

	stTest(string name = "", int math = 0, int eng = 0, int lang = 0) :
		m_name(name), m_math(math), m_eng(eng), m_lang(lang) {}

	void printtest() {
		printf("name = %s, math = %d, eng = %d, lang = %d\n",
			m_name.c_str(), m_math, m_eng, m_lang);
	}

	void setdata(string& str)
	{
		stringstream sstest(str);
		string line;

		while (getline(sstest, line, ',')) {
			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			int index = line.find('=');
			string leftstr = line.substr(0, index);
			string rightstr = line.substr(index + 1, line.length() - index);

			if (leftstr == "name") m_name = rightstr;
			else if (leftstr == "math") m_math = stoi(rightstr);
			else if (leftstr == "eng") m_eng = stoi(rightstr);
			else if (leftstr == "lang") m_lang = stoi(rightstr);
		}
	}

};

int main()
{
	ifstream readfile;
	readfile.open("test.txt");

	vector<stTest> vectest;

	if (readfile.is_open()) {
		while (!readfile.eof()) {
			string str;
			getline(readfile, str);

			stTest newdata;
			newdata.setdata(str);
			vectest.push_back(newdata);
		}
		readfile.close();
	}

	for (stTest& test : vectest) {
		test.printtest();
	}
}