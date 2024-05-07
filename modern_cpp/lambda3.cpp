// Todo : 람다 표현식 추가 선택 사항
// 지금까지 알아본 람다 표현식에서는 다양한 방법으로 외부 변수를 캡처해 사용할 수 있스빈다.
// 그런데 만약 외부 변수를 람다 표현식 내에서만 변경해서 사용하고 외부에는 영향을 주지않으려면 어떻게 해야할 까요?

// 참조 형식이나 읽기 전용으로는 어려울 것입니다.
// 이때는 변수나 객체를 복사해서 가져올 수 있는 mutable 키워드를 이용합니다. 람다 표현식을 선언할 때 mutable 키워드를 이용하면 람다 표현식 내에서는 변경이 가능하나
// 외부 변수에는 영향을 미치지 않도록 변수가 복사됩니다. 즉, 일긱 전용도 아니고 참조 형식도 아니므로 변경 가능하면서 외부에는 영향을 미치지 않스비낟.
// mutable 키워드는 매개변수 목록 다음에 추가하는 선택 사항입니다. 만약 this 포인터도 복사해야한다면 *this 로 캡처하면 됩나다.

// 또한 람다 표현식 내부에서 예외 사항이 발생했을 때 동적 예외 처리 식별자를 사용할 수 있습니다.
// 예외 처리를 나타내는 throw 를 -> 연산자 앞쪽에 추가가 가능합니다.

// [&changes] (int payment , int price) mutable throw() -> int {
//   // 정의부
// } (payments[i] , price [i]);

#include <iostream>
using namespace std;
class object1 {
  private : 
  int abs;

  public :
  object1() : abs(1) {}

  void lambda_change() {
    [=] (int p , int g)  throw() -> int {
      cout<<p<<endl;
      cout<<g<<endl;
      this -> abs = 50;
      cout<<this -> abs<<endl;
    } (1 , 2);
  }
};

int main(int argc, char const *argv[])
{
  object1 o = object1();
  o.lambda_change();
  return 0;
}

/*
1
2
50
*/