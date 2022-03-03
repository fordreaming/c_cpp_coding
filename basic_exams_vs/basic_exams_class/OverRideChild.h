#pragma once
#include <iostream>
using namespace std;

#include "OverRide.h"
class OverRideChild :
	public OverRide
{
public:
	OverRideChild();
	~OverRideChild();

	void fun1(int, int){
		std::cout << "override child" << std::endl;
	}
};

