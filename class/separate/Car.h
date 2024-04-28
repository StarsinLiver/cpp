#ifndef __CAR_H_
#define __CAR_H_
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
   void InitMembers(char* ID, int fuel);
   void ShowCarState();
   void Accel();
   void Break();
};
#endif