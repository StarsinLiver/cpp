// 이름공간 (namepace) 에 대해
// 이름공간은 '이름을 붙여놓은 공간'이라는 특정 영역이다.

// [상황 예시] BeastCom 과 ProgCom 두 회사에서 정의한 함수의 이름이 같다면? 문제가 발생!

#include <iostream>

// -- 에러 발생 코드
// void SimpleFunc(void) {
//   std::cout<<"BestCom 이 정의한 함수"<<std::endl;
// }

// -- 에러 발생 코드
// void SimpleFunc(void) {
//   std::cout<<"ProgtCom 이 정의한 함수"<<std::endl;
// }

namespace BestComImpl
{
  void SimpleFunc(void);
}

namespace BestComImpl
{
  void PrettyFunc(void);
}

namespace ProgComImpl
{
  void SimpleFunc(void);
}

int main(int argc, char const *argv[])
{
  // SimpleFunc(); <-- 에러 발생

  // 따라서 namespace 를사용해서 확인해보자
  BestComImpl::SimpleFunc();
  ProgComImpl::SimpleFunc();

  // 위에서 사용한 연산자 :: 을 '범위지정 연산자(scope resolution operator)'이라 칭하며 그
  //  이름이 의미하듯 이름공간을 지정할 때 사용하는 연산자이다.

  // 참고로 동일한 이름공간에 정의된 함수를 호출할 때에는 이름 공간을 명시할 필요가 없다.

  return 0;
}

void BestComImpl::SimpleFunc(void)
{
  std::cout << "BestCom SimpleFunc이 정의한 함수 " << std::endl;
  PrettyFunc();
  ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
  std::cout << "BestCom PrettyFunc 이 정의한 함수 " << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
  std::cout << "ProgtCom 이 정의한 함수" << std::endl;
}
