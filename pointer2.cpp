#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  // char 형식의 배열
  char str[10] = "Hello";
  cout << "str 주소값 : " << &str << endl;

  // 배열 포인터 1번
  char *a = str;
  cout << "a 의 실제 값 == \"Hello\"를 가리킴 : " << a << endl;
  cout << "a 의 주소값 : " << &a << endl;
  cout << "a 의 * 연산자 : " << *a << endl; // 첫번째 H 를 가리킴
  cout << "a 의 * 연산자 : " << *a + 1 << endl; // 두번째 e 를 가리킴

  // 배열 포인터 2번
  char *b = a;
  cout << "b 의 실제 값 : " << b << endl; // Hello? 를 가리킴
  cout << "b 의 주소값 : " << &b << endl;
  cout << "b 의 * 연산자 : " << *b << endl; // 첫번째 H 를 가리킴
  cout << "b 의 * 연산자 : " << *b + 1 << endl; // 두번째 e 를 가리킴

  cout << endl;

  // int
  int ia = 4;
  cout << "ia 의 주소값 : " << &ia << endl;

  // 포인터 1번
  int *pa = &ia;
  cout << "pa 의 실제 값 == ia 의 주소값 : " << pa << endl;
  cout << "pa 의 주소값 : " << &pa << endl;
  cout << "pa 가 참조하는 ia 의 값 : " << *pa << endl;

  // 포인터 2번
  int **pb = &pa;
  cout << "pb 의 실제 값 == pa 의 주소값 : " << pb << endl;
  cout << "pb 의 주소값 : " << &pb << endl;
  cout << "pb 가 참조하는 pa 의 값 : " << *pb << endl;                       // pa 의 값을 의미 == ia 의 주소
  cout << "pb 가 참조하는 pa 와 pa 가 참조하는 ia 의 값 : " << **pb << endl; // pa -> ia -> ia 의 값

  cout << endl;

  // int 배열
  int iarr[5] = {1, 2, 3, 4, 5};
  cout << "iarr 의 주소값 : " << iarr << endl;  // 둘다
  cout << "iarr 의 주소값 : " << &iarr << endl; // 같음

  // 배열 포인터 1번
  int *piarr = iarr;
  cout << "piarr 의 실제 값 == iarr 의 주소값 : " << piarr << endl;
  cout << "piarr 의 주소값 : " << &piarr << endl;
  cout << "piarr 의 * 포인터 : " << *piarr << endl; // 1
  cout << "piarr 의 * 포인터 : " << *piarr + 1 << endl; // 2
  cout << "piarr 의 * 포인터 : " << *piarr + 2 << endl; // 3

  // 배열 포인터 1번
  int *pbiarr = piarr;
  cout << "pbiarr 의 실제 값 == iarr 의 주소값 : " << pbiarr << endl; // iarr 의 실제값(주소값)을 가리킴
  cout << "pbiarr 의 주소값 : " << &pbiarr << endl;
  cout << "pbiarr 의 * 연산 : " << *pbiarr << endl; // [0]의 값 : 1
  cout << "pbiarr 의 [0]의 주소값 : " << pbiarr << endl; // [0]의 주소값
  cout << "pbiarr 의 * 포인터 : " << *pbiarr + 1 << endl; // [1]의 값 : 2
  cout << "pbiarr 의 [1]의 주소값 : " << pbiarr + 1 << endl; // [1]의 주소값
  cout << "pbiarr 의 * 포인터 : " << *pbiarr + 2 << endl; // [2]의 값 : 3
  cout << "pbiarr 의 [2] 의 주소값 : " << pbiarr + 2 << endl; // [2] 의 주소값
  return 0;
}

