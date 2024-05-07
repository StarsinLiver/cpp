// Todo : 람다 표현식
// 람다 표현식은 람다식 , 람다 함수로도 부르지만 , C++ 에서 정확한 용어는 람다 표현식 (lambda expression)입니다.
// 함수형 언어나 파이썬과 같은 인터프리터를 사용하는 언어에서 사용되던 클러저(closure)가 네이티브 프로그래밍 언어에 도입되면서 람다 함수 , 람다 표현식이 되었습니다.

// C++ 언어에서 람다 표현식은 함수를 단순하게 만들고 로직을 이해하기 쉽게 만들어 줍니다.
// 공통 기능을 함수로 만들면 여러 상황을 고려해야 하므로 예외 처리 , 매개변수에 따른 분류 등 부수적인 코드가 필요합니다.
// 하지만 람다 표현식을 즉시 호출 형태로 사용하면 코드의 위치가 곧 호출 위치이므로 로직을 한눈에 파악할 수 있으며, 인라인(inline)함수로 만들어 성능을
// 최적화 하는데도 도움이 됩니다.

// Todo : 즉시 호출 형태로 사용하기
[&changes] // 외부 변수 캡쳐
(int payment , int price) // 인자 목록
 -> int  // 반환 형식

// 정의부
 {
  int change = payment - price;
  changes[0] = change / 1000;
  change %= 1000;
  return payment - price;
}

// 호출부(인자)
(payments[i] , price [i])

// 매개변수 목록과 정의부는 일반 함수와 같습니다. 다른 점은 함수 이름이 없다는 것과 외부 변수를 캡처하는 부분, 그리고 반환값의 데이터 형식을 화살표 연산자(->)
// 다음에 명시한다는 점입니다.

// 그리고 람다 함수를 즉시 호출 형태로 사용하려면 정의부 다음에 호출 연산자와 함께 매개변수에 맞춰 인자를 전달합니다.

// 람다 표현식은 이를 선언한 함수의 범위에서 사용되지만, 하위 함수로 선언되므로 상위 함수의 지역인 선언부의 변수에는 접근할 수 없습니다.
// 외부 변수 캡쳐는 상위 함수에 선언된 지역 변수를 람다 표현식 내에서 사용할 수 있게 해주비낟

// Todo : 외부 변수를 캡처하는 방법은 다음 표에서 확인할 수 있습니다.
// 표에서 '선언부 범위'란 람다 표현식이 선언된함수를 의미합니다. 예를 들어 main 함수에서 람다 함수를 선언했다면 main 함수에 선언된 지역 변수를 캡쳐합니다.
// 만약, main 함수에서 생성한 객체의 맴버 함수에서 람다 표현식을 선언했다면 해당 객체의 맴버 함수에 선어노딘 지역변수를 캡처합니다.

// 캡쳐 방법       | 캡쳐되는 변수           | 람다표현식 내 사용
// [=]             : 선언부 범위의 모든 변수 : 읽기 전용으로 사용
// [&]             : 선언부 범위의 모든 변수 : 참조 형식으로 사용되어 읽기와 쓰기 가능
// [변수1]         : 변수1                   : 변수1을 읽기 전용으로 사용
// [변수1 , 변수2] : 변수1 , 변수2           : 변수1, 변수2를 읽기 전용으로 사용
// [&변수1 , 변수2]: 변수1 , 변수2           : 변수1은 참조형식으로, 변수2는 읽기 전용으로 사용
// [= , &변수1]    : 선언부 범위의 모든 변수 : 변수1은 참조형식으로 나머지는 읽기 전용으로 사용
// [& , 변수1]     : 선언부 범위의 모든 변수 : 변수1은 읽기 전용으로 나머지는 참조형식으로 사용

// '=(읽기 전용 캡쳐)' 이나 '&(참조 캡쳐)'를 사용하면 선언부 범위의 지역 변수를 모두 캡쳐할 수 있으며, 이와 함께 지역 변수 이름을 나열하면
// 전체 지역 변수 캡처와 반대되는 방식(읽기 전용 <-> 참조)으로 캡쳐됩니다.

// Todo : 실습
// 다음 코드에서 람다 표현식은 main 의 지역 변수인 changes 를 캡처해서 사용하고 payments 와 price 를 매개변수로 전달받습니다.
// 람다 표현식을 함수 객체에 대입하지 않고 마지막에 호출부 (payments[i] , price[i])를 작성했으므로 이 람다 표현식은 즉시 실행(호출) 됩니다.

#include <iostream>
#define loop_count 5
#define change_count 1
using namespace std;

class vending_machine
{
private:
  int price[loop_count];

public:
  vending_machine() : price{450, 390, 11340, 900, 150} {};

  void sale_using_basic_lambda(int payments[], int changes[])
  {
    for (int i = 0; i < loop_count; ++i)
    {
      cout << payments[i] << "원을 내고" << price[i] << "원짜리 음료를 선택했습니다." << endl;
      cout << "거슬러 받은 돈은" << [&changes](int payment, int price) -> int
      {
        int change = payment - price;
        changes[0] = change / 1000;
        change %= 1000;
        changes[1] = change / 500;
        change %= 500;
        changes[2] = change / 100;
        change %= 100;
        changes[3] = change / 50;
        change %= 100;
        changes[4] = change / 10;
        change %= 100;
        return payment - price;
      }(payments[i], price[i]) << "입니다."
                               << endl;

      cout << "천원짜리 " << changes[0] << "개, 오백원짜리 " << changes[1] << "개 , 백원짜리 " << changes[2] << "개,";
      cout << "오십원 짜리 " << changes[3] << "개, 십원짜리 " << changes[4] << "개로 받습니다." << endl;
    }
  }
};

