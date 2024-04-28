// Todo : protected로 선언된 맴버가 허용하는 접근의 범위

#include <iostream>
using namespace std;

class Base
{
private:
  int num1;

protected:
  int num2;

public:
  int num3;

  void ShowData() const
  {
    cout << num1 << " , " << num2 << " , " << num3 << endl;
  }
};

class Derived : public Base
{
public:
  void ShowBaseMember()
  {
    cout << num1; // 컴파일 에러
    cout << num2; // 컴파일 OK!!
    cout << num3; // 컴파일 OK!!
    cout << endl;
  }
};

int main(int argc, char const *argv[])
{
  Derived der;
  der.ShowBaseMember();
  return 0;
}

// private 접근 불가능
// protected 상속시 접근 가능

// "protected 로 선언된 맴버변수는 이를 상속하는 유도 클래스에서 접근이 가능합니다!"
// 다만 기본적으로는 기초 클래스와 이를 상속하는 유도 클래스의 사이에서도 '정보 은닉'은 지켜지는게 좋다.

