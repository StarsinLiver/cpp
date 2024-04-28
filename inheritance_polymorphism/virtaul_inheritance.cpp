// Todo : 가상 상속(virtual Inheritance)
// 함수 호출 관계의 모호함은 다른 상황에서도 발생할 수 있다.
// 이 상황을 다음 예제로 확인해보자

#include <iostream>
using namespace std;

class Base {
  public :
  Base () {
    cout<<"Base Constructor"<<endl;
  }
  void SimpleFunc() {cout<<"BaseOne"<<endl;}
};

class MiddleDerivedOne : virtual public Base {
  public :
  MiddleDerivedOne() : Base() {
    cout<<"MiddleDeriveOne Constructor"<<endl;
  }
  void MiddleFuncOne() {
    SimpleFunc();
    cout<<"MiddleDerivedOne"<<endl;
  }
};

class MiddleDerivedTwo : virtual public Base {
  public :
  MiddleDerivedTwo() : Base() {
    cout<<"MiddleDerivedTwo Constructor"<<endl;
  }
  void MiddleFuncTwo() {
    SimpleFunc();
    cout<<"MiddleDerivedTwo"<<endl;
  }
};

class LastDerived : public MiddleDerivedOne , public MiddleDerivedTwo {
  public :
  LastDerived() : MiddleDerivedOne() , MiddleDerivedTwo() {
    cout<<"LastDerived Constructor"<<endl;
  }
  void ComplexFunc() {
    MiddleFuncOne();
    MiddleFuncTwo();
    SimpleFunc();
  }
};

int main(int argc, char const *argv[])
{
  cout<<"객체 생성 전 ..."<<endl;
  LastDerived ldr;
  cout<<"객체 생성 후 ..." <<endl;
  ldr.ComplexFunc();
  return 0;
}

/*
객체 생성 전 ...
Base Constructor
MiddleDeriveOne Constructor
MiddleDerivedTwo Constructor
LastDerived Constructor
객체 생성 후 ...
BaseOne
MiddleDerivedOne
BaseOne
MiddleDerivedTwo
BaseOne
*/

// 위의 예제에서 보이는 상속 구조는 다음과 같다. 여기서 중요한 것은 LastDerived 클래스가 Base 클래스를 간접적으로 두 번 상속한다는 점이다

//                   Base 
//               |         |
// MiddleDerivedOne     MiddleDerivedTwo
//                   |
//              LastDerived

// Todo : 만약 virtual 선언이 되지 않은 상태에서 객체가 생성되면 Base 클래스의 맴버가 두번 포함되게 될 것이다.
// 만약 virtual 선언이 되지 않았다면 명시적으로 어떤 Base 함수를 실행시킬 지 알려주어야 했을 것이다,

// MiddleDerivedOne::SimpleFunc();

// 그런데 이러한 상황에서 Base 클래스의 맴버가 LastDerived 객체에 하나씩만 존재하는 것이 타당한 경우가 대부분이다.
// 즉, Base 클래스가 딱 한번만 상속하게끝 하는 것이 더 현실적인 해결책이 될 수 있다.
// 그리고 이를 위한 문법이 "가상 상속이다."

// Todo : 가상 상속
// 가상으로 상속하는 방법은 위의 예제에서 보이고 있다.

// class MiddleDerivedOne : virtual public Base {...};
// class MiddleDerivedTwo : virtual public Base {...};

// 이렇게 사용하면 LastDerived 객체 내에는 MiddleDerivedOne 클래스와 MiddleDerivedTwo 클래스가 동시에 상속하는 Base 클래스의 맴버가 하나씩만 존재하게 된다.

// 한마디로 MiddleDerivedOne::SimpleFunc() 가 아닌 SimpleFunc() 함수를 이름만 가지고 호출할 수 있게 된다

// 만약 가상 상속(virtual)을 하지 않는다면 , Base 클래스의 생성자는 두번 호출하게 된다.