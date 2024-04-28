// Todo : 키워드 operator 와 연산자
// 연산자 오버로딩은 일종의 약속이다.

// 한마디로 예를 들어보면

// 1번
// pos1 + pos2 
// pos1.operator+(pos2)

// 2번
// pos1 - pos2 
// pos1.operator-(pos);

// 가 되는 것이다.

// 따라서 두 문장은 100% 동일한 문장이다.

// Todo : 연산자를 오버로딩하는 두 가지 방법
// 연산자를 오버로딩 하는 방법에는 다음 두 가지가 있다.

// - 멤버함수에 의한 연산자 오버로딩
// - 전역함수에 의한 연산자 오버로딩

// 앞서 보인 예제는 + 연산자를 멤버함수를 이용해서 오버로딩 하였다.

// 따라서 pos1+pos2 는 pos1.operator+(pos) 와 같이 해석이 된다.
// 즉, 어떻게 오버로딩을 했느냐에 따라서 해석하는 방법이 다음과 같이 두 가지로 나뉘게 된다.

// Todo : 두가지 방법 == pos1+pos2 
// 1. pos1.operator+(pos2); - 멤버 함수에 의한 연산자 오버로딩
// 2. operator+(pos1,pos2); - 전역 함수에 의한 연산자 오버로딩

// 참고로 동일한 자료형을 대상으로 + 연산자를 전역함수 기반으로, 그리고 맴버함수 기반으로 동시에 오버로딩 할 경우,
// 맴버함수 기반으로 오버로딩 된 함수가 전역함수 기반으로 오버로딩 된 함수보다 우선시 되어 호출된다.

// 단, 일부 오래된 컴파일러는 이러한 상황에서 컴파일 에러를 발생시키기도 하니 이러한 상황은 가급적 만들지 않는게 좋다.

// Todo : 전역함수를 기반으로 오버로딩 해보자
#include <iostream>
using namespace std;


class Point {
  private :
  int xpos , ypos;

  public :
  Point(int x = 0 , int y = 0) :xpos(x) , ypos(y) {}

  void ShowPosition () const {
    cout<<"["<<xpos<<" , "<<ypos<<"]"<<endl;
  }

  friend Point operator+ (const Point &pos1 , const Point &pos2);
};

Point operator+ (const Point &pos1 , const Point &pos2) {
  Point pos(pos1.xpos + pos2.xpos , pos1.ypos + pos2.ypos);
  return pos;
}

int main(int argc, char const *argv[])
{
  Point pos1(3 , 4);
  Point pos2(10, 20);
  Point pos3 = pos1 + pos2;

  pos1.ShowPosition();
  pos2.ShowPosition();
  pos3.ShowPosition();
  return 0;
}

/*
[3 , 4]
[10 , 20]
[13 , 24]
*/

// 위의 예제는 전역함수 기반의 연산자 오버로딩에 대한 일반적인 모델을 보여주고 있다.
// 특히, friend 선언이 적절히 사용된 예를 보이고 있다.
// 위 예제 friend 선언을 보면서 어떤 생각이 드는가?

// "아! operator+ 함수내에서는 Point 클래스의 private 영역에 접근이 가능하겠구나!"
// "아! Point 클래스는 +연산에 대해서 연산자 오버로딩이 되어 있구나!"

// 이렇듯 Point 클래스에 삽입된 friend 선언으로 인해서, 이 클래스는 + 연산에 대해서 오버로딩이 되어 있다는 정보를 쉽게 확인할 수 있다.







