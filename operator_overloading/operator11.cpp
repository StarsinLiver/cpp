// Todo : 포인터 연산자 오버로딩

// 포인터를 기반으로 하는 연산자 모두를 포인터 연산자라 한다. 그런데 그 중에서도 대표적인 포인터 연산자 둘은 다음과 같다.

// -> 포인터가 가리키는 객체의 맴버에 접근
// *  포인터가 가리키는 객체에 접근

// 이 두 연산자의 오버로딩은 일반적인 연산자의 오버로딩과 크게 차이가 없으니 (달리 말하면 , 차이가 좀 있다.)
// 그 자체만 가지고는 부담을 가질 필요가 없다. 다만, 둘 다 피연산자가 하나인 단항 연산자의 형태로 오버로딩 된다는 특징만 기억하면 된다.

// 그럼 간단히 두 연산자를 오버로딩 해보자

#include <iostream>
using namespace std;

class Number
{
private:
  int num;

public:
  Number(int n) : num(n) {}
  void ShowData() const { cout << num << endl; }

  Number *operator->()
  {
    return this;
  }

  Number &operator*()
  {
    return *this;
  }
};

int main(int argc, char const *argv[])
{
  Number num(20);
  num.ShowData();

  (*num) = 30;
  num->ShowData();

  (*num).ShowData();
  return 0;
}

/*
20
30
30
*/

// 위의 예제에서 다음 두 문장은
(*num) = 30;
num->ShowData();

// 각각 다음과 같이 해석된다.

(num.operator*()) = 30;
(num.operator*()).ShowData();

// 이는 오버로딩 된 다른 연산자들의 해석방법과 차이가 없으니 어려울 게 없다. 그런데 다음 문장에

num->ShowData();

// 일반적인 해석의 방법을 적용하면 다음과 같다

num.operator->() ShowData();

// 그런데 맴버함수 operator->() 반환하는 것은 주소 값이니 ShowData 함수의 호출은 문법적으로 성립하지 않는다.
// 때문에 반환되는 주소 값을 대상으로 적절한 연산이 가능하도록 -> 하나더 추가하여 다음과 같이 해석이 되어야 한다.

num.operator->()->ShowData();

// operator-> 함수가 반환하는 것이 주소 값이니, 이를 통한 맴버의 접근을 위해서 -> 연산자를 하나 더 추가시켜서 해석한 것이다. 
// 자! 이로써 포인터 관련 * 연산자와 > 연산자의 오버로딩 방법에 대해서 설명하였다.
