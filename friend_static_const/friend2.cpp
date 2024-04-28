
// Todo : 함수의 friend 선언
// 전역 함수를 대상으로도, 클래스의 맴버함수를 대상으로도 friend 선언이 가능하다.

#include <iostream>
using namespace std;

class Point;

class PointOP {
  private :
  int opcnt;
  public :
  PointOP() : opcnt(0) {}
  Point PointAdd(const Point &, const Point&);
  Point PointSub(const Point &, const Point&);
  ~PointOP() {
    cout<<"Operation times"<<opcnt<<endl;
  }
};

class Point {
  private :
  int x;
  int y;
  public :
  Point(const int &xpos , const int &ypos) :x(xpos) , y(ypos) {}
  friend Point PointOP::PointAdd(const Point& , const Point&);
  friend Point PointOP::PointSub(const Point& , const Point&);
  friend void ShowPointPos(const Point&);
};

Point PointOP::PointAdd(const Point& pnt1 , const Point& pnt2) {
  opcnt++;
  return Point(pnt1.x+pnt2.x , pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
  opcnt++;
  return Point(pnt1.x - pnt2.x , pnt2.y - pnt2.y);
}

int main(int argc, char const *argv[])
{
  Point pos1(1,2);
  Point pos2(2,4);
  PointOP op;

  ShowPointPos(op.PointAdd(pos1,pos2));
  ShowPointPos(op.PointSub(pos1,pos2));
  return 0;
}

void ShowPointPos(const Point& pos) {
  cout<<"x : "<<pos.x<<" , ";
  cout<<"y : "<<pos.y<<endl;
}

/*
x : 3 , y : 6
x : -1 , y : 0
Operation times2
*/

