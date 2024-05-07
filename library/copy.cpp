// Todo : 복사 함수

// copy 함수의 원형
/*
template <class _InIt , class _OutIt>
_CONSTEXPR20 _OutIt copy(_InIt _First , _InIt _Last , OutIt _Dest)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
  string name;
  int age;
  float height;
  float weight;
};

void print_person_all(vector<Person> &vec)
{
  for (vector<Person>::iterator it = vec.begin(); it != vec.end(); it++)
  {
    cout << "이름 : " << it->name << " 나이 :" << it->age << " 키 : " << it->height
         << " 몸무게 : " << it->weight
         << endl;
  }
}

int main(int argc, char const *argv[])
{
  Person p[2] = {
    {"Brain" , 24 , 180 , 70},
    {"Jessica" , 22 , 165 , 70},
  };

  vector<Person> from_vector;
  from_vector.push_back(p[0]);
  from_vector.push_back(p[1]);

  // 출력
  print_person_all(from_vector);
  cout<<endl;

  // to_vector 에 from_vector 원소를 "깊은 복사" 수행
  vector<Person> to_vector;
  copy(from_vector.begin() , from_vector.end() , back_inserter(to_vector));

  print_person_all(to_vector);
  cout<<endl;

  return 0;
}
