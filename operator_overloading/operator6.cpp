// Todo : 배열의 인덱스 연산자 오버로딩
// Todo : 배열보다 나은 배열 클래스
// C ,C++ 의 기본 배열은 다음의 단점을 지니고 있다.

// "경계 검사를 하지 않는다."

// 때문에 다음과 같은 엉뚱한 코드가 만들어 질 수도 있다. 컴파일도 되고 , 실행도 무리 없이 진행되기 때문이다
// #include <iostream>
// using namespace std;

int main(int argc, char const *argv[])
{
  int arr[3] = {1, 2, 3};
  cout << arr[-1] << endl; // arr의 주소 + sizeof(int) * -1 의 위치에 접근
  cout << arr[-2] << endl; // arr의 주소 + sizeof(int) * -2 의 위치에 접근
  cout << arr[3] << endl;
  cout << arr[4] << endl;
  return 0;
}

/*
5679216
0
15679152
0
*/

// 물론 이러한 특성이 유용하게 활용될 수도 있지만, 지금은 부정적인 측면을 보자

// 이러한 단점의 해결을 위해서는 "배열 클래스"라는 것을 디자인 해 볼텐데, 배열 클래스라는 것은 '배열의 역할을 하는 클래스'를 의미한다.
// 그런데 이에 앞서 배열 요소에 접근에 사용되는 []연산자의 오버로딩에 대해 알아보자

// Todo : [] 연산자
// arrObject[2]; 는 어떻게 해석을 해야 할까?

// - 객체 arrObject 의 맴버 함수 호출로 이어진다.
// - 연산자가 [] 이므로 맴버 함수의 이름은 'operator[]' 이다.
// - 함수 호출 시 전달되는 인자의 값은 정수 2이다.

// 그럼 위의 연산자는
// int operator[] (int idx) {...} 로 arrObject[2] 는

// arrObject.operator[](2); 라는 것을 알 수 있다.

// [] 연산자에 뭔가를 넣어야 할 것만 같은 생각에 위의 문장이 어색하게 느껴지겠지만, [] 연산자가 여기서는 함수이름의 일부로 사용되었다는 사실만 인식한다면, 어렵게
// 느끼지 않아도 된다.

#include <iostream>
#include <cstring>
using namespace std;

class BoundCheckIntArray
{
private:
  int *arr;
  int arrlen;

public:
  BoundCheckIntArray(int len) : arrlen(len)
  {
    arr = new int[len];
  }

  int &operator[](int idx)
  {
    if (idx < 0 || idx >= arrlen)
    {
      cout << "Array index out of bound exception" << endl;
      exit(1); // 예외 던짐
    }
    return arr[idx];
  }
  ~BoundCheckIntArray()
  {
    delete[] arr;
  }
};

int main(int argc, char const *argv[])
{
  BoundCheckIntArray arr(5);
  for (int i = 0; i < 5; i++)
    arr[i] = (i + 1) * 11;
  for (int i = 0; i < 6; i++)
    cout << arr[i] << endl;

  return 0;
}

/*
11
22
33
44
55
Array index out of bound exception
*/

// 예제에서 보이듯이, 실행결과를 통해서 잘못된 배열접근이 있었음이 확인된다.
// 때문에 위 유형의 클래스 정의를 통해서 배열접근의 안전성을 보장받을 수 있다.
// 그리고 만약에 안전성을 더 높이기 위해서 다음과 같은 코드의 실행을 허용하지 않고자 한다면,

int main(int argc, char const *argv[])
{
  BoundCheckIntArray arr(5);
  for (int i = 0; i < 5; i++)
    arr[i] = (i + 1) * 11;

  BoundCheckIntArray cpy1(5);
  cpy1 = arr; // 안전하지 않는 코드 
  BoundCheckIntArray copy = arr; // 역시 안전하지 않는 코드

  return 0;
}

// 다음과 같이 복사 생성자와 대입 연산자를 private 로 선언하여, 복사 또는 대입을 원천적으로 막을 수 도 있다.
class BoundCheckIntArray {
  private :
  int *arr;
  int arrlen;

  BoundCheckIntArray(const BoundCheckIntArray& arr) {}
  BoundCheckIntArray& operator= (const BoundCheckIntArray& arr ) {}

  public :
  ...
}

// BoundCheckIntArray 클래스 객체의 복사 또는 대입은 얕은 복사로 이어지기 때문에, 단순히 코드만 놓고 보면, 깊은 복사가 진행되도록 복사 생성자와 대입
// 연산자를 별도로 정의해야 한다고 생각할 수 있다. 그러나 배열은 저장소의 일종이고, 저장소에 저장된 데이터는 '유일성'이 보장되어야 하기 때문에
// 대부분의 경우 저장소의 복사는 불필요하거나 잘못된 일로 간주된다.
// 따라서 깊은 복사가 진행되도록 클래스를 정의할 것이 아니라, 위의 코드에서 보이듯이 빈 상태로 정의된 복사 생성자와 대입 연산자를
// private 맴버로 둠으로써 복사와 대입을 원천적으로 막는 것이 좋은 선택이 되기도 한다.
