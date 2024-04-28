// Todo : 객체의 저장을 위한 배열 클래스의 정의
// 이번에 설명한 내용은 다양한 예제를 제시한다는 측면에서 의미를 갖는다. 앞서 보인 예제가 기본자료형 대상의 배열 클래스였기 때문에,
// 객체 대상의 배열 클래스를 제시하고자 한다. 저장 대상은 다음과 같다.

#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
  int xpos, ypos;

public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
  friend ostream &operator<<(ostream &os, const Point &pos);
};

ostream& operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << " , " << pos.ypos << ']' << endl;
  return os;
}

// 다음의 두가지 형태로 각각 정의해보고자 한다.

// - Point 객체의 주소값을 저장하는 배열 기반의 클래스
// - Point 객체를 저장하는 배열 기반의 클래스

// 즉, 저장의 대상이 객체냐, 아니면 객체의 주소값이냐 차이가 있는 것이다
// Todo : 먼저 Point 객체를 저장하는 배열 기반의 클래스이다.

class BoundCheckPointArray
{
private:
  Point *arr;
  int arrlen;

  BoundCheckPointArray(const BoundCheckPointArray &arr) {}
  BoundCheckPointArray &operator=(const BoundCheckPointArray &arr) {}

public:
  BoundCheckPointArray(int len) : arrlen(len)
  {
    arr = new Point[len];
  }

  Point &operator[](int idx)
  {
    if (idx < 0 || idx >= arrlen)
    {
      cout << "Array index out of bound exception" << endl;
      exit(1);
    }

    return arr[idx];
  }

  int GetArrLen() const { return arrlen; }
  ~BoundCheckPointArray() { delete[] arr; }
};

int
main(int argc, char const *argv[])
{
  BoundCheckPointArray arr(3);
  arr[0] = Point(3, 4);
  arr[1] = Point(5, 6);
  arr[2] = Point(7, 8);

  for(int i = 0; i < arr.GetArrLen(); i++) {
    cout<<arr[i];
  }
  return 0;
}

/*
[3 , 4]
[5 , 6]
[7 , 8]
*/

// 위 예제에서 보이듯이 객체의 저장은 객체간의 대입연산을 기반으로 한다. 
// Todo : 따라서 다음예제에서 보이는 주소 값을 저장하는 방식이 보다 많이 사용된다.

#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
  int xpos, ypos;

public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
  friend ostream &operator<<(ostream &os, const Point &pos);
};

ostream& operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << " , " << pos.ypos << ']' << endl;
  return os;
}

typedef Point * POINT_PTR;

class BoundCheckPointArray
{
private:
  POINT_PTR * arr;
  int arrlen;

  BoundCheckPointArray(const BoundCheckPointArray &arr) {}
  BoundCheckPointArray &operator=(const BoundCheckPointArray &arr) {}

public:
  BoundCheckPointArray(int len) : arrlen(len)
  {
    arr = new POINT_PTR[len];
  }

  POINT_PTR &operator[](int idx)
  {
    if (idx < 0 || idx >= arrlen)
    {
      cout << "Array index out of bound exception" << endl;
      exit(1);
    }

    return arr[idx];
  }
    POINT_PTR &operator[](int idx) const
  {
    if (idx < 0 || idx >= arrlen)
    {
      cout << "Array index out of bound exception" << endl;
      exit(1);
    }

    return arr[idx];
  }

  int GetArrLen() const { return arrlen; }
  ~BoundCheckPointArray() { delete[] arr; }
};

int
main(int argc, char const *argv[])
{
  BoundCheckPointArray arr(3);
  arr[0] = new Point(3, 4);
  arr[1] = new Point(5, 6);
  arr[2] = new Point(7, 8);

  for(int i = 0; i < arr.GetArrLen(); i++) {
    cout<<*(arr[i]);
  }
  delete arr[0];
  delete arr[1];
  delete arr[2];
  return 0;
}

/*
[3 , 4]
[5 , 6]
[7 , 8]
*/

// 위의 예제와 같이 주소값을 저장하는 경우, 객체의 생성과 소멸을 위한 new , delete 연산때문에 더 신경 쓸것이 많아보이지만,
// 깊은 복사냐 얕은 복사냐 하는 문제를 신경 쓰지 않아도 되기 때문에 이 방법이 더 많이 사용된다.