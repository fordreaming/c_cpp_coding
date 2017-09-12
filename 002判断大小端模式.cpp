#include <iostream>
#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1
using namespace std;

int TestByteOrder()
{
  short int word = 0x0001;
  char *byte = (char *)&word;
  return(byte[0]?LITTLE_ENDIAN:BIG_ENDIAN);
}

int main()
{
  if(TestByteOrder())
	  cout<<"LITTLE_ENDIAN";
  else 
	  cout<<"BIG_ENDIAN";
  return 0;
}
