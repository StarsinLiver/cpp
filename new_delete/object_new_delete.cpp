// Todo : malloc 과 free 를 대신하는 new & delete
#include <iostream>
#include <cstring>

using namespace std;

// 객체의 생성에서는 반드시 new & delete 를 사용해보자
class Simple {
  public: Simple() {
    cout<<"I'm simple constructor"<<endl;
  } 
};

int main(int argc, char const *argv[])
{
  // new 연산자를 사용
  cout<<"case 1: ";
  Simple * sp1 = new Simple();


  // malloc 을 사용
  cout<<"case 2 : ";
  Simple * sp2 = (Simple*)malloc(sizeof(Simple)*1);

  cout<<endl<<"end of main"<<endl;

  // delete 사용 과 free 사용
  delete sp1;
  free(sp2);

  // 위의 실행결과에서 알 수 있듯 case1 에서는 문자가 출력된 반면 case2 에서는 문자가 출력되지 않았다.
  // 즉, 결론은 "new 와 malloc 함수의 동작방식에는 차이가 있다."
}
