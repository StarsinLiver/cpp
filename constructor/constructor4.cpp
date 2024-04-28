// Todo : 복사 생성자의 호출 시점
// 이제 복사 생성자를 알았으니 호출 시점은 언제 일까?

// Person man1("Lee dong woo" , 29);
// Person man2 = man1; // 복사 생성자 호출

// 이것이 전부가 아니다. 이를 포함해서 복사 생성자가 호출되는 시점은 크게 3가지이다.

// - case 1 : 기존에 생성된 객체를 이용해서 새로운 객체를 초기화 (앞의 예제)
// - case 2 : Call by value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
// - case 3 : 객체를 반환하되 참조형으로 반환하지 않는 경우

// 이들은 모두 다음의 공통점을 지닌다.
// "객체를 새로 생성해야 한다. 단, 생성과 동시에 동일한 자료형의 객체로 초기화해야한다."

// Todo : 메모리 공간의 할당과 초기화가 동시에 일어나는 상황
// 복사 생성자의 호출시기를 논하기에 앞서, 먼저 메모리 공간이 할당과 동시에 초기화되는 상황을 나열해 보자.

// Todo : 1번
// int num1 = num2;

// 이는 num1이라는 이름의 메모리 공간을 할당과 동시에 num2에 저장된값으로 초기화 시키는 문장이다.
// 즉, 할당과 동시에 초기화가 이뤄지나. 다음의 경우에서도 할당과 동시에 초기화가 이루어진다.

// Todo : 2번
... int SimpleFunc(int n) { ... }

int main(int argc, char const *argv[])
{
  int num = 10;
  SimpleFunc(num); // 호출되는 순간 매개변수 n 이 할당과 동시에 초기화
  return 0;
}

// 위의 코드에서 SImpleFunc 함수가 호출되는 순간에 매개변수 n 이 할당과 동시에 변수 num에 저장되어있는 값으로 초기화 된다.
// 이렇듯 매개변수도 함수가 호출되는 순간에 할당되므로 이 상황도 메모리 공간의 할당과 초기화가 동시에 일어나는 상황이다.

// Todo : 3번
// 마지막도 마찬가질 메모리 공간이 할당되면서 동시에 초기화가 이뤄진다.
int SimpleFunc(int n) { ... return n }

int main(int argc, char const *argv[])
{
  int num = 10;
  cout << SimpleFunc(num) << endl;
  return 0;
}

// 위 코드를 보면서 다음과 같이 의아해할 수도 있다.

// "정수를 반환하는데, 그 과정에서 메모리 공간이 할당된다고?"
// 이미 언급했듯이 반환되는 값을 변도의 변수에 저장하는 것과 별개로, 값을 반환하면 반환된 값을 별도의 메모리 공간에 할당되어서 저장이 된다. 이는 위 코드를 보면 쉽다.

// 반환되는 값을 메모리 공간의 어딘가에 저장해 놓지 않았다면 , cout 에 의한 출력이 가능하겠는가?
// 값이 출려고디기 위해서는 그 값을 참조할 수 있어야하고, 참조가 가능하려면 메모리 공간의 어딘가에 저장되어야 한다. 결론은

// "함수가 값을 반환하면 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다.(반환 값으로 초기화된다.)"

// 이 세가지 상황은 객체를 대상으로 해도 달라지지 않는다.

// 밑의 함수가 호출되는 순간, 매개변수로 선언된 ob 객체가 생성되고, 이는 인자로 전달된 obj 객체로 초기화된다. 즉, 메모리 공간이 할당되면서
// 동시에 초기화된다. 이렇듯 앞서 보인 기본 자료형의 인자전달과 차이가 없다. 마찬가지로 다음의 경우에도 객체가 생성되면서 동시에 초기화 된다.

SoSimple SimpleFuncObj(SoSimple ob) { ... return ob; } // 반환하는 순간 메모리 공간이 할당되면서 동시에 초기화

// Todo : 할당 이후 , 복사 생성자를 통한 초기화
// 앞서 객체가 생성 및 초기화되는 세 가지 경우에 대해서 정이래 보았는데, 이때 초기화는 어떻게 이루어지겠는가?
// 다음의 방식으로 초기화를 진행한다.

