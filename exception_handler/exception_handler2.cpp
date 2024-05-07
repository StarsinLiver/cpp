// Todo : 어설션을 이용한 예외 처리
// 어설션(assertion)은 코드를 검증하여 예상치 못한 상황에서 프로그램 동작을 중단시키는 도구로 안전성과
// 신뢰성을 높여 줍니다.
// C++ 에서는 <cassert> 헤더에 정의된 assert 매크로를 통해 예외를 비교적 간단하게 처리가 가능합니다.
// assert는 디버그 모드에서 오류가 생길 수 있는 부분을 검사할 수 있는 매크로이다.

#include <iostream>
#include <cassert>

using namespace std;

void print_number(int *_pt_int)
{
  // Todo : 디버그 모드에서 _pt_int 가 널인지 검사
  assert(_pt_int != NULL);
  cout << *_pt_int << endl;
}

int main(int argc, char const *argv[])
{
  int a = 100;
  int *b = NULL;
  int *c = NULL;

  b = &a;

  print_number(b);

  // c 는 NULL 인채로 인자 전달
  print_number(c);

  return 0;
}

/*
Expression: _pt_int != NULL
*/