int main(int argc, char const *argv[])
{
  vending_machine vending_machine_object = vending_machine();

  int paymets[loop_count] = {1000, 500, 15000, 1000, 200};
  int changes[change_count] = {
      0,
  };

  cout << "람다 표현식 기본 사용" << endl;
  vending_machine_object.sale_using_basic_lambda(paymets, changes);

  return 0;
}

/*
람다 표현식 기본 사용
1000원을 내고450원짜리 음료를 선택했습니다.
거슬러 받은 돈은550입니다.
천원짜리 0개, 오백원짜리 1개 , 백원짜리 0개,오십원 짜리 1개, 십원짜리 5개로 받습니다.

0원을 내고390원짜리 음료를 선택했습니다.
거슬러 받은 돈은-390입니다.
천원짜리 0개, 오백원짜리 0개 , 백원짜리 -3개,오십원 짜리 -1개, 십원짜리 -9개로 받습니다.

-1원을 내고11340원짜리 음료를 선택했습니다.
거슬러 받은 돈은-11341입니다.
천원짜리 -11개, 오백원짜리 0개 , 백원짜리 -3개,오십원 짜리 0개, 십원짜리 -4개로 받습니다.

-4원을 내고900원짜리 음료를 선택했습니다.
거슬러 받은 돈은-904입니다.
천원짜리 0개, 오백원짜리 -1개 , 백원짜리 -4개,오십원 짜리 0개, 십원짜리 0개로 받습니다.

200원을 내고150원짜리 음료를 선택했습니다.
거슬러 받은 돈은50입니다.
천원짜리 0개, 오백원짜리 0개 , 백원짜리 0개,오십원 짜리 1개, 십원짜리 5개로 받습니다.
*/

// Todo : 함수 객체로 사용하기
// 이번에는 람다 표현식을 함수 객체로 선언해서 사용하는 예를 살펴보겠습니다.
// 람다 표현식을 함수 객체로 사용할 때는 호출부를 작성하지 않습니다. 함수 객체로 서넝ㄴ한 람다 표현식은 호출이 필요할 때 함수 객체를 호출해서 사용합니다.

auto calcu_changes =
    [&changes]               // 외부 변수 캡쳐
    (int payment, int price) // 인자 목록
    -> int                   // 반환 형식
                             // 정의부
{
  int change = payment - price;
  changes[0] = change / 1000;
  change %= 1000;
  return payment - price;
};

// 함수 객체는 다른 함수나 객체에 매개변수로 전달할 수 있습니다.
// 그런데 변수를 캡쳐했을때는 범위를 벗어나서 뎅글링 포인터(dangling pointer)가 될 수 있으므로 람다 표현식을 인자로 전달할 때는 변수를 캡쳐하지 않는 것이 좋습니다.

// Todo : 뎅글링 포인터란?
// 댕글링 포인터는 이미 해제된 메모리의 주소가 포인터에 저장된 경우를 의미합니다. 이미 해제된 메모리이므로 다른 포인터가 사용하거나 쓰레기 값이 담겨 있을 수 있습니다.

#include <iostream>
#define loop_count 5
#define change_count 1
using namespace std;

class vending_machine
{
private:
  int price[loop_count];

public:
  vending_machine() : price{450, 390, 11340, 900, 150} {};

  void sale_using_basic_lambda(int payments[], int changes[])
  {

    // Todo : 람다 표현식을 함수 객체로 사용하기
    auto calcu_changes = [&changes](int payment, int price) -> int
    {
      return payment - price;
    };

    for (int i = 0; i < loop_count; ++i)
    {
      cout<<payments[i]<<"원을 내고"<<price[i]<<"원 짜리 음료를 선택했습니다."<<endl;
      cout<<"거슬러 받을 돈은"<<calcu_changes(payments[i] , price[i])<<"입니다."<<endl;
    }
  }
};

int main(int argc, char const *argv[])
{
  vending_machine vending_machine_object = vending_machine();

  int paymets[loop_count] = {1000, 500, 15000, 1000, 200};
  int changes[change_count] = {
      0,
  };

  cout << "람다 표현식 기본 사용" << endl;
  vending_machine_object.sale_using_basic_lambda(paymets, changes);

  return 0;
}

/*
람다 표현식 기본 사용
1000원을 내고450원 짜리 음료를 선택했습니다.
거슬러 받을 돈은550입니다.
500원을 내고390원 짜리 음료를 선택했습니다.
거슬러 받을 돈은110입니다.
15000원을 내고11340원 짜리 음료를 선택했습니다.
거슬러 받을 돈은3660입니다.
1000원을 내고900원 짜리 음료를 선택했습니다.
거슬러 받을 돈은100입니다.
200원을 내고150원 짜리 음료를 선택했습니다.
거슬러 받을 돈은50입니다.
*/


