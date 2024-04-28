// Todo : 클래스 템플릿 (Class template)

// 앞서 함수를 템플릿으로 정의했듯이 클래스도 템플릿으로 정의가 가능하다.

#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
  T xpos, ypos;

public:
  Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}

  void ShowPosition() const
  {
    cout << "[" << xpos << " , " << ypos << "]" << endl;
  }
};

int main(int argc, char const *argv[])
{
  Point<int> pos1(3, 4);
  pos1.ShowPosition();

  Point<double> pos2(2.4, 3.6);
  pos2.ShowPosition();

  Point<char> pos3('P', 'F');
  pos3.ShowPosition();
  return 0;
}

/*
[3 , 4]
[2.4 , 3.6]
[P , F]
*/

// 함수 템플릿과 마찬가지로, 컴파일러는 "클래스 템플릿"을 기반으로 "템플릿 클래스"를 만들어 낸다.

// Todo : "템플릿 함수를 호출할 때와 마찬가지로 템플릿 클래스의 객체를 생성할 때에도 <int> , <double> 과 같은 자료형 정보를 생략할 수 있나요?"
// 안타깝게도 이 경우에는 생략이 불가능 하다.
// 클래스 템플릿 기반의 객체생성에는 반드시 자료형 정보를 명시하도록 되어있다.

// Todo : 클래스 템플릿의 선언과 정의의 분리
#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
  T xpos, ypos;

public:
  Point(T x = 0, T y = 0);

  void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T>
void Point<T>::ShowPosition() const
{
  cout << "[" << xpos << " , " << ypos << "]" << endl;
}

int main(int argc, char const *argv[])
{
  Point<int> pos1(3, 4);
  pos1.ShowPosition();

  Point<double> pos2(2.4, 3.6);
  pos2.ShowPosition();

  Point<char> pos3('P', 'F');
  pos3.ShowPosition();
  return 0;
}

/*
[3 , 4]
[2.4 , 3.6]
[P , F]
*/

// Todo : 파일 분할 (컴파일 에러)
// 클래스 템플릿의 멤버함수를 외부에 정의하는 방법도 알았으니, 이번에는 위의 예제를 대상으로 파일 분할원칙을 적용해보자

#include <iostream>
#include "./separate/PointTemplate.h"
using namespace std;

int main(int argc, char const *argv[])
{
  Point<int> pos1(3, 4);
  pos1.ShowPosition();

  Point<double> pos2(2.4, 3.6);
  pos2.ShowPosition();

  Point<char> pos3('P', 'F');
  pos3.ShowPosition();
  return 0;
}

// Todo : 컴파일 에러 문제가 발생하는 것이 당연합니다.
// Todo : 파일을 나루 때에는 고려할 사항이 있습니다.

// 컴파일은 파일단위로 이뤄진다는 사실을 이미 알고 있을 것이다.

int main(int argc, char const *argv[])
{
  Point<int> pos1(3, 4); // Point<int> 템플릿 클래스가 만들어 지는 시점
  ...
 
  Point<double> pos2(2.4, 3.6); // Point<double> 템플릿 클래스 만들어지는 시점
  ...

  Point<char> pos3('P', 'F'); // Point<char> 템플릿 클래스가 만들어지는 시점
  ...
  return 0;
}

// 위의 main 함수가 정의된 소스파일 PointMain.cpp 가 컴파일 될때, 컴파일러는 총 3개의 템플릿 클래스를 생성해야 한다.
// 그리고 이를 위해서는 클래스 템플릿인 Point 의 모든 것을 알아야한다.
// 즉, 컴파일러에는 헤더 파일 PointTemplate.h 에 담긴 정보 뿐만아니라, PointTmpelate.cpp 에 담긴 정보도 필요하다

// Todo : 즉, PointTemplate.cpp 에 대한 어떠한 선언도 되어있지 않다.

// "클래스 템플릿인 Point 에 대한 정보가 부족합니다."
// "컴파일러가 PointMain.cpp 를 컴파일 할 때 PointTemplate.cpp 도 함께 컴파일을 하니까, 컴파일러는 PointTemplate.cpp 에 담긴 내용도 다 알고 있는 것이 아닌가?"

// 동시에 컴파일 되는 것은 맞다. 그러나 이 둘은 서로 다른 소스파일이기 때문에, 그리고 파일 단위 컴파일 원칙에 의해서 PointMain.cpp 을 컴파일 하면서
// PointTemplate.cpp 의 내용을 참조하지 않으며, PointTemplate.cpp 을 컴파일 할 때에도 PointMain.cpp 의 내용을 참조하지 않아 컴파일 에러가 발생한다.

// Todo : 해결책
// "헤더파일 PointTemplate.h 에 템플릿 Point 의 생성자와 멤버 함수의 정의를 모두 넣는다."
#include <iostream>
#include "./separate/PointTemplate.h"
#include "./separate/PointTemplate.cpp" // Todo : 추가
using namespace std;

int main(int argc, char const *argv[])
{
  Point<int> pos1(3 ,4);
  pos1.ShowPosition();
  return 0;
}

/*
[3 , 4]
*/
// 다소 이상하게 보일 수 있지만, 템픞릿의 경우에는 이러한 방법을 사용해서라도 템플릿의 모든 정보를 소스파일에 전달해야 한다.
// 그리고 실제로 이 #include 문의 삽입 하나로 위의 예제는 컴파일과 실행이 가능해진다.

