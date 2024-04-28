// Todo : 문자열 처리 클래스의 저으이
// Todo : 표준 string 클래스의 분석
// 먼저 , String 클래스의 정의를 위해서 어떠한 것들이 요구되는 지 하나씩 정리해보자

// Todo : 하나, 문자열을 인자로 전달받는 생성자의 정의
// 앞서 보인 예제에서는 다음의 형태로 string 객체를 생성한다.

string str1 = "I like ";
string str2 = "string class";

// 그런데 이는 문자열을 전달받는 생성자의 호출로 이어진다. 즉, 다음의 문장과 동일한 문장이다.

string str1("I like ");
string str2("string class");

// 따라서 이에 적절한 생성자를 정의해야한다.

// Todo : 둘, 생성자 소멸자 복사 생성자 그리고 대입 연산자의 정의
// 우리가 구현할 String 클래스는 문자열을 저장 및 표현하는 클래스이다.
// 그런데 저장하고자 하는 문자열의 길이가 일정치 않다

// 따라서 문자열의 저장을 위한 메모리 공간을 생성자 내에서 동적 할당해야 한다.
// 그리고 이로 인해서 소멸자를 정의해야 하며, 깊은 복사를 하는 복사 생성자와 대입 연산자 까지 함께 정의하고자 한다.

// Todo : 셋 , 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩
string str3 = str1 + str2;

// - 문자열의 주소 값(str1 과 str2 가 지니고 있는 문자열을 합한 문자열의 주소값)
// - string 객체(str1과 str2 가 지니고 있는 문자열을 합한 문자열을 저장하는 객체)

// Todo : 넷 , 문자열을 덧붙이는 += 연산자의 오버로딩
str1 += str2;

// Todo : 다섯, 내용비교를 진행하는 == 연산자의 오버로딩

// Todo : 여섯 콘솔입출력이 가능하도록 << , >> 연산자의 오버로딩

// Todo : String 클래스의 선언 부분
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
  int len;
  char *str;

public:
  String();
  String(const char *s);
  String(const String &s);
  ~String();
  String &operator=(const String &s);
  String &operator+=(const String &s);
  bool operator==(const String &s);
  String operator+(const String &s);

  friend ostream &operator<<(ostream &os, const String &s);
  friend istream &operator<<(istream &is, String &s);
};

// Todo : String 클래스의 완성
String::String()
{
  len = 0;
  str = NULL;
}

String::String(const char *s)
{
  len = strlen(s) + 1;
  str = new char[len];
  strcpy(str, s);
}

String::String(const String &s)
{
  len = s.len;
  str = new char[len];
  strcpy(str, s.str);
}

String::~String()
{
  if (str != NULL)
  {
    delete[] str;
  }
}

String &String::operator=(const String &s)
{
  if (str != NULL)
    delete[] str;
  len = s.len;
  str = new char[len];
  strcpy(str, s.str);
  return *this;
}

String &String::operator+=(const String &s)
{
  len += (s.len - 1);
  char *tempstr = new char[len];

  strcpy(tempstr, str);
  strcpy(str, s.str);

  if (str != NULL)
    delete[] str;

  str = tempstr;
  return *this;
}

bool String::operator== (const String& s) {
  return strcmp(str , s.str) ? false : true;
}

String String::operator+ (const String& s) {
  char * tempstr = new char[len + (s.len - 1)];
  strcpy(tempstr , str);
  strcat(tempstr , s.str);

  String temp(tempstr); // String temp = tempstr;
  delete []tempstr;
  return temp;
}

ostream &operator<<(ostream &os, const String &s) {
  os<<s.str;
  return os;
}

istream &operator<<(istream &is, String &s) {
  char str[100];
  is>>str;
  s = String(str);
  return is;
}