// Todo : 세가지 형태의 상속
// class Derived : public Base
// class Derived : protected Base
// class Derived : private Base

// 위에서 보이듯이 상속의 형태를 명시하는 용도로도 사용된다.

// Todo : protected 상속
// "protected 보다 접근의 범위가 넓은 맴버는 protected 로 변경시켜서 상속하겠다."

// 그런데 protected 보다 접근범위가 넓은 맴버는 public 맴버 뿐이니, protected 상속을 한 클래스는 다음의 형태가 된다.
class Base {
  private : // -> 접근 불가
  int num1;
  protected :
  int num2;
  public :  // -> protected 변환
  int num3;

  Base() : num1(1) , num2(2) , num3(3) {}
};

class Derived : protected Base {
  // empty
}

int main(int argc, char const *argv[])
{
  Derived drv;
  drv.num3; // 컴파일에러
  return 0;
}

// Todo : 컴파일 에러?
// 이유는 Base 클래스를 protected 로 상속했기 때문이다. 
// protected 로 상속했기 때문에 public 맴버변수인 num3 는 Derived 클래스에서 protected 맴버가 된다.
// 그로 인해 외부에서는 접근이 불가능한 맴버가 된 것이다.

// Todo : private 상속
// 이는 다음과 같다.
class Base {
  private : // -> 접근 불가
  int num1;
  protected : // -> private 변환 , 접근 불가
  int num2;
  public :  // -> private 변환 , 접근 불가
  int num3;
};

class Derived : private Base {};

// 의미는 다음과 같다.
// "private 보다 접근의 범위가 넓은 맴버는 private 으로 변경시켜서 상속하겠다."
// 한마디로 모두 접근이 불가 한 것이다.