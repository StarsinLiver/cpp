

#include <iostream>

namespace Hybrid
{
  void HybFunc(void)
  {
    std::cout << "So simple function!" << std::endl;
    std::cout << "In namespace Hybird!" << std::endl;
  }
}

int main(int argc, char const *argv[])
{

  // "HybFunc 를 이름공간 Hybrid 에서 찾으라"라는 일종의 선언
  using Hybrid::HybFunc;

  // 이 때, HybFunc 는 함수의 이름도 될 수 있고 , 변수의 이름도 될 수 있다. 
  HybFunc();
  return 0;
}
