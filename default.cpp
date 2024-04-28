#include <iostream>

int myFunc(int num = 1);
int rightFunc(int num1, int num2 = 1);
int wrongFunc(int num1 = 1, int num2);


int main(int argc, char const *argv[])
{

  // 매개변수의 디폴트 값
  int num;
  num = myFunc();
  std::cout << "매개변수에 설정하는 디폴트 : " << num << std::endl;

  // 꼭 디폴트 매개변수는 오른쪽 부터 채울것!
  // 맞는 매개변수의 디폴트 값
  rightFunc(1);

  // 잘못된 매개변수의 디폴트 값
  // wrongFunc(1);

  return 0;
}


int myFunc(int num)
{
  num++;
  return num;
}

int rightFunc(int num1, int num2)
{
  return num1 + num2;
}

int wrongFunc(int num1, int num2)
{
  return num1 + num2;
}

