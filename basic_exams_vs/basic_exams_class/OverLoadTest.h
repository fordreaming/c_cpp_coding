#pragma once
class OverLoadTest
{
public:
	OverLoadTest();
	~OverLoadTest();

	virtual int fun() { return 0; }
	void fun(int) {}
	void fun(double, double) {}
	static int fun(char) {}
};

