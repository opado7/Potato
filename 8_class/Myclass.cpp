#include "Myclass.h"
#include <stdio.h>
#include <iostream>

cMyClass2::cMyClass2(int avalue): a(avalue), m_b(0), c(0)
{
	printf("持失切1");
}
cMyClass2::cMyClass2(int avalue, int bvalue) :a(avalue), m_b(bvalue), c(0)
{
	printf("持失切2");
}

cMyClass2::~cMyClass2()
{
}

void cMyClass2::printb()
{
	printf("B = %d\n", m_b);
}

void cMyClass2::setc(int num)
{
	c = num;
	std::cout << "good~" << std::endl;
}