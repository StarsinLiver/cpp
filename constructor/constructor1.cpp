// Todo : '복사 생성자'와의 첫만남
// 복사 생성자가 조금 생소하긴 해도 생성자의한 형태일 뿐이니, 어렵지 않다.

// C++ 스타일의 초기화
// 우리는 지금까지 다음과 가틍ㄴ 방식으로 변수와 참조자를 선언 및 초기화 해 왔다.

// int num = 20;
// int &ref = num;

// 하지만 C++에서는 다음의 방식으로 선언 및 초기화가 가능하다.

// int num(20);
// int &ref(num);

// 위의 두가지 초기화 방식은 결과적으로 동일하다.
// 즉, C++에서는 위의 두 가지 초기화 방식을 동시에 지원하고 있다. 그렇다면 이야기를 객체의 생성으로 옮겨가 보자. 그리고 이를 위해서 다음과
// 같이 클래스를 하나 간단히 정의해보자

#include <iostream>
using namespace std;
class SoSimple
{
private:
  int num1;
  int num2;

public:
  SoSimple(int n1, int n2) : num1(n1), num2(n2)
  {}

  void SetNum(int num1 , int num2) {
    this -> num1 = num1;
    this -> num2 = num2;
  }

  void ShowSimpleData()
  {
    cout << num1 << " , ";
    cout << num2 << endl;
  }
};

// 이어서 다음 코드의 실행결과를 예쌍해보자 단순히 출력결과만 예상하는 것이 아닌 객체의 생성관계를 예측해보자

int main(int argc, char const *argv[])
{
  SoSimple sim1(15, 20);
  SoSimple sim2 = sim1;
  sim2.SetNum(30 , 40);
  sim1.ShowSimpleData();
  sim2.ShowSimpleData();
  return 0;
}

// 위의 코드 중에서 main 함수의 두번째 문장에 해당하는 다음 문장은 객체의 생성 및 초기화를 연상시킨다.
// SoSimple sim2 = sim1;

// 즉, SIM2 객체를 새로 생성해서, 객체 sim1 과 sim2 간의 맴버 대 맴버 복사가 일어난다고 예상해 볼수있다.
// 그런데 실제로 그러한 일이 일어난다.
// sim2 객체가 생성된 다음에 sim1 과 sim2 간의 맴버 대 맴버 복사가 일어난다.(참고로 아래의 그림에서는 객체의 맴버변수만을 대상으로 객체를 표현했다.)

/*
sim1 : 15 , 20
sim2 : 30 , 40
*/

// 따라서 위의 main 함수를 실제 실행해보면 복사가 되므로 다음 두 문장이 동일한 의미로 해석되듯이
// int num1 = num2;
// int num1(num2);

// 다음문장도 동일한 문장이다.
// SoSimple sim2 = sim1;
// SoSimple sim2(sim1);

// 그런데 한가지 이상하다. C++ 의 모든객체는 생성자의 호출을 동반한다고 했는데 , sim2의 생성자 호출에 대해서는 언급한 바가 없다.
// 과연 sim2 는 어떤 과정을 거쳐서 생성되는 것일까?

// Todo : SoSimple sim2(sim1)
// 다음 문장을 한번 관찰하자. 그리고 생성자의 호출관점에서 이를 재분석 해보자

// 위의 문장에 담겨있는 내용을 정리하면 다음과 같다.
// - SoSimple 형 객체를 생성
// - 객체 이름은 sim2 로 정한다.

// 위의 내용과 관련해서는 추가적 설명은 필요 없을 것이다. 즉, 위의 객체 생성문에서 호출하고자 하는 생성자는 다음과 같이 SoSimpel 객체를 인자로 받을 수 있는 생성자 이다.

// SoSimple(SoSimple &copy) {...}

// 그리고 다음의 문장도 
// SoSimple sim2 = sim1;

// 실은 다음의 형태로 묵시적 변환이 되어서 (자동으로 변환이 되어서) 객체가 생성되는 것이다
// SoSimple sim2(sim1);

//그런데 앞서 정의한 SoSimple 클래스에는 이러한 유형의 생성자가 정의되어 있지 않았다.
// 일단 예제를 보고 "디폴트 복사 생성자"를 이해해보자

class SoSimple
{
private:
  int num1;
  int num2;

public:
  SoSimple(int n1, int n2) : num1(n1), num2(n2) {}

  SoSimple(SoSimple &copy) : num1(copy.num1) , num2(copy.num2) {
    cout<<"Called  SoSimple(SoSimple &copy)"<<endl;
  }

  void SetNum(int num1 , int num2) {
    this -> num1 = num1;
    this -> num2 = num2;
  }

  void ShowSimpleData()
  {
    cout << num1 << " , ";
    cout << num2 << endl;
  }
};

int main(int argc, char const *argv[])
{
  SoSimple sim1(15, 20);
  SoSimple sim2 = sim1; // == SoSimple sim2(sim1) 과 같다
   sim2.ShowSimpleData();
  return 0;
}

/*
Called  SoSimple(SoSimple &copy)
15 , 20
*/

// 위의 예제는, SoSimple sim2 = sim1; 해당 문장이 묵시적으로(자동으로) 변환된다는 사실만 제외하면 특별할 게 없는 예제이다.
// 이러한 생성자를 가리켜 "복사 생성자 (copy constructor)"라고 부른다.

// 이는 생성자의 정의 형태가 독특해서 붙인 이름이 아니다. 다만 이 생성자가 호출되는 시점이 다른 일반 생성자와 차이가 있기 때문에 붙은 것이다

// 즉, 복사 생성자를 정확히 이해하기 위해서는 복사 생성자의 호출시점을 확실히 이해해야 한다.
// 그리고 위 예제에 정의된 복사 생성자는 다음과 같이 좀 더 예쁘게 정의를 해야 일반적인 복사 생성자가 된다.

// Todo : SoSimple(const SoSimple &copy ) : num1(copy.num1), num2(copy.num2){}

// 맴버 대 맴버의 복사에 사용되는 원본을 변경시키는 것은 복사의 개념을 무너뜨리는 행위가 되니, 키워드 const 를 삽입해서 이러한 실수를 막아 놓는 것이 좋다.




