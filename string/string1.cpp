// Todo : String 클래스의 디자인
// Todo : C++ 의 표준과 표준 string 클래스

// Todo : 표준 string 클래스
// C++ 표준 라이브러리에는 string 이라는 이름의 클래스가 정의되어 있다.
// 클래스의 이름이 의미하는 것처럼, 문자열의 처리를 목적으로 정의된 클래스이며, 이 클래스의 사용을 위해서는 헤더파일 <string>
// 을 포함해야한다.

// 사용예시를 보고 잠시 후에는 string 클래스와 유사한 문자열 처리 클래스를 직접 정의해보자

// Todo : string 클래스 사용 예시
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  string str1 = "I like ";
  string str2 = "string class";
  string str3 = str1 + str2;

  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;

  str1 += str2;
  if (str1 == str3)
    cout << "동일 문자열!" << endl;
  else
    cout << "동일하지 않은 문자열!" << endl;

  string str4;
  cout<<"문자열 입력 : ";
  cin>>str4;
  cout<<"입력한 문자열 : "<<str4<<endl;
  return 0;
}

/*
I like 
string class
I like string class
동일 문자열!
문자열 입력 : fsdafdasfdsfsdfads
입력한 문자열 : fsdafdasfdsfsdfads
*/

