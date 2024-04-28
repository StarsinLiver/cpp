// Todo : 가상함수 (Virtual Function)
// 다음과 같이 상속으로 연결된 두 클래스가 있다

#include <iostream>
using namespace std;

class Base {
  public :
  void BaseFunc() {
    cout<<"Base function()"<<endl;
  }
};
class Derived : public Base {
  public :
  void DerivedFunc() {
    cout<<"Derived function()"<<endl;
  }
};

// 그렇다면, 컴파일러는 main 함수에 삽입된 다음 문장은 문제없이 컴파일 하나 DerivedFunc는 컴파일 에러가 발생한다
int main(int argc, char const *argv[])
{
  Base * bptr = new Derived(); // 컴파일 OK!
  bptr -> DerivedFunc(); // 컴파일에러 ('class Base' has no member named 'DerivedFunc')
  return 0;
}

// 왜냐하면 bptr 이 Base 형 포인터이기 때문이다
// "그래도 실제로 가리키는 대상은 Derived 객체이니까 위의 문장은 컴파일되어야 정상이 아닌가요?"

// C++ 컴파일러는 포인터 연산의 가능성여부를 판단 할 때, 포인터의 자료형을 기준으로 판단하지 , 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.

int main(int argc, char const *argv[])
{
  Base * bptr = new Derived();
  Derived * dptr = bptr ; // 컴파일 에러!!!
  return 0;
}


// 컴파일러는 다음과 같이 판단을 한다.
// "Derived 클래스는 Base 클래스의 유도 클래스이니까 Base 클래스의 포인터 변수로 Derived 객체의 참조가 가능하다! 그러니 문제없이 컴파일이 가능해!"
// "다만, bptr 은 Base 형 포인터이니까, bptr 이 가리키는 대상은 Base  객체일 수 도 있는 거잖아! 그럴 경우에는 이 문장이 성립하지 않으니까 컴파일 에러를 발생시켜야겠다."

// Todo : 반면 다음의 코드는 문제없이 컴파일이 가능하다
int main(int argc, char const *argv[])
{
  Derived * dptr = new Derived(); // 컴파일 OK!!
  Base * bptr = dptr; // 컴파일 OK!!
  return 0;
}

// 위는 다음과 같다.
// "DPTR 은 dERIVED 클래스의 포인터 변수니까 ,이 포인터가 가리키는 객체는 분명 base 클래스를 직접 혹은 간접적으로 상속하는 객체이다. 그러니 Base 형 포인터 변수로도
// 참조가 가능하다."

// Todo : 다음과 같이 가능하다는 이야기
class First {
  public :
  void FirstFunc() {cout<<"FirstFunc()"<<endl}
};
class Second : public First {
  public :
  void SecondFunc() {cout<<"SecondFunc()"<<endl}
};
class Third : public Second{
  public :
  void ThirdFunc() {cout<<"ThirdFunc()"<<endl}
};

int main(int argc, char const *argv[])
{
  Third * tptr = new Third();
  Second * sptr = tptr;
  First * fptr = sptr;

  tptr -> FirstFunc();
  tptr -> SecondFunc();
  tptr -> ThirdFunc();

  sptr -> FirstFunc();
  sptr -> SecondFunc();

  fptr -> FirstFunc();
  return 0;
}

// 결론적으로는 포인터 형에 해당하는 클래스에 정의된 맴버에만 접근이 가능한 것이다.
// "C++ 컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다."

