// Todo : 이니셜라이저
// 대입 연산자를 알았으니 이니셜라이저가 왜 성능향상에 좋은지 알아보자

#include <iostream>
using namespace std;

class AAA {
  private :
  int num;

  public :
  AAA (int n= 0): num(n) {
    cout<<"AAA(int n = 0)" <<endl;
  }

  AAA(const AAA& ref) : num(ref.num) {
    cout<<"AAA(const AAA& ref)"<<endl;
  }

  AAA operator= (const AAA& ref) {
    num = ref.num;
    cout<<"operator=(const AAA& ref)"<<endl;
    return *this;
  }
};

class BBB {
  private :
  AAA mem;

  public :
  BBB (const AAA&ref): mem(ref) {}
};

class CCC {
  private :
  AAA mem;

  public :
  CCC (const AAA&ref) {
    mem = ref;
  }
};

int main(int argc, char const *argv[])
{
  AAA obj1(12);
  cout<<"* * * * * *"<<endl;
  BBB obj2(obj1);
  cout<<"* * * * * *"<<endl;
  CCC obj3(obj1);
  return 0;
}

/*
AAA(int n = 0)

* * * * * * BBB
AAA(const AAA& ref)

* * * * * * CCC
AAA(int n = 0)
operator=(const AAA& ref)
AAA(const AAA& ref)
*/

// 실행결과를 보면, BBB 객체 생성과정에서는 복사 생성자만 호출되었는데 ,CCC 객체의 생성과정에서는 생성자와 대입 연산자까지 호출되었다.
// 즉, CCC 객체의 생성과정에서 호출된 함수의 수가 하나 더 많다.

// Todo : 이 차이점은 왜 발생하게 된 것일까?

// 먼저 BBB 클래스의 생성자이다.

BBB(const AAA& ref) : mem(ref) {}

// "이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다."

// 즉, 위의 이니셜라이저를 통한 초기화 구문은 다음 문장과 유사하다
// AAA mem = ref;

// 그래서 복사 생성자만 호출이 되었던 것이다

// 이번에는 CCC 클래스의 생성자이다.

CCC (const AAA&ref) { mem = ref; }

// "생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면, 선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다."

// 그래서 객체 mem의 초기화 과정에서, 생성자와 대입 연산자가 각각 한번씩 호출된 것이다. 이렇듯 위 예제에서 보이듯이 이니셜라이저를 이용해서 초기화를 진행하면,
// 함수의 호출 횟수를 줄일 수 있다.

