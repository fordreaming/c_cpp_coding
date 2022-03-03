#pragma once
#include <iostream>
using namespace std;

class OverRide
{
public:
	OverRide();
	~OverRide();

	virtual void fun1(int, int){
		std::cout << "override parent" << std::endl;
	}
};



