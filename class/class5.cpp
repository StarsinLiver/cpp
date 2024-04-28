// Todo : 생성자 (Constructor) 와 소멸자 (Destructor)
// 생성자를 이용해보자
class SimpleClass {
  private:
    int num;

    public :
    SimpleClass(int n) {
      num = n;
    }// 생성자
};

// "생성자 (constructor)"은 다음의 특징을 가진다.
// "객체 생성시 딱 한번 호출된다."

int main(int argc, char const *argv[])
{

  // SimpleClass simple; // 전역, 지역 및 매개변수의 형태
  SimpleClass simple(20); // 생성자에 20을 할당

  // SimpleClass * ptr; // 동적 할당의 형태
  SimpleClass * ptr = new SimpleClass(30); // 생성자에 30을 전달
  return 0;
}
