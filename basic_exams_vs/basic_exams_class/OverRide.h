#pragma once
#include <iostream>
using namespace std;

#include "base1.h"

class OverRide
{
public:
	OverRide();
	~OverRide();

	virtual void fun1(int, int){
		std::cout << "override parent" << std::endl;
	}

	virtual void fun2(MyClass& my) {
		std::cout << "override parent" << std::endl;
	}
};



