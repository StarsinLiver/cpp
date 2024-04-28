// Todo : static 맴버변수의 또 다른 접근 방법
/// .. 알거라 생각함 page 262 쪽 참조

// Todo : const static 맴버
// 클래스 내에 선언된 const 맴버변수(상수)의 초기화는 이닌셜라이저를 통해야 하낟.
// 그러나 const static 으로 선언되는 맴버변수(상수)는 다음과 같이 선언과 동시에 초기화가 가능하다

#include <iostream>
using namespace std;

class CountryArea {
  public :
  const static int RUSSIA = 71561;
  const static int CANADA = 85165;
}
int main(int argc, char const *argv[])
{
  cout<<"러시아의 면적 ::"<<CountryArea::RUSSIA<<"km"<<endl;
  cout<<"캐나다의 면적 ::"<<CountryArea::CANADA<<"km"<<endl;
  return 0;
}
