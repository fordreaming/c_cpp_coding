// basic_exams_vs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

char* GetMemory(void) {
	char* p = "hello world";
	return p;
}

void fun(const int* i) {

}

void f(const int& i) {

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
    return 0;
}

