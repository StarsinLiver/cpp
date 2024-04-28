// Todo : 잘못된 참조의 반환

#include <iostream>

using namespace std;

// 밑의 함수를 한번 봐보자
int& RetuRefFunc(int n) {
  int num = 20;
  num += n;
  return num;
}

// 위의 함수에서는 지역변수 num 에 저장된값을 반환하지 않고, num을 참조의 형태로 반환한다면?
// 함수의 호출로 인해 곧 사라질 num의 참조 값을 반환하고 있기 때문에 예외가 발생하게 된다.

int main(int argc, char const *argv[])
{
  int n = 10;
  int &a = RetuRefFunc(10);

  cout<<"a 의 갑?? "<<a<<endl;
  return 0;
}