// "복사 생성자의 호출"

// 디폴트 복상 생성자는 맴버 대 맴버가 복사되도록 정의가 되니, 이는 매우 적적한 초기화의 방식이라고 할 수 있다.
// 예제를 진행해보자

class SoSimple
{
private:
  int num;

public:
  SoSimple(int n) : num(n) {}

  SoSimple(cosnt SoSimple &copy) : num(copy.num)
  {
    cout << "Called SoSimple(const SoSimple &copy)" << endl;
  }

  void ShowData()
  {
    cout << "num : " << num << endl;
  }
};

void SimpleFuncObj(SoSimple ob)
{
  ob.ShowData();
}

int main(int argc, char const *argv[])
{
  SoSimple obj(7);
  cout << "함수 호출 전" << endl;
  SimpleFuncObj(obj);
  cout << "함수 호출 후" << endl;
  return 0;
}

/*
함수 호출 전
Called SoSimple(const SoSimple &copy)
num : 7
함수 호출 후
*/

// 우선 실행 결과를 통해서 함수에 인자를 전달하는 과정에서 복사 생성자가 호출된다.
// 그리고 이로 인해서 멤버변수 num에 저장된 값이 복사됨을 확인하였다.
// 그렇다면 복사 생성자의 호출 주제가 생성자가 호출되는 것인지 헷갈리지 않는가?

// 초기화 객체 대상은 obj 객체가 아닌 ob 객체이다.
// 그리고 ob 객체는 obj 객체로 초기화된다.
// 따라서 ob 객체의 복사 생성자가 호출되면서, obj 객체가 인자로 전달되어야 한다.
class SoSimple
{
private:
  int num;

public:
  SoSimple(int n) : num(n) {}

  SoSimple(cosnt SoSimple &copy) : num(copy.num)
  {
    cout << "Called SoSimple(const SoSimple &copy)" << endl;
  }

  SoSImple &AddNum(int n)
  {
  }

  void ShowData()
  {
    cout << "num : " << num << endl;
  }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
  cout << "return 이전" << endl;
  return ob;
}

int main(int argc, char const *argv[])
{
  SoSimple obj(7);
  SimpleFuncObj(obj).AddNum(30).ShowData();
  obj.ShowData();
  return 0;
}

/*
Called SoSimple(const SoSimple &copy)
return 이전
Called SoSimple(const SoSimple &copy)
num : 37
num : 7
*/

// 위는 이런 방식이다.
SoSimple SimpleFuncObj(SoSimple ob)
{ // 복사 객체 ob 생성 -> 복사 함수 호출
  cout << "return 이전" << endl;
  return ob; // 임시 객체 (Temporary Object) 생성 -> 복사 함수 호출
}

// 위의 그림에서 보이듯이 객체를 반환하게 되면, "임시객체"라는 것이 생성되고, 이 객체의 복사 생성자가 호출되면서 return 문에 명시된 객체가 인자로 전달된다.
// 즉, 최종적으로 반환되는 객체는 새롭게 생성되는 임시객체이다.

// Todo : 반환할 때 만들어진 객체는 언제 사라지나 (임시객체)
// 임시객체도 임시변수와 마찬가지로 임시로 생성되었다가 소멸되는 객체이다. 그리고 임시 객체는 우리가 임의로 만들 수도 있다.

#include <iostream>
using namespace std;
class Temporary
{
private:
  int num;

public:
  Temporary(int n) : num(n) { cout << "create obj : " << num << endl; }
  ~Temporary()
  {
    cout << "destroy obj : " << num << endl;
  }
  void ShowTempInfo()
  {
    cout << "My num is " << num << endl;
  }
};

int main(int argc, char const *argv[])
{
  Temporary(100);
  cout << "1번 Temporary after make!" << endl;

  Temporary(200).ShowTempInfo();
  cout << "2번 Temporary after make!" << endl;

  const Temporary &ref = Temporary(300);
  cout << "3번 Temporary after make!" << endl;
  return 0;
}
/*
create obj : 100
destroy obj : 100
1번 Temporary after make!

create obj : 200
My num is 200
destroy obj : 200
2번 Temporary after make!

create obj : 300
3번 Temporary after make!

destroy obj : 300
*/

