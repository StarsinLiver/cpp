// call by value - 값을 인자로 전달하는 함수의 호출 방식
// call by reference - 주소 값을 인자로 전달하는 함수의 호출 방식
// call by address - 최근 주소 값을 전달하는 call by reference 함수 호출을 call by address 라고 불리는 경우가 있다.
//                 - 이는 c++ 의 참조자(reference) 기반의 함수 호출과 구분을 짓기 위함인데

#include <iostream>

using namespace std;


int * SimpleFunc(int * ptr) {
  return ptr + 1; // 주소값을 증가시켜서 반환
} // call by value 

// 왜 위의 함수가 call by value 일까?
// 이 함수의 연산 주체는 값(value)이며 다만 그 값이 주소 값일 뿐디ㅏ. 
// 주소값에 1을 더한 결과를 반환하는 연산을 하니(포인터 연연산의 결과로 4가 증가한다.),
// 흔히 우리가 생각하는 주소 값을 이용해서 함수 외부에 선언된 변수에 접근하는 call by reference 와는 거리가 멀다.

// 반면 다음과 같이 작성되면 의삼할 여지 없이 call by reference 가 된다
int * SimpleFunc2(int * ptr) {
  if(ptr == NULL) return NULL;

  *ptr = 20;
  return ptr;
} // call by reference 


// Todo : c 언어에서 말하는 call by reference 는 다음의 의미를 지닌다.
// "주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출"

// Todo : c++ 에서는 함수 외부에 선언된 변수의 접근방법으로 두가지가 존재한다. 하나는 '주소 값'을 이용하는 방식이며, 다른 하나는 '참조자'를 이용하는 방식이다.
// 주소 값을 이용한 call-by-reference
// 참조자 값을 이용한 call-by-reference

// Todo : 참조자를 이용한 call by reference
// 선언된 참조자 ref1 과 ref2 는 main 함수에 선언된 변수 val1 , val2 의 또 다른 이름이 되는 것임
void SwapByRef2(int &ref1 , int &ref2) {
  int temp = ref1;
  ref1 = ref2;
  ref2 = temp;
} // call by reference

int main(int argc, char const *argv[])
{
  // 위는 다음과 같이 변경된다
  int val1 = 10;
  int val2 = 20;
  SwapByRef2(val1 , val2);
  cout << "val1 : " << val1 << endl; // 같이 두개가
  cout << "val2 : " << val2 << endl; // 교체되었다.
  return 0;
}
