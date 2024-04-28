// Todo : 반드시 해야하는 대입 연산자의 오버로딩 (객체 간의 대입연산)

// Todo : 객체간 대입연산의 비밀 : 디폴트 대입 연산자
// 이전에 설명한 복사 생성자의 대표적인 특성이다.
// - 정의하지 않으면 디폴트 복사 생성자가 삽입된다.
// - 디폴트 복사 생성자는 맴버 대 맴버의 복사(얕은 복사)를 진행한다.
// - 생성자 내에서 동적할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야한다.

// 이어서 대입 연산자의 대표적인 특성이다.
// - 정의하지 않으면 디폴트 대입 연산자가 삽입된다.
// - 디폴트 대입 생성자는 맴버 대 맴버의 복사(얕은 복사)를 진행한다.
// - 생성자 내에서 동적할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야한다.

// 특징은 유사하나 호출되는 시점에 차이가 있다.

// int main(int argc, char const *argv[])
// {
//   // 복사 생성자
//   Point pos1(5 , 7);
//   Point pos2 = pos1; 

//   // 대입 연산자
//   Point pos3(5 ,7);
//   Point pos4(9 , 10);
//   pos4 = pos3;
//   return 0;
// }

// 여기서 중요한 사실은 pos 3 와 pos4는 이미 생성 및 초기화가 진행된 객체라는 사실이다.
// 즉, 기존에 생성된 두 객체간의 대입연산 시에는 대입 연산자가 호출된다. 그런데 우리는 이미 연산자 오버로딩을 공부한 상태이니, 그냥 딱 봐도 다음의 문장은

// pos4 = pos3;
// pos4.operator=(pos3);

// 의 형태로 해석됨을 할 수 있다.

// Todo : 대입연산자를 정의한 것과 정의하지 않은 것
#include <iostream>
using namespace std;

// 대입 연산자를 정의하지 않은 것
class First {
  private :
  int num1 , num2;
  public :
  First(int n1 = 0 , int n2 = 0) : num1(n1) , num2(n2) {}
  void ShowData () {
    cout<<num1<<" , "<<num2<<endl;
  }
};

// 대입 연산자를 정의한 것
class Second {
  private :
  int num3 , num4;
  public :
  Second(int n3 = 0 , int n4 = 0) : num3(n3) , num4(n4) {}
  void ShowData () {
    cout<<num3<<" , "<<num4<<endl;
  }

  Second& operator=(const Second& ref) {
    cout<<"Second& operator=()"<<endl;
    num3 = ref.num3;
    num4= ref.num4;
    return *this;
  }
};

int main(int argc, char const *argv[])
{
  First fsrc(111, 222);
  First fcpy;
  
  Second ssrc(333 , 444);
  Second scpy;

  fcpy = fsrc;
  scpy = ssrc;

  fcpy.ShowData();
  scpy.ShowData();

  First fob1 , fob2;
  Second sob1 , sob2;

  fob1 = fob2 = fsrc;
  sob1 = sob2 = ssrc;

  fob1.ShowData();
  fob2.ShowData();
  sob1.ShowData();
  sob2.ShowData();
  return 0;
}

/*
Second& operator=()
111 , 222
333 , 444
Second& operator=()
Second& operator=()
111 , 222
111 , 222
333 , 444
333 , 444
*/

// 위의 실행결과를 통해서 확인할 수 있는 사실은 다음과 같다.
// "분명 디폴트 대입 연산자가 삽입되어 맴버 대 맴버의 복사가 진행된다."

// 게다가, 연산문을 통해서 반환형도 예측이 가능하다.
// 즉, 위에서 정의한 First 클래스에 자동으로 삽입된 디폴트 대입 연산자는 다음과 같다.

First operator= (const First& ref) {
  num1 = ref.num1;
  num2 = ref.num2;
  return *this;
}

// 따라서 위의 함수를 First 클래스에 직접 삽입해도 실행 결과에는 차이가 없다.

// 다음과 같이 생각하기 쉽다.
// "아라? 동일한 자료형의 두 객체간에 대입션한이 허용이 되네?"

// 그리고 맴버 대 맴버의 복사가 이뤄지는 것을 보면서, C 언어의 구조체 변수간 대입연산의 결과와 비슷하다고 생각하기 쉽다.
// 그러나 앞서 보았듯이, 객체간의 대입연산은 C 언어의 구조체 변수간의 대입연산과 본질적으로 다르다.
// 이는 단순한 대입연산이 아닌, 대입 연산자를 오버로딩 한 함수의 호출이기 때문이다.

