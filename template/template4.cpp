// Todo : 함수 템플릿의 특수화(Specialization)
// 이번에는 "함수 템플릿의 특수화" 라는 것에 대해 알아보자

#include <iostream>
using namespace std;

template <typename T>
T Max(T a , T b) {
  return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
  cout<<Max(11 , 15)<<endl;
  cout<<Max('T' , 'Q')<<endl;
  cout<<Max(3.5 , 7.5)<<endl;
  cout<<Max("Simple", "Best")<<endl;  
  return 0;
}

/*
15
T
7.5
Simple
*/

// 이와 같이 문자열을 대상으로 호출할 경우, 그 결과에 대해서는 아무런 의미도 부여할 수 없게 된다. (단순히 주소 값의 비교 결과가 반환이 된다.)
// 만약 문자열의 길이비교가 목적이라면 strlen 을 활용할 수 있다.

const char* Max(const char* a , const char* b) {
  return strlen(a) > strlen(b) ? a : b;
}

// 사전편찬 순선의 비교가 목적이라면 다음과 같이 구성되어야 한다.

const char* Max(const char* a , const char* b) {
  return strcmp(a,b) > 0 ? a : b;
}

// Todo : 이렇듯 상황에 따라서 템플릿 함수의 구성방법에 예외를 둘 필요가 있는데, 이 때 사용되는 것이 "함수 템픞릿의 특수화(specialization of function template)" 이다.
// 그럼 다음의 예제를 통해서 문자열 길이의 사넞ㄴ편찬 순서 비교에 대해서 "함수 템플릿의 특수화"를 진행해 보자

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a , T b) {
  return a > b ? a : b;
}

template <>
char* Max(char* a ,char* b) {
  cout<<"char* Max<<char*>(char* a ,char* b)"<<endl;
  return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a , const char* b) {
  cout<<"const char* Max<<const char* > (const char* a , const char* b)"<<endl;
  return strcmp(a,b) > 0 ? a : b;
}

int main(int argc, char const *argv[])
{
  cout<<Max(11 , 15)<<endl;
  cout<<Max('T' , 'Q')<<endl;
  cout<<Max(3.5 , 7.5)<<endl;
  cout<<Max("Simple", "Best")<<endl;  

  char str1[] = "Simple";
  char str2[] = "Best";
  cout<<Max(str1 , str2)<<endl;
  return 0;
}

/*
15
T
7.5
const char* Max<<const char* > (const char* a , const char* b)
Simple
char* Max<<char*>(char* a ,char* b)
Simple
*/

// 다음에 추가된 정의는
// 컴파일러에게 다음의 메시지를 전달하는 것이다.

template <>
char* Max(char* a ,char* b) {
  cout<<"char* Max<<char*>(char* a ,char* b)"<<endl;
  return strlen(a) > strlen(b) ? a : b;
}

// "char* 형 함수는 내가 이렇게 제시를 하니, char* 형 템플릿 함수가 필요한 경우에는 별도로 만들지 말고 이것을 써라!"

// 마찬가지로 다음의 정의는
// 컴파일러에게 다음의 메시지를 전달하는 것이다.

template <>
const char* Max(const char* a , const char* b) {
  cout<<"const char* Max<<const char* > (const char* a , const char* b)"<<endl;
  return strcmp(a,b) > 0 ? a : b;
}

// "const char*" 형 함수는 내가 이렇게 제시를 하니, const char* 형 템플릿 함수가 필요한 경우에는 별도로 만들지 말고 이것을 써라!

// 그리고 이 두 "함수 템플릿의 특수화"정의 형태는 특수화하는 자료형의 정보 <char*> 와 <const char*>를 생략한 형태이며 이를 생략하지 않고 정의를 하면 다음과 같다.

template <>
char* Max<char*>(char* a ,char* b) { ... }

template<>
const char* Max<const char*>(const char* a , const char* b) { ... }

// 물론 특수화하는 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에는 차이가 없으나, 가급적이면 자료형 정보를 명시하는 것이 뜻을 명확히 할 수 있다.