// Todo : function 객체
// function 은 std 네임스페이스에 속한 함수 객체입니다.

// 함수 객체란 함수는 아니지만 함수처럼 호출할 수 있도록 정의한 객체를 말합니다.

// Todo : 함수 보인터란 무엇인가?
// 함수 포인터는 포인터를 활용하여 함수를 호출하는 방법입니다. 함수 호출은 메모리에서 함수의 주솟값을 찾아가는 명령이므로 함수 포인터로 함수의 주솟값을
// 찾아가는 동작도 함수 호출과 동일한 결과를가집니다. 
// C와 C++ 언어에서 함수 포인터는 콜백을 구현할 때 자주 사용됩니다.

// Todo : 콜백이란?
// 콜백(callback)이란 다시 부른다는 의미로, 프로그램에서 다른 함수에 의해 특정한 실행이 필요할 때 호출되는 함수를 나타냅니다.

// 예시로써 퀵 정렬 함수 qsort 는 다음처럼 선언되어있습니다.
// void qsort (
//   void* base,
//   size_t num,
//   size_t size,
//   int (*compare)(const void*, const void*) // 함수 포인터
// );

// 위 처럼 함수 포인터는 콜백을 구현할 때 사용할 수 있을 뿐만아니라 , 여러 함수를 구조체나 배열에 포인터로 보관한 후 필요한 함수를
// 적절히 선택하는 알고리즘을 구현할 때 등 다양한 방식으로 사용될 수 있습니다. 다만, 함수 포인터를 남발하면 가독성이 떨어지고 유지 및 보수가 어렵습니다.

// Todo : 함자(functor) 이란?
// 함자는 매우 생소한 용어입니다. C++ 언어에서 함자는 '함수 객체 (function object)'라고 합니다
// 함수 객체를 풀어서 설명하면 함수처럼 호출할 수 있는 객체(callable object)를 말합니다.

#include <iostream>
using namespace std;

struct bomb {
  void operator() () {
    cout<<"꽝!"<<endl;
  }

  void operator() (int range) {
    cout<<"반경"<<range<<"m 내 플레이어 공격"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  bomb mine;

  mine();
  mine(30);

  return 0;
}

/*
꽝!
반경30m 내 플레이어 공격
*/

// 구조체에서 함자를 정의하려면 함수 호출 연산자 operator()를 오버로딩하빈다. 그러면 구조체 객체를 선언한 후 객체 자체를 함수처럼 사용할 수 있습니다.
// 이처럼 함자는 연산자 오버로딩으로 정의하므로 구조체뿐만아니라 클래스에서 사용할 수 있습니다.

// Todo : function 클래스
// C++ 에서는 함수 포인터, 함자, 람다까지 객체를 함수처럼 활용하는 다양한 방법이 있습니다.
// 모던 C++ 에서는 이처럼 다양한 호출 객체를 통일된 형식으로 사용할 수 있도록 function 클래스를 제공합니다. function 은 클래스 템플릿으로 정의되었으며,
// function 으로 선언한 객체에는 함수, 함자 , 람다 그리고 클래스의 맴버 함수를 저장하고 호출할 수 있습니다.

// Todo : function 문법 요약
// 함수를 저장하는 function 객체
function<return_Data_type(param0 , param1)> func_name = function;

// 클래스, 구조체 멤버 함수를 저장하는 function 객체
function<return_data_type(object& , param0 , param1)> func_name = &class|struct::target_method;

// function 객체를 생성할 때는 함수처럼 반환값과 매개변수이 데이터 형식을 지정해주어야 합니다. 그리고 함자나 멤버 함수를 function 에 저장할 때는 대상(객체 )의 주소
// 를 함께 전달해야합니다.

#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

void function_pointer(int input) {
  cout<<"함수 포인터 대상 함수 : "<<input <<endl;
}

struct functor {
  void operator()(char functor_prefix) {
    cout<<"함자 : "<<functor_prefix<<endl;
  }
};

class class_object {
  private :
  string class_object_name;

  public :
  class_object(string init_string) : class_object_name(init_string) {}
  void std_function_call_member(string contents) {
    cout<<"클래스 맴버 함수 객체화 ("<<class_object_name<<") : "<<contents<<endl;
  }
};

int main(int argc, char const *argv[])
{
  class_object class_obj("호출 개게를 가지고 있는 클래스");

  functor functor_obj;

  function<void(int)> func_pointer = function_pointer;
  
  function<void(functor& , char)> functor_func = &functor::operator();
  
  function<void(double)> lambda_func = [](double input) {
    cout<<"람다 함수 : "<<input <<endl;
  };

  function<void(class_object& , string)> member_func = &class_object::std_function_call_member;

  func_pointer(10);
  functor_func(functor_obj , 'A');
  lambda_func(0xa8);
  member_func(class_obj , "출력");
  return 0;
}

/*
함수 포인터 대상 함수 : 10
함자 : A
람다 함수 : 168
클래스 맴버 함수 객체화 (호출 개게를 가지고 있는 클래스) : 출력
*/

// function 은 클래스 템플릿이므로 컨테이너 처럼 함수 형식을 <> 사이에 넣습니다. 여기에는 함수, 함자 , 멤버 함수 , 람다 함수등의 데이터 형식을 넣을 수 있습니다.