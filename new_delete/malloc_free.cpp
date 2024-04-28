// Todo : malloc 과 free 를 대신하는 new & delete



#include <iostream>
#include <cstring>

using namespace std;

// 원래의 c 언어
// 길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 그 배열의 주소값을 반환하는 함수를 정의해보자
char * MakeStrAdr(int len) {
  char * str = (char*)malloc(sizeof(char)*len);
  return str;
}

int main(int argc, char const *argv[])
{
  
  char * str = MakeStrAdr(20); // char(1byte) 20 만큼 힙 메모리에 공간이 생긴 str 을 만들었당

  strcpy(str , "I am so Happy ~");
  cout<<str<<endl;
  free(str);

  // Todo : new 와 delete
  // 위의 예제는 c 언어에서의 동적할당을 보이기 위한 것이다. 

  // 그런데 c++ 에서 제공하는 키워드 new 와 delete 를 사용하면 이러한 불편한 점이 사라진다.
  // new 
  int * ptr1 = new int;
  double * ptr2 = new double;
  int * arr1 = new int[3];
  double * arr2 = new double[7];

  // delete
  delete ptr1;
  delete ptr2;
  delete []arr1;
  delete []arr2;
  return 0;
}
