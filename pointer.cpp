#include <iostream>

using namespace std;

// 밑과 같이 true 1 이 아니며 , false 는 0 이 아니다.
// 다만 true 와 false 가 정의되기 이전에는 참을 표현하기 위해 1 을 거짓을 표현하기 위해 0을 사용했기에, 이둘 을 출력하거나
// 정수의 형태로 형 변환 하는 경우 각각 1 과 0으로 변환하도록 정의되어 있을 뿐이다.
int main(int argc, char const *argv[])
{
  int a , *pa;

  a = 10;
  pa = &a; // a 의 주소값을 대입

  cout<<"a 의 값 : "<<a<<endl;
  cout<<"a 의 주소값 : "<<&a<<endl;


  cout<<"pa 의 값 : "<<pa<<endl; // pa 실제값 == a 의 주소값
  cout<<"pa 의 주소값 : "<<&pa<<endl; // pa 의 주소값
  cout<<"pa 의 참조하는 a의 실제값 : "<<*pa<<endl; // pa 가 참조하는(a) 실제값
 
  return 0;
}
