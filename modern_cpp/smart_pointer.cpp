// Todo : 스마트 포인터
// C++ 의 대표적인 특징은 메모리를 직접 관리할 수 있다는 점입니다.
// 즉, 필요할 때 메모리를 할당하고 필요하지 않을 때 메모리를 해제할 수 있습니다. 덕분에 C++ 언어로 만든 프로그램은 메모리를 효율적으로 사용해
// 성능이 좋지만, 메모리 할당과 해제 등을 개발자가 직접 관리해야합니다.

// 최근 프로그래밍 언어들은 메모리 관리가 아주 쉽거나 아예 필요 없는 언어도 많습니다.
// C++ 언어도 메모리 관리를 지원하고자 auto_ptr 을 제공했지만, 여러가지 문제로 C++17 부터는 제외되었습니다.
// 모던 c++ 에서는 auto_ptr 를 대신해 unique_ptr , shared_ptr , weak_ptr 등 다양한 스마트 포인터(smart pointer)를 제공합니다.
// 여기서는 unique_ptr 를 살펴보겠습니다.

// Todo : RAII 디자인 패턴
// 스마트 포인터를 이해하려면 RAII라는 디자인 패턴을 알아야 합니다
// RAII 는 Resource Acquisition Is Initialization 의 앞글자를 따서 만든 단어로 , "리소스 할당은 초기화다"라고 직역이 가능하빈다.

// RAII 패턴의 핵심은 리소스가 피요할 때 이미 할당되어 있고 리소스가 필요 없어질때 객체와 함께 해제되어 객체 내 변숫값이 객체와 함께 일정하게 유지되는 클래스 불변성
// (class invariant) 입니다.

// RAII 패턴의 주요 특징은 동적으로 할당된 메모리가 생성된 범위를 벗어나면 자동으로 해제 되는 것입니다.

// 지역변수는 스택 메모리에 할당되어 범위를 벗어나면 자동으로 해제되지만, 동적 메모리는 힙 영역에 할당되므로 직접 해제하지 않으면 프로그램이 종료되어도
// 할당된 상태로 남아 메모리 누수가 발생합니다.

// 스마트 포인터는 지역 변수의 특징과 동적 메모리의 특징을 혼합해서 사용합니다
// 지역 변수가 생섣뢰 때 동적 메모리를 할당하고 지역변수가 해제될 때 할당된 동적 메모리를 해제합니다.
// 방법은 의외로 간단한데, 동적 메모리 할당과 해제를 관리하는 클래스를 지역 변수로 만들어서 사용하면 됩니다.
// 클래스의 생성자에서 동적 메모리를 할당하고 소멸자에서 메모리를 해제하면 됩니다.

// RAII 패턴은 메모리를 필요한 범위에서 사용하고 범위를 벗어나면 자동으로 해제되는데 따라서 개발자가 객체의 생명 주기를 직접 관리하면서도 메모리 관리에 많은 신경을
// 쓰지 않아도 되는 장점이 있습니다.

// Todo : 스마트 포인터 unique_ptr 
// C++13부터 제공되는 unique_ptr 은 포인터 객체에 RAII 디자인 패턴을 적용할 수 있는 범용 스마트 포인터 클래스입니다.
// 메모리 관리 객체 또는 래퍼(wrapper)라고 불리는 unique_ptr 은 이중 참조를 허용하지 않고 하나의 포인터 변수만을 허용하는 스마트 포인터 이빈다.

// unique_ptr 은 앞에서 설명한 RAII 디자인 패턴을 구현한 범용 래퍼로서, 메모리 사용 범위를 벗어나면 메모리를 자동으로 해제합니다.

// Todo : 메모리 누수가 발생하는 코드
#include <iostream>
using namespace std;

class class_object {
  public :
  class_object() {
    cout<<"메모리가 할당되었습니다."<<endl;
  }

  ~class_object() {
    cout<<"메모리가 해제되었습니다."<<endl;
  }
};

int main(int argc, char const *argv[])
{
  class_object *unique_pointer = new class_object();
  return 0;
}

/*
메모리가 할당되었습니다.
*/

// Todo : 스마트 포인터 unique_ptr 를 이용하는 코드
// 이전 코드와 달리 객체를 생성할 때 unique_ptr 클래스로 감싸(wrapper) 주었스비낟. 스마트 포인터로 생성된 unique_pointer 는 class_object 객체와 똑같이 사용이 
// 가능합니다. 즉, 함수 호출이나 멤버 변수에 접근하는 방법은 같스빈다.
#include <iostream>
#include <memory>
using namespace std;

class class_object {
  public :
  class_object() {
    cout<<"메모리가 할당되었습니다."<<endl;
  }

  ~class_object() {
    cout<<"메모리가 해제되었습니다."<<endl;
  }
  void print_out() {
    cout<<"객체의 함수를 호출"<<endl;
  }
};

int main(int argc, char const *argv[])
{
  unique_ptr<class_object> unique_pointer(new class_object());
  unique_pointer -> print_out();
  return 0;
}

/*
메모리가 할당되었습니다.
객체의 함수를 호출
메모리가 해제되었습니다.
*/

// Todo : unique_ptr 을 생성하는 또 다른 방법으로 make_unique 함수를 사용할 수도 있습니다.
// 이때 auto 키워드를 함께 사용하면 코드를 간결하게 작성이 가능합니다. 무엇보다 new 연산자를 사용하지 않으므로 포인터를 사용하는 복잡함이 덜합니다.
// 사용법이 쉽우면서 메모리가 자동으로 해제되는 장점은 유지됩니다.

auto unique_pointer = make_unique<class_object>();