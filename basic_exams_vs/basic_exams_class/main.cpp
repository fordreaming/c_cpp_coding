#include <iostream>
using namespace std;

#include "OverRide.h"
#include "OverRideChild.h"

#include "OverSee.h"
#include "OverSeeChild.h"

#include "base1.h"

class A {
public:
	virtual int fun();
	void fun(int);
	void fun(double, double);
	static int fun(char);
};

int main() {
	OverRideChild over_ride_child;
	over_ride_child.fun1(2, 3);

	OverRide* over_ride = &over_ride_child;
	over_ride->fun1(2, 3);

	OverSeeChild over_see_child;
	over_see_child.fun(2);
	over_see_child.OverSee::fun(3);

	OverSee over_see;
	over_see.fun(3);

	int data = 1;
	//over_see_child.fun1(data);
	//over_see_child.OverSee::fun1(data);

	OverSee* over_see_p = new OverSeeChild;
	over_see_p->fun1(2);


	// p158 ¶à¼Ì³Ð
	mi MI;
	std::cout << "sizeof(mi): " << sizeof(mi) << std::endl;
	MI.printthis();
	base1* b1 = &MI;
	base2* b2 = &MI;

	std::cout << "base 1 pointer: " << b1 << std::endl;
	std::cout << "base 2 pointer: " << b2 << std::endl;
	return 0;
}