// Todo : C++에서의 구조체
// Todo : 구조체 안에 함수 삽입하기
// 구조체 Car 에 종속적인 함수들을 구조체안에 함께 묶어버리면 어떻겠는가? 그렇게 되면 자동차와 관련된 데이터와 함수를 모두 묶는 셈이 되기 때문에 보다 확실한 구분이 가능하다.
// C++ 에서는 구조체안에 함수를 삽입하는 것을 허용한다.

// Todo : 구조체 안에 enum 상수 선언
// 상수 역시 구조체 Car 에게만 의미가 있는 사우들이다.
// 즉, 다른 영역에서 사용하도록 정의된 상수가 아니니, 이들 상수도 구조체 내에 포함시키는 것이 좋을 수도 있다.
// 따라서 이러한 경우에는 열거형 enum 을 사용해서 다음과 같이 구조체 내에서만 유효한 상수를 정의하면 된다.

#include <iostream>

using namespace std;

// Todo : namespace 로 묶어서 사용하면 가독성도 좋아질 수도 있다 [안해도 됨]
// namespace CAR_CONST
// {
//   enum
//   {
//     ID_LEN = 20,
//     MAX_SPD = 200,
//     FUEL_STEP = 2,
//     ACC_STEP = 10,
//     BRK_STEP = 10,
//   };
// } // namespace CAR_CONST

struct Car
{

  enum
  {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10,
  };

  char gamerID[ID_LEN]; // 소유자의 아이디
  int fuelGauge;        // 연료량
  int curSpeed;         // 현재 스피드

  void ShowCarState()
  {
    cout << "소유자ID : " << gamerID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재 속도 : " << curSpeed << "km/s" << endl;
  }

  void Accel()
  {
    if (fuelGauge <= 0)
      return;
    else
      fuelGauge -= FUEL_STEP;

    if (curSpeed + ACC_STEP >= MAX_SPD)
    {
      curSpeed = MAX_SPD;
      return;
    }

    curSpeed += ACC_STEP;
  }

  void Break()
  {
    if (curSpeed < BRK_STEP)
    {
      curSpeed = 0;
      return;
    }

    curSpeed = BRK_STEP;
  }
};

int main(int argc, char const *argv[])
{

  Car run99 = {"run77", 100, 0};
  run99.Accel();
  run99.Break();
  Car run77 = {"run77", 100, 0};
}
