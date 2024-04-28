// Todo : 스마트 포인터 (Smart Pointer)
// 스마트 포인터란 말 그대로 똑똑한 포인터이다. 우리가 알고 있는 포인터는 자기 스스로 하는 일이 아무것도 없지만, 스마트 포인터는 자기 스스로 하는 일이 존재하는 포인터이다.

// 사실 스마트 포인터는 객체이다. 포인터의 역할을 하는 객체를 뜻하는 것이다.

// 따라서 구해야 할 대상이 아닌, 구현해야할 대상인 것이다.

// 이후에 여러분이 프로그램의 개발을 목적으로 라이브러리에서 제공하는 스마트 포인터를 사용할 때 큰 도움이 될 것이다.

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

  ~Point()
  {
    cout << "Point 객체 소멸" << endl;
  }

  void SetPos(int x, int y)
  {
    xpos = x;
    ypos = y;
  }

  friend ostream &operator<<(ostream &os, const Point &pos);
};

ostream &operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << " , " << pos.ypos << ']' << endl;
  return os;
}

class SmartPtr
{
private:
  Point *posptr;

public:
  SmartPtr(Point *ptr) : posptr(ptr) {}

  Point &operator*() const
  {
    return *posptr;
  }

  Point *operator->() const
  {
    return posptr;
  }

  ~SmartPtr()
  {
    delete posptr;
  }
};

int main(int argc, char const *argv[])
{
  SmartPtr sptr1(new Point(1, 2));
  SmartPtr sptr2(new Point(3, 4));
  SmartPtr sptr3(new Point(5, 6));

  cout << *sptr1;
  cout << *sptr2;
  cout << *sptr3;

  sptr1->SetPos(10, 20);
  sptr2->SetPos(30, 40);
  sptr3->SetPos(50, 60);

  cout << *sptr1;
  cout << *sptr2;
  cout << *sptr3;
  return 0;
}

/*
Point 객체 생성
Point 객체 생성
Point 객체 생성
[1 , 2]
[3 , 4]
[5 , 6]
[10 , 20]
[30 , 40]
[50 , 60]
Point 객체 소멸
Point 객체 소멸
Point 객체 소멸
*/

// 위의 예제에서 가장 중요한 사실은, Point 객체의 소멸을 위한 delete 연산이 자동으로 이뤄졌다는 사실이다.
// 그리고 바로 이것이 스마트 포인터의 똑똑함이다.

// 앞서 말했듯이 위 예제는 스마트 포인터에 대한 개념적인 이해를 돕기 위해 작성했다.