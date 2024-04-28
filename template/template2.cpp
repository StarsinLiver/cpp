// Todo : 함수 템플릿과 템플릿 함수
// 앞서 보인 다음의 정의를 가리켜 "함수 템플릿(function template)"이라고 한다.
template <typename T>
T Add(T num1, T num2)
{
  return num1 + num2;
}

// 반면, 위의 템플릿을 기반으로 컴파일러가 만들어 내는 다음 유형의 함수들을 가리켜 "템플릿 함수(template funciton)"이라고 한다.

int Add<int>(int num1, int num2)
{
  return num1 + num2;
}

double Add<double>(double num1, double num2)
{
  return num1 + num2;
}

// 앞서 언급했듯이, 위의 템플릿 함수의 표시에서 <int> 와 <double>은 일반함수가 아닌, 컴파일러가 만들어낸 템플릿 기반의 함수임을 표시한 것이다.

// Todo : 한마디로?
// "함수 템플릿"
// 함수를 만드는데 사용되는 템플릿!

// "템플릿 함수"
// 템플릿을 기반으로 만들어진 함수!

// Todo : 즉, 템플릿을 기반으로 만들어진, 호출이 가능한 함수임을 강조한 것이다.
// 그런데 이렇게 만들어지는 템플릿 함수는 일반함수와 구분이 된다.
// 따라서 두 가지 모두 함께 존재할 수 있다.

#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2)
{
  cout << "T Add(T num1 , T num2 )" << endl;
  return num1 + num2;
}

int Add(int num1, int num2)
{
  cout << "int Add(int num1, int num2)" << endl;
  return num1 + num2;
}

double Add(double num1, double num2)
{
  cout << "double Add(double num1, double num2)" << endl;
  return num1 + num2;
}

int main(int argc, char const *argv[])
{
  cout<<Add(5,7)<<endl;
  cout<<Add(51.15,7.15)<<endl;

  cout<<Add<int>(5,7)<<endl;
  cout<<Add<double>(51.15,7.15)<<endl;
  return 0;
}

/*
int Add(int num1, int num2)
12
double Add(double num1, double num2)
58.3

T Add(T num1 , T num2 )
12
T Add(T num1 , T num2 )
58.3
*/