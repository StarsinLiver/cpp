// Todo : C++ 에서의 파일 분할

// 나'(me)' 를 표현하는 클래스의 정의
#include <iostream>

class FruitBuyer {
  int myMoney; // private :
  int numOfApples; // private :
};

// 위의 클래스에 선언된 두 변수 myMoney 와 numOfApples 에는 private 이나 public 과 같은 선언이 존재하지 않음을 알수있다.
// 그러나 클래스는 아무런 서넝ㄴ이 존재하지 않을 때 private 으로 간주된다 

// (구조체는 public 으로 간주된다.)

// 즉 위의 변수 두개는 private 이다.
// 클래스를 정의할 때 private 선언을 목적으로 접근제어 지시자를 생략하는 경우가 흔히 있으니 주의하기 바란다.

class FuritSeller {
  char name[10];
  int balance;

};

// Todo : 클래스 기반의 두 가지 객체 생성방법
// 위의 두 개의 클래스를 정의하였다. 그렇다면 객체를 생성하지 않고, 이 두 클래스 안에 존재하는 변수에 접근하고, 함수를 호출하는 것이 가능할까?
// 이는 접근 불가능하다.


using namespace std;

int main(int argc, char const *argv[])
{
  // 동적으로 할당
  FruitBuyer * buyer = new FruitBuyer;
  FuritSeller * buyer = new FuritSeller;
}
