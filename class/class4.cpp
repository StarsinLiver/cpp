// Todo : 정보 은닉 (Information Hiding)
// 정보 은닉의 이해
// 뭐 알거니깐 패스 (걍 getter , setter)

// Todo : const 함수
// 앞서 보인 예제 [여기엔 없지만] 다음 함수들에는 const 선언이 추가되어 있다.

// 이 const 는 다음 내용을 선언하는 것이다
// "이 함수 내에서는 맴버변수에 저장된 값을 변경하지 않겠다."

// 매개변수도 아니고, 지역변수도 아닌, 맴버변수에 저장된 값을 변경하지 않겠다는 선언이다.
// 따라서 const 선언이 추가된 맴버함수 내에서 멤버변수의 값을 변경하는 코드가 삽입되면, 컴파일 에러가 발생한다.

// 이렇게 함수를 const로 선언하면, 실수로 자신의 의도와 다르게 멤버변수의 값을 변경했을 때, 컴파일 에러를 통해서 이를 확인할 수 있다.
// 따라서 이는 프로그래머의 실수를 최소화하기 위한 매우 의미있는 선언이다. 그런데 이러한 const 함수에는 또 다른 특징이 있다.

// 이는 밑의 코드를 확인해보자
#include <iostream>

using namespace std;

class SimpleClass
{
private:
  int num;

public:
  void InitNum(int n)
  {
    num = n;
  }
  int GetNum()
  {
    return num;
  }
  void ShowNum() const { cout << GetNum() << endl; } // 컴파일 에러 발생
};

// 위의 클래스 정의에서 ShowNum 함수는 const 함수로 선언되었는데, 그리고 실제로 함수 내에서는 멤버변수 num 값을 변경하지 않는다.
// 그럼에도 불구하고 GetNum 함수를 호출하는 문장에서 컴파일 에러가 발생한다.

// Todo : "const 함수 내에서는 const 가 아닌 함수의 호출이 제한된다."
// const 로 선언되지 않은 함수는 아무리 멤버변수에 저장된 값을 변경하지 않더라도 변경할 수 있는 능력을 지닌 함수다.
// 따라서 이런 변경이 가능함 함수의 호출을 아예 허용하지 않는것이다.

class EasyClass {
  private:
  int num;

public:
  void InitNum(int n)
  {
    num = n;
  }
  int GetNum()
  {
    return num;
  }
};

class LiveClass {
  private :
    int num;

    public : 
    void InitNum(const EasyClass &easy) {
      num = easy.GetNum();
    } // 컴파일 에러
};

// 위의 클래스 정의에서 InitNum 함수의 매개변수 easy 는 'const 참조자'이다.
// 그런데 이를 대상으로 GetNum 함수를 호출하면 컴파일 에러가 발생한다. 이는 GetNum이 const 함수가 아니기 때문이다.

// C++ 에서는 const 참조자를 대사응로 값의 변경 능력을 가진 함수의 호출을 허용하지 않는다.(실제 값 변경여부에 상관없이)
// 따라서 const 참조자를 이용해서는 const 함수만 호출이 가능하다.
// 이는 코드의 안정성을 높일 수 있는 방법이다.

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
