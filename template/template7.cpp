// Todo : Template 내용의 확장
// Todo : Point 클래스 템플릿과 배열 클래스 템플릿

// 예제를 통해서 확인해보자
// ArrayTemplate2.h
// PointTemplate2.h

#include <iostream>
#include "./separate/ArrayTemplate2.h"
#include "./separate/PointTemplate2.h"

int main(int argc, char const *argv[])
{
  BoundCheckArray<Point<int>> oarr1(3);
  oarr1[0] = Point<int>(3, 4);
  oarr1[1] = Point<int>(5, 6);
  oarr1[2] = Point<int>(7, 8);

  for (int i = 0; i < oarr1.GetArrLen(); i++)
  {
    oarr1[i].ShowPosition();
  }

  BoundCheckArray<Point<double>> oarr2(3);
  oarr2[0] = Point<double>(3.14, 4.31);
  oarr2[1] = Point<double>(5.09, 6.07);
  oarr2[2] = Point<double>(7.82, 8.54);

  for (int i = 0; i < oarr2.GetArrLen(); i++)
  {
    oarr2[i].ShowPosition();
  }

  typedef Point<int> *POINT_PTR;
  BoundCheckArray<POINT_PTR> oparr(3);
  oparr[0] = new Point<int>(11, 12);
  oparr[1] = new Point<int>(13, 14);
  oparr[2] = new Point<int>(15, 16);

  for (int i = 0; i < oparr.GetArrLen(); i++)
  {
    oparr[i] -> ShowPosition();
  }

  delete oparr[0];
  delete oparr[1];
  delete oparr[2];
  return 0;
}

/*
[3 , 4]
[5 , 6]
[7 , 8]
[3.14 , 4.31]
[5.09 , 6.07]
[7.82 , 8.54]
[11 , 12]
[13 , 14]
[15 , 16]
*/

// Todo : 특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend 선언
// Point<int> , Point<double> 과 같은 템플릿 클래스의 자료형을 대상으로도 템플릿이 아닌 일반함수의 정의가 가능하고, 클래스 템플릿 내에서 이러한 함수를 대상으로 
// friend 선언이 가능하다.
