// Todo : 템플릿 매개변수는 디폴트 값 지정도 가능하다.
// 함수의 매개변수에 디폴트 값의 지정이 가능하듯이, 템플릿 매개변수에도 디폴트 값의 지정이 가능하다.
#include <iostream>
using namespace std;

template <typename T = int, int len = 7>

// main 은 다음과 같이 적용이 가능하다
SimpleArray<> arr;