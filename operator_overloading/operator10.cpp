// Todo : new 와 delete
// 실행 결과를 통해서 맴버함수 operator new 와 맴버 함수 operator delete 가 호출되는 것은 확인을 하였다
// 아직 객체생성이 완성된 상태가 아닌데, 어떻게 맴버함수의 호출이 가능했을 지 생각해보자

// "아! operator new 함수와 operator delete 함수가 static 으로 선언된 함수라면?"
// 그렇다! operator new ㅎ마수와 operator delete 함수가 static 으로 선언된 함수라면 말이 된다.

// Todo : operator new & operator new []
// 앞서 설명한 내용을 잘 이해했다면 다음 내용은 쉽게 이해가 가능하다

void * operator new (size_t size) { ... }
void * operator new[] (size_t size) { ... }

// 첫번째 함수는 앞서 설명한 것이고, 두 번째 함수는 new 연산자를 이용한 배열 할당시 호출되는 함수이다

// 즉, 이런 new 할당이다

Point * arr = new Point[3];

// 컴파일러는 세 개의 Point 객체에 필요한 메모리 공간을 바이트 단위로 계산해서, 이를 인자로 전달하면서 다음 함수를 호출하낟.

void * operator new[] (size_t size) { ... }

// 즉, 배열할당 시 호출되는 함수라는 사실을 제외하고는 operator new 함수와의 차이가 없다.

// Todo : operator delete & operator delete[]

// 마찬가지로 delete 연산자도 다음 두 가지의 형태로 오버로딩이 가능하다.

void operator delete (void * adr) { ... }
void operator delete[] (void * adr) { ... }

// 첫 번째 함수는 앞서 설명한 것이고, 두번째 함수는 delete 연산자를 이용한 배열소멸시 호출되는 함수이다.

// 즉, 이런 delete 이다.

delete []arr;

// 컴파일러는 소멸자를 호출한 이후에 arr 에 저장된 주소 값을 전달하면서 다음 함수를 호출한다.

void operator delete[] (void * adr) { ... }

// 이렇듯, 이 함수 역시도 배열 소멸 시 호출되는 함수라는 사실을 제외하면, operator delete 함수와 차이가 없다.

// Todo : 예제
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

  void * operator new[] (size_t size) {
    cout<<"operator new : "<<size<<endl;
    void * adr = new char[size];
    return adr;
  }

  void operator delete (void * adr) {
    cout<<"operator delete ()"<<endl;
    delete []adr;
  } 

    void operator delete[] (void * adr) {
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
  Point * arr = new Point[3];

  delete ptr;
  delete []ptr;
  return 0;
}

/*
operator new : 8
operator new : 24
operator delete ()
operator delete ()
*/

// 위 예제에서는 함수의 호출시점을 확인하기 위한 용도로 간단히 정의하였다. 그리고 이로써 new 와 delete 연산자의 오버로딩에 대한 설명을 마무리 하겠다.