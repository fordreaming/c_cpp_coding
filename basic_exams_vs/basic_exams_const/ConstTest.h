#pragma once
class ConstTest
{
public:
	ConstTest();
	~ConstTest();

	enum MyEnum
	{
		size1 = 100,
		size2 = 200
	};

private:
	const int a;
	static int b;
	const static int c;          // 整个类中都恒定的常量：
};

