// Todo : 난수 생성
// 난수 생성에는 rand 와 srand 함수가 있다.
// #define RAND_MAX 0x7fff 는 난수의 범위가 0 ~ 32767 까지라는 의미다.

#include <iostream>
#include <random>
#include <chrono> // 시드 
using namespace std;

int main(int argc, char const *argv[])
{
  mt19937_64 mt_rand;

  for (int i = 0; i < 10; i++)
  {
    cout << mt_rand() << endl;
  }
  /*
  14514284786278117030
4620546740167642908
13109570281517897720
17462938647148434322
355488278567739596
7469126240319926998
4635995468481642529
418970542659199878
9604170989252516556
6358044926049913402
  */

 // 위의 코드는 난수를 생성할 때에 시드값을 사용하지 않음
 // Todo : 이번에는 시드값으로 시스템의 현재 시각을 넣어 난수를 생성
  auto curTime = chrono::steady_clock::now();
  auto duration = curTime.time_since_epoch();
  auto millis = chrono::duration_cast<chrono::microseconds>(duration).count();

  mt19937_64 mt_rand2(millis);

  // .. 위와 동일

  // Todo : 하드웨어 엔트로피로 난수 생성하기
   random_device rng;
   auto result = rng();
  return 0;
}
