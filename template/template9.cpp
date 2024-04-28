// Todo : 템플릿 인자
// Todo : 템플릿 매개변수에는 변수의 선언이 올 수 있습니다.

template <typename T, int len>
class SimpleArray
{
private:
  T arr[len];

public:
  T &operator[](int idx)
  {
    return arr[idx];
  }
};

// 이렇듯 템플릿 매개변수에도 변수가 올 수 있다. 그리고 이를 기반으로 다음의 형태로 객체생성이 가능하다.
SimpleArray<int, 5> i5arr;
SimpleArray<double, 7> d7arr;

// 위의 두 문장에서 템픞릿 매개변수 len 에 전달된 인자 5 와 7 은 해당 템플릿 클래스에서 상수처럼 사용된다.
// 즉, len 은 각각 5와 7로 치환되어, 컴파일러에 의해서 다음과 같이 SimpleArray<int,5> 처럼 각각 생성이 된다.

template <int, 5>
class SimpleArray
{
private:
  int arr[5];

public:
  int &operator[](int idx)
  {
    return arr[idx];
  }
};

// "위에서 보인 것 처럼 배열의 길이를 결정하기 위해서 굳이 템플릿 매개변수에 정수를 전달하는 피곤한 작업까지는 하지 않아도 될것같은데요? 생성자를 이용하면 안되나요?"
#include <iostream>
using namespace std;

template <typename T, int len>
class SimpleArray
{
private:
  T arr[len];

public:
  T &operator[](int idx) { return arr[idx]; }
  SimpleArray<T, len> &operator=(const SimpleArray<T, len> &ref)
  {
    for (int i = 0; i < len; i++)
    {
      arr[i] = ref.arr[i];
    }
  }
};

int main(int argc, char const *argv[])
{
  SimpleArray<int, 5> i5arr1;
  for (int i = 0; i < 5; i++)
    i5arr1[i] = i * 10;

  SimpleArray<int, 5> i5arr2;
  i5arr2 = i5arr1;
  for (int i = 0; i < 5; i++)
    cout << i5arr2[i] << " , ";

  cout << endl;
  return 0;
}

/*
0 , 10 , 20 , 30 , 40 ,
*/

// 이 예제에서 주목할 사실은 다음과 같다
// "SimpleArray<int , 5> 와 SimpleArray<int , 7>은 서로 다른 형(type) 이다."

int main(int argc, char const *argv[])
{
  SimpleArray<int, 5> i5arr;
  SimpleArray<int, 7> i7arr;
  i5arr = i7arr; // Todo : 컴파일 에러
  return 0;
}

// 때문에 길이가 다른 두 배열 객체간의 대입은 허용되지 않는다.
// 이렇듯, 템플릿 매개변수에 값을 전달받은 수 있는 변수를 선언하면, 변수에 전달되는 상수를 통해서 서로 다른 형의 클래스가 생성되게 할 수 있다.
// 길이가 다른 두 배열 객체간의 대입 및 복사에 대한 부분을 신경쓰지 않아도 된다.
// 만약에 생성자를 이용해서 배열의 길이를 결정하게 했다면, 길이가 같은 배열에 대해서만 대입을 허용하기 위해서 추가적인 코드의 삽입이 불가피하며,
// 이러한 추가적인 코드는 대입 및 복사의 과정에서 CPU 가 수행해야 할 일을 더 늘리는 결과로 이어진다.
