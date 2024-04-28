#include <iostream>

using namespace std;

// Todo : const 참조자의 또 다른 특징

int Adder (const int &num1 , const int &num2)  {
  return num1 + num2;
}



int main(int argc, char const *argv[])
{
  // 밑의 코드를 실행하면 에러가 뜨게된다. c++ 에서는 이를 허용하지 않는다.
  const int num = 20;
  // int &ref = num;
  // ref++;

  // 따라서 이렇게 정의를 해야한다.
  const int &ref = num;

  // Todo : 어떻게 참조자가 상수를 참조를 할 수 있을까?
  // 리터럴 상수 (literal constant)란 ?
  // "임시적으로 존재하는 값이다. 다음 행으로 넘어가면 존재하지 않는 상수다".

  // 그런데 c++ 에서는 참조자가 상수를 참조할 수 있다. 
  const int &ref = 30; // 물론 이렇게 쓰면 에러다.

  // 이는 숫자 30이 메모리 공간에 계속 남아있을 때에나 성립이 가능하지만
  // c++ 에서는 위의 문장이 성립이 가능하도록, const 참조자를 이용해서 상수를 참조할 때 '임시 변수'라는 것을 만든다.
  // 그리고 이 장소에 상수 30을 저장하고선 참조자가 이를 참조하게끔 한다.

  // Todo : 위의 임시변수를 왜 만들었을까?
  // 함수를 실행해보자 함수에 인자를 전달을 목적으로 변수를 선언한다는 것은 매우 번거로운 일이 아닐 수 없다.
  // 그러나 임시변수의 생성을 통한 const 참조자의 상수참조를 허용함으로써, 위의 함수 호출을 매우 간단히 호출하게 끔 만들어 놓았다.
  cout<<Adder(3 , 4)<<endl;

  return 0;
}


