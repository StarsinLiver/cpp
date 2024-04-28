// Todo : const 함수를 이용한 오버로딩의 활용
// 앞서 정의한 BoundCheckIntArray  클래스에는 제약이 존재하는 데 이를 확인해 보자
// 참고로 이 예제에서는 앞서 간단히 정의한 BoundCheckIntArray 클래스에 배열의 길이를 반환하는 함수를 추가하였다.

#include <iostream>
#include <cstring>
using namespace std;

class BoundCheckIntArray
{
private:
  int *arr;
  int arrlen;
  BoundCheckIntArray(const BoundCheckIntArray &arr) {}            // 복사 생성자 막음
  BoundCheckIntArray &operator=(const BoundCheckIntArray &arr) {} // 대입 연산자 막음

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

  // 추가
  int GetArrLen() const { return arrlen; }

  ~BoundCheckIntArray()
  {
    delete[] arr;
  }
};

void ShowAllData(const BoundCheckIntArray &ref)
{
  int len = ref.GetArrLen();
  for (int i = 0; i < len; i++)
    cout << ref[i] << endl; // Todo : 컴파일 에러
}

int main(void)
{
  BoundCheckIntArray arr(5);
  for (int i = 0; i < 5; i++)
    arr[i] = (i + 1) * 11;

  ShowAllData(arr);
}

// Todo : 컴파일 에러 -> const 오버로딩으로 해결!

// 위 예제에는 BoundCheckIntArray 객체의 배열에 저장된 모든 요소를 출력하는 ShowAllData 함수가 추가 되었는데
// 함수 내에서 배열에 저장된 데이터를 변경하지 못하도록 매개변수 형이 const 로 선언되었다면

// 이때 호출되는 operator[] 함수도 const 되어야 할 것이다.

// 위의 예제를 다음과 같이 확장이 가능하다. 다음 예제에서는 const 의 선언 유무를 이용해서 operator[] 함수를 오버로딩 하고 있다.

#include <iostream>
#include <cstring>
using namespace std;

class BoundCheckIntArray
{
private:
  int *arr;
  int arrlen;
  BoundCheckIntArray(const BoundCheckIntArray &arr) {}            // 복사 생성자 막음
  BoundCheckIntArray &operator=(const BoundCheckIntArray &arr) {} // 대입 연산자 막음

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

  int &operator[](int idx) const
  {
    if (idx < 0 || idx >= arrlen)
    {
      cout << "Array index out of bound exception" << endl;
      exit(1); // 예외 던짐
    }
    return arr[idx];
  }

  // 추가
  int GetArrLen() const { return arrlen; }

  ~BoundCheckIntArray()
  {
    delete[] arr;
  }
};

void ShowAllData(const BoundCheckIntArray &ref)
{
  int len = ref.GetArrLen();
  for (int i = 0; i < len; i++)
    cout << ref[i] << endl;
}

int main(void)
{
  BoundCheckIntArray arr(5);
  for (int i = 0; i < 5; i++)
    arr[i] = (i + 1) * 11;

  ShowAllData(arr);
}

/*
11
22
33
44
55
*/
