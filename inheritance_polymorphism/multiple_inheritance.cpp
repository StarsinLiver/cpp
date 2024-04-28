// Todo : 다중 상속 (Multiple INheritance)에 대한 이해
// 다중 상속이란, 둘 이상의 클래스를 동시에 상속하는 것을 말한다. 그리고 C++ 은 다중상속을 지원하는 객체 지향 언어이다.

// Todo : 다중상속의 기본방법
// 예제를 확인해보자
#include <iostream>
using namespace std;

class BaseOne {
  public :
  void SimpleFuncOne() {cout<<"BaseOne"<<endl;}
};

class BaseTwo {
  public :
  void SimpleFuncTwo() {
    cout<<"BaseTwo"<<endl;
  }
};

class MultiDerived : public BaseOne , protected BaseTwo {
  public :
  void ComplexFunc() {
    SimpleFuncOne();
    SimpleFuncTwo();
  }
};

int main(int argc, char const *argv[])
{
  MultiDerived mdr;
  mdr.ComplexFunc();
  return 0;
}

/*
BaseOne
BaseTwo
*/

// Todo : 다중상속의 모호성(Ambigous) 
// 다중상속의 대상이 되는 두 기초 클래스에 동일한 이름의 맴버가 존재하는 경우에는 문제가 발생할 수 있다.
// 이러한 경우에는 유도 클래스 내에서 맴버의 이름만으로 접근이 불가능하기 때문이다.
// 만약에 이름만으로 접근하려 든다면 컴파일러는 다음과 같이 불만을 토로할 것이다.

// "도대체 어느 클래스에 선언된 맴버에 접근을 하라는 거야?"

// Todo : 해결책도 있다!
class MultiDerived : public BaseOne , protected BaseTwo {
  public :
  void ComplexFunc() {
    BaseOne::SimpleFuncOne();
    BaseTwo::SimpleFuncTwo();
  }
};

// 위 예제를 통해서, 어떠한 경우에는 다중상속으로 인한 모호성이 발생하는 지 이해하였을 것이다.
