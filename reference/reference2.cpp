// call by value - 값을 인자로 전달하는 함수의 호출 방식
// call by reference - 주소 값을 인자로 전달하는 함수의 호출 방식

#include <iostream>

using namespace std;

int SwapByValue(int num1, int num2)
{
  int temp = num1;
  num1 = num2;
  num2 = temp;

  return 0;
} // call by value

void SwapByRef(int *ptr1, int *ptr2)
{
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
} // call By reference

int main(int argc, char const *argv[])
{
  // 위는 다음과 같이 변경된다
  int val1 = 10;
  int val2 = 20;
  SwapByRef(&val1, &val2);
  cout << "val1 : " << val1 << endl; // 같이 두개가
  cout << "val2 : " << val2 << endl; // 교체되었다.
  return 0;
}