// Todo : 디폴트 대입 연산자의 문제점
// 지금부터 디폴트 대입 연산자의 문제점을 언급하고 이에 대한 해결책을 제시할 것이다.
#include <iostream>
#include <cstring>
using namespace std;

class Person {
  private :
  char * name;
  int age;

  public :
  Person (char * myname ,int myage) {
    int len = strlen(myname) + 1;
    name = new char [len];
    strcpy(name , myname);
    this -> age = myage;
  }

  void ShowPersonInfo() const {
    cout<<"이름 : "<<name<<endl;
    cout<<"나이 : "<<age<<endl;
  }

  ~Person() {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  Person man1("Lee dong woo" , 29);
  Person man2("Yoon ji yul" , 29);
  // 문제점
  man2 = man1;

  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}

/*
이름 : Lee dong woo
나이 : 29
이름 : Lee dong woo
나이 : 29
called destructor!
*/

// 실행결과를 보면 called destructor 가 딱 한번 출력되었으니, 이전에 디폴트 복사 생성자의 문제점을 설명하면서 보인 상황과 마찬가지로 소멸자의 호출과정에서 문제가
// 발생했음을 알 수 있다.

// man2 = man1 디폴트 대입 연산자가 호출되고 main 이 끝이나면서 두 객체 중 하나가 소멸되면
// 참조하고 있던 문자열 "Lee dong woo" 가 사라지면서 다른 객체에서의 delete []name 에서 런타임 에러가 발생하게 된다.

// 또한 이로 인해서 문자열 "Lee dong woo"은 소멸되지만 , "Yoon ji yul"은 메모리 누수된 상태로 존재하게 된다 


// Todo : 디폴트 대입 연산자는 두 가지 문제를 일으키므로 다음의 형태로 직접 대입 연산자를 정의해야한다.

// "깊은 복사를 진행하도록 정의한다."
// "메모리 누수가 발생하지 않도록, 깊은 복사에 앞서 메모리 해제의 과정을 거친다."

// 그렇다면 대입 연산자의 오버로딩 결과를 제시해보자
Person& operator= (const Person& ref) {
  delete []name; // 이전 name 메모리 해제
  int len = strlen(ref.name) + 1;
  name = new char[len];
  strcpy(name , ref.name); // 깊은 복사
  age = ref.age;
  return *this; 
}

// 이와 같이 구성을 한다면 메모리 누수가 일어나지 않고 런타임 에러가 발생하지 않을 것이다.

// Todo : 상속 구조에서의 대입 연산자 호출
// 예제를 확인하자
#include <iostream>
using namespace std;

class First {
  private :
  int num1 , num2;
  public :
  First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {}

  void ShowData() {cout<<num1<<" , "<<num2<<endl;}

  First & operator= (const First & ref) {
    cout<<"First& operator=()"<<endl;
    num1 = ref.num1;
    num2 = ref.num2;
    return *this;
  }
};

class Second : public First{
  private :
  int num3 , num4;
  public :
  Second(int n1 = 0 , int n2 = 0 , int n3 = 0, int n4 = 0) : First(n1 , n2), num3(n3), num4(n4) {}

  void ShowData() {
    First::ShowData();
    cout<<num3<<" , "<<num4<<endl;
    }

  // Todo : 주석을 제거해 디폴트 대입 연산자를 사용하면 실행 결과가 다름
  // Second & operator= (const Second & ref) {
  //   cout<<"Second& operator=()"<<endl;
  //   num3 = ref.num3;
  //   num4 = ref.num4;
  //   return *this;
  // }
};

int main(int argc, char const *argv[])
{
  Second ssrc(111, 222, 333 ,444);
  Second scpy(0 , 0 ,0 ,0);

  scpy = ssrc;
  scpy.ShowData();

  return 0;
}

// 주석 사용 (디폴트 대입 연산자) 사용 시
/*
First& operator=()
111 , 222
333 , 444
*/

// 주석 코드 사용 시
/*
Second& operator=()
0 , 0
333 , 444
*/

// "유도 클래스의 대입 연산자 정의에서 , 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면, 기초 클래스의 대입 연산자는 호출되지 않아서, 기초 클래스의
// 맴버변수는 맴버 대 맴버의 복사 대상에서 제외된다."

// 때문에 유도 클래스의 대입 연산자를 정의해야 하는 상황에 놓이게 되면, 기초 클래스의 대입 연산자를 명시적으로 호출해야한다.
// 즉 , 위의 예제에서 Second 클래스의 대입연산자는 다음과 같이 정의가 되어야 한다.

// Todo : 유도 클래스 대입 연산자는 이렇게
Second& operator= (const Second& ref) {
  First::operator=(ref);
  num3 = ref.num3;
  num4 = ref.num4;
  return *this;
}