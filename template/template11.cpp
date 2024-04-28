// Todo : 템플릿과 static
// Todo : 함수 템플릿과 static 지역변수

template <typename T>
void ShowStaticValue(void)
{
  static T num = 0;
  num += 1;
  cout << num << " ";
}

// 함수 템플릿 내에 지역변수 num 이 static 으로 선언되었다.
// 그런데 위의 "함수 템플릿"을 기반으로 컴파일러는 다음과 같이 "템플릿 함수"들을 만들어 낸다.

void ShowStaticValue<int>(void)
{
  static int num = 0;
  num += 1;
  cout << num << " ";
}

void ShowStaticValue<long>(void)
{
  static long num = 0;
  num += 1;
  cout << num << " ";
}

// Todo : 클래스 템플릿과 static 맴버변수
// static 맴버변수는 변수가 선언된 클래스의 객체간 공유가 가능한 변수이다.
// 따라서 이와 같이 정의가 되었다면

template <typename T>
class SimpleStaticMem {
  private :
  static T mem;
  
  public :
  void AddMem(int num) {mem += num;}
  void ShowMem() {cout<<mem<<endl;}
};

template <typename T>
T SimpleStaticMem<T>::mem = 0; // 이는 템플릿 기반의 static 맴버 초기화 문장이다.

// 컴파일러는 다음과 같이 템플릿 클래스들이 생성된다.
class SimpleStaticMem <int> {
  private :
  static int mem;
  
  public :
  void AddMem(int num) {mem += num;}
  void ShowMem() {cout<<mem<<endl;}
};
int SimpleStaticMem<int>::mem = 0; 

class SimpleStaticMem <double> {
  private :
  static double mem;
  
  public :
  void AddMem(double num) {mem += num;}
  void ShowMem() {cout<<mem<<endl;}
};
double SimpleStaticMem<double>::mem = 0; 

// 그리고 템플릿 클래스 별로 static 맴버변수를 유지하게 된다.

// Todo : 언제 template <typename T> 와 template<> 선언이 필요한가?
// "언제 template <typename T> 선언이 필요한가?"
// "언제 template <> 선언이 필요한가?"

// "템플릿 관련 정의에는 template <typename T> 또는 template<> 와 같은 선언을 둬서, 템플릿의 일부 또는 전부를 정의하고 있다는 사실을 컴파일러에게 알려야한다."
// 템플릿에 사용된 문자 T 에 대한 정보가 필요한 정의가 있고, 필요치 않은 정의가 있다.

// Todo : template <typename T> 이 필요한 순간
template <typename T>
class SoSimple {
  T SimpleFunc(T num) {..}
}

// Todo : template <> 가 필요한 순간
template <>
class SoSimple<int> {
  public :
  int SoSimpleFunc(int num) {...}
}

// 이 정의의 핵심은 <int> 이다. 그런데 이 역시 템플릿 관련 정의이기 때문에, 이러한 사실을 알리기 ㅜ이한 선언이 필요하다.
// 하지만 이 정의에서는 T라는 문자가 등장하지 않으니, template<> 을 선언하는 것이다.
// 즉 , 정의부분에 T 가 존재하면 설명을 위해 <typename T>의 형태로 덧붙이면 되고,
// T가 존재하지 않으면 <>의 형태로 간단히 선언하면 된다.

// 다음과 같이 맴버 변수의 초기화도 진행이 가능하다.
int SoSimple<int>::mem = 5;





