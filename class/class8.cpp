// Todo : 디폴트 생성자(Default Constructor)
// 메모리 공간의 할당 이후에 생성자의 호출까지 완료되어야 "객체"라 할 수 있다.
// 즉, 객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다.
// 그리고 이러한 기준에 예외를 두지 않기 위해서 생성자를 정의하지 않는 클래스에넌 C++ 컴파일러에 의해서 디폴트 생성자라는 것이 자동으로 삽입된다.

// Todo : 생성자 불일치
// 매개변수가 void 형으로 선언되는 디폴트 생성자는 , 생성자가 하나도 정의되어 있지 않을 때에만 삽입된다.

// Todo : private 생성자
// "그럼 클래스 내부에서 객체를 생성한다면, 생성자가 private 으로 선언되어도 되는 건가요?"
// 그렇다! 그래서 클래스 내부에서만 객체의 생성을 허용하려는 목적으로 생성자를 private 로 선언하기도 한다.

// Todo : 소멸자의 이해와 활용
// 객체생성시 반드시 호출되는 것이 생성자라면, 객체소멸시 반드시 호출되는 것은 소멸자이다. 소멸자는 다음의 형태를 갖는다.
// - 클래스의 이름 앞에 '~'가 붙은 형태의 이름을 갖는다.
// - 반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다.
// - 매개변수는 void 형으로 선언되어야 하기 때문에 오버로딩도, 디폴트 값 설정도 불가능하다.

// 예를 들어서 AAA 라는 클래스가 정의되어 있다면, 다음의 형태를 갖춘것이 소멸자이다.

// class AAA {} 는 밑과 동일하다.

class AAA {
  public :
  AAA () {}
  ~AAA () {} // 소멸자
};

// 이러한 소멸자는 대게 생성자에서 할당한 리소스의 소멸에 사용된다. 예를 들어서 생성자내에서 NEW 연산자를 이용해서 할당해 놓은 메모리 공간이 있다면,
// 소멸자에서는 DELETE 연산자를 이용해서 메모리 공간을 소멸한다.

// 예시를 들어보자

#include <iostream>
#include <cstring>
using namespace std;

class Person {
  char * name;
  int age;

  public :
  Person(char * myname , int myage) {
    int len = strlen(myname) + 1;
    name = new char[len];
    strcpy(name , myname);

    age = myage;
  }

  void ShowPersonInfo() const {
    cout<<"이름 : "<<name<<endl;
    cout<<"나이 : "<<age<<endl;
  }

  ~Person() {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};


int main(int argc, char const *argv[])
{
  Person man1("Lee dong woo" , 29);
  Person man2("Jang dong gun" , 41);
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}

// 이름 : Lee dong woo
// 나이 : 29
// 이름 : Jang dong gun
// 나이 : 41
// called destructor!
// called destructor!

// 위 예제에서 보이듯이 , 소멸자를 통해서 객체소멸과정에서 처리해야 할 일들을 자동으로 처리할 수 있다.
// 소멸자가 실제 사용이 되는 예는 위 예제에서 보여준 내용과 큰 차이가 없으니, 이정도로 설명을 마무리 하자.