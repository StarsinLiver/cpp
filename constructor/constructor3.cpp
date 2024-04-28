// Todo : 깊은 복사와 얕은 복사
// Todo : 디폴트 복사 생성자의 문제점
// 디폴트 복사 생성자는 맴버 대 맴버 복사를 진행한다. 그리고 이러한 방식의 복사를 가리켜 얕은 복사 (shallow copy)라고 하는데,
// 이는 멤버변수가 힙의 메모리 공간을 참조하는 경우에 문제가 된다.

// 밑의 예제는 컴파일은 제대로 되지만, 실행을 하면 문제가 발생하는데 어떤 문제가 발생하는 지 확인하고, 그 원인을 유추해보자

#include <iostream>
#include <cstring>
using namespace std;

class Person {
  private :
  char * name;
  int age;

  public :
    Person (char * myname , int myage) {
      int len = strlen(myname) + 1;
      name = new char (len);
      strcpy(name , myname);
      age = myage;
    }

    void ShowPersonInfo() const {
      cout<<"이름 : "<<name<<" , " ;
      cout<<"나이 : "<<age<<endl;
    }

    ~Person () {
      delete []name;
      cout<<"called destructor!"<<endl;
    }
};

int main(int argc, char const *argv[])
{
  Person man1("Lee dong woo" , 29);
  Person man2 = man1;
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}

 // 위의 실행결과에서 주목할 점은 "called destructor!"가 단 한번만 출력되었다는 점이다.
 // 분명 두 개의 객체를 생성했으므로 , 소멸자도 두번 호출되어야 할 텐데, 실행결과를 보면 딱 한번만 호출되고 있다.
 
 // 이는 Person man2 = man1; 에서 진행되는 얕은 복사에 있다.
 // 위의 문장에 의해서 man2가 생성되면서 디폴트 복사 생성자가 호출된다.

 // 그런데 디폴트 복사 생성자는 멤버 대 멤버를 단순히 복사만 하므로 , 문제가 된다.

 // Todo : 그림은 223 , 224 쪽을 참조하자
 
 // .. 그러나 디폴트 복사 생성자는 맴버 대 맴버의 단순 복사를 진행하기 때문에 복사의 결과로 하나의 문자열을 두 개의 객체가 동시에 참조하는 꼴이 만들어버린다.
 // 그리고 이로 인해서 객체의 소멸과정에서 문제가 발생한다.
 // 다음 문장이 실행되는데 delete []name;

 // man2 는 소멸로 인해 "Lee dong woo"의 문자열이 소멸된다.
 // 이제 남아있는 man1 객체가 소멸될 차례인데, man1 객체의 맴버 name 이 참조하는 문자열은 이미 소멸된상태다. 조금 전에 man2 의 소멸자가 호출되면서 소멸시켜버렸다.
 // 즉 man1 객체의 소멸자에 포함되어 있는 다음의 문장의 실행이 문제가 된다.
 
 // delete []name;

 // 이미 지워진 문자열을 대상으로 delete 연산이 불가능하여 문제가 발생하게 된다.
 
 // Todo : 깊은 복사를 위한 복사 생성자의 정의
 // 그럼 깊은 복사를 해보자

Person(const Person &copy) : age(copy.age)  {
  name = new char [strlen(copy.name) + 1];
  strcpy(name , copy.name);
 }

// 깊은 복사를 위한 위의 생성자만 추가하면 되기때문에 전체 코드를 싣지 않고,생성자만 보였다. 
// - 멤버변수 age의 멤버 대 멤버 복사
// - 메모리 공간 할당 후 문자열 복사 , 그리고 할당된 메모리의 주소 값을 멤버 name 에 저장

