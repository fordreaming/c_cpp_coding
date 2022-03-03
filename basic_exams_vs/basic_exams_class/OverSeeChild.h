#pragma once
#include "OverSee.h"
class OverSeeChild :
	public OverSee
{
public:
	OverSeeChild();
	~OverSeeChild();

	void fun(int xp) {
		std::cout << "child" << std::endl;
	}

	void fun1(char* xp) {
		std::cout << "child" << std::endl;
	}
};

