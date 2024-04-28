// 함수 정의 부분
#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char* ID , int fuel) {
  strcpy(gamerID , ID);
  fuelGauge = fuel;
  curSpeed = 0;

  cout<<"안녕?"<<endl;
}

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