// Todo : const 와 관련해서 아직 못다한 이야기
// const : 상수화
// const int num = 10;

// 이렇듯 객체에 const 선언이 붙으면 "이 객체의 데이터 변경을 허용하지 않겠다"라는 것이다.

// 함수도 그렇다
// void ShowData() const {
//   ... 데이터 변경 없음
// }

// Todo : const 와 함수 오버로딩
// 함수의 오버로딩이 성립하려면 매개변수의 수나 자료형이 달라야 한다.
// 하지만 다음과 같이 const 선언유무도 함수 오버로딩 조건에 해당이 된다.
// void SimpleFunc() {...}
// void SimpleFunc() const {...}

// 다음 예제를 통해서 두 함수가 어떠한 경우에 호출되는 지 확인해 보자
#include <iostream>
using namespace std;

class SoSimple {
  int num;
  public :
  SoSimple (int n) : num(n) {}

  void SimpleFunc() {
    cout<<"SimpleFunc : "<<num<<endl;
  }
    void SimpleFunc() const {
    cout<<"const SimpleFunc : "<<num<<endl;
  }
};

void YourFunc(const SoSimple &obj) {
  obj.SimpleFunc();
}

int main(int argc, char const *argv[])
{
  SoSimple obj1(2);
  const SoSimple obj2(7);

  obj1.SimpleFunc();
  obj2.SimpleFunc();

  YourFunc(obj1);
  YourFunc(obj2);
  return 0;
}

/*
SimpleFunc : 2
const SimpleFunc : 7
const SimpleFunc : 2
const SimpleFunc : 7
*/

// 다 알거라고 생각한다.