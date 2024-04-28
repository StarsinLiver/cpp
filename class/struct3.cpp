// Todo : 함수는 외부로 뺄 수 있다.
// 함수가 포함되어 있는 C++ 구조체를 보는 순간 다음의 정보들이 쉽게 눈에 들어와야 코드의 분선이 용이하다.
// - 선언되어 있는 변수 정보
// - 정의되어 있는 함수 정보

// 따라서 구조체를 보는 순간, 정의되어 있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 작성하는 것이 좋다
// 따라서, 구조체 내에 정의된 함수의 수가 많거나 그 길이가 길다면, 다음과 같이 구조체 밖으로 함수를 빼낼 필요가 있다.

// 사실 언급하진 않았지만, 사실 구조체 안에 함수가 정의되어 있으면 , 다음의 의미가 더불어 내포된다.
// "함수를 인라인으로 처리해라!"

// 반면, 위의 예제와 같이 함수를 구조체 밖으로 빼내면, 이러한 의미가 사라진다. 따라서 인라인의 의미를 그대로 유지하려면
// 다음과 같이 키워드 inline 을 이용해서 인라인 처리를 명시적으로 지시해야 한다.

// inline void Car::ShowCarState() {...}
// inline void Car::Accel() {...}
// inline void Car::Break() {...}

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

struct Car
{
  char gamerID[CAR_CONST::ID_LEN]; // 소유자의 아이디
  int fuelGauge;                   // 연료량
  int curSpeed;                    // 현재 스피드

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

  Car run99 = {"run77", 100, 0};
  run99.Accel();
  run99.Break();
  Car run77 = {"run77", 100, 0};
}
