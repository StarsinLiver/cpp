// Todo : 클래스와 배열 그리고 this 포인터

// Todo : 객체 배열
// 객체 기반의 배열은 다음의 형태로 선언한다.
// Sosimple arr[10];

// 이를 동적으로 할당하는 경우에는 다음의 형태로 선언한다.
// Sosimple * ptrArr = new Sosimple[10];

// 이러한 형태로 배열을 선언하면, 열 개의 Sosimple 객체가 모여서 배열을 구성하는 형태가 된다.
// 이렇듯 구조체 배열의 선언과 차이가 없다.
// 하지만 배열을 선언하는 경우에도 생성자는 호출이 된다.
// 단, 배열의 선언과정에서는 호출할 생성자를 별도로 명시하지 못한다(생성자에 인자를 전달하지 못한다.

// 즉, 위의 형태로 배열이 생성되려면 다음 형태의 생성자가 반드시 정의되어 있어야 한다.
// Sosimple () {...}

// 그리고 배열 선언 이후에는 각각의 요소를 여려분이 원하는 값으로 초기화시키길 원한다면, 일일이 초기화의 과정을 별도로 거쳐야한다.

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

  Person() {
    name = NULL;
    age = 0;
    cout<<"called Person()"<<endl;
  }

  void SetPersonInfo(char * myname , int myage) {
    name = myname;
    age = myage;
  }

  void ShowPersonInfo() const {
    cout<<"이름 : "<<name<<" , ";
    cout<<"나이 : "<<age<<endl;
  }

  ~Person() {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  Person parr[3];
  char namestr[100];
  char * strptr;
  int age;
  int len;

  for(int i = 0; i < 3 ; i++) {
    cout<<"이름 : " ;
    cin>>namestr;
    cout<<"나이 : " ;
    cin>>age;
    len = strlen(namestr) + 1;
    strptr = new char[len];
    strcpy(strptr , namestr);
    parr[i].SetPersonInfo(strptr,age);
  }

  parr[0].ShowPersonInfo();
  parr[1].ShowPersonInfo();
  parr[2].ShowPersonInfo();
  return 0;
}

/*
called Person()
called Person()
called Person()
이름 : lee 
나이 : 21
이름 : san
나이 : 34
이름 : ha
나이 : 54
이름 : lee , 나이 : 21
이름 : san , 나이 : 34
이름 : ha , 나이 : 54
called destructor!
called destructor!
called destructor!
*/

// 위의 실행결과를 통해서 객체 배열 생성시 void 형 생성자가 호출됨을 확인할 수 있다. 그리고 배열 소멸시에도
// 그 배열을 구성하는 객체 소멸자가 호출됨을 확인할 수 있다.

