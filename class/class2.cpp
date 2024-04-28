// Todo : C++ 에서의 파일 분할
// 어떠한 프로그램이건 하나의 파일에 모든 것을 담진 않는다. 특히 C++은 클래스 별로 헤더파일과 소스파일을 생성해서 클래스의 선언과 정의를 분리하는 경우가 많기 때문에
// 많은 수의 파일이 만들어 진다.
// 그럼 이어서 클래스를 대상으로, 파일을 나누는 기준을 알아보자

// Car을 대상으로 파일을 구분해보자

// Car.h  : 클래스의 선언을 담는다.

// Car.cpp : 클래스의 정의(맴버함수의 정의)를 담는다.
// 클래스 선언은 다음과 같다.
// class Car {
//   private:
//   char gamerID[CAR_CONST::ID_LEN]; // 소유자의 아이디
//   int fuelGauge;                   // 연료량
//   int curSpeed;                    // 현재 스피드

//   public:
//    void InitMembers(char *ID, int fuel);
//    void ShowCarState();
//    void Accel();
//    void Break();
// };

// 이는 컴파일러가 Car 클래스와 관련된 문장의 오류를 잡아내는데 필요한 최소한의 정보로써 ,클래스를 구성하는 외형적을 틀을 보여준다
// 따라서 이를 가리켜 "클래스의 선언 (declaration)"이라고 한다.

// 반면, "클래스의 정의(definition)"에 해당하는 다음 함수의 정의는 다른 문장의 컴파일에 필요한 정보를 가지고 있지 않다.
// 따라서 함수의 정의는 컴파일 된 이후에, 링커에 의해 하나의 실행파일로 묶어주기만 하면 된다.

// 그럼 이제 결론을 내리겠다. Car 클래스와 관련된 문자의 컴파일 정보로 사용되는 "클래스의 선언"은 헤더파일에 저장을 해서, 필요한 위치에 쉽게 포함될 수
// 있도록 해야하며, "클래스의 정의"는 소스 파일에 저장해서 컴파일 되도록 하자

// Todo : 인라인 함수는 헤더파일에 함께 넣어야 한다.
// 밑과 같이 보인 파일분할 예제에서 Car.cpp 에 정의된 함수 ShowCarState 와 Break 를 다음과 같이 인라인화 한 다음에 그대로 Car.cpp 에 두면 컴파일 에러가 발생한다.

// inline void Car::ShowState() {...}

// 인라인 함수의 특징을 잘 생각해보면 그 이유를 알 수 있다
// "컴파일 과정에서 함수의 호출 문이 있는 곳에 함쉬의 몸체 부분이 삽입되어야 하므로!"

// Todo : 한 마디로 인라인 함수는 header 파일 에 선언해서 사용하자
// 컴 파일러는 파일 단위로 컴파일을 한다. 즉 여러분이 A.cpp 와 B.cpp 를 동시에 컴파일해서 하나의 실행파일을 만든다 해도,
// A.cpp의 컴파일 과정에서 B.cpp를 참조하지 않으며, B.cpp 의 컴파일 과정에서 A.cpp를 참조하지 않는다.
// 그래서 위의 예제에서 보이듯이 클래스의 선언과 인라인 함수의 정의를 함께 묶어야 한다.


// Todo : 사용해보자 (파일 : class/separate)
#include <iostream>
#include ".\\separate\\Car.h"

using namespace std;

int main(int argc, char const *argv[])
{
  // 초기화
  Car run99;

  char str[10] = "run99";
  run99.InitMembers(str, 100);

  run99.Accel();
  run99.Break();
  run99.ShowCarState();
  return 0;
}
