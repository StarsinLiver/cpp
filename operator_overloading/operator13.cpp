// Todo : () 연산자의 오버로딩과 펑터(Functor)
// 함수의 호출에 사용되는 인자의 전달에 사용되는 () 도 연산자라는 사실을 알고 있는가?
// 때문에 이 역시도 오버로딩이 가능한 연산자이다.
// 그리고 이 연산자를 오버로딩하면, 객체를 함수처럼 사용할 수 있게 된다.

// 물론 객체를 함수처럼 사용했을 때 얻게 되는 이점만 말할것이다.
// C++ 을 잘하려면 "객체를 함수처럼 사용할 수 있어야 한다."

// 객체의 이름이 adder 이고 이 객체의 () 연산자가 맴버함수로 오버로딩되어 있는상태라면, 다음 문장은 이런식일 것이다.

// adder.operator()(2,4);

// 이 내용만 알면 () 연산자의 오버로딩에 대해서는 더는 설명할 것이 없다.

// Todo : 예제
#include <iostream>
using namespace std;

class Point
{
private:
  int xpos, ypos;

public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y)
  {
    cout << "Point 객체 생성" << endl;
  }

  Point operator+ (const Point& pos) const {
    return Point(xpos + pos.xpos , ypos + pos.ypos);
  }
  friend ostream &operator<<(ostream &os, const Point &pos);
};

ostream &operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << " , " << pos.ypos << ']' << endl;
  return os;
}

class Adder {
  public :
  int operator() (const int& n1 , const int& n2) {
    return n1 + n2;
  }

  double operator()(const double& e1 , const double& e2) {
    return e1 + e2;
  }
  Point operator()(const Point& pos1 , const Point& pos2) {
    return pos1 + pos2;
  }
};

int main(int argc, char const *argv[])
{
  Adder adder;
  cout<<adder(1,3)<<endl;
  cout<<adder(1.5 , 3.7)<<endl;
  cout<<adder(Point(3 ,4) , Point(7 ,9))<<endl;
  return 0;
}

/*
4
5.2
Point 객체 생성
Point 객체 생성
Point 객체 생성
[10 , 13]
*/

// 위 예제에서 정의한 Adder 클래스와 같이 함수처럼 동작하는 클래스를 가리켜 "펑터(Functor)"라 한다.
// 그리고 "함수 오브젝트(Function Object)"라고도 불린다.

// 그런데 펑터라는 전문적인 표현에 비해 () 연산자의 오버로딩이나 펑터 자체를 이해하는 것은 그리 어려운 일이 아니다.


