// Todo : 교환법칙 문제의 해결
// 교환법칙이란 "A+B의 결과는 B+A 의 결과와 같음"을 뜻하낟. 즉, 연산자를 중심으로 한 피연산자의 위치는 연산의 결과에 아무런 영향을 미치지 않는다는 법칙이다.
// 대표적으로 교환법칙이 성립하는 연산으로 곱셈연산과 덧셈연산이 있다.

// Todo : 자료형이 다른 두 피연산자를 대상으로 하는 연산
// 다음 예제를 보자
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

  Point operator*(int times) {
    Point pos(xpos*times, ypos * times);
    return pos;
  }
};

int main(int argc, char const *argv[])
{
  Point pos (1 , 2);
  Point cpy;

  cpy = pos * 3;
  cpy.ShowPosition();

  cpy = pos * 3 * 2;
  cpy.ShowPosition();
  return 0;
}

/*
[3 , 6]
[6 , 12]
*/

// 위 예제에서 오버로딩 한 곱셈 연산자의 경우, Point 클래스의 맴버함수형태로 정의했기 때문에 Point 객체가 * 연산자의 왼편에 와야한다.
// 그러나 여러분도 알다시피 곱셈연산은 교환법칙이 성립한다. 

// 따라서
// cpy = pos * 3; 은 다음의 형태로 문장을 구성해도 동일한 결과를 보여야 한다
// cpy = 3 * pos; // 3.operator*(pos)로는 해석이 불가능

// Todo : 교환법칙의 성립을 위한 구현
// 그렇다면 cpy = 3 * pos 를 성립하려면 전역 함수의 형태로 곱셈 연산자를 오버로딩 하는 수 밖에 없다. 즉 ,

// operator*(3 , pos) 의 형태가 되어야 한다.

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

  Point operator* (int times) {
    Point pos (xpos * times , ypos * times);
    return pos;
  }
  friend Point operator*(int times , Point &ref);
};

Point operator*(int times , Point &ref) {
  return ref * times;
}

int main(int argc, char const *argv[])
{
  Point pos (1 , 2);
  Point cpy;

  cpy = 3 * pos;
  cpy.ShowPosition();

  cpy = 2 * pos * 3 ;
  cpy.ShowPosition();
  return 0;
}

/*
[3 , 6]
[6 , 12]
*/

// Todo : 위와 같이 전역함수를 기반으로 연산자를 오버로딩 해야하는 경우도 있으니 , 전역함수 기반의 연산자 오버로딩에도 익숙해 지기를 바란다.