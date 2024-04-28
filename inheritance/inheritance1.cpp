// Todo : 상속의 이해
// 상속의 문법적인 이해
// Todo : 상속이란?
// "알지 않어? ㅋㅋㅋ"

// 상속의 방법과 그 결과
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
  int age;
  char name[50];

public:
  Person(int myage, char *myname) : age(myage)
  {
    strcpy(name, myname);
  }
  void WhatYourName() const
  {
    cout << "My name is " << name << endl;
  }

  void HowOlderYou() const
  {
    cout << "My age is " << age << " years old" << endl;
  }
};

// 상속
class UnivStudent : public Person
{
private:
  char major[50]; // 전공 과목

public:
  UnivStudent(char *myname, int myage, char * mymajor) : Person(myage, myname)
  {
    strcpy(major, mymajor);
  }
};

int main(int argc, char const *argv[])
{
  UnivStudent uni("이름" , 17 , "전공과목");
  uni.WhatYourName();
  uni.HowOlderYou();
  return 0;
}
