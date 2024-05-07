// Todo : 연관 컨테이너
// 연관 컨테이너는 데이터를 저장하고 검색할 때에 사용됩니다.
// 특정 키 (key)를 사용하여 데이터를 효율적으로 검색할 수 있습니다.
// 연관 컨테이너의 내부 구조는 트리나 해시 테이블과 같은 최적화된 데이터 구졸르 사용하므로
// 검색시간 복잡도가 O(log n)또는 O(1) 에 가깝습니다.

// 이러한 구조 덕에 대량의 데이터에서도 빠르게 검색할 수도 있으며, 실시간 또는 반응형 시스템에서
// 매우 유용합니다.

// 1. set : 중복된 값 허용하지 않음
// 2. multiset : 중복된 값 허용
// 3. map : 키와 값이 서로 쌍으로 구성
// multimap : 중복된 키 허용


// Todo : set (std::set) <set>
// set 은 연관 컨테이너에 속하지만 내부적으로는 이진 탐색 트리를 사용하여 원소를 저장하고 정렬된 순서를 유지하는 
// 정렬 컨테이너(sorted container)이기도 합니다.

#include <set>
using namespace std;
set<int> mySet;
mySet.insert(5);
mySet.size();
mySet.find(5);
mySet.end();

// ..

// Todo : 멀티 세트 (std::multiset)
// std::multiset 도 std::set처럼 정렬된 세트 자료 구조를 구현하는 연관 컨테이너이지만,
// 중복된 값을 포함하는 차이가 있습니다.
#include <set>
using namespace std;
multiset<int> myMultiSet;

myMultiSet.count(5); // 특정 값의 개수 출력

// ...

// Todo : 맵 (std::map)
// 키 값 쌍

#include <map>
#include <cstring>

std::map<std::키_형식 , 값 형식> myMap;
std::map<std::string , int> myMap2;

// 원소 삽입 std::make_pair
myMap.insert(std::make_pair("Bob" , 25));

// ...

// Todo : 멀티 맵 (std::multiMap)
// 키 - 값 쌍으로 구성된 맵을 구현하는 연관 컨테이너지만, 중복된 값을 허용한다는 차이가 있습니다.

// 특징은 다음과 같습니다.
// 1. 중복된 키 저장
// 2. 자동 정렬 : 멀티 맵은 내부적으로 키를 기준으로 정렬됩니다.
// 3. 이진 탐색 트리 : 멀티맵은 이진 탐색 트리 자료 구조를 기반으로 구현되어 검색,삽입,삭제 등의 수행

// 키에 해당하는 원소의 범위 구하기 - equeal_range
// 범위는 (first , last) 형태의 반복자 쌍으로 표현되며, first 는 첫번째 원소를 가리키는 반복자이며
// last 는 범위에서 끝을 가리키는 반복자 입니다.
#include <map>
#include <cstring>
std::multiMap<std::string , int> scores;
scores.insert(std::make_pair("Bob" , 25));

auto range = scores.equal_range("Bob"); // 특정 키를 가진 원소의 범위 구하기
range.first; // ...

