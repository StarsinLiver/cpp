// Todo : 예외 처리 생략 - noexcept

#include <iostream>
using namespace std;

// 예외를 던지지 않는 형식
void real_noexcept() noexcept {

}

// 잘못된 예외 처리 방식
void fake_noexcept() noexcept {
  throw 1;
}