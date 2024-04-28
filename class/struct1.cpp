// Todo : C++에서의 구조체
// C언어의 구조체의 등장배경은 무엇인가?
// "연관 있는 데이터를 하나로 묶으면, 프로그램의 구현 및 관리가 용의하다."

// 소프트웨어를 단순하게 표현한다면?
// "소프트웨어 = 데이터의 표현 + 데이터의 처리"

// 그런데 "표현해야 하는 데이터"는 항상 부류를 형성하기 마련이다. 그리고 이렇게 부류를 형성하는 데이터들은 함께 생성, 이동 및 소멸된다는 특징이 있다.
// 그래서 구조체는 연관있는 데이터를 묶을 수 있는 문법적 장치로 데이터의 표현에 매우 큰 도움을 준다

// struct Car {
//   char gamerID[ID_LEN];
//   int fuelGauge;
//   ...
// }

// Todo : C++ 에서의 Class
// C 언어에서 구조체 변수를 선언하는 방법은 다음과 같다
// struct Car basicCar;

// 앞에 삽입된 키워드 struct 는 이어서 선언되는 자료형이 구조체를 기반으로 정의된 자료형임을 나타낸다.
// 그리고 키워드 struct를 생략하려면 별도의 typedef 선언을 추가해야한다

// 하지만 C++ 에서는 별도의 typedef 선언없이도 다음과 같이 변수를 선언이 가능하다.
// Car basicCar;

// 이어서 앞서 정의한 구조체를 기반으로 예제를 작성해 보자
#include <iostream>

using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
  char gamerID[ID_LEN]; // 소유자의 아이디
  int fuelGauge;        // 연료량
  int curSpeed;         // 현재 스피드
};

void ShowCarState(const Car &car)
{
  cout << "소유자ID : " << car.gamerID << endl;
  cout << "연료량 : " << car.fuelGauge << "%" << endl;
  cout << "현재 속도 : " << car.curSpeed << "km/s" << endl;
}

void Accel(Car &car)
{
  if (car.fuelGauge <= 0)
    return;
  else
    car.fuelGauge -= FUEL_STEP;

  if (car.curSpeed + ACC_STEP >= MAX_SPD)
  {
    car.curSpeed = MAX_SPD;
    return;
  }

  car.curSpeed += ACC_STEP;
}

void Break(Car &car)
{
  if (car.curSpeed < BRK_STEP)
  {
    car.curSpeed = 0;
    return;
  }

  car.curSpeed = BRK_STEP;
}

int main(int argc, char const *argv[])
{
  Car run99 = {"run99", 100, 0};
  Accel(run99);
  Accel(run99);
  ShowCarState(run99);
  Break(run99);
  ShowCarState(run99);

  Car run77 = {"run77", 100, 0};
  Accel(run77);
  Break(run77);
  ShowCarState(run77);

  return 0;
}
