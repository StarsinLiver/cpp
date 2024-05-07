// Todo : 3방향 비교 연산자 (three_way_comparison)
// Todo : 객체 간 비교 연산
// 객체 간의 비교 연산은 operator= 을 오버로딩 후 객체를 비교가 가능하다

// Todo : 우주선 연산자
// 객체 간 비교 연산은 operator= 을 오버로딩 해야 한다면 3방향 비교 연산자는 이처럼 복잡한 과정을 단순하게 해줍니다.
// 비교 연산자 6개를 모두 오버로딩할 필요없이 3방향 비교 연산자 <=> 하나만 오버로딩 하면 됩니다.
// 그러면 컴파일러가 나머지 연산자를 모두 오버로딩해 줍니다. 참고로 <=> 연산자는 우주선 모양과 비슷하다고 해서 흔히 '우주선 연산자'라고도 합니다.

// auto result = obj_a <=> obj_b;

// 다음 코드는 정수와 문자로 구성된 구조체 배열에서 원소의 크기를 비교한 예시입니다.
// 3방향 비교 연산자를 사용하려면 소스에 <compare> 헤더를 포함해야 합니다

#include <compare>
#include <iostream>
using namespace std;

typedef struct _tag {
  int number;
  char alphabt;
  auto operator<=> (const _tag &object) const {
    return number <=> object.number;
  }
};

using DATA  = struct _tag; // 구조체를 DATA 로 사용하기 위해 선언

DATA data_element[5] = {{4, 'a'} , {1, 'c'} , {8, 'b'} , {2, 'z'} ,{4, 'd'}};

int main(int argc, char const *argv[])
{
  cout<<boolalpha<<"0번째가 3번째 원소보다 큽니다 : ";
  cout<<((data_element[0] <=> data_element[3]) > 0)<<endl;

  cout<<boolalpha<<"1번째가 2번째 원소보다 큽니다 : ";
  cout<<((data_element[1] > data_element[2]))<<endl;
  return 0;
}

/*
0번째가 3번째 원소보다 큽니다 : true
1번째가 2번째 원소보다 큽니다 : false
*/

// Todo : 코드 분석
// 코드에서 구조체의 정수형 맴버인 number 를 비교하는 3방향 비교 연산자를 오버로딩 했습니다.
// 3방향 비교 연산자는 두 피연산자를 비교해 같으면 0 , 앞쪽 피연산자가 작으면 -1 , 크면 1을 반환합니다.
// 만약 비교가 불가능하면 -128(unordered)를 반환합니다.

// 그런데 <=>연산자가 실제 반환하는 데이터 형식은 구조체에서 정의된 맴버 상수임에 주의해야 합니다. 피연산자의 형식에 따라 구조체의 상수 가운데 하나를 반환합니다.
// 예를 들어 크기가 명확한 정수형 연산에서는 강한 비교 결과로 strong_ordering 구조체의 멤버 상수를 반환하고 , 부동 소수점 연산에서는 부분 비교 결과로 partial_ordering
// 의 맴버 상수를 반환합니다.

// 구분      | 구조체                | 허용 비교 연산과 결과                      | 비고
// 강한 비교 : std::strong_ordering  : >(1) , ==(0) , <(-1)                       : 정확한 값이 일치하는 객체 비교
// 약한 비교 : std::weak_ordering    : >(1) , ==(0) , <(-1)                       : 논리적 값이 일치하는 객체 비교
// 부분 비교 : std::partial_ordering : >(1) , ==(0) , <(-1), 비교불가 (unordered) : 때때로 비교 불가한 객체 비교