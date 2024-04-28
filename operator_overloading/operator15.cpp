// Todo : 임시객체로의 자동 형 변환과 형 변환 연산자(Conversion Operator)
// 이제 마지막으로 형 변환 연산자의 오버로딩에 대해서 소개하겠다.

#include <iostream>
using namespace std;

class Number
{
private:
  int num;

public:
  Number(int n = 0) : num(n) {}
  void ShowNumber() const { cout << num << endl; }
}

int
main(int argc, char const *argv[])
{
  Number num1(100);
  Number num2(0); // 동일 자료형의 객체간 대입연산
  num2 = num1;
  num2.ShowNumber();
  return 0;
}

/*
100
*/

// 그런데 만약 이것이라면?
Number num;
num = 30;

// 일치하지 않는 자료형간의 대입연산이 되어 버린다.
// Todo : 그렇다면 대입 연산자에 대한 예시를 살펴보자
#include <iostream>
using namespace std;

class Number
{
private:
  int num;

public:
  Number(int n = 0) : num(n) {}
  void ShowNumber() const { cout << num << endl; }

  Number &operator=(const Number &ref)
  {
    cout << "operator=()" << endl;
    num = ref.num;
    return *this;
  }
};

int main(int argc, char const *argv[])
{
  Number num;
  num = 30;
  num.ShowNumber();
  return 0;
}

/*
30
*/

// 출력 결과를 통해서 위의 예제를 조금 풀어서 써보자
num = Number(30);
num.operator=(Number(30));

// 여기서의 핵심은 임시객체의 생성이다. 그리고 이러한 임시객체의 생성을 통해서 대입연산이 진행되는데에는 다음과 같은 문법적 기준이 존재한다.

// "A 형 객체가 와야할 위치에 B 형 데이터 (또는 객체)가 왔을 경우, B 형 데이터를 인자로 전달받는 A형 클래스의 생성자 호출을 통해서 A 형 임시객체를 생성한다."

// 때문에 위의 예제에서는 'Number 형 객체가 와야할 위치에 int 형 데이터가 와서, int 형 데이터를 인자로 전달받는 Number 클래스의 생성자 호출을 통해서 Number 형
// 임시객체를 생성한 것이다.'

// Todo : 이렇듯 기본 자료형 데이터를 객체로 형 변환하는 것은 적절한 생성자의 정의를 통해서 얼마든지 가능하다.
// Todo : 그렇다면 반대로 객체를 기본자료형 데이터로 형 변환하는 것도 가능할까? 가능하다!

// 예를 들어 앞서 정의한 Number 클래스를 대상으로 다음과 같은 덧셈 연산이 가능하려면
int main(int argc, char const *argv[])
{
  Number num1;
  num1 = 30;
  Number num2 = num1 + 20;
  num2.ShowNumber();
  return 0;
}

// Number 클래스가 + 연산자를 오버로딩하거나 , num1 이 int 형 데이터로 변환되어야 한다.

// Todo : int 형 데이터로 변환되어서 뎃셈 연산을 진행해보자
#include <iostream>
using namespace std;

class Number
{
private:
  int num;

public:
  Number(int n = 0) : num(n)
  {
    cout << "Number(int n = 0)" << endl;
  }
  void ShowNumber() const { cout << num << endl; }

  Number &operator=(const Number &ref)
  {
    cout << "operator=()" << endl;
    num = ref.num;
    return *this;
  }

  // int 형 데이터 변환
  operator int()
  {
    return num;
  }
};

int main(int argc, char const *argv[])
{
  Number num1;
  num1 = 30;
  Number num2 = num1 + 20;
  num2.ShowNumber();
  return 0;
}

/*
Number(int n = 0)
Number(int n = 0)
operator=()
Number(int n = 0)
50
*/

// 위 예제에서 정의한 형 변환 연산자는 다음과 같다.
// int 형 데이터 변환
operator int()
{
  return num;
}

// 이렇듯 형 변환 연산자는 반환형을 명시하지 않는다. 하지만 return 문에 의한 값의 반환은 얼마든지 가능하다.
// 그리고 오버로딩 된 연산자의 이름이 operator+ 이면 , + 연산자가 등장했을 대 호출되는 것과 유사하게 operator int 는 다음의 의미로 이해하면 된다.

// "int 형으로 형 변환해야 하는 상황에서 호출되는 함수이다."

// 즉 , int 형으로 형 변환되어야 하는 상황에서 호출이 되며, 이때 return 문에 의해 반환되는 값이 int 형으로의 형 변환 결과가 되는 것이다.
Number num2 = num1 + 20;

// 위의 문장 실행과정에서 num1 객체의 operator int 함수가 호출되어 이때 반환되는 값 30 과 20의 덧셈연산이 진행되며 연산의 결과로
// num2 객체가 생성된 것이다.