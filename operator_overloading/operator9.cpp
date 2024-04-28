// Todo : 그 이외의 연산자 오버로딩
// new 와 delete 도 연산자이기 때문에 오버로딩이 가능하다. 그래서 이 두 연산자의 오버로딩에 대해서 예를 보이겠다.
// 또한 포인터 연산자를 오버로딩하면서 개념적으로 어렵다는 "스마트 포인터(smart pointer)" 와 "펑터(functor)" 에 대해서도 알아보자

// Todo : new 연산자 오버로딩
// new 와 delete 를 C++ 문법을 구성하는 단순한 키워드가 아닌, 분명 연산자이다.
// 따라서 연산자 오버로딩이 가능하며, 이 둘을 이용해서 클래스 별로 독특한 객체의 생성과정을 정의할 수도 있다.
// 그런데 이 둘에 대한 연산자 오버로딩은 이전에 보았던 연산자 오버로딩과는 다소 차이가 있다
// 간단한 예제를 보자

#include <iostream>
using namespace std;

class Point {
  private:  
  int xpos , ypos;
  pbulic :
  Point(int x = 0 , int y = 0) : xpos(x) , ypos(y) {}
  friend ostream& operator<<(ostream& os , const Point& pos);
};

ostream& operator<<(ostream& os , const Point& pos) {
  os<<'['<<pos.xpos<<" , "<<pos.ypos<<"]"<<endl;
  return os;
}

// Point * ptr = new Point(3 , 4);
// 이때 new 연산자가 오버로딩 되어 있다면 위의 문장은 어떻게 해석이 되는가?
// 기본적인 것은 다음과 같다

// - 메모리 공간의 할당
// - 생성자의 호출
// - 할당하고자 하는 자료형에 맞게 반환된 주소 값의 형 변환

// 이 중에서 세번째 내용은 malloc 과는 달리, new 연산자가 반환하는 주소 값을 형 변환할 필요가 없음을 의미한다.

// "객체의 생성과정은 다소 복잡한 과정을 거치니까, 생성자의 호출과 반환된 주소 값의 형 변환은 계속해서 내가 책임질게, 그러니 new 연산자를 오버로딩 할 때에는 메모리
// 공간의 할당만 책임져"

// Todo : 즉, 우리는 위에서 말한 new 연산자가 진행하는 세 가지 작업 중에서 1번에 해당하는 메모리 공간의 할당만 오버로딩을 할 수 있는 것이다.
// 그리고 나머지 두 가지 작업은 여전히 C++ 컴파일러에 의해서 진행이 되며, 오버로딩이 불가능 하다.
// 오버로딩은 다음과 같다.

void * operator new (size_t size) {...}

// 반환형은 반드시 void 포인터 형이어야 하고, 매개변수형은 size_t 이어야 한다
// 그리고 이렇게 오버로딩 된 함수는 컴파일러에 의해서 호출이 이루어진다
// 컴파일러는 Point 클래스를 대상으로 new 연산자가 오버로딩 된 상태에서 다음 문자을 만나면,
Point * ptr = new Point(3 , 4);

// 먼저 필요한 메모리 공간을 계산한다. 그리고 그 크기가 계산이 됬다면, operator new ㅎ마수를 호출하면서 계산된 크기의 값을 인자로 전달한다.
// 여기서 중요한 것은 크기정보는 바이트 단위로 계산되어 전달된다는 점이다.

void * operator new (size_t size) {
  void * adr = new char[size];
  return adr;
}


// 컴파일러에 의해서, 필요한 메모리 공간의 크기가 바이트 단위로 계산되어서 인자로 전달되니, 크기가 1바이트인 char 단위로 메모리 공간을 할당해서 반환하였다.
// 물론 이것이 operator new 함수의 전부라면 굳이 new 연산자를 오버로딩할 필요가 없다.
// 하지만 이는 operator new 함수가 반드시 해야할 일이 '메모리 공간의 할당' 임을 알리기 위한 것이다. 여러분은 이 이상의 일을 하도록
// operator new 함수를 정의해야한다. new 연산자를 오버로딩 했다면 말이다.

