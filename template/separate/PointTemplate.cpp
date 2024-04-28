#include "PointTemplate.h"
#include <iostream>
using namespace std;

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T>
void Point<T>::ShowPosition() const
{
  cout << "[" << xpos << " , " << ypos << "]" << endl;
}
