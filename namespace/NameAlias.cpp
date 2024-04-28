// 만약 이런 상황이라면?
#include <iostream>

namespace AAA
{
  namespace BBB
  {
    namespace CCC
    {
      int num1;
      int num2;
    }
  }
}

// 위의 코드를 간결하게 별칭을 주어보자
namespace ABC = AAA::BBB::CCC;

int main(int argc, char const *argv[])
{

  // 위의 코드의 num 1 에 들어가려면 힘들다
  AAA::BBB::CCC::num1 = 20;

  // 위의 별칭을 사용해 보자
  ABC::num2=21;

  // 출력 시켜보자
  std::cout<<AAA::BBB::CCC::num1<<std::endl;
  std::cout<<ABC::num2<<std::endl;

  return 0;
}
