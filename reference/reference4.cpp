// call by value - 값을 인자로 전달하는 함수의 호출 방식
// call by reference - 주소 값을 인자로 전달하는 함수의 호출 방식
// call by address - 최근 주소 값을 전달하는 call by reference 함수 호출을 call by address 라고 불리는 경우가 있다.
//                 - 이는 c++ 의 참조자(reference) 기반의 함수 호출과 구분을 짓기 위함인데

#include <iostream>

using namespace std;

// Todo : 참조자를 이용한 Call-by-reference 의 황당함과 const 참조자
// 밑과 같이 HappyFunc(num); 를 실행하게 되면? 

// 이는 값을 받기 때문에 상관없지만
void HappyFunc(int prm);
// 밑의 함수는 어떤 결과가 나올지 모른다.
void HappyFunc(int &num);
// 이를 극복하고자 한다면 다음과 같이 사용할 수 있다.
// "함수 HappyFunc 내에서 참조자 ref를 이용한 값의 변경은 하지 않겠다."
// 따라서 "함수 내에서, 참조자를 통한 값의 변경을 진행하지 않을 경우, 참조자를 const 로 선언하여, 함수 원형만 봐도 값의 변경이 이뤄지지 않음을 확인할 수 있다."
void HappyFunc(const int &num);

// Todo : 반환형이 참조형(reference type)인 경우
int& RefRetFuncOne(int &ref) {
  ref++;
  return ref;
}

// 밑의 main 을 실행하게 되면 다음과 같아진다
// 1번
// int num1 = 1;
// int &ref = num1;
// int &num2 = &ref;

// 2번
// int num3 = 1;
// int &ref = num1;
// int num4 = ref;

int main(int argc, char const *argv[])
{

  int num1 = 1;
  int &num2 = RefRetFuncOne(num1);

  num1++;
  num2++;
  cout<<"num1 : "<<num1<<endl; // 결국
  cout<<"num2 : "<<num2<<endl; // num1을 참조하는 참조자 num2가 생겨나 버린다.

  // 위를 한끝 차이로 없앨 수 있다.
  int num3 = 1;
  int num4 = RefRetFuncOne(num3);

  num3++;
  num4 += 100;
  cout<<"num3 : "<<num3<<endl; // 정말 
  cout<<"num4 : "<<num4<<endl; // 한끗 차이다.
  return 0;
}