// 실행결과를 보자
// Temporary(200).ShowTempInfo();

// 클래스의 외부에서 객체의 멤버함수를 호출하기 위해 필요한 것은 다음 세가지 중 하나다.
// 1. 객체에 붙여진 이름
// 2. 객체의 참조 값(객체 참조에 사용되는 정보)
// 3. 객체의 주소값

// 그런데 임시객체가 생성된 위치에는 임시객체의 참조 값이 반환된다. 즉, 위의 문장의 경우 먼저 임시객체가 생성되면서 다음의 형태가 된다.

// (임시객체의 참조값).ShowTempInfo();

// 그런데 이어서 멤버함수의 호출이 가능한 것이다. 또한 이렇듯 "참조값"이 반환되기 때문에 다음의 문장도 가능한 것이다.
// const Temporary &ref = Temporary(300);

// 위의 코드는 ref 가 임시객체를 참조하게 된다.
// 실제로 임시 객체가 통째로 반환되는 것이 아닌 임시객체는 메모리에 저장되고, 그 객체의 참조값이 반환된다.

// Todo : 즉 반환을 위해서 임시객체가 생성은 되지만, 이 객체는 메모리 공간에 존재하고, 이 객체의 참조값이 반환되어서 함수 호출이 진행이 된다.
// 실행결과를 통해서 내릴 수 있는 결론 두가지다.

// 1. 임시객체는 다음 행으로 넘어가면 바로 소멸된다.
// 2. 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.

// 즉, 임시객체를 참조자로 참조하는 순간 바로 소멸되지 않고 다음 행에서도 접근이 가능하다.

// 다음 문장을 실행해보자

#include <iostream>
using namespace std;
class SoSimple {
  private : 
  int num;
  public :
  SoSimple(int n) : num (n) {
    cout<<"New Object : "<<this<<endl;
  }

  SoSimple(const SoSimple & copy) : num(copy.num) {
    cout<<"New Copy obj : "<<this<<endl;
  }
  ~SoSimple() {
    cout<<"Destroy obj : "<<this<<endl;
  }
};

SoSimple SimpleFuncObj(SoSimple ob) {
  cout<<"Param ADR : "<<&ob<<endl;
  return ob;
}

int main(int argc, char const *argv[])
{
  SoSimple obj(7);
  SimpleFuncObj(obj);

  cout<<endl;
  SoSimple tempRef = SimpleFuncObj(obj);
  cout<<"return obj : "<<&tempRef<<endl;
  return 0;
}

/*
New Object : 0x61fd30    // SoSimple obj(7);
New Copy obj : 0x61fd38  // SimpleFuncObj(obj); -- 복사 생성자로 ob 객체 생성
Param ADR : 0x61fd38     // ob 객체의 주소값
New Copy obj : 0x61fd34  // return ob;  -- 임시 객체생성
Destroy obj : 0x61fd34   // 임시객체 제거
Destroy obj : 0x61fd38   // 매개 변수 ob 객체 제거

New Copy obj : 0x61fd3c  // SimpleFuncObj(obj) - 복사 생성자 (obj) 객체 생성
Param ADR : 0x61fd3c     // obj 의 주소값
New Copy obj : 0x61fd2c  // 임시 객체 복사 생성자 객체 생성
Destroy obj : 0x61fd3c   // 매개변수 obj 제거
return obj : 0x61fd2c    // return 된 ob 의 주소값  --- ******* ob 객체를 다음 행에서도 사용 가능
Destroy obj : 0x61fd2c   // tempRef 가 참조하는 임시객체 소멸
Destroy obj : 0x61fd30   // obj 소멸
*/

// 위의 결과에서 알 수 있듯이 , 추가로 객체를 생성하는 것이 아닌, 반환되는 임시객체에 tempRef 라는 이름을 할당하고 있음을 보여준다.
// (객체의 생성 수를 하나 줄여서 효율성을 높이기 위해서)
