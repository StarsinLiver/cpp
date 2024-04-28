// Todo : 파일 분리를 해보자!

#include ".\separate\Simple.h"

int main(int argc, char const *argv[])
{
  SimpleClass * simple = new SimpleClass(50); // 동적 할당
  SimpleClass simple2(20); // 생성자 20

  simple->ShowInfo();
  simple2.ShowInfo();
  return 0;
}
