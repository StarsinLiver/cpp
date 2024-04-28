// Todo : 클래스(Class) 와 객체(Object)
// 앞의 struct 구조체는 클래스의 일종이다. 그렇다면 클래스와 구조체는 어떤 차이점이 있을까?

// Todo : 클래스와 구조체의 유일한 차이점
// 키워드 struct 를 대신해서 class를 사용하면, 구조체가 아닌 클래스가 된다.
// 그렇다! 코드상에서 유일하게 차이점은 키워드가 struct 냐 class 일 뿐이다. (정말? 아니다. ㅋㅋ)
// 그런데 이렇게 키워드를 바꿔놓으면 앞서 예제에서 보였던 다음 방식으로 변수(구조체 변수)를 선언하지 못한다.

// Car run99 = {"run99",11,0} (x) <- 사용 불가능

// 그렇다면 어떻게 초기화를 할까?
// 클래스 내에 선언된 변수는 기본적으로 클래스 내에 선언된 함수에서만 접근이 가능하다.
// 이렇듯 클래스는 정의하는 과정에서 각각의 변수 및 함수의 접근 허용 범위를 별도로 선언해야 한다.
// 그리고 이것이 바로 키워드 struct 를 이용해서 정의하는 구조체와 키워드 class 를 이용해서 정의하는 클래스의 유일한 차이점이다.

// Todo : 접근제어 지시자
// C++ 에서는 접근 제어 지시자는 세가지다.
// public : 어디서든 접근 허용
// protected : 상속관계에 놓였을때 , 유도 클래스에서의 접근 허용
// privated : 클래스 내(클래스 내에 정의된 함수)에서만 접근 허용

#include <iostream>

using namespace std;

namespace CAR_CONST
{
  enum
  {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10,
  };
} // namespace CAR_CONST

class Car {
  private:
  char gamerID[CAR_CONST::ID_LEN]; // 소유자의 아이디
  int fuelGauge;                   // 연료량
  int curSpeed;                    // 현재 스피드

  public:
   void InitMembers(char *ID, int fuel);
   void ShowCarState();
   void Accel();
   void Break();
};

void Car::ShowCarState()
{
  cout << "소유자ID : " << gamerID << endl;
  cout << "연료량 : " << fuelGauge << "%" << endl;
  cout << "현재 속도 : " << curSpeed << "km/s" << endl;
}

void Car::InitMembers(char * ID , int fuel) {
  strcpy(gamerID , ID);
  fuelGauge = fuel;
  curSpeed = 0;
}

void Car::Accel()
{
  if (fuelGauge <= 0)
    return;
  else
    fuelGauge -= CAR_CONST::FUEL_STEP;

  if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
  {
    curSpeed = CAR_CONST::MAX_SPD;
    return;
  }

  curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
  if (curSpeed < CAR_CONST::BRK_STEP)
  {
    curSpeed = 0;
    return;
  }

  curSpeed = CAR_CONST::BRK_STEP;
}

int main(int argc, char const *argv[])
{
  // 초기화
  Car run99;
  run99.InitMembers("run99", 100);

  return 0;
}
