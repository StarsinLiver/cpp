// Todo : 표준 라이브러리 구성과 사용법
// 1. 입출력
// 2. 문자열 처리
// 3. 컨테이너 
// 4. 알고리즘
// 5. 기타 유틸리티

// https://en.cppreference.com/w/cpp/standard_library

// 보통은 #include 다음에 헤더 파일 이름을 큰따옴표로 감싸서 지금 자것아흔ㄴ 소스 파일이 있는
// 디렉터리에서 헤더 파일을 찾지만

// 표준 라이브러리 헤더를 포함할 때는 <> 를 사용합니다.

// Todo : 문자열 라이브러리
// Todo : 표준 문자열 라이브러리 - std::string

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  string str1("hello");

  cout<<str1[0]<<endl;
  cout<<str1[1]<<endl;
  cout<<str1[2]<<endl;
  cout<<str1[3]<<endl;
  cout<<str1[4]<<endl;
  return 0;
}

// Todo : 문자열 길이 구하기 - length , size
str1.length();
str1.size();

// Todo : 빈 문자열인지 검사하기 - empty
// true 또는 false 를 반환
str1.empty();

// Todo : 문자열 추가하기 - append
str1.append("추가 문자열")
str1.append("추가 문자열" , 문자열_시작_인덱스 , 문자_개수)


// Todo : 문자열 찾기 - find
// find 함수는 매개변수로 전달받은 문자열을 찾는데 성공하면 해당 문자열의 시작위치를 반환합니다.
// 만약 찾지 못하면 정수 타입의 string::npos 라는 상수를 반환합니다.
str1.find("찾을 문자열");
str1.find('찾을 문자');
str1.find("찾을 문자열" 시작_위치);

void check_found(string:size_type n) {
  if(n == string::npos) {
    // 찾지 못함
  }
}

// Todo : 문자열 비교하기 - compare
// 문자열을 비교할 때 사용
// 0 : 두 문자열이 완전히 같음
// 양수 : 대상 문자열이 더 길거나 일치하지 않는 첫번째 문자가 더 큼
// 양수 : 대상 문자열이 더 짧거나 일치하지 않는 첫번째 문자가 더 작음
str1.compare("비교할 문자열");

void string_compare() {
  int result = str1.compare("안녕");

  if(result == 0) {
    // 문자열이 같음
  }
  else if (result > 0) {
    // 대상 문자열이 더 길거나 일치하지 않는 첫 번째 문자가 더 큼
  }
  else if (result < 0) {
    // 대상 문자열이 더 짧거나 일치하지 않는 첫 번째 문자가 더 작음
  }
}

// 연산자를 활용하면 더 직관적이다.
void string_operator() {
  string s1 = "h";
  string s2 = "h";
  if(s1 == s2) {
    // 문자열이 일치
  }
}

// Todo : 문자열 교체하기 - replace 
// replace 는 문자열의 일부를 다른 문자열로 교체하는 함수이다.

// 원형은 다음과 같다
string& replace (size_t pos , size_t len , const string &str);
string& replace (const_iterator i1 , const_iterator i2 , const string &str);

string& replace (size_t pos , size_t len , const string &str , size_t subpos , size_t sublen = npos);

string& replace (size_t pos , size_t len , const char* s);
string& replace (const_iterator i1 , const_iterator i2 ,const char* s);

// 사용법은 다음과 같다
void string_replace () {
  string str = "hello, world";
  str.replace(7 , 5 , "C++");

  // -> hello, C++
}

// Todo : 와이드 문자열 - wstring
// string 은 유니코드를 지원하지만 , 상황에 맞게 적절한 데이터 형식과 인코딩을 선택하여 유니코드
// 문자열을 처리해야하는 번거로움이 있다.

// 그래서 C++11 부터는 std::wstring 이라는 와이드 문자열 형식을 제공한다.

// 다음 문법은 string 으로 유니코드 문자열을 저장하고 출력하는 간단한 예이다
void string_w() {

  // 프로그램의 지역 설정
  setlocale(LC_ALL , "");

  wstring korString = L"안녕하세요";
  wcout<< korString <<endl;
}

// 와이드 문자열 형식은 유니코드 인코딩 방식에 따라 wstring , u16string , u32string 등을 사용가능