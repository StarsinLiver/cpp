// // Todo : C++ 에서의 형 변환 연산
// // C++ 에서는 다음과 같이 총 4개의 연산자를 추가로 제공하면서 용도에 맞는 형 변환 연산자의 사용을 유도하고 있다.

// // 1. static_cast
// // 2. const_cast
// // 3. dynamic_cast
// // 4. reinterpret_cast

// // Todo : dynamic_cast : 상속관계에서의 안전한 형 변환
// // 다음의 형태를 갖는다.

// dynamic_cast<T>(expr)

// // 즉, <> 사이에 변환하고자 하는 자료형의 이름을 두되, 객체의 포인터 또는 참조형이 와야하며, () 사이에는 변환 대상이 와야한다.
// // 그리고 요구한 형 변환이 적절한 경우에는 형 변환 된 데이터를 반환하고 요구한 형 변환이 적절하지 않는 경우에는 컴파일 시 에러가 발생한다.

// // 적절한 경우란 "상속관계에 놓여 있는 두 클래스 사이에서 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환 하는 경우"

// #include <iostream>
//     using namespace std;

// class Car
// {
// }

// class Truck : public Car
// {
// }

// int
// main(int argc, char const *argv[])
// {
//   Car *pcar1 = new Car();
//   Truck *ptruck1 = dynamic_cast<Truck *>(pcar1); // 컴파일 에러

//   Car *pcar2 = new Car();
//   Truck *ptruck2 = dynamic_cast<Truck *>(pcar2); // 컴파일 에러

//   Truck *ptruck3 = new Truck();
//   Car *pcar3 = dynamic_cast<Car *>(ptruck3); // OK!!
//   return 0;
// }

// // dynamic_cast 는 다음의 의미를 두고 있다.
// // "상속 관계에 있는 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환하겠습니다!"

// // Todo : static_cast : A 타입에서 B 타입으로
// // static_cast 형 변환 연산자는 다음의 형태를 갖는다

// static_cast<T>(expr);

// // 그리고 static_cast 연산자를 사용하는 우리들에게 컴파일러는 다음과 같이 이야기한다.
// // "좋아! 유도 클래스의 포인터 및 참조형 ㄷ이터를 기초 클래스의 포인터 및 참조형 데이터로뿐만아니라, 기초 클래스의 포인터 및 참조형 데이터도 유도 클래스의 포인터
// // 및 참조형 데이터로 아무런 조건 없이 형변환 시켜줄게. 하지만 그에 대한 책임은 네가 져야 해!"

// int main(int argc, char const *argv[])
// {
//     Car *pcar1 = new Truck();
//   Truck *ptruck1 = static_cast<Truck *>(pcar1); // 컴파일 OK!!

//   Car *pcar2 = new Car();
//   Truck *ptruck2 = static_cast<Truck *>(pcar2); // 컴파일 OK! 그러나!
//   ptruck2 -> 어떠한함수();
//   return 0;
// }

// // "static_cast 연산자는 dynamic_cast 연산자와 달리, 보다 많은 형 변환을 허용합니다.
// // 하지만 그에 대한 책임도 프로그래머가 져야하기 때문에 신중하게 선택해야합니다.
// // dynamic_cast 연산자를 사용할 수 있는 경웨는 dynamic_cast 연산자를 사용해서 안전성을 높여야 하며, 그 이외의 경우에는
// // 정말 책임질 수 있는 상황에서만 제한적으로 static_cast 연산자를 사용해야 합니다."

// // 다만, static_cast 가 dynamic_cast 보다 연산 속도가 더 빠르다.

// // Todo : const_cast : const 의 성향을 삭제하라!
// // C++ 에서는 포인터와 참조자의 const 성향을 제거하는 형 변환을 목적으로 ,다음의 형 변환 연산자를 제공하고 있다.

// const_cast<T>(expr)

// // 위의 연산자를 통해서 const 로 선언된 참조자, 그리고 포인터의 const 성향을 제거하는 것이 의미가 있을까?
// // 사실 이러한 연산은 const 의 가치를 떨어뜨리는 것이라고 생각할 수 있는데,
// // 이면을 잘 보면 나름의 의미를 발견할 수 있다.

// #include <iostream>
// using namespace std;

// void ShowString(char* str) {
//   cout<<str<<endl;
// }

// void ShowAddResult(int & n1 , int & n2) {
//   cout<<n1 + n2<<endl;
// }

// int main(int argc, char const *argv[])
// {
//   const char* name = "Lee Sung Ju";
//   ShowString(const_cast<char*>(name));

//   const int& num1 = 100;
//   const int& num2 = 200;
//   ShowAddResult(const_cast<int&>(num1) , const_cast<int&>(num2));
//   return 0;
// }

// /*
// Lee Sung Ju
// 300
// */

// // 이렇듯 const_cast 형 변환 연산은, 함수의 인자 전달시 const 선언으로 인한 형 (type)의 불일치가 발생해서 인자의 전달이 불가능한 경우에 유용하게 사용이 된다.

// // Todo : reinterpret_cast : 상관없는 자료형으로의 형 변환
// // reinterpret_cast 연산자는 전혀 상관이 없는 자료형으로의 형 변환에 사용이 되며, 기본적인 형태는 같다

// reinterpret_cast<T>(expr);

// // 두 클래스를 보면 상속 관계를 맺은 것이 아닌 서로 전혀 상관없는 클래스이다.
// class SimpleCar {...}
// class BestFriend {...}

// // 그런데 두 클래스를 대상으로 다음과 같은 코드를 작성할 때 사용되는 것이 reinterpret_cast 이다.
// int main(int argc, char const *argv[])
// {
//   SimpleCar * car =new Car;
//   BestFriend * fren = reinterpret_cast<BestFriend*>(car);
//   return 0;
// }

// 이렇듯 reinterpret_cast 연산자는 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용한다.

// 다음 예제를 살펴보자
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int num = 0x010203;
  char * ptr = reinterpret_cast<char*>(&num);

  for(int i = 0; i < sizeof(num); i++) 
    cout<<static_cast<int>(*(ptr+i))<<endl;
  return 0;
}

/*
3
2
1
0
*/

// 다음과 같이도 가능하다

int main(int argc, char const *argv[])
{
  int num = 72;
  int* ptr = &num;

  int adr = reinterpret_cast<int>(ptr); // 주소 값을 정수로 변환
  cout<<"Addr : "<<adr<<endl; // 주소 값 출력

  int* rptr = reinterpret_cast<int*>(adr); // 정수를 다시 주소값으로 변환
  cout<<"Addr : "<<*radr<<endl; // 주소 값에 저장된 정수 출력

  return 0;
}

