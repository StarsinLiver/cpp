// Todo : malloc 과 free 를 대신하는 new & delete



#include <iostream>
#include <cstring>

using namespace std;

// new 를 사용해보자
// 길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 그 배열의 주소값을 반환하는 함수를 정의해보자
char * MakeStrAdr(int len) {
  char * str = new char[len];
  return str;
}

int main(int argc, char const *argv[])
{
  char * str = MakeStrAdr(20);
  strcpy(str , "I am so Happy~");
  cout<<str<<endl;
  delete []str;
  return 0;
}
