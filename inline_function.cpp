#include <iostream>


// 매크로 함수
#define SQR(x) x*x
#define PRT(x) printf("계산 결과는 %d입니다.\n", x)  

// 인라인 함수
inline int SQUARE(int x) {
  return x * x;
}

template <typename T>
inline T SQARE_TEMPLATE(T x) {
  return x * x;
}

int main(int argc, char const *argv[])
{

  // 인라인 함수
  // 매크로 함수의 장점 :
  // 일반적인 함수에 비해서 실행 속도에 이점이 있다.
  // 매크로 함수의 단점 : 
  // 정의하기가 어렵다. 복잡한 함수를 매크로의 형태로 정의하는 데 한계가 있다.
  std::cout<<SQR(2)<<std::endl;

  // 따라서 매크로 함수는 정의하기가 복잡하니, 일반 함수처럼 정의가 가능하면 좋겠다!
  std::cout<<SQUARE(5)<<std::endl;
  // 위의 코드는 컴파일에 의해 이와 같이 처리된다. std::cout<<x*x<<std::endl;

  // 매크로 함수에는 자료형 형변환이 이루어지나 인라인 함수에는 자료형이 명확하여 데이터의 손실이 발생할 수 있다. 
  // 이를 보안하고 싶다면 template 를 사용할 수 있다.
  std::cout<<"매크로 함수 : "<<SQR(3.12)<<std::endl;
  std::cout<<"인라인 함수 : "<<SQUARE(3.12)<<std::endl;
  std::cout<<"템플릿 함수 : "<<SQARE_TEMPLATE(3.12)<<std::endl;
  
  return 0;
}
