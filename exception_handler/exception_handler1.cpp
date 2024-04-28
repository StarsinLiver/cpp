// Todo : 예외처리 (Exception Handler)
// try   예외를 발견한다.
// catch 예외를 잡는다.
// throw 예외를 던진다.

// Todo : 전달되는 예외의 명시
// 함수 내에서 발생할 수 있는 예외의 종류도 함수의 특징으로 간주된다.
// 따라서 이미 정의된 특정 함수의 호출을 위해서는 함수의 이름, 매개변수 선언 , 반환형 정보에 더해서, 함수 내에서 전달될 수 있는 예외의 종류(예외 데이터의 자료형)
// 과 그 상황도 알아야한다.
// 그래야 해당 함수의 호출문장을 감싸는 적절한 try~catch 블록을 구성할 수 있다.

// 다음과 같이 명시가 가능하다
// int ThrowFunc(int num) throw(int, char) { ... }

// // 다음과 같이 예외를 받은 수 있다.
// try
// {
//   ThrowFunc(20);
// }
// catch (int expn)
// {
//   ...
// }
// catch (char expn)
// {
//   ...
// }

// Todo : 예외 클래스와 예외 객체
#include <iostream>
#include <cstring>
using namespace std;

class DepositException {
  public :
  DepositException() {}
  void ShowException() {
    cout<<"DepositException"<<endl;
  }
};

class WithDrawException {
  public :
  WithDrawException() {}
  void ShowException() {
    cout<<"WithDrawException"<<endl;
  }
};

class Account {
  public :
  void Deposit() throw(DepositException) {
    throw DepositException();
  }
  void WithDraw() throw (WithDrawException) {
    throw WithDrawException();
  }
};

int main(int argc, char const *argv[])
{
  Account account;
  try {
    account.Deposit();
  } catch(DepositException &e) {
    e.ShowException();
  }
  
  try {
    account.WithDraw();
  } catch(WithDrawException &e) {
    e.ShowException();
  }
  return 0;
}

/*
DepositException
WithDrawException
*/

// Todo : 상속 관계로 예외처리 클래스를 구성하는 것이좋다.

