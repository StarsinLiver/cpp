#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int num1 = 2010; // 2010으로 초기화 된 메모리 공간에 num1 이라는 이름이 붙게된다.

  int *ptr = &num1; // 변수 num1의 주소값을 반환해서 포인터 ptr 에 저장해라!
    // int &num2 = num1; // num1 이라는 이름이 붙어있는 메모리 공간에 num2 라는 이름이 하나 더 붙게된다.
  int &num2 = num1; // 변수 num1에 대한 참조자 num2를 선언해라!

  // 따라서 num2 는 num1의 '참조자'가 된다.
  num2 = 3047;

  cout<<"num1 : "<<num1<<endl; // 같은
  cout<<"num2 : "<<num2<<endl; // 3047 이 된다.
  cout<<"&num1 (주소값) : "<<&num1<<endl; // 같은
  cout<<"&num2 (주소값) : "<<&num2<<endl; // 주소값 이 된다.

  // 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름이 되는 것이다!
  // 참조자의 수에는 제한이 없으며, 참조자를 대상으로도 참조자를 선언할 수 있다.

  // TODO: 참자조의 선언 가능 범위
  // 참조자는 변수에 대해서만 선언이 가능하고, 선언됨과 동시에 누군가를 참조해야만 한다. 즉, 다음의 선언은 유효하지 않다
  // int &ref = 20;
  // int &ref;
  // int &ref = NULL; // 널로 초기화도 불가능 하다.


  // Todo : 포인터 변수도 변수이기 때문에 참조자의 선언이 가능하다
  int num = 12;
  int *ptr2 = &num; // num 주소를 ptr2 에 대입
  int **dptr = &ptr2; // ptr2 의 주소를 dptr 포인터에 대입

  int &ref = num; // num 주소를 ref 에 대입
  int *(&pref) = ptr2; // ptr2 주소를 pref 포인터에 대입 == ptr2
  int **(&dpref) = dptr; // dptr 포인터 주소를 dpref 포인터에 대입 == dptr

  cout<<"전부"<<ref<<endl; // ref 는 num 을 참조하고 있다.
  cout<<"같은"<<*pref<<endl; // pref -> ptr2 -> num 순으로 참조하고 있다.
  cout<<"놈 같지만 다르다 엌"<<**dpref<<endl; // dpref -> dptr -> ptr2 -> num 순으로 참조하고 있다.

  return 0;
}
