#include <iostream>

using namespace std;

void sizeofStrlenTest(char *data)
{
	cout << sizeof(data) << endl;
	cout << strlen(data) << endl;
}

int main()
{
	std::string str = "string";
	cout << &str[0] << endl;
	char* chr = const_cast<char*>(str.c_str());
	int len = strlen(chr);
	int len1 = sizeof(chr);
	cout << len << endl;

	char test[10] = "hello";
	cout << sizeof(test) << endl;
	cout << strlen(test) << endl;
	sizeofStrlenTest(test);
	

	return 0;
}