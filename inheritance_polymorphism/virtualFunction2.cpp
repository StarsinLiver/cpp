// Todo : 함수의 오버라이딩과 포인터 형
#include <iostream>
using namespace std;
class First {
  public :
  void MyFunc() {cout<<"FirstFunc()"<<endl;}
};
class Second : public First {
  public :
  void MyFunc() {cout<<"SecondFunc()"<<endl;}
};
class Third : public Second{
  public :
  void MyFunc() {cout<<"ThirdFunc()"<<endl;}
};

int main(int argc, char const *argv[])
{
  Third * tptr = new Third();
  Second * sptr = tptr;
  First * fptr = sptr;

  tptr -> MyFunc();
  sptr -> MyFunc();
  fptr -> MyFunc();

  delete tptr;
  return 0;
}

// 실행결과는 다음과 같다.

/*
ThirdFunc()
SecondFunc()
FirstFunc()
*/

// Todo : 가상함수(Virtual Function)
// 예제를 살펴보면서 이렇게 생각할 수 있다.
// "함수를 오버라이딩 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데, 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은
// 문제가 있어 보입니다."

// 그래서 C++은 이러한 상황이 발생하지 않도록 '가상함수' 라는 것을 제공하고 있다.
// 그런데 이 가상함수 라는 것은 C++의 개념이 아닌 객체지향의 개념이다.
// 따라서 C++ 뿐만 아니라 JAVA , C#과 같은 객체지향 언어에서도 동일한 개념의 문법이 제공되고 있다. 

// 선언은 다음과 같다.
class First {
  public :
  virtual void MyFunc() {...}
}

// 이렇듯, 가상함수의 선언은 virtual 키워드의 선언을 통해서 이뤄진다. 그리고 이렇게 가상함수가 선언되고 나면, 이 함수를 오버라이딩하는 함수도 가상함수가 된다.
// 따라서 위와 같이 First 클래스의 MyFunc 함수가 virtual 로 선언되면, 이를 오버라이딩 하는 Second 클래스의 MyFunc 도 그리고 이를 오버라이딩 하는 Third 클래스의 
// MyFunc 함수도 가상함수가 된다.

class First {
  public :
  virtual void MyFunc() {cout<<"FirstFunc()"<<endl;}
};
class Second : public First {
  public :
  virtual void MyFunc() {cout<<"SecondFunc()"<<endl;}
};
class Third : public Second{
  public :
  virtual void MyFunc() {cout<<"ThirdFunc()"<<endl;}
};

int main(int argc, char const *argv[])
{
  Third * tptr = new Third();
  Second * sptr = tptr;
  First * fptr = sptr;

  tptr -> MyFunc();
  sptr -> MyFunc();
  fptr -> MyFunc();

  delete tptr;
  return 0;
}

/*
ThirdFunc()
ThirdFunc()
ThirdFunc()
*/

// 위의 실행결과에서 보이듯이 , 함수가 가상함수로 선언되면, 해당 함수 호출시 , 포인터의 자료형을 기반으로 호출대상을 결정하지 않고, 포인터 변수가
// 실제로 가리키는 객체를 참조하여 호출대상을 결정한다.