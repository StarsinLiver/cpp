// 이름 공간의 중첩
// 이름공간은 다른 이름 공간안에 삽입될 수 있다.

#include <iostream>

namespace Parent {
  int num = 2;
  
  namespace SubOne {
    int num = 3;
  }

  namespace SubTwo {
    int num = 4;
  }
}

int main(int argc, char const *argv[])
{
  
  std::cout<<Parent::num<<std::endl;
  std::cout<<Parent::SubOne::num<<std::endl;
  std::cout<<Parent::SubTwo::num<<std::endl;
  return 0;
}
