// Todo : 알고리즘
// 표준 라이브러리에서 알고리즘은 컨테이너의 멤버함수가 아닌 일반 함수로 제공되며,
// 컨테이너의 구조와 상관없이 독립적으로 동작합니다.

// 1. 정렬 : 컨테이너의 원소 정렬
// 2. 검색 : 원소의 존재를 확인하거나 특정 원소를 검색
// 3. 변환 : 원소를 수정하거나 다른 형식으로 변환
// 4. 반복자 : 컨테이너의 원소를 순회하고 조작
// 5. 집계 : 컨테이너의 원소를 집계하거나 요약

// Todo : 정렬 라이브러리

// Todo : 퀵 정렬 (std:sort)
// 기본 정렬 함수인 sort 는 퀵 정렬(quick sort) 기반으로 구현되었습니다.

//! sort 함수는 <algorithm> 헤더에 다음처럼 정의되어 있습니다. (c++ 20 기준)
template <class RandomIt>
constexpr void sort(RandomIt first, RandomIt last);

// first 와 last 매개변수의 형식으로 지정된 RandomIt 은 임의 접근 반복자 (random access iterator)를 의미합니다
// 임의 접근 반복자는 컨테이너에 원소가 어디에 저장되어 있든 상관없이 한번에 접근할 수 있습니다.
// array[index] , vector[index]를 떠올리면 이해가 쉽습니다.

// 반면에 리스트는 std::list 의 순방향 반복자만 지원하므로 list[index]처럼 임의의 위치에 있는 원소로 한번에 접근할 수 없습니다.

// 따라서 sort 함수는 std::array 나 std::vector 처럼 임의 접근 반복자를 지원하는 컨테이너를 대상으로만 사용할 수 있으며 std::list 처럼 원소에 차례로 접근해야하는
// 컨테이너에는 sort 함수를 사용할 수 없습니다.

// 만약 정렬 순서(비교 기준)를 별도로 지정하고 싶을 때는 다음처럼 오버로딩 된 sort 함수를 호출하면서 세 번째 매개변수로 정렬 순서를 지정하는 비교함수나
// 함수 객체를 전달하면 됩니다.

// 이때 비교 함수는 2개의 값을 받아서 첫번째 값과 두번째 값을 비교한 후 true 나 false 를 반환하도록 만들면 됩니다.

//! 정렬 순서를 지정하는 sort 함수 원형 (C++20 기준)
template <class RandomIt, class Compare>
constexpr void sort(RandomIt first, RandomIt last, Compare comp);

// Todo : constexpr
// constexpr 이란 함수, 변수 , 상수 표현식의 값이 컴파일 타입에 결정됨을 나타내는 키워드 입니다.
// sort 함수 처럼 constexpr 키워드로 지정된 함수는 런타임에 실행되는 일반 함수와 달리 컴파일 타입에 값을 계산합니다.
// 따라서 실행할 때는 더 빠를 수 있습니다.

// Todo : 오름차순으로 정렬하기 - sort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void print_vector_all(vector<T> &vec)
{
  for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
  {
    cout << *it << " ";
  }

  cout << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> vec = {7 ,6 ,2,3,6, 1 ,0};

  sort(vec.begin() , vec.end());

  print_vector_all(vec);

  return 0;
}

/*
0 1 2 3 6 6 7 
*/