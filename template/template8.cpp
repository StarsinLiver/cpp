// Todo : 클래스 템플릿의 특수화(Class Template Specialization)
// Todo : 클래스 템플릿 특수화
// 함수 템플릿 특수화를 하는 이유는 특정 자료형에 대해서 구분이 되는 다른 행동을 보이기 위해서이다.
// 마찬가지로 클래스 템플릿을 특수화하는 이유는 특정 자료형을 기반으로 생성된 객체에 대해 구분이 되는 다른 행동양식을 적용하기 위해서이다.
// 즉, 클래스 템플릿을 특수화하면, 템플릿을 구성하는 멤버함수의 일부 또는 전부를 다르게 행동하도록 정의할 수 있다.

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
  T xpos, ypos;

public:
  Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
  void ShowPosition() const
  {
    cout << "[" << xpos << " , " << ypos << ']' << endl;
  }
};

template <typename T>
class SimpleDataWrapper
{
private:
  T mdata;

public:
  SimpleDataWrapper(T data) : mdata(data) {}
  void ShowDataInfo(void)
  {
    cout << "Data : " << mdata << endl;
  }
};

template <>
class SimpleDataWrapper<char *>
{
private:
  char *mdata;

public:
  SimpleDataWrapper(char *data)
  {
    mdata = new char[strlen(data) + 1];
    strcpy(mdata, data);
  }

  void ShowDataInfo(void)
  {
    cout << "String : " << mdata << endl;
    cout << "Length :  " << strlen(mdata) << endl;
  }

  ~SimpleDataWrapper() { delete[] mdata; }
};

template <>
class SimpleDataWrapper<Point<int>>
{
private:
  Point<int> mdata;

public:
  SimpleDataWrapper(int x, int y) : mdata(x, y) {}

  void ShowDataInfo(void)
  {
    mdata.ShowPosition();
  }
};

int main(int argc, char const *argv[])
{
  SimpleDataWrapper<int> iwrap(170);
  iwrap.ShowDataInfo();

  SimpleDataWrapper<char *> swrap("Class Template Specialization");
  swrap.ShowDataInfo();

  SimpleDataWrapper<Point<int>> poswrap(3, 7);
  poswrap.ShowDataInfo();

  return 0;
}

/*
Data : 170
String : Class Template Specialization
Length :  29
[3 , 7]
*/

// Todo : 클래스 템플릿의 부분 특수화
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MySimple
{
public:
  void WhoAreYou()
  {
    cout << "size of T1 : " << sizeof(T1) << endl;
    cout << "size of T2 : " << sizeof(T2) << endl;
    cout << "<typename T1 , typename T2> : " << endl;
  }
};

template <>
class MySimple<int, double>
{
public:
  void WhoAreYou()
  {
    cout << "size of int : " << sizeof(int) << endl;
    cout << "size of double : " << sizeof(double) << endl;
    cout << "<int , double> : " << endl;
  }
};

template <typename T1>
class MySimple<T1, double>
{
public:
  void WhoAreYou()
  {
    cout << "size of T1 : " << sizeof(T1) << endl;
    cout << "size of double : " << sizeof(double) << endl;
    cout << "<T1 , double> : " << endl;
  }
};

int main(int argc, char const *argv[])
{
  MySimple<char, double> obj1;
  obj1.WhoAreYou();

  MySimple<int , long> obj2;
  obj2.WhoAreYou();

  MySimple<int , double> obj3;
  obj3.WhoAreYou();

  return 0;
}

/*
size of T1 : 1
size of double : 8
<T1 , double> : 

size of T1 : 4
size of T2 : 4
<typename T1 , typename T2> : 

size of int : 4
size of double : 8
<int , double> : 
*/

