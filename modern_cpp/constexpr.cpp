// Todo : constexpr 변수 선언
// 변수에 constexpr 을 사용하는 방법은 const 와 매우 유사합니다.
// const 변수처럼 갑승ㄹ 초기화 한 후에 변경할 수 없습니다.

// const 와 constexpr 차이점은 const 변수는 값이 런타임에 결정되지만, constexpr 변수는 컴파일 시점에 결정됩니다.

// 값이 컴파일 시점에 결정된다는 것은 프로그램이 메모리에 적재되지 않더라도 소스 코드상에서 변수의 초기값이 결정되야 한다는 의미입니다

#include <iostream>
using namespace std;

void sum_int(int operand1, int operand2)
{
  const int var11 = 10;
  const int var12 = operand1 + 10;
  const int var13 = operand1 + operand2;

  constexpr int var14 = 20;                  // 가능
  constexpr int var15 = operand1 + 15;       // 컴파일 에러
  constexpr int var16 = operand1 + operand2; // 컴파일 에러
}

int main(int argc, char const *argv[])
{
  const int var1 = 10;
  const int var2 = var1 + 10;
  const int var3 = var1 + var2;

  constexpr int var4 = 20;      
  constexpr int var5 = var1 + 15;      
  constexpr int var6 = var1 + var4; 

  sum_int(var1 , var4);
  return 0;
}

// Todo : constexpr 함수 선언
// const와 constexpr 키워드는 둘 다 변수를 상수로 만들어 주지만 중요한 차이점이 있습니다.

// const 는 변수를 상수로 변환해 읽기만 가능하지만, constexpr 은 변수를 상수 표현식으로 치환합니다. 따라서 변수에 사용할 때는 별다른 차이가 없지만, 
// 함수에 사용할 때는 큰 차이를 보입니다.

// constexpr 은 함수 가장 앞부분에 작성하며 클래스의 멤버 함수가 아닌 일반 함수에도 사용이 가능합니다.
// constexpr 함수는 컴파일 시점에 상수 표현식으로 치환됩니다.

class monster {
  public :
  int hp;

  // const 멤버 함수
  int get_hp() const {
    return hp;
  }
};

// constexpr 전역 함수
constexpr int sum_int_constexpr(int operand1 , int operand2) {
  return operand1 + operand2;
}

// .. 길어서 생략 .. 읿반 함수와 constexpr 함수의 차이는 한마디로 컴파일 시간은 좀 더 걸려도 함수 호출에 필요한 절차가 생략되어 실행 시간이 빨라짐

// Todo : constexpr 어셈블리어 코드 예시
int var1 = sum_int(4 , 5);
mov edx,5
mov ecx,4
call sum_int(07FF668B810E1h)
mov dword ptr [var1],eax

constexpr int var11 = sum_int_constexpr(4,5);
mov dword ptr [var11],9

//! constexpr 함수 제약조건은 다음과 같습니다.
// 1. 함수의 인자와 반환값 모두 리터럴 형식이어야 합니다.
// 2. 재귀 함수에 적용할 수 있습니다. 가상 함수에는 적용이 불가능합니다.
// 3. try~catch , goto 구문을 사용할 수 없습니다.
// 4. if 와 switch , 범위 기반 for 문 등 모든 박복 구문을 사용할 수 있습니다.
// 5. 지역 변수는 반드시 초기화하거나 리터럴 형식이어야 합니다. 정적 변수는 허용하지 않습니다.
