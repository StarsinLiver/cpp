// Todo : 참조의 정보 (참조값)에 대한 이해
// 필자는 위의 예제를 통해서 '참조의 정보' 또는 '참조 값'이라는 표현을 사용하였다. 그런데 여기서 말하는 참조 값이 무엇을 뜻하는 지 헷갈릴 수 있으니 확인해보자
int main(int argc, char const *argv[])
{
  int num = 7;
  int &ref = num; // 무엇이 전달되는 걸까?
  return 0;
}

// 여러분도 알다시피 위의 두 번째 대입연산에 의해서 변수 num을 참조자 ref가 참조하게 된다.
// 그렇다면 대입연산의 과정에서 참조자 ref에 무엇이 전달된다고 해야 할까?
// 한가지 확실한 것은 num 에 저장된 정수 값은 아니다. 그래서 대입연산에 어울리게 다음과 같이 표현하기도 한다.

// "변수 num을 참조할 수 있는 참조의 정보가 전될된다."

// 즉, 다음과 이해를 하는 것이 자연스러운 측면도 있다.
// "변수 num을 참조할 수 잇는 참조 값이 참조자 ref에 전달되어, ref 가 변수 num을 참조할 수 있게 된다."

// 이제 참조 값이 의미하는 바를 이해하겠는가? 대입 연산자의 왼편에 "참조자의 선언"이 오거나 , 반환형으로 "참조형"이 선언되면,
// 그 때 전달되는 정보를 표현하기 위해서 "참조의 정보" 또는 "참조 값"이라는 표현을 사용한 것이다.
