// Todo : 예외 처리 실패 대응 - set_terminate
// throw 문으로 예외를 던졋는데 해당 예외를 받을 catch 문이 없거나 있어도 형식이 맞지 않으면 프로그램이
// 강제종료된다. 이때 종료 처리함수를 설정하는 set_terminate 로 프로그램이 강제 종료 되기전에 
// 특정 동작을 수행하도록 구성이 가능하다.


// main 함수에서 throw 1 코드를 만나면 catch 문을 찾을 수 없어 오류가 발생하고 프로그램이 강제 종료됨
// 그런데 강제로 종료하기 전에 set_terminate 로 지정한 종료 처리 함수가 실행되게 됨

// 종료 처리 함수로 지정한 myterminate 에서는 프로그램을 강제로 종료하는 exit 함수를 사용함
// exit는 <cstdlib> 헤더에 정의되어 있음


#include <iostream>
#include <cstdlib>
using namespace std;

void myterminate() {
  cout << "myterminate called"<<endl;
  exit(-1);
}

int main(int argc, char const *argv[])
{
  set_terminate(myterminate); // 종료 처리 함수 지정
  throw 1;
  return 0;
}
