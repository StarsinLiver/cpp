// Todo : 폴드 표현식
// 매개변수 팩은 매개변수 구성을 간단하게 할 수 있어 활용도가 높은 문법입니다. 하지만 재귀 함수 설계에 익숙하지 않은 사람은 코드를 작성하기 어려울 수있습니다.
// 이러한 문제점을 보완하여 폴드 표현식은 매개변수 팩을 쉽게 사용할 수 있게 해줍니다.

// 폴드 표현식은 보통 괄호와 연산자 , 점 3개로 표현합니다. 폴드 표현식은 프로그래밍이 실행되면 매개변수 팩의 원소를 펼쳐서 지정된 연산을 차례로 수행합니다

// (매개변수_팩_이름 연산자 ...)

// Todo : fold_expression1.cpp 를 수정해보자
// 다음 코드는 폴드 표현식으로 수정한 것입니다. find_doll 함수에서는 show_doll 함수를 호출할 때 매개변수 팩의 원소를 모두 펼쳐 개별 원소를 대상으로 같은 연산을 
// 반복합니다. 예에서는 폴드 표현식에 덧셈 연산자(+)를 사용했으므로 매개변수 팩의 모든 원소를 순회하며 문자열을 합해서 출력합니다.
// 다만 이 예에서는 말단 함수를 별도로 두지 않아 마지막 인자임을 인지할 수 없으므로 "안쪽에"라는 문자열이 불필요하게 한 번 더 출력됩니다.

// #include <iostream>
// #include <cstring>
// using namespace std;

// template <typename doll>
// string show_doll(doll doll_name)
// {
//   return "'" + doll_name + "' 안쪽에";
// }

// // 매개변수 팩을 이용한 가변 인자 템플릿 - 재귀 함수용
// template <typename... dolls>
// // find_doll 함수 오버로딩
// string find_doll(dolls... doll_list)
// {
//   return (show_doll(doll_list) + ...);
// }

// int main(int argc, char const *argv[])
// {
//   // 첫번째 마트료시카
//   cout << "첫번째 마트료시카 "<<
//   find_doll(string("대형"), string("중형"), string("소형"));
//   cout << "있습니다." << endl
//        << endl;

//   // 두번째 마트료시카
//   cout << "두번째 마트료시카 "<<
//   find_doll(string("특대형"),string("대형"), string("중형"), string("소형") , string("극소형"));
//   cout << "있습니다." << endl
//        << endl;
//   return 0;
// }

/*
첫번째 마트료시카 '대형' 안쪽에'중형' 안쪽에'소형' 안쪽에있습니다.

두번째 마트료시카 '특대형' 안쪽에'대형' 안쪽에'중형' 안쪽에'소형' 안쪽에'극소형' 안쪽에있습니다.
*/

// 폴드 표현식은 단항이나 이항의 왼쪽 , 오른쪽 폴드 표현식으로 나뉩니다. 매개변수 팩 한가지로만 폴드 표현식을 사용하면 단항, 매개변수 팩과 초깃값 두 가지로 폴드 표현식을
// 사용하면 이항이라고 합니다.

// Todo : 다음 표에서는 네 가지의 폴드 표현식의 형대를 보여줍니다.
// 폴드 표현식 | 유형 | 실행 연산(초기값 init는 0으로 설정)
// (init_pack + ...) : 단항 오른쪽 폴드 표현식 : (((1 + 2) + 3) + 4)
// (... + init_pack) : 단항 왼쪽 폴드 표현식 : (1 + (2 + (3 + 4)))
// (init_pack + ... + init) : 이항 오른쪽 폴드 표현식 : ((((0 + 1) + 2) + 3) + 4)
// (init + ... + init_pack) : 이항 왼쪽 폴드 표현식 : (0 + 1) + 2) + 3) + 4))))

// 덧셈 연산은 연산 순서와 결과가 다르지 않지만, 나누기 연산 등 다른 연산은 결과가 달라질 수 있으므로 주의해야합니다. 
// Todo : 폴드 표현식에서 사용할 수 있는 연산자는 다음과 같습니다.
// + , - , * , / , % , ^ , & , | , = , < , > , << , >>
// += , -= , *= , /= , %= , ^= , &= , |= , == , <= , >= , <<= , >>= , != , && , || , ,(쉼표), . , *(포인터) , ->*

// Todo : 실습 실수형 데이터를 나누는 폴드 표현식
#include <iostream>
using namespace std;

// 단항 왼쪽 폴드 표현식
template <typename ... numbers>
double unary_left(numbers ... num_list) {
  return (... / num_list);
}

// 단항 오른쪽 폴드 표현식
template <typename ... numbers>
double unary_right(numbers ... num_list) {
  return (num_list / ...);
}

// 이항 왼쪽 폴드 표현식
template <typename ... numbers>
double binary_left(numbers... num_list) {
  return (10.0 / ... / num_list);
}

// 이항 오른쪽 폴드 표현식
template <typename ... numbers>
double binary_right(numbers... num_list) {
  return (num_list / ... / 10.0);
}

int main(int argc, char const *argv[])
{
  cout<<"단항 왼쪽 푤드 표현식 : " << unary_left(1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0) <<endl;
  cout<<"단항 오른쪽 푤드 표현식 : " << unary_right(1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0) <<endl;
  cout<<"이항 왼쪽 푤드 표현식 : " << binary_left(1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0) <<endl;
  cout<<"이항 오른쪽 폴드 표현식 : " << binary_right(1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0) <<endl;
  return 0;
}

/*
단항 왼쪽 푤드 표현식 : 0.00138889
단항 오른쪽 푤드 표현식 : 0.3125
이항 왼쪽 푤드 표현식 : 0.0138889
이항 오른쪽 폴드 표현식 : 3.125
*/

