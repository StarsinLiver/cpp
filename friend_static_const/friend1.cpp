// Todo : 클래스 와 함수에 대한 friend 선언
// 클래스의 friend 선언
// friend 선언의 의미하는 바는 이렇다.

// 1. A 클래스가 B 클래스를 대상으로 friend 선언을 하면, B 클래스는 A 클래스의 private 맴버에 직접 접근이 가능하다.
// 2. 단 A 클래스도 B 클래스의 private 멤버에 직접 접근이 가능하려면, B 클래스가 A 클래스를 대상으로 friend 선언을 해주어야 한다.

// 이렇듯 friend 선언은 private 멤버의 접근을 허용하는 선언이다.
// 예제를 확인해보자
#include <iostream>
#include <cstring>

using namespace std;

class Girl; // Girl 이라는 이름의 클래스의 이름이 있다는 것을 알림

class Boy {
  private :
  int height;
  friend class Girl;

  public :
  Boy(int len) : height(len) {}
  void ShowYourFriendInfo(Girl &grn);
};

class Girl {
  private :
  char phNum[20];
  public :
  Girl(char * num) {
    strcpy(phNum , num);
  }
  void ShowYourFriendInfo(Boy &frn);
  friend class Boy; // Boy 클래스에 대한 friend 선언
};

void Boy::ShowYourFriendInfo(Girl &frn) {
  cout<<"Her phone number: "<<frn.phNum<<endl;
}

void Girl::ShowYourFriendInfo(Boy &frn) {
  cout<<"His height : "<<frn.height<<endl;
}

int main(int argc, char const *argv[])
{
  Boy boy(170);
  Girl girl("010-1234-5678");
  boy.ShowYourFriendInfo(girl);
  girl.ShowYourFriendInfo(boy);
  return 0;
}

/*
Her phone number: 010-1234-5678
His height : 170
*/

// Todo : friend 선언은 언제?
// 사실 C++ 문법 중에서 제법 논란이 되었던 것 중 하나가 바로 이 friend 선언이다.
// friend 선언은 객체지향 대명사 중 하나인 '정보은닉'을 무너뜨리는 문법이기 때문이다.

// friend 선언과 관련해서 다음 사실은 확실히 말할 수 있다.
// "friend 선언은 지나치면 아주 위험할 수 있다. friend 선언은 필요한 상황에서 극히 소극적으로 사용하자."
