// Todo : C++ 에서의 static
// 이미 여러분이 잘 알고 있는 , c언어의 static 이다.

// Todo : C 언어의 static
// 전역변수에 선언된 static 의 의미 -> 선언된 파일 내에서만 참조를 허용하겠다는 의미
// 함수 내에 선언된 static 의 의미 -> 한번만 초기화 되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않음

// 예제를 간단히 보자
#include <iostream>
using namespace std;

void Couter()
{
  static int cnt;
  cnt++;
  cout << "Current cnt : " << cnt << endl;
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 10; i++)
    Couter();

  return 0;
}

/*
Current cnt : 1
Current cnt : 2
Current cnt : 3
Current cnt : 4
Current cnt : 5
Current cnt : 6
Current cnt : 7
Current cnt : 8
Current cnt : 9
Current cnt : 10
*/

// Todo : static 맴버 변수(클래스 변수)
// static 맴버변수는 "클래스 변수"라고도 한다. 일반적인 맴버변수와 달리 클래스 하나씩만 생성되기 때문이다. 다음은 클래스의 변수로 선언한 예이다.

class SoSimple
{
private:
  static int simObjCnt; // static 맴버변수 , 클래스 변수
public:
  SoSimple()
  {
    simObjCnt++;
    cout << simObjCnt << "번째 SoSimple 객체" << endl;
  }
}

// int SoSimple::simObjCnt = 0;
; // static 맴버변수의 초기화

// 해당 객체를 생성하건 생성하지 않건, 메모리 공간에 딱 하나만 할당되어서 공유되는 변수이다.
// 다음 예제를 보자
class SoSimple
{
private:
  static int simObjCnt; // static 맴버변수 , 클래스 변수
public:
  SoSimple()
  {
    simObjCnt++;
    cout << simObjCnt << "번째 SoSimple 객체" << endl;
  }
};

int SoSimple::simObjCnt = 0;
; // static 맴버변수의 초기화

class SoComplex
{
private:
  static int cmxObjCnt; // static 맴버변수 , 클래스 변수
public:
  SoComplex()
  {
    cmxObjCnt++;
    cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
  }
};

int SoComplex::cmxObjCnt = 0;
; // static 맴버변수의 초기화

int main(int argc, char const *argv[])
{
  SoSimple sim1;
  SoSimple sim2;

  SoComplex cmx1;
  SoComplex cmx2 = cmx1;
  SoComplex(); // 얘는 뭐야?? ㅋㅋ
  return 0;
}

/*
1번째 SoSimple 객체
2번째 SoSimple 객체
1번째 SoComplex 객체
2번째 SoComplex 객체
*/

// 변수 simObjCnt 는 객체가 생성될 때 동시에 생성되는 변수가 아닌, 이미 메모리 공간에 할당이 이뤄진 변수이다.
// 따라서 static 맴버변수의 초기화 문법은 다음과 같이 별도로 정의가 가능하다.
// int SoSimple::simObjCnt = 0;

