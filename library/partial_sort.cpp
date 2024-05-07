// Todo : 부분 정렬 (std::partial_sort)
// 컨테이너의 모든 원소가 아닌 일정 구간만 정렬할 때는 partial_sort 함수를 사용합니다.
// partial_sort 함수는 지정한 원소까지만 정렬하고 나머지 뒤쪽은 정렬하지 않습니다.
// partial_sort 함수는 <algorithm> 헤더에 정의되어 있습니다.

//! 정의 (C++20 기준)
template <class RandomIt>
constexpr void partial_sort(RandomIt first, RandomIt middle, RandomIt last);

// first : 정렬을 시작할 범위의 시작을 가리키는 반복자
// middle : 정렬을 원하는 범위의 끝을 가리키는 반복자. 정렬 후에 이 반복자가 가리키는 위치 이전의 원소들은 정렬되지만,
// 이후 원소들은 순서가 보장되지 않음
// last : 정렬을 종료할 범위의 끝을 가리키는 반복자

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> number = {7, 2, 4, 1, 6, 5, 3};

  partial_sort(number.begin() , number.begin() + 3 , number.end());

  for(vector<int>::const_iterator it = number.begin(); it != number.end(); ++it) {
    cout<< *it << " ";
  }

  cout<< endl;
  return 0;
}

/*
1 2 3 7 6 5 4 
*/

