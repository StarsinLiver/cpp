// Todo : 배열 클래스의 템플릿화
// ArrayTemplate.h  , Point.h
// ArrayTemplate.cpp , Point.cpp

// BoundCheckArray<Point> 객체의 생성을 위해서 Point 클래스를 정의하였다.
// 선언과 정의를 분리해서 헤더 파일과 소스파일에 나눠서 저장한 것 뿐이낟.

#include <iostream>
#include "./separate/ArrayTemplate.h"
#include "./separate/Point.h"
#include "./separate/Point.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
  /** int 형 정수 저장 **/
  BoundCheckArray<int> iarr(5);
  for (int i = 0; i < 5; i++)
    iarr[i] = (i + 1) * 11;
  for (int i = 0; i < 5; i++)
    cout << iarr[i] << endl;

  /** Point 객체 저장 **/
  BoundCheckArray<Point> oarr(3);
  oarr[0] = Point(3, 4);
  oarr[1] = Point(5, 6);
  oarr[2] = Point(7, 8);

  for (int i = 0; i < oarr.GetArrLen(); i++)
    cout << oarr[i];

  /** Point 객체의 주소값 저장 **/
  typedef Point * POINT_PTR;
  BoundCheckArray<POINT_PTR> parr(3);
  parr[0] = new Point(3 ,4);
  parr[1] = new Point(5 ,6);
  parr[2] = new Point(7 ,8);
  for (int i = 0; i < parr.GetArrLen(); i++)
    cout << *(parr[i]);
  
  delete parr[0];
  delete parr[1];
  delete parr[2];
  return 0;
}

/*
11
22
33
44
55

[3 , 4]
[5 , 6]
[7 , 8]

[3 , 4]
[5 , 6]
[7 , 8]
*/

