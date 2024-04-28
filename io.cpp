#include <iostream>

int myFunc(int num);
int myFunc(int num1 , int num2);


int main(int argc, char const *argv[])
{

// iostream 사용 방법

// 문자 출력
// std::cout<<"문자"
// endl 은 개행문자 (\n)
  int num = 20;
  std::cout<< "Hello World!"<<std::endl;
  std::cout<<"Hello"<<" World"<<std::endl;
  std::cout<<"Hello";
  std::cout<<" and "<<" World"<<std::endl;


// scanf 를 대신하는 데이터의 입력
// std::cin>>변수
  int val1;
  std::cout<<"첫번째 숫자입력 : ";
  std::cin>>val1;

  int val2;
  std::cout<<"두번째 숫자 입력 : ";
  std::cin>>val2;

  int result = val1 + val2;
  std::cout<<"뎃셈결과 : "<<result<<std::endl;

  // 두개의 정수 입력
  std::cout<<"두 정수 한번에 입력 : ";
  std::cin>>val1>>val2;

  std::cout<<"두 정수 : "<<val1<<" "<<val2<<std::endl;

  // 배열 기반 문자열 입출력
  char str[100];
  std::cout<<"문자열 입력 : ";
  std::cin>>str;

  std::cout<<"문자열 : "<<str<<std::endl;

  // 함수 오버로딩
  result = myFunc(1) + myFunc(1 ,2);
  std::cout<<"result : "<<result<<std::endl;

  return 0;
}

int myFunc(int num) {
  num++;
  return num;
}

int myFunc(int num1 , int num2) {
  int result =  num1 + num2;
  return result;
}