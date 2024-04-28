// Todo : 가상 소멸자와 참조자의 참조 가능성
// 가상함수 말고도 virtual 키워드를 붙여줘야 할 대상이 하나 더 있다. 그건 바로 소멸자다. 즉, virtual 선언은 소멸자에도 올수있다.

// Todo : 가상 소멸자 (Virtual Destructor)
// virtual 로 선언된 소멸자를 가리켜 '가상 소멸자'라 하는데, 이것이 필요한 이유를 설명에 앞서 예제를 보자
#include <iostream>
#include <cstring>
using namespace std;

class First {
  private :
  char * strOne;
  public :
  First (char * str) {
    strOne = new char[strlen(str) + 1];
  }

  ~First() {
    cout<<"~First()"<<endl;
    delete []strOne;
  }
};

class Second : public First {
  private :
  char * strTwo;
  public :
  Second (char * str1 , char* str2) : First(str1) {
    strTwo = new char [strlen(str2) + 1];
  }
  ~Second() {
    cout<<"~Second()"<<endl;
    delete[]strTwo;
  }
};

int main(int argc, char const *argv[])
{
  First * ptr = new Second("simple" , "complex");
  delete ptr;
  return 0;
}

/*
~First()
*/

// 실행결과에서도 보이듯이 객체의 소멸을 First 형 포인터로 명령하니, First 클래스의 소멸자만 호출되었다.
// 따라서 이러한 경우에는 메모리의 누수(leak)가 발생하게 된다. 그러니 객체의 소멸과정에서는 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자
// 가 호출되어야 한다.
// 그리고 이를 위해서 다음과 같이 소멸자에 virtual 선언을 추가해주면 된다.

class First {
  ...
  public :
  virtual ~First() {..}
};

class Second : public First{
  ...
  public :
  virtual ~Second() {..}
};

class Third : public Second {
  ...
  public :
  virtual ~Third() {..}
};

// 가상함수와 마찬가지로 소멸자도 상속의 계층 구조상 맨위에 존재하는 기초 클래스의 소멸자만 virtual 로 선언하면 이를 상속하는 유도 클래스의 소멸자들도 모두
// '가상 소멸자' 로 선언된다.
// 그리고 가상소멸자가 호출되면, 상속의 계층 구조상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출하게 되면서, 기초 클래스의 소멸자가 순차적으로 호출된다.

