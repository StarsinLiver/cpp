// 전역변수와 지역변수
#include <iostream>
using namespace std;
// 전역변수와 지역변수의 이름이 같다면 전역변수는 지역변수에 의해 가려진다는 특징이 있다
// :: 연산자로 이를 해결해보자 

int val = 100;

int main(int argc, char const *argv[])
{
  
  int val = 1;
  cout<<"지역변수 : "<<val<<endl;
  cout<<"전역변수 : "<<::val<<endl;
  return 0;
}
