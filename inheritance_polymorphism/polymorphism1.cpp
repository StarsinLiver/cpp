
// Todo : 함수 오버라이딩
#include <iostream>
using namespace std;
class List {
  public :
  void ShowInfo() {
    cout<<"list"<<endl;
  }
};

class Over : public List {
  public :
  void ShowInfo() {
    cout<<"Over"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  Over* over = new Over();

  over ->ShowInfo();
  return 0;
}

