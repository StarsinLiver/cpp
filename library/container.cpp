// Todo : 대표적인 컨테이너
// 1. 순차 컨테이너 : 데이터가 순서대로 삽입이 되는 컨테이너
// 2. 연관 컨테이너 : 데이터가 오름차순/내림차순처럼 미리 정의된 순서로 삽입되는 컨테이너
// 3. 컨테이너 어댑터 : 순차, 연관 컨테이너와 다르게 특별한 자료 구조를 표현한 컨테이너

// Todo : 순차 컨테이너
// 1. array : 표준 C 언어 스타일 배열
// 2. vector : 활용도가 높은 기본 컨테이너
// 3. list : 연결 리스트
// 4. deque : 양뱡향 큐

// Todo : 배열 std::array
// C++11 에서 소개된 array 는 고정된 크기의 배열을 담는 컨테이너입니다.

#include <array>
array<데이터_형식,크기> 객체_이름;
array<int , 5> myArray {1,2,3,4,5};

// 연산자[] 또는 at() 로 접근이 가능합니다.
객체_이름[0];

// Todo : 백터 std::vector
// vector 컨테이너는 <vector> 헤더의 std 네임스페이스에 정의되어 있으며 다음처럼 선언해 사용합니다.
// 그리고 선언할 때 크기를 지정하지 않을 수도 있고 지정할 수도 있으며,
// 크기와 초깃값, 중괄호를 이용한 유니폼 초기화도 가능합니다.
#include <vector>
using namespace std;

vector <데이터_형식> 객체이름;
vector <데이터_형식> 객체이름(크기);
vector <데이터_형식> 객체이름(크기 , 초기값);
vector <데이터_형식> 객체이름 = {값1 , 값2 , 값3 ...};

// 원소는 [] 연산자 또는 at 함수로 접근이 가능합니다.
vector[1];
vector.at(1);

// 원소 추가는 push_back으로 백터의 크기는 동적이므로 힙 메모리가 허용하는 한 늘릴 수 있으며
// push_back 함수를 통하여 벡터의 끝에 원소를 계속 추가할 수 있습니다.
vector.push_back(100); // vector 맨 뒤에 100 추가

// 백터의 모든 원소 출력
for(vector::iterator it = vec.begin(); it != vec.end(); it++)

// 리버스 반복자
for(vector<T>::revecse_iterator it = vec.rbegin(); it != vec.rend(); it++)

// insert 함수와 erase 함수에 반복자를 전달하면 새로운 원소를 추가하거나 지울 수 있습니다.
vec.insert(vec.begin() +3 , 25); // vector[3] 앞에 25 추가
vec.erase(vec.begin() + 3); // vector[3] 제거

// Todo : 리스트 std::list
// C++의 std::list 는 연결 리스트라는 데이터 구조를 구현한 컨테이너 입니다.

#include <list>
using namespace std;

list<int> myList;

myList.push_back(100);
myList.push_front(199);

myList.pop_front();
myList.pop_back();

myList.size();
myList.empty();


// Todo : 덱 std::deque
// 마지막 컨테이너인 deque 는 배열기반의 컨테이너이며 벡터 컨텡너와 유사합니다.
// 벡터는 하나의 메모리 블록에 원소들을 저장하는 구조입니다. 따라서 새로운 원소를 추가할 때
// 공간이 부족하면 메모리를 재할당한 후에 이전 원소들을 모두 복사합니다.

// 반면, deque 컨테이너는 여러 개의 메모리 블록으로 나눠서 저장하는 것이 특징입니다.
// 저장할 공간이 부족하면 일정한 크기의 새로운 메모리 블록을 만들어서 연결합니다.
// 따라서 벡터 컨테이너에서 일어나는 복사 저장이 발생하지 않습니다.

// 즉, deque 는 벡터의 단점을 보안하는 컨테이너 입니다.

//! 함수는 위와 비슷합니다.