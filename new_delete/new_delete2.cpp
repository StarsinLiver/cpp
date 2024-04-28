// Todo : malloc 과 free 를 대신하는 new & delete



#include <iostream>
#include <cstring>

using namespace std;

// Todo : 힙에 할당된 변수를 포인터를 사용하지 않고 접근해보자
// 참조자의 선언은 상수가 아닌 변수를 대상으로만 가능함을 알고있을 것이다.
// 그렇다면 new 연산자를 이용해서 할당된 메모리 공간에도 참조자의 선언이 가능할 까?

// c++ 에서는 new 연산자를 이용해서 할당된 메모리 공간도 변수로 간주하여, 참조자의 선언이 가능하도록 하고있다.

int main(int argc, char const *argv[])
{
  int * ptr = new int;
  int &ref = *ptr;
  ref = 20;
  cout<<*ptr<<endl;

  // 비록 흔히 사용되는 문장은 아니지만, 참조자의 선언을 통해서, 포인터 연산없이 힙 영역에 접근할 수 있다는 사실에 주목할 필요가 있다.
}
