#include <iostream>
#include <vector>

using namespace std;

#include "ConstTest.h"

char* GetMemory(void) {
	char* p = "hello world";
	return p;
}

void GetMemory(char* p) {
	p = (char*)malloc(11);
	int a = 0;
}

void fun(const int* i) {

}

void f(const int& i) {

}

class base {

public:
	void func1() {
		this->nums = 1;
	}

	void func2() const {

	}

private:
	int nums;
};

void test_mem() {
	char *p = new char[64];
	delete []p;
	p = NULL;
	return;
}

class ConstFunRetVal {
public:
	ConstFunRetVal(){}
public:
	int val;
};

ConstFunRetVal FunTestConstRetSelfDef(ConstFunRetVal temp) {
	ConstFunRetVal const_fun_ret_val;
	return const_fun_ret_val;
}


int main()
{
	const double *cptr;   // cptr pointe to const double object;
	double data = 1.0f;
	cptr = &data;
	double data2 = 2.0f;
	cptr = &data2;
	//*cptr = 2.0f;       // error

	double d = 1.0;
	double * const cptr_const = &d;   // cptr pointer is const
									  //cptr_const = &d;   // error
	*cptr_const = 2.0;

	double d1 = 1;
	const double * const x = &d1;
	// x = &d;
	// *x = d;
	double const* const x2 = &d1;

	const char* pp;
	// pp++;
	// (*pp)++;
	// (*pp)++;

	char *p = "hello world";
	char p_arr[] = "hello world";

	//	char* str = GetMemory();
	//	str[0] = 'a';

	const int a = 1;
	fun(&a);

	f(1);
	int* data_p = new int[1];

	int i = 0;
	if (!!i) {
		std::cout << "enter: " << std::endl;
	}

	base base_obj;
	base base_obj2;
	base_obj.func1();


	char* str = "Hello";
	GetMemory(str);
	//strcpy(str, "Hello World");
	//printf("%s", str);

	int *pi = new int;
	int *pi1 = new int();

	test_mem();

	//const int *pci = new const int(1024);
	const int *pci = new const int(1024);
	const string *pcs = new const string;

	char test[] = "hello world";
	size_t size = strlen(test);
	int size1 = sizeof(test);

	ConstFunRetVal const_ret_val;
	ConstFunRetVal ret = FunTestConstRetSelfDef(const_ret_val);


	vector<float> temp_val{ 1, 2, 3, 4,5 };
	vector<double> temp_val_d;
	for (int i = 0; i < temp_val.size(); i++) {
		temp_val_d.emplace_back(temp_val[i]);
	}

	vector<double> temp_val_d2(temp_val.begin(), temp_val.end());
	return 0;
}

