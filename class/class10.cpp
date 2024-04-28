// Todo : 객체 포인터 배열
// 객체 배열이 객체로 이뤄진 배열이라면, 객체 포인터 배열은 객체의 주소값이 저장이 가능한 포인터 변수로 이뤄진 배열이다.
// 이에 대한 소개를 위해서 앞서 보인 예제를 객체 포인터 배열 기반으로 변경해보자

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
  Person * parr[3];
  char namestr[100];
  char * strptr;
  int age;
  int len;

  for(int i = 0; i < 3 ; i++) {
    cout<<"이름 : " ;
    cin>>namestr;
    cout<<"나이 : " ;
    cin>>age;
    parr[i] = new Person(namestr,age); // new 연산자
  }

  parr[0]->ShowPersonInfo();
  parr[1]->ShowPersonInfo();
  parr[2]->ShowPersonInfo();

  delete parr[0]; // delete 연산자
  delete parr[1];
  delete parr[2];
  return 0;
}

/*
이름 : lee
나이 : 21
이름 : san
나이 : 31
이름 : ha
나이 : 54
이름 : lee , 나이 : 21
이름 : san , 나이 : 31
이름 : ha , 나이 : 54
called destructor!
called destructor!
called destructor!
*/

// 객체를 저장할 때에는 위의 예제에서 보인 두가지 방법 중 하나를 택해야한다. 즉, 저장의 대상을 객체로 하느냐, 객체의 주소값으로 하느냐를 결정해야한다.
// 그러니 위의 두 예제를 통해서 '객체 배열'과 '객체 포인터 배열'의 차이점을 정확히 이해하기 바란다.
