// Todo : 둘 이상의 형(Type) 에 대해 템플릿 선언하기
// 함수 템플릿을 정의할 때에는 기본 자료형 선언을 못하는 것으로 오해하는 경우가 많은데, 템플릿의 정의에도 다양한 자료형의 선언이 가능할 뿐만 아니라,
// 둘 이상의 형(type)에 대해서 템플릿을 선언할 수도 있다.

#include <iostream>
using namespace std;

template <class T1 , class T2>

void ShowData(double num) {
  cout<<(T1)num<<" , "<<(T2)num<<endl;
}

int main(int argc, char const *argv[])
{
  ShowData<char , int>(65);
  ShowData<char , int>(67);
  ShowData<char , double>(68.9);
  ShowData<short , double>(69.2);
  ShowData<short , double>(70.4);
  return 0;
}

/*
A , 65
C , 67
D , 68.9
69 , 69.2
70 , 70.4
*/

// 위 예제에서는 typename 을 대신해서 class 를 사용했는데 이 위치에서의 typename 과 class 는 같은 의미로 해석이 된다.
// 따라서 다음과 같이 선언해도 좋다
template <typename T1 , typename T2>

// 다음의 형변환은 소괄호를 묶는 형태로 형 변환 명령이 가능하다 즉, 두 문장은 같은 문장이다.
int num = (int)3.14;
int num = int(3.14);

