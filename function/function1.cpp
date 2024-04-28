// Todo : C++ 에서 C언어의 표준함수 호출하기

// Todo : c 를 더하고 .h를 빼라
// C언어의 라이브러리에는 매우 다양한 유형의 함수들이 정의되어 있다. 그런데 이런 함수들은 C++ 표준 라이브러리에도 포함되어 있다.
// C 언어의 헤더파일에 대응하는 C++ 헤더정보를 일부만 정리한 것이다.

// #include <stdio.h> -> #include <cstudio>
// #include <stdlib.h> -> #include <cstdlib>
// #include <math.h> -> #include <cmath>
// #include <string.h> -> #include <cstring>

// 물론 stdio.h 와 같은 c 언어의 헤더파일을 이요해도 되지만 , 가급적 c++의 헤더를 기반으로 작성하자

// Todo : C++ 헤더를 선언해야 하는 이유
// C++ 관점에서, 여전히 다음형태로 함수호출을 허용하는 이유는 "하위 버전과의 호환성(backwards compatibillity)"를 제공하기 위함으로 볼 수 있다.

// 그리고 C++ 표준 라이브러리가 제공하는 함수들과 c 표준 라이브러리가 제공하는 함수들이 완전히 일치하는 것도 아니다
// C++ 에서는 함수 오버로딩이 가능하기 때문에 자료형에 따라서 함수의 이름을 달리해서 정의하지 않고, 보다 사용하기 편하도록
// 함수를 오버로딩 해 놓은 것이다.
// 이렇듯 C++ 문법을 기반으로 개선된 형태로 라이브러리가 구성되어 있으므로 가급적 C++ 표준헤더를 이용해서 함수를 호출하자

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;



int main(int argc, char const *argv[])
{
  char str1[] = "Result";
  char str2[30];

  strcpy(str2 , str1);
  printf("%s : %f \n" , str1 , sin(0.14));
  printf("%s : %f \n" , str2 , abs(-1.25));
}
