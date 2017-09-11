//共用体与大小端模式
//小端系统中，代码输出结果
#include <iostream>
using namespace std;

union Student
{
  int i;
  unsigned char ch[2];
};

int main()
{
  Student student;
  student.i = 0x1420;
  printf("%d,%d",student.ch[0],student.ch[1]);
  return 0;
}

