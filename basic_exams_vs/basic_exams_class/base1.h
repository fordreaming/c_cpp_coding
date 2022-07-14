#pragma once

#include <iostream>
using namespace std;


class base1
{
public:
	base1();
	~base1();

	void printthis1() {
		std::cout << "base1 this: " << this << std::endl;
	}

public:
	char c[16];
};


class base2
{
public:
	base2() {}
	~base2() {}

	void printthis2() {
		std::cout << "base2 this: " << this << std::endl;
	}

public:
	char c[16];
};

class member1
{
public:
	member1() {}
	~member1() {}

	void printthism1() {
		std::cout << "member1 this: " << this << std::endl;
	}

public:
	char c[16];
};

class member2
{
public:
	member2() {};
	~member2() {};

	void printthism2() {
		std::cout << "member2 this: " << this << std::endl;
	}

public:
	char c[16];
};



class mi : public base1, public base2 {
public:
	void printthis() {
		std::cout << "m1 this: " << this << std::endl;
		printthis1();
		printthis2();
		m1.printthism1();
		m2.printthism2();
	}

public:
	member1 m1;
	member2 m2;
	
};


class MyClass
{
public:
	MyClass(){}
	~MyClass(){};

private:

};

class MyClass2 : public MyClass
{
public:
	MyClass2(){}
	~MyClass2(){}


private:

};