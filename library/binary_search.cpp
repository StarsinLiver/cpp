// Todo : 이진 탐색 (std::bianry_search)
// find 함수는 선형 검색(linear search)을 기반으로 동작합니다. 선형 검색은 입력 범위를 처음부터 끝까지 차례로 탐색하면서 원하는 값을 찾습니다.
// 따라서 검색 범위의 크기에 비례하는 시간이 걸리므로 데이터가 많을 때는 효율적이지 않을 수 있습니다.

// 이때는 이진 탐색(binary search) 와 같은 다른 알고리즘을 사용하는 것이 빠를 수 있습니다.

// std::binary_search 함수는 정렬된 범위에서 특정 값을 이진 탐색으로 찾는 함수입니다.
// binary_search 함수는 first 부터 last 전 까지 범위에서 세 번째 매개변수로 전달받은 value 가 있는지 이진 탐색으로 확인합니다.

// 이진 탐색이란 탐색 범위를 반으로 나눠 범위를 좁혀 가는 방식으로 동작하는 알고리즘 입니다.

// binary_search 함수는 find 함수와 매개변수 구성 , 사용법이 같습니다. 하지만 find 정렬 여부와 상곤없이 선형으로 검색하지만, binarysearch 는 정렬된 범위에서
// 빠른 이진 탐색을 수행합니다. 따라서 binary_search 함수를 사용하려면 컨테이너를 정렬해야 합니다.
// 만약 정렬되지 않은 상태에서 binary_search 를 사용하면 검색 겨로가가 불확실하거나 검색을 아예 실패할 가능성이 있습니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> vec = {5, 3, 1, 4, 6, 2, 7, 8};

  int target = 4;

  // 정렬
  sort(vec.begin(), vec.end());

  // 이진탐색
  bool found = binary_search(vec.begin() , vec.end() , target);

  if(found) {
    cout<<"찾았습니다."<<endl;
  }
  else {
    cout<<"검색 결과가 없습니다."<<endl;
  }
  return 0;
}
