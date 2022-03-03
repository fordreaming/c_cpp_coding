#pragma once
#include <iostream>
using namespace std;

class OverSee
{
public:
	OverSee();
	~OverSee();

	void fun(int xp) {
		std::cout << "xp parent" << xp << std::endl;
	}

	virtual void fun1(int xp) {
		std::cout << xp << "parent" << std::endl;
	}
};

