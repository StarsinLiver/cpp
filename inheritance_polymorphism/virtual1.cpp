// Todo : 가상(Virtual)의 원리와 다중상속
// Todo : 맴버함수와 가상함수의 동작원리
// 지금까지는 객체 내에 맴버함수가 존재한다고 설명해왔다. 하지만 이는 사실이아니다.
// 때문에 여기서는 맴버함수가 실제로 어디에 존재하는지를 설명하고자 한다.
// 단, 진실을 알아도 객체 내에 맴버함수가 존재한다고 인식하고 객체를 바라보자

// Todo : 객체안에 정말로 맴버함수가 존재하는가?
// 지금부터 구조체 변수와 전역함수를 이용해서 클래스와 객체를 흉내내보겠다.
// 다시말해 C언어의 문법만을 이용해서 클래스와 객체를 흉내내보자

// 일단 먼저 흉내낸ㄹ 모델이 되는 C++ 코드를 제시해보자
#include <iostream>
using namespace std;

class Data {
  private:
  int data;
  public :
  Data(int num) : data(num) {}
  void ShowData() {cout<<"Data : "<<data<<endl;}
  void Add(int num) {data += num;}
};

int main(int argc, char const *argv[])
{
  Data obj(15);
  obj.Add(17);
  obj.ShowData();
  return 0;
}

/*
Data : 32
*/

// 이어서 위의 예제를 C언어 스타일의 구조체와 전역함수를 사용하여 흉내내보자
typedef struct Data {
  int data;
  void (*ShowData)(Data*);
  void (*Add)(Data* , int);
};

void ShowData(Data* THIS) {cout<<"Data : "<<THIS->data<<endl;}
void Add(Data* THIS , int num) {THIS -> data += num;}

int main(int argc, char const *argv[])
{
  Data obj1 = {15 , ShowData , Add};
  Data obj2 = {7 , ShowData , Add};

  obj1.Add(&obj1,17);
  obj2.Add(&obj2,9);

  obj1.ShowData(&obj1);
  obj2.ShowData(&obj2);
  return 0;
}

/*
Data : 32
Data : 16
*/

// page 378
// 핵심은 두 개의 구조체 변수객체가 함수를 공유하고 있다는 사실이다.
// 그리고 실제로 C++ 객체와 맴버함수는 이러한 관계를 갖는다.
// 즉, 객체가 생성되면 맴버변수는 객체 내에 존재하지만, 맴버 함수는 메모리 한 공간에 별도로 위치하고선, 이 함수가 정의된 클래스의 모든 객체가 이를 공유하는
// 형태를 취한다.


