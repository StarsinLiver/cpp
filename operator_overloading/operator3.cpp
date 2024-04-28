// Todo : cout , cin , endl 의 정체
// 현재까지 많이 사용한 iostream 라이브러리의 cout , cin , endl 의 정체는 operator 이다.

#include <iostream>
namespace mystd {
  using namespace std;

  class ostream {
    public :
    ostream& operator<<(char * str) {
      printf("%s" , str);
      return *this;
    }

    ostream& operator<<(char str) {
      printf("%c" ,str);
      return *this;
    }
    ostream& operator<<(int num) {
      printf("%d" , num);
      return *this;
    }
    ostream& operator<<(double e) {
      printf("%g" , e);
      return *this;
    }
    ostream& operator<<(ostream& (*fp)(ostream &ostm)) {
      return fp(*this);
    }
  };

  ostream& endl(ostream &ostm) {
    ostm<<"\n";
    fflush(stdout);
    return ostm;
  }

  ostream cout;
}

int main(int argc, char const *argv[])
{
  using mystd::cout;
  using mystd::endl;

  cout<<"Simple String";
  cout<<endl;

  cout<<3.14<<endl<<124<<endl;
  return 0;
}

// 물론 이때 사용된 cout 은 이름공간 mystd 내에 선언된 cout 이다.
// 그리고 cout<<endl 은 다음과 같이 해석된다

// cout.operator<<(endl);

// 즉, 이름공간 mystd 내에 선언된 함수 endl 을 인자로 전달하고, 함수 endl 을 호출하면서 인자로 cout을 전달하고 있다.

// Todo : << , >> 연산자의 오버로딩
// cout 과 endl 의 이해를 돕는 예제의 작성과정에서 << 연산자를 오버로딩 해 보았다. 그래서 이번에는 앞서 정의한 Point 클래스를 대상으로
// << 연산자와 >> 연산자를 오버로딩 해 보자
// 즉 다음과 같이 출력이 가능하도록 하고자 한다.

//   cout<<pos << endl; // [3 , 4] 출력

// Todo : cout<<pos
// cout<<pos 이 가능하기 위해서는 << 연산자가 오버로딩 되어 있어야한다. 그리고 만약 오버로딩을 한다면

// cout.operator<<(pos) // 맴버함수의 형태로 오버로딩
// operator<<(cout , pos) // 전역함수의 형태로 오버로딩

// 우리는 어떠한 방법을 선택하겠는가?
// 맴버함수에 의한 방법을 선택하려면 cout 객체의 맴버함수를 하나 추가해야 하므로 , ostream 클래스를 정정해야 한다.
// 그런데 이는 불가능한 방법이니, 전역함수에 의한 방법을 택하는 수 밖에 없다

// 따라서 다음의 형태로 정의해야한다.
#include <iostream>
using namespace std;

class Point {
  private :
  int xpos , ypos;

  public :
  Point(int x = 0 , int y = 0) :xpos(x) , ypos(y) {}

  void ShowPosition () const {
    cout<<"["<<xpos<<" , "<<ypos<<"]"<<endl;
  }

  friend ostream& operator<<(ostream& , const Point&);
};

ostream& operator<<(ostream& os , const Point& pos) {
  os<<'['<<pos.xpos<<" , "<<pos.ypos<<']'<<endl;
  return os;
}

int main(int argc, char const *argv[])
{
  Point pos1(1 , 3);
  cout<<pos1;
  Point pos2(101 , 303);
  cout<<pos2;
  return 0;
}

/*
[1 , 3]
[101 , 303]
*/

// cin 은 istream 클래스의 객체이다.
// istream 은 이름 공간 std 에 선언되어 있으며, 이의 사용을 위해서는 헤더 파일 <iostream>을 사용한다.
