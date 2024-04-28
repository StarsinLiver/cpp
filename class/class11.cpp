// Todo : this 포인터의 이해
// 맴버함수 내에서는 this 라는 이름의 포인터를 사용할 수 있는데 , 이는 객체 자신을 가리키는 용도로서 사용되는 포인터이다.

#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
  int num;

public:
  SoSimple(int n) : num(n)
  {
    cout << "num = " << num << " , ";
    cout << "address = " << this << endl;
  }

  void ShowSimpleData()
  {
    cout << num << endl;
  }
  SoSimple *GetThisPointer()
  {
    return this;
  }
};

int main(int argc, char const *argv[])
{
  SoSimple sim1(100);
  SoSimple *ptr1 = sim1.GetThisPointer(); // sim1 객체의 주소 값 저장
  cout << ptr1 << " , ";                  // 참조하고 있는 주소값
  ptr1->ShowSimpleData();
  return 0;
}

// Todo : this 포인터의 활용
// 이러한 this 포인터는 제법 유용하게 사용되는데, 이에대한 설명에 앞서 먼저 다음 클래스를 관찰하기 바란다.

class ThisClass
{
private:
  int num; // 207 이 저장된다
public:
  void ThisFunc(int num)
  {
    this->num = 207; // 207 이 저장된다
    num = 105;
  }
};

// 위 클래스에서 thisFunc 함수의 매개변수 이름은 num 이다. 그런데 이 이름은 멤버변수의 이름과 동일하기 때문에 ThisFunc 함수 내에서의 num 은 매개변수 num 을 의미하게된다
// 따라서 변수의 이름만 참조하는 방법으로는 ThisFunc 함수 내에서 멤버변수 num 에 접근이 불가능하다.
// 그러나 this 포인터를 활용하면 가능하다.

// this->num=207

// 위 문장에서 this 는 객체를 참조하는 포인터이다. 그럼 객체의 포인터를 가지고 접근하는 변수 num 은 맴버변수 num 이다.

// Todo : Self-Reference 반환
// Self-Reference 반환이란 객체 자신을 참조할 수 있는 참조자를 의미한다.

class SelfRef {
  private :
    int num;

    public :
    SelfRef(int n ) : num(n) {
      cout<<"객체생성"<<endl;
    }

    SelfRef& Adder(int n) {
      num += n;
      return *this;
    }

    SelfRef& ShowTwoNumber() {
      cout<<num<<endl;
      return *this;
    }
};

int main(int argc, char const *argv[])
{
  SelfRef obj(3);
  SelfRef& ref = obj.Adder(2);

  obj.ShowTwoNumber();
  ref.ShowTwoNumber();

  ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
  return 0;
}

/*
객체생성
5
5
6
8
*/

// 실행결과에서 보이듯이. 위 예제에서는 하나의 객체만 생성하였다. 다만, 그 객체가 반환하는 참조값을 대상으로 다양한 방법으로 맴버 함수를 호출이 가능하다


