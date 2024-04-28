// Todo : 객체 포인터의 참조 관계
// Todo : 객체 포인터 변수 : 객체의 주소값을 저장하는 포인터 변수
// 이전에 제시한 예제들을 통해서도 보았듯이, 클래스를 기반으로 포인터 변수를 선언할 수 있다.
// 예를 들어서 Person 이라는 이름의 클래스가 정의되었다면 Person 객체의 주소값을 저장하기 위해서 다음과 같이 포인터 변수를 선언할 수 있다.

// Person * ptr; // 포인터 변수 선언
// ptr = new Person(); // 포인터 변수의 객체 참조

// 그런데 Person 형 포인터는 Person 객체뿐만 아니라, Person 을 상속하는 유도 클래스의 객체도 가리킬 수 있다.

// class Student : public Person {...}
// Person * ptr = new Student();

// Todo : 이것이 어떻게 가능한 것일까?
#include <iostream>
using namespace std;

class Person {
  public :
  void Sleep() {
    cout<<"Sleep"<<endl;
  }
};

class Student : public Person {
  public :
  void Study() {
    cout<<"Study"<<endl;
  }
};

class PartTimeStudent : public Student {
  public :
  void Work() {
    cout<<"Work"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  Person * ptr1 = new Student();
  Person * ptr2 = new PartTimeStudent();
  Student * ptr3 = new PartTimeStudent();
  ptr1 -> Sleep();
  ptr2 -> Sleep();
  ptr3 -> Study();

  delete ptr1; delete ptr2; delete ptr3;
  return 0;
}

/*
Sleep
Sleep
Study
*/

// Todo : 유도 클래스의 객체까지 가리킬 수 있다니!!
// 객체 포인터의 다음 특성은, 상속의 IS-A 관계를 통해서 논리적으로 이해가 가능하다.

// "C++ 에서, AAA 형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.(객체의 주소 값을 저장할 수 있다.)"
