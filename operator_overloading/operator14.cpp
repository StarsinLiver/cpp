// Todo : 펑터의 위력
// 펑터는 함수 또는 객체의 동작방식에 유연함을 제공할 때 주로 사용된다.
// 그럼 예제를 통해 어떻게 펑터가 사용되는 지 보자

// 이 예제에서는 "버블정렬 (bubble sort)"라는 정렬 알고리즘이 사용된다

#include <iostream>
using namespace std;

class SortRule
{
public:
  virtual bool operator()(int num1, int num2) const = 0;
};

// 위의 클래스는 추상클래스로 정의되었다. 그리고 operator() 함수도 순수 가상함수로 정의되었다
// 이는 이 함수의 기능을 유도 클래스에서 확정 짓겠다는 의미이다.

// Todo : 오름차순
class AscendingSort : public SortRule
{
public:
  bool operator()(int num1, int num2) const
  {
    if (num1 > num2)
      return true;
    else
      return false;
  }
};

// 위 클래스에 정의된 operator() 함수는 두 정수의 대소비교를 진행하고 있다. num1 이 크면 true 를 그렇지 않으면 false 를 반환한다.

// Todo : 내림차순
class DescendingSort : public SortRule
{
public:
  bool operator()(int num1, int num2) const
  {
    if (num1 < num2)
      return true;
    else
      return false;
  }
};

// 위의 클래스에 정의된 operator() 함수도 두 정수의 대소비교를 진행하고 있다.

// Todo : int 형 정수의 저장소
class DataStorage
{
private:
  int *arr;
  int idx;
  const int MAX_LEN;

public:
  DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
  {
    arr = new int[MAX_LEN];
  }

  void AddData(int num)
  {
    if (MAX_LEN <= idx)
    {
      cout << "더 이상 저장이 불가능 합니다." << endl;
      return;
    }

    arr[idx++] = num;
  }

  void ShowAllData()
  {
    for (int i = 0; i < idx; i++)
      cout << arr[i] << ' ';
    cout << endl;
  }

  void SortData(const SortRule &functor)
  {
    for (int i = 0; i < (idx - 1); i++)
    {
      for (int j = 0; j < (idx - 1); j++)
      {
        if (functor(arr[j], arr[j + 1])) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }
};

int main(int argc, char const *argv[])
{
  DataStorage storage(5);
  storage.AddData(40);
  storage.AddData(30);
  storage.AddData(50);
  storage.AddData(20);
  storage.AddData(10);

  storage.SortData(AscendingSort());
  storage.ShowAllData();

  
  storage.SortData(DescendingSort());
  storage.ShowAllData();
  return 0;
}

/*
10 20 30 40 50 
50 40 30 20 10 
*/

// 매개변수 형이 SortRule 의 참조형이므로 , SortRule 클래스를 상속하는 AscendingSort 와 DescendingSort 의 객체는 인자로 전달이 가능하다.
// 그리고 SortRule 의 operator() 함수는 virtual 로 선언되었으니, 유도 클래스의 operator() 함수가 대신 호출된다.

