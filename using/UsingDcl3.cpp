#include <iostream>
// 만약 using 선언을 하는 것이 귀찮다면, 그리고 꼭 그렇게 해야만 하는 상황이 아니라면, 다음의 선언을 통해
// '이름 공간 std에 선언된 모든 것에 대해 이름 공간 지정의 생략'을 명령할 수 있다.
using namespace std;

int main(int argc, char const *argv[])
{

  char val[100];
  cout<<"Hello World"<<endl;

  cout<<"문자열 입력 : ";
  cin>>val;
  cout<<"문자열 출력 : "<<val<<std::endl;
  return 0;
}
