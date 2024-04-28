// Todo : 참조자의 참조 가능성
// 앞서 포인터는 다음과 같이 이야기 했다.
// "C++ 에서 AAA 형 포인터 변수는 AAA 객체 또는 AAA 를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다. (객체의 주소 값을 저장할 수 있다.)"

// 그런데, 이러한 특성은 참조자에도 적용이 된다. 따라서 다음의 문장도 성립한다.
// "C++ 에서 AAA 형 첨조자는 AAA 객체 또는 AAA 를 직접 혹은 간접적으로 상속하는 모든 객체를 참조 할 수 있다."

// 따라서 앞서 First , Second , Third 클래스에도 참조자가 적용될 수 있다.
// "First 형 참조자를 이용하면 First 클래스에 정의된 MyFunc 함수가 호출되고, Second 형 참조자를 이용하면 Second 클래스에 정의된 MyFunc 함수가 호출되고,
// Third 형 참조자를 이용하면  Third클래스에 정의된 MyFunc 함수가 호출되는 구나! "

// 하나의 예제를 보자
#include <iostream>
using namespace std;

class First {
  public :
  void FirstFunc() {cout<<"FirstFunc()"<<endl;}
  virtual void SimpleFunc() {cout<<"First's SimpleFunc()"<<endl;}
};

class Second : public First{
  public :
  void SecondFunc() {cout<<"SecondFunc()"<<endl;}
  virtual void SimpleFunc() {cout<<"Second's SimpleFunc()"<<endl;}
};

class Third : public Second{
  public :
  void ThirdFunc() {cout<<"ThirdFunc()"<<endl;}
  virtual void SimpleFunc() {cout<<"Third's SimpleFunc()"<<endl;}
};

int main(int argc, char const *argv[])
{
  Third obj;
  obj.FirstFunc();
  obj.SecondFunc();
  obj.ThirdFunc();
  obj.SimpleFunc();

  Second & sref = obj;
  sref.FirstFunc();
  sref.SecondFunc();
  sref.SimpleFunc();

  First & fref = obj;
  fref.FirstFunc();
  fref.SimpleFunc();
  return 0;
}

/*
FirstFunc()
SecondFunc()
ThirdFunc()
Third's SimpleFunc()
FirstFunc()
SecondFunc()
Third's SimpleFunc()
FirstFunc()
Third's SimpleFunc()
*/

// 위의 예제를 이해했으니 이제 다음과 같이 정의된 함수를 보게되면
void GooFunction (const First &ref) {...}

// 다음과 같이 판단이 된다.
// "음, First 객체 또는 First 를 직접 혹은 간접적으로 상속하는 크랠스의 객체가 인자의 대상이 되는 구나!"
// "인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서는 First 클래스에 정의된 함수만 호출할 수 있겠구나!"라는 사실을 고려해 판단하자