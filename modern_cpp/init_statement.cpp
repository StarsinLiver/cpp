// Todo : 제어문의 초기화 구문
// if 나 switch , for 같은 제어문에서 사용할 변수를 제어문 외부에서 초기화하면 코드를 읽을 때 혼란스러울 수 있습니다.
// 이를 보완하는 문법이 바로 초기화 구문(init-statement) 입니다.

// 예를 들어 다음 코드에서는 element 변수를 if 문 외부에서 함수가 반환하는값으로 초기화 한 후 if 문의 조건식과 for 문에서 특정 인덱스의 원소값을 연산할 때 사용합니다.
int element = 1;
if(0 != element) { ... }

// Todo : 다음은 if 와 switch, 그리고 범위 기반 for 문에 초기화 구문을 사용한 예입니다.
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

#define odd 1
#define even 0

int main(int argc, char const* argv[])
{
    array<int, 5> data_array{47, 23, 58, 10, 36};

    if (auto element = data_array[3] + data_array[4]; element > 20) {
        cout << "if 문 초기화" << endl;
    }

    switch (auto element = data_array[4] % 2; element) {
    case odd:
        cout << "다섯번째 요소값은 홀수 입니다." << endl;
        break;

    case even:
        cout << "다섯번째 요소 값은 짝수 입니다." << endl;
        break;
    }

    for (sort(data_array.begin(), data_array.end()); auto && element : data_array) {
        cout << element << " , ";
    }

    cout << endl;


    return 0;
}
/*
if 문 초기화
다섯번째 요소 값은 짝수 입니다.
10 , 23 , 36 , 47 , 58 ,
*/

