// 파일명: check-cxx.cc
// 빌드: $ g++ -o check-cxx check-cxx.cc
#include <iostream>

int main() {
  std::cout << "__cplusplus = " << __cplusplus << std::endl;
  return 0;
}

/*
C++ 버전	__cplusplus
C++98	199711L
C++11	201103L
C++14	201402L
C++17	201703L
C++20	202002L
C++23	TBD (202100L)
*/