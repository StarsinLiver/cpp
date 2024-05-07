// Todo : 폴드 표현식 (fold expression)
// C++17 부터 도입된 폴드 표현식은 개수가 정해지지 않은 매개변수를 하나로 묶은 매개변수 팩(parameter pack)을 반복해서 계산해 줍니다.
// C++11 부터 도입된 가변 인수 템플릿(variadic templates)의 재귀 호출을 함수 하나로 표현할 수 있는 방법입니다. 폴드 표현식은 어려운 문법에 속하지만
// 소스 코드를 간결하게 만들 수 있는 좋은 방법입니다.
// 매개변수 팩과 폴드 표현식을 살펴보겠습니다.

// Todo : 매개변수 팩
// 함수의 매개변수 개수는 일반적으로 소스 코드를 작성하는 시점에 정합니다. 하지만 매개변수의 개수를 알 수 없거나 필요에 따라 가변 개수의 인자를 허용할 때가 있습니다.
// 예를 들어 c 언어에서 prinf 함수를 호출할 대를 떠올려 보면 첫 번째 인자의 형식에 따라 나머지 인자의 개수가 결정됩니다.

// 매개변수가 가변적이다.
printf("%d , %d , %d"  ,1 , 2 ,3);

// 모던 C++ 에서는 가변 인자를 허용하는 함수를 선언 할 때 템플릿과 매개변수 팩을 사용합니다.
// 매개변수 팩은 데이터 형식과 개수가 모두 정해지지 않은 템플릿 매개변수들을 하나로 묶어 주빈다.

// 다음 코드에서는 러시아 전통 인형인 마트료시카를 매개변수 팩을 이용한 가변 인자 템플릿과 재귀 호출로 구현한 예입니다.
// 이 예에서 마트료시카 인형의 구성은 find_doll 함수에 전달하는 인자의 개수에 따라 변경됩니다.

#include <iostream>
using namespace std;

template <typename doll>
void find_doll(doll doll_name)
{
  cout << "'"<< doll_name << "'(이)가";
}

// 매개변수 팩을 이용한 가변 인자 템플릿 - 재귀 함수용
template <typename doll, typename... dolls>
// find_doll 함수 오버로딩
void find_doll(doll doll_name, dolls... doll_list)
{
  cout << "'"<< doll_name << "' 안쪽에 ";
  find_doll(doll_list...);
}

int main(int argc, char const *argv[])
{
  // 첫번째 마트료시카
  cout << "첫번째 마트료시카";
  find_doll("대형", "중형", "소형");
  cout << "있습니다." << endl
       << endl;

  // 두번째 마트료시카
  cout << "두번째 마트료시카";
  find_doll("특대형","대형", "중형", "소형" , "극소형");
  cout << "있습니다." << endl
       << endl;
  return 0;
}

/*
첫번째 마트료시카'대형' 안쪽에 '중형' 안쪽에 '소형'(이)가있습니다.

두번째 마트료시카'특대형' 안쪽에 '대형' 안쪽에 '중형' 안쪽에 '소형' 안쪽에 '극소형'(이)가있습니다.
*/

// 매개변수 팩을 처리하려면 재귀함수와 마지막 매개변수를 처리할 말단 함수를 정의해야 합니다.
// 이때 두 함수의 이름은 같아야 합니다. 즉 , 하나는 오버로딩해야합니다. 이를 전제로 코드를 보면 오버로딩한 find_doll 함수의 마지막 줄에는 find_doll(doll_list...)
// 처럼 재귀 호출합니다. 이렇게 재귀 호출하면 doll_list 의 첫번째 원소가 doll_name 으로 전달되고 첫번째 원소를 제외한 원소들은 doll_list 인 매개변수 팩으로 전달됩니다.

// 따라서 이와 같은 형식이 이루어 집니다. 
// Todo : 1번째
"대형" // doll doll_name 
"중형"|"소형" // dolls... doll_list

template <typename doll, typename... dolls>
void find_doll(doll doll_name, dolls... doll_list)


// Todo : 2번째
"중형" // doll doll_name
"소형" // dolls... doll_list

template <typename doll, typename... dolls>
void find_doll(doll doll_name, dolls... doll_list)

// Todo : 3번째
"소형" // doll doll_name

template <typename doll>
void find_doll(doll doll_name)

