// Todo : 순수 가상함수(Pure Virtual Function) 와 추상 클래스 (abstract Class)
// 클래스 중에서는 객체생성을 목적으로 정의되지 않는 클래스도 존재한다.

// '순수 가상함수' 란 '함수의 몸체가 정의되지 않는 함수'를 의미한다.
// 그리고 이를 표현하기 위해서, 위에 보이듯이 '0의 대입'을 표시한다. 그런데 이것은 0의 대입을 의미하는 것이 아닌, '명시적으로 몸체를 정의하지 않았음'
// 을 컴파일러에게 알리는 것이다.

class Employee
{
private:
  char name[100];
public :
Employee(char * name) {
  this -> name = name
}
void ShowYourName() const {..}
virtual int GetPay() const {
  return 0;
}
virtual void ShowSalaryInfo() const {..}
}

// Todo : 위의 코드를 순수 가상함수로 바꾸면?
virtual int GetPay() const = 0; // 몸체 {} 를 정의하지 않음
virtual void ShowSalaryInfo() const = 0; // 몸체 {}를 정의하지 않음


// 따라서 컴파일러는 이 부분에서 함수의 몸체가 정의되지 않았다고 컴파일 오류를 일으키지 않는다. 그러나 Employee 클래스는 순수 가상함수를 지닌, 완전하지 않는 
// 클래스가 되기 때문에 다음과 같이 객체를 생성하려면 컴파일 에러가 발생한다.
int main(int argc, char const *argv[])
{
  Employee * emp = new Employee("Lee Dong Sook"); //! 컴파일 에러
  return 0;
}

// 이렇듯 하나 이상의 맴버함수를 순수 가상함수로 선언한 클래스를 가리켜 "추상 클래스(Abstract class)"라고 한다.
// 이는 완전하지 않은, 그래서 객체생성이 불가능한 클래스라는 의미를 지닌다.

// Todo : 다형성 (Polymorphism)
// 이제 '다형성'이라는 단어를 소개하면서 이야기를 한차례 마무리 하자.
// 다형성이란 지금까지 설명한 가상함수의 호출관계에서 보인 특성을 가리킨다.

// "모습은 같은데 형태는 다르다."

// 이를 C++에 적용하면 , 다음과 같이 이야기 할 수 있다.
// "문장은 같은데 결과는 다르다."
#include <iostream>
using namespace std;
class First {
  public :
  virtual void SimpleFunc() {cout<<"first"<<endl;}
};

class Second : public First {
  public :
  virtual void SimpleFunc() {cout<<"second"<<endl;}
};

int main(int argc, char const *argv[])
{
  First * ptr= new First();
  ptr -> SimpleFunc();
  delete ptr;

  ptr = new Second();
  ptr -> SimpleFunc();
  delete ptr;
  return 0;
}

/*
first
second
*/

// ptr 은 동일한 포인터 변수이나, 그럼에도 불구하고 실행결과는 다르다. 포인터 변수 ptr 이 참조하는 객체의 자료형이 다르기 때문이다.
// 이것이 '다형성'이다.


