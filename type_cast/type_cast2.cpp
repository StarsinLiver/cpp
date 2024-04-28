// Todo : dynamic_cast 두 번째 이야기 : Polymorphic 클래스 기반의 형 변환
// 상속과 관련된 형 변환에 대해서 다음과 같이 정리가 가능하다

// "상속관계에 놓여있는 두 클래스 사이에서, 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환 할 경우에는 dynamic_cast 연산자를
// 사용한다"

// "반대로, 상속관계에 놓여있는 두 클래스 사이에서, 기초 클래스의 포인터 및 참조형 데이터를 유도클래스의 포인터 및 참조형 데이터로 형 변환할 경우에는
// static_cast 연산자를 사용한다"

// 그리고 dynamic_cast 는 이 조건을 만족하여야 한다.
// "기초 클래스가 Polymorphic 클래스 이다."

// Todo : Polymorphic 클래스
// Polymorphic 클래스란 하나 이상의 가상함수를 지니는 클래스를 뜻하낟.
// 그러니 상속관계에 놓여있는 두 클래스 사이에서, 기초 클래스에 가상함수가 하나 이상 존재하면, dynamic_cast 연산자를 이용해서
// 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형 데이터로 변환이 가능하다.

#include <iostream>
using namespace std;

class SoSimple
{
public:
  virtual void ShowSimpleInfo()
  {
    cout << "SoSimple Base Class" << endl;
  }
};

class SoComplex : public SoSimple
{
public:
  void ShowSimpleInfo() // 이 역시 가상함수이다.
  {
    cout << "SoComplex Derived Class" << endl;
  }
};

int main(int argc, char const *argv[])
{
  SoSimple *simPtr = new SoComplex;
  SoComplex *comPtr = dynamic_cast<SoComplex *>(simPtr);
  comPtr->ShowSimpleInfo();
  return 0;
}

/*
SoComplex Derived Class
*/

// 이 예제를 통해 먼저 확인할 사실은 virtual 로 선언되었을 때에는 에러가 발생하지 않으나 virtual 선언이 되지 않았을 때에는 에러가 발생한다.

// Todo : 정말 마지막까지 골치 아프네 ㅋㅋ
// 유도 클래스의 포인터 및 참조형으로의 형 변환을 시도할 때, 사용할 수 있는 두 연산자는 다음과 같다.
// 1. dynamic_cast 
// 2. static_cast

// 그렇다면 이 둘에는 어떠한 차이가 있을까?
// 형 변환을 시도한다는 사실에는 차이가 없지만 그 결과에는 큰 차이가 있다.

SoSimple *simPtr = new SoComplex;
SoComplex *comPtr = dynamic_cast<SoComplex *>(simPtr);

// Todo : 위의 형 변환이 성공한 이유는 무엇일까?
// 그 이유는 포인터 변수 simPtr 이 실제 가리키는 객체가 SoComplex 이기 때문이다.

SoSimple *simPtr = new SoSimple;
SoComplex *comPtr = dynamic_cast<SoComplex *>(simPtr);

// Todo : 위의 경우에는?
// NULL 결과로 반환이 된다.

// Todo : dynamic_cast
// 이렇듯 dynamic_cast 는 안정적인 형 변환을 보장한다. 특히 컴파일 시간이 아닌 실행 시간에(프로그램이 실행중인 동안에) 안정성을 검사하도록 컴파일러가 바이너리 
// 코드를 생성한다는 점에 주목할 필요가 있다.
// 물론 이로 인해서 실행속도는 늦어지지만 그만큼 안정적인 형 변환이 가능한 것이다.

// Todo : static_cast
// static_cast 연산자는 안정성을 보장하지 않고 컴파일러는 무조건 형 변환이 되도록 바이너리 코드를 작성하기 때문에, 그로 인한 실행의 결과는 전적으로
// 프로그래머가 책임져야 한다.
// 물론 실행속도는 빠르다.

