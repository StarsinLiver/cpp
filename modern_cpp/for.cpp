// Todo : 범위 기반 for 문

#include <iostream>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{
  array<int , 10> numbers {7 , 8 , 2 , 5 , 3 , 9 , 0 , 4 , 1 , 6};

  for(auto &value : numbers) {
    cout<<value << " , ";
  }

  cout <<endl;
  return 0;
}

/*
7 , 8 , 2 , 5 , 3 , 9 , 0 , 4 , 1 , 6 , 
*/

// Todo : 범위 기반 for 문 활용
// 1. 데이터 집합 원소 복사 : for (auto 변수_이름 : ...)
// 2. 데이터 집합 원소 참조 : for(auto &변수 이름 : ...)
// 3. 데이터 집합 원소 상수 참조 : for(const auto &변수 이름 : ...)
// 4. 데이터 집합 원소 Rvalue 참조 : for(auto &&변수 이름 : ...)

// Todo : R-value 참조란 무엇일까?
// R-value 참조는 C++11 부터 추가된 모던 C++의 주요한 개념입니다. 하지만 내용이 복잡하고 방대한 편입니다.
// 이와 관련한 상세 내용은 std::move 나 std::forward 함수를 공부해야 합니다.

// R-value 는 임시로 만들어지거나 특정 범위에서만 존재하는 값입니다. R-value를 전달받아 사용하려면 반드시 사용하는 범위의 R-value 나 L-value 가 가리키는
// 메모리 영역에 복사하는 과정이 필요하빈다. 매우 적은 리소스가 필요한 R-value 라면 문제가 없지만, std::vector  나 std::string 처럼 리소스가 많이 필요한
// R-value 라면 복사 과정이 반복될 때 실행 성능이 떨어지게 됩니다

// 이러한 단점을 보안하고자 R-value 를 복사하지 않고 사용하는 범위(함수나 클래스 등)으로 이동할 수 있도록 한 것입니다.
// 즉, 이름 없는 객체인 R-value 는 선언 범위를 벗어나면 소멸하는 데 다른 범위에서도 사용할 수 있도록 해당 범위의 R-value 로 이동하게 하는 방법입니다.

// 범위 기반 for 문의 4번 형태에서 auto && 로 전달된 R-value 참조는 1번 형태처럼 auto 변수 사용법은 같지만, 전달 과정에서 복사가 이루어지지 않아 속도가 더 빠릅니다.