// 이렇게 해서 operator new 함수가 할당한 메모리 공간의 주소 값을 반환하면, 컴파일러는 생성자를 호출해서 메모리 공간을 대상으로 초기화를 진행한다
// 정리하면 다음 문장에서

Point * ptr = new Point(3, 4);

// new 연산자가 반환하는 값은 operator new 함수가 반환하는 값이 아니다. operator new 함수가 반환하는 값은, 컴파일러에 의해 적절히 형 변환이 된 값이다.
// 또한 생성자의 호출 정보는 oeprator new 함수와 아무런 상관이 없다. 생성자의 호출은 여전히 컴파일러의 몫이기 때문에 이 정보는 컴파일러에 의해서 참조될 뿐이다.

// "new 연산자가 맴버함수의 형태로 오버로딩 되었다면, 객체가 생성된 이후에 호출이 되어야 하잖아! 근데 new 연산자는 객체를 생성할 때 사용하는 연산자란 말이야!"

// Todo : delete 연산자 오버로딩에 대한 상세한 이해와 예제

// 앞의 new 연산자의 내용을 이해했다면 delete 연산자의 오버로딩에 대해서는 쉽게 이해가 가능하다.

Point * ptr = new Point (3 , 4);

// 다음의 문장으로 객체의 소멸을 명령하면

delete ptr;

// 컴파일러는 먼저 ptr 이 가리키는 객체의 소멸자를 호출한다.
// 그리고는 다음의 형태로 정의된 함수에 ptr 에 저장된 주소 값을 전달한다.

void operator delete (void * adr) { ... }

// 따라서 delete 함수는 다음의 형태로 정의해야 한다. 즉, 소멸자는 오버로딩 된 함수가 호출되기 전에 호출되니 오버로딩 된 함수에서는 메모리 공간의 소멸을 책임져야한다.
// 물론, 그 이외의 필요한 내용은 얼마든지 추가로 담을 수 있다.

void operator delete (void  * adr) {
  delete []adr;
}

// 참고로, 사용하는 컴파일러에서 void 포인터 형 대상의 delete 연산을 허용하지 않는다면 위의 delete 문을 다음과 같이 작성하면 된다
// 즉, char 포인터 형으로 변환해서 delete 연산을 진행하면 된다

delete []((char*) adr);

// Todo : 자! 그럼 이제 new 와 delete 연산자를 오버로딩 해보자
#include <iostream>
using namespace std;

class Point {
  private :
  int xpos , ypos;
  public :
  Point(int x = 0, int y = 0) : xpos(x) , ypos(y) {}
  friend ostream& operator<<(ostream& os , const Point& pos);

  // void 포인터
  void * operator new (size_t size) {
    cout<<"operator new : "<<size<<endl;
    void * adr = new char[size];
    return adr;
  }

  void operator delete (void * adr) {
    cout<<"operator delete ()"<<endl;
    delete []adr;
  } 
};

ostream& operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << " , " << pos.ypos << ']' << endl;
  return os;
}

int main(int argc, char const *argv[])
{
  Point * ptr = new Point(3 ,4);
  cout<<*ptr;
  delete ptr;
  return 0;
}

/*
operator new : 8
[3 , 4]
operator delete ()
*/

// Todo : new 와 delete
// 실행 결과를 통해서 맴버함수 operator new 와 맴버 함수 operator delete 가 호출되는 것은 확인을 하였다
// 아직 객체생성이 완성된 상태가 아닌데, 어떻게 맴버함수의 호출이 가능했을 지 생각해보자

// "아! operator new 함수와 operator delete 함수가 static 으로 선언된 함수라면?"
// 그렇다! operator new ㅎ마수와 operator delete 함수가 static 으로 선언된 함수라면 말이 된다.