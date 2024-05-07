// Todo : 찾기 (std::find)
// std::find 는 순차 컨테이너에서 원하는 값을 찾는 함수입니다. find 함수는 <algorithm> 헤더에 다음처럼 정의되어 있습니다

// find 함수는 first ~ last 범위에서 value 와 일치하는 첫번째 원소를 가리키는 반복자를 반환합니다.
// 만약 일치하는 원소를 찾지 못하면 last 를 반환합니다.

// find 함수는 선형 검색(linear search)을 기반으로 동작합니다. 선형 검색은 입력 범위를 처음부터 끝까지 차례로 탐색하면서 원하는 값을 찾습니다.
// 따라서 검색 범위의 크기에 비례하는 시간이 걸리므로 데이터가 많을 때는 효율적이지 않을 수 있습니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> number = {1, 2, 3, 4, 5};

  int target = 3;

  vector<int>::iterator it = find(number.begin(), number.end(), target);

  if (it != number.end())
  {
    cout << "찾은 위치 : " << distance(number.begin(), it) << endl;
    cout << "it : " << *it << endl;
  } else {
    cout<<"찾을 수 없음"<<endl;
  }
  return 0;
}

/*
찾은 위치 : 2
it : 3
*/

// find 함수는 두 값이 같은지 판달할 때 operator == 을 사용합니다.
// 따라서 찾고자 하는 값과 컨테이너 내의 각 원소를 == 연산자로 비교합니다. 만약 사용자 정의 타입의 객체를 비교하려면 == 연산자를 오버로딩해야합니다.

// Todo : 객체 find
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class People {
  private :
  int age;
  string name;

  public :

  People(int p_age , string p_name) : age(p_age) , name(p_name) {}
  
  bool operator== (const People& other) const {
    return other.age == this -> age && other.name == this -> name;
  }
};

int main(int argc, char const *argv[])
{
  vector<People> peoples = { {1, "hi"} , {2 , "san"}};


  vector<People>::iterator it = find(peoples.begin(), peoples.end(), People(2 , "san"));

  if (it != peoples.end())
  {
    cout << "찾은 위치 : " << distance(peoples.begin(), it) << endl;
  } else {
    cout<<"찾을 수 없음"<<endl;
  }
  return 0;
}

/*
찾은 위치 : 1
*/