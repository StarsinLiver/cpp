// Todo : 멤버 이니셜라이저(Member Initializer)를 이용한 멤버 초기화
// 생성자는 맴버변수의 초기화를 목적으로 정의가 되니 , 객체 생성과정에서의 생성자 호출은 객체의 초기화를 한결 수월하게 한다.
// 따라서 위와 같은 생각을 하지 않을 수 없다. 다행히 맴버 이니셜라이저(member initializer) 라는 것을 사용하여 우리가 원하는 것을 얻어보자

#include "./separate/Point.h"
#include <iostream>

using namespace std;

class Rectangle
{
private:
  Point upLeft;
  Point lowRight;

public:
  Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
  void ShowRecInfo() const;
};

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1, y2), lowRight(x2, y2)
{
  // empty
}

void Rectangle::ShowRecInfo() const
{
  // 여기에 아무거나
}

// 이 중에서 다음의 내용이 '멤버 이니셜라이져' 이다.
// :upLeft(x1 , y2) , lowRight(x2 , y2)

// 그리고 이것이 의미하는 바는 각각 다음과 같다
// "객체 upLeft 의 생성과정에서 x1 과 y1을 인자로 전달받는 생성자를 호출하라."
// "객체 lowRight 의 생성과정에서 x2와 y2를 인자로 전달받는 생성자를 호출하라."

// 이를 main 에서 해본다면

int main(int argc, char const *argv[])
{
  Rectangle rec(1, 1, 4, 4);
  rec.ShowRecInfo();

  return 0;
}

// C++ 의 모든 객체는 위의 세가지 과정을 순서대로 거쳐서 생성이 완성된다. 물론 이니셜라이져가 선언 되지 않았다면,
// 메모리 공간의 할당과 생성자의 몸체부분의 실행으로 객체생성은 완성된다.

// Todo :  "그럼 생성자도 정의되어 있지 않으면, 메모리 공간의 할당만으로 객체생성이 완료되나요?"

// 그건 아니다! 생성자는 이니셜라이저처럼 선택적으로 존재하는 대상이 아니다.
// 한마디로 생성자는 반드시 호출된다

// Todo : 맴버 이니셜라이저(Member initializer)를 이용한 변수 및 const 상수(변수) 초기화
// "멤버 이니셜라이저"는 객체가 아닌 멤버의 초기화에도 사용할 수 있다.

class Sosimple
{
private:
  int num1;
  int num2;

public:
  Sosimple(int n1, int n2) : num1(n1)
  {
    num2 = n2;
  }
};

// 위 클래스에서 보이듯이 객체가 아닌 맴버변수도 이니셜라이저를 통해서 초기화가 가능하다. 이니셜라이저의 다음문장인

// num1(n1) 은 num1 을 n1 으로 초기화하라는 뜻이다. 따라서 프로그래머는 생성자의 몸체에서 초기화하는 방법과 이니셜라이저를 이용하는 초기화 방법 중 선택이 가능하다.
// 그러나 일반적으로 맴버변수의 초기화는 이니셜라이저를 선호하는데 두 이점이 있다.

// Todo : 이니셜라이저 이점
// - 초기화의 대상을 명확히 인식할 수 있다.
// - 성능에 약간의 이점이 있다.

// 성능면에서 "이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다."
// 반면 생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면, 선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다.

// 그리고 우리는 이러한 사실로부터 다음의 가능성을 발견하게 된다. const 변수는 선언과 동시에 초기화해야하기 때문이다.

// Todo : "const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다!"
class FruitSeller
{
private:
  const int APPLE_PRICE;
  int numOfApples;
  int myMoney;

public:
  FruitSeller(int price, int num, int money) : APPLE_PRICE(price), numOfApples(num), myMoney(money)
  {
    // empty
  }
  int SaleApples(int money)
  {
    // ...
  }
};

// Todo : 이니셜라이저의 이러한 특징은 멤버변수로 참조자를 선언할 수 있게 합니다.
// const 변수와 마찬가지로 "참조자"도 선언과 동시에 초기화가 이뤄져야한다. 따라서 이니셜라이저를 이용하면 참조자도 멤버변수로 선언될 수 있다.
// 이러한 특성을 파악하기 위한 간단한 예제를 보이겠다.

class AAA
{
public:
  AAA()
  {
    cout << "emdty object" << endl;
  }

  void ShowInfo()
  {
    cout << "I'm class AAA" << endl;
  }
};

class BBB {
  private:
  AAA &ref;
  const int &num;

  public :
    BBB(AAA &r , const int &n) : ref(r) , num(n) {
    }// empty

  void ShowInfo() {
    ref.ShowInfo();
    cout<<"and"<<endl;
    cout<<"I ref num"<<num<<endl;
  }
};

// main 에서는 이런식
int main(int argc, char const *argv[])
{
  AAA obj1;
  BBB obj2 (obj1 , 200);
  obj2.ShowInfo();
  return 0;
}
