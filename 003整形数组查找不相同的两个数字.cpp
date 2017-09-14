#include <iostream>
using namespace std;

//判断indexBitOf1的位置是否为1
bool (int num, int indexBitOf1)
{
  num = num >>indexBitOf1;
  return (num&1);
}

//找出异或结果中第一位为1的位所在的位置
int findIndexBitOf1(int num)
{
  int index = 0;
  while((num^1==1)&&(index<32))
  {
    num = num>>1;
    index++;  
  }
  return index;
}

//找出不相同的两个数字
void FindAppearOnce(int data[], int length, int &num1, int &num2)
{
  if(length<2)
    return;
  int resultExclusiveOR = 0;
  //将数组里所有的数字进行异或
  for(int i=0;i<length;i++)
    resultExclusiveOR = resultExclusiveOR^data[i];
  //找出异或结果中第一位为1的位所在的位置
  int indexBitOf1;
  indexBitOf1 = findIndexBitOf1(resultExclusiveOR);
  //根据1所在的位置，将数组中该位为1的值分到一个数组，为0的分到另外一个数组
  num1 = num2 = 0;
  for(int j=0;j<length;j++)
  {
    //判断indexBitOf1的位置是否为1
    if(IndexBitIs1(data[j],indexBitOf1)
      num1 = num1^data[j];
    else 
      num2 = num2^data[j];  
  }  
}

int main()
{
  int num1,num2;
  int testArr[6]={4,3,2,2,1,3};
  FindAppearOnce(testArr,6,num1,num2);
  cout <<num1 <<num2<<endl;
}
