// Todo : 연산자 오버로딩

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

  Point operator+ (const Point &ref) {          // operator+ 의 이름의 함수
    Point pos(xpos + ref.xpos , ypos + ref.ypos) ;
    return pos;
  }
};

int main(int argc, char const *argv[])
{
  Point pos1(3 , 4);
  Point pos2(10 , 20);
  Point pos3 = pos1.operator+(pos2);

  pos1.ShowPosition();
  pos2.ShowPosition();
  pos3.ShowPosition();
  return 0;
}

/*
[3 , 4]
[10 , 20]
[13 , 24]
*/

// 위는 이해가 가능할 것이다.
// 그렇다면 다음 main 함수만 변경해서 예제를 한번 더 봐보자

int main(int argc, char const *argv[])
{
  Point pos1(3 , 4);
  Point pos2(10 , 20);
  Point pos3 = pos1 + pos2; // main 변경

  pos1.ShowPosition();
  pos2.ShowPosition();
  pos3.ShowPosition();
  return 0;
}

/*
[3 , 4]
[10 , 20]
[13 , 24]
*/

// 위의 의미는 누구나 pos1 과 pos2를 더하여 그 결과를 pos3 에 저장하는 의미로 해석할 것이다.
// Todo : 그렇다면 이러한 문장이 컴파일이 가능할까?
// 실행결과에서 보이듯이 컴파일이 가능할 뿐만아니라 , pos3 객체에는 pos1과 pos2의 덧셈결과가 저장되었다는 사실도 확인이 가능하다.

// "음 아마도 pos1 + pos2 가 pos1.operator+(pos2)의 다른 표현이었을 것이다."

// 그리고 다음과 같은 생각을 했다면,
// "pos1 + pos2 가 pos1.operator+(pos2)의 다른 표현이 되기 위해서 약속된 변환의 규칙이 있을 거야"

// 라면 50% 정도는 이해가 된것이다.

