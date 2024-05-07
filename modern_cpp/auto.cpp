// Todo : 형식을 추론하는 auto
// 모던 C++ 에서는 형식 추론을 말할 때 형식 연역(type deduction)이라는 단어를 사용합니다.
// 이 책에서도 형식 추론 대신 형식 연역을 사용하도록 하겠습니다.

// auto 는 형식 연역을 할 수 있는 형식 지정자(type specifier)입니다. 더 정확하게는 "플레이스홀더 형식 지정자(placeholder type specifier)"입니다.
// auto 로 선언한 변수에 초기화되는 데이터를 통해서 형식을 연역합니다.

//! 그런데 C++ 에서 auto 는 다른 프로그래밍 언어의 형식 추론과 달리 제약 사항이 많습니다.
// 1. auto 변수는 반드시 선언과 함께 초기화 되어야합니다.
// 2. 함수에서 매개변수의 형식 지정자로 사용할 수 있다.
// 3. 구조체나 클래스의 맴버 변수로 사용할 수 없다
// 4. auto 변수를 반환하는 함수는 dctitype을 사용해야 한다.

// Todo : 형식을 추출하는 decltype 
// auto 키워드와 마찬가지로 decltype 키워드도 혀식 연역을 할 수 있습니다. auto 는 변수 선언과 초기화에 주로 사용되지만, decltype 은 변수 선언 뿐만아니라
// 함수 템플릿이나 클래스 템플릿에서 반환값의 형시을 연역하는 데도 사용할 수 있스비낟.

// 함수에서 반환값의 형식을 연역할 때는 선언문 앞쪽이 아닌 뒤쪽에 표기합니다. 이를 "후행 반환 형식"이라고 합니다.
// 반환값의 형식을 나타낸느 자리에 auto 키워드만 사용하면 형식을 연역할 수 없어 오류가 발생합니다. 따라서 반드시 후행 반환 형식으로 decltype 을 지정해야 합니다.

template <typename T , typename TT>
auto mix_tempalte(T t , TT tt) -> decltype(t + u) {
  return t * tt;
}

// C++ 부터 추가된 decltype 은 가로 안에 작성한 표현식으로 형식을 연역합니다.
// auto 와는 다르게 복잡한 표현식에서 형식을 연역할 수 있스며, 레퍼런스(&)나 상수 (const) 도 정확하게 추론합니다.