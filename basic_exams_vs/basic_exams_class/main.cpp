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

	OverRide* p_over_ride = &over_ride_child;
	p_over_ride->fun1(2, 3);

	// 在override时，如果派生类虚函数的参数类型是基类中被替换的虚函数的参数类型的子类，
	// 是否可以发生override
	// answer: 经过测试之后，发现这种情况不会发生override,这种情况属于oversee的第二种情况

	MyClass2 my_clas2;
	MyClass  my_class;
	over_ride_child.fun2(my_clas2);
	over_ride_child.OverRide::fun2(my_class);

	OverRide override;
	override.fun2(my_clas2);

	p_over_ride->fun2(my_clas2);

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



	// p158 多继承
	mi MI;
	std::cout << "sizeof(mi): " << sizeof(mi) << std::endl;

	MI.printthis();
	base1* b1 = &MI;
	base2* b2 = &MI;

	std::cout << "base 1 pointer: " << b1 << std::endl;
	std::cout << "base 2 pointer: " << b2 << std::endl;

	return 0;
}