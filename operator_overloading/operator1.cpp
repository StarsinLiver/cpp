// Todo : 단항 연산자의 오버로딩
// 피연산자가 두 개인 이항 연산자와 피연산자가 한 개인 단항 연산자의 가장 큰 차이점은 피연산자의 개수이다.
// 그리고 이에 따른 연산자 오버로딩의 차이점은 매개변수의 개수에서 발견된다

// Todo : 증가, 감소 연산자의 오버로딩
// 대표적인 단항 연산자로는 다음 두가지가 있다.
// ++ 
// --

// 이에 앞서 보인 Point 클래스에 ++ 연산자가 오버로딩 되어있다고 가정해보자
// 그렇다면 다음의 행대로 문장 구성이 가능하다.

// ++pos
// pos.operator++(); // - 맴버 함수로 오버로딩 된 경우

// 여기서 전달한 일자가 없는 이유는 단항 연산자를 오버로딩 했기 때문이다. 그나마 하나 있는 피연산자의 맴버호출하는 형태이기 때문이다

// 그런데 전역함수의 형태라면 operator++ 가 전역함수의 이름이 되므로 다음과 같이 된다.
// operator++(pos) // - 전역 함수로 오버로딩 된 경우

// #include <iostream>
// using namespace std;


class Point {
  private :
  int xpos , ypos;

  public :
  Point(int x = 0 , int y = 0) :xpos(x) , ypos(y) {}

  void ShowPosition () const {
    cout<<"["<<xpos<<" , "<<ypos<<"]"<<endl;
  }

  Point operator++() {
    xpos+=1;
    ypos+=1;
    return *this;
  }
  friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref) {
  ref.xpos -=1;
  ref.ypos -=1;
  return ref;
}

int main(int argc, char const *argv[])
{
  Point pos1(3 , 4);
  ++pos1;                   // 맴버 함수이므로 pos1.operator++(); 로 해석이 된다.
  pos1.ShowPosition();

  Point pos2(10, 20);
  --pos2;                   // 전역 함수이므로 operator--(pos2); 로 해석이 된다.
  pos2.ShowPosition();

  return 0;
}

// Todo : 전위증가와 후위증가의 구분
// ++pos == pos.operator();
// pos++ == pos.operator(int);

// --pos == pos.operator--();
// pos-- == pos.operator--(int);

// 즉, 키워드 int 를 이용해서 후위 연산에 대한 함수를 전위연산에 대한 함수와 구분하고 있다.
// 물론 여기서 사용된 int 는 단지 후위연산을 구분하기 위한 목적으로 선택된 것일뿐 int 형 데이터를 인자로 전달하라는 뜻과는 거리가 멀다.
// 아니 아무상관이 없다.

// Todo : 전위 증가와 후위증가
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

  // 전위 증가
  Point operator++() {
    xpos+=1;
    ypos+=1;
    return *this;
  }

  // 후위 증가
  const Point operator++(int) {
    const Point retobj(xpos , ypos);
    xpos+=1;
    ypos+=1;
    return retobj;
  }

  // 전위 감소
  friend Point& operator--(Point &ref);
  // 후위 감소
  friend const Point operator--(Point &ref , int);
};

// 전위 감소
Point& operator--(Point &ref) {
  ref.xpos -=1;
  ref.ypos -=1;
  return ref;
}

// 후위 감소
const Point operator--(Point &ref , int) {
  const Point retobj(ref); 
  ref.xpos -=1;
  ref.ypos -=1;
  return retobj;
}

int main(int argc, char const *argv[])
{
  Point pos(3 , 5);
  Point cpy;
  cpy = pos--; // 후위 감소
  cpy.ShowPosition();
  pos.ShowPosition();


  cpy = pos++;  // 후위 증가
  cpy.ShowPosition();
  pos.ShowPosition();

  return 0;
}

/*
[3 , 5]
[2 , 4]
[2 , 4]
[3 , 5]
*/

