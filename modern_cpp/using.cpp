// Todo : using 키워드
// using 의 다양한 활용법을 배워보자

// Todo : 상속 맴버의 접근 지정자 변경
// using 키워드는 자식 클래스에서 부모 클래스의 맴버 접근 지정자를 변경할 때 사용할 수 있습니다.
// 상속받은 클래스의 맴버는 상속 지정자에 맞게 접근 지정자가 변경되지만, 때로는 상속 지정자와 다르게 맴버 함수, 변수의 접근 범위를 개방하는 쪽으로 바꿔야 할 수 있습니다.

// 이때 자식 클래스에서 부모 클래스의 맴버를 using 으로 선언하면 접근 범위가 변경됩니다.
// 그리고 부모 클래스에서 접근 지정자는 무시됩니다. 이렇게 변경할 수 있는 접근 지정자는 protected 입니다.
// 즉, 부모 클래스에서 protected 로 지정된 맴버를 using 으로 접근 지정자를 변경할 수 있습니다.

// 단, privae 로 선언된 맴버의 접근 지정자는 변경할 수 없습니ㅏㄷ.

// 문법은 간단한데 자식 클래스의 public 범위에서 using 과 함께 부모 클래스에서 protected로 지정한 멤버를 다시 선언해 주면 됩니다.

class monster {
  public :
  monster() {};
  protected :
  void get_damage(int _damage) {};

  //..
};

class monster_a : public monster {
  public:
  using monster::get_damage;
};

class monster_b : public monster{ 

};

int main(int argc, char const *argv[])
{
  monster_a mon_1;
  monster_b mon_2;

  mon_1.get_damage(199);
  mon_2.get_damage(199); // 접근 오류 발생
  return 0;
}

// 위와 같이 moster_a 와 moster_b 는 모두 moster 클래스를 상속 받습니다. 그리고 moster 클래스에서 protected 로 지정된 get_damage 함수를 monster_a 클래스에서만
// using 키워드를 통해 public 으로 접근 범위를 변경했습니다. 따라서 main 함수에서 monster_a 클래스의 객체로 get_damage 함수를 호출할 수 있지만 monster_b에서는
// get_damage 함수를 호출 할 수 없습니다.



// Todo : 열거형 사용 선언
// 열거형을 선언한 후에 구조체나 클래스 내부에서 사용할 때는 열거형 이름과 함께 사용하면 됩니다.
// 만약 열거형 선언을 구조체나 클래스 내부에 있는 데이터 형식처럼 사용하려면 해당 클래스나 구조체에서 using 키워드로 선언하면 됩니다.
// 이렇게 하면 열거형과 구조체 또는 클래스 간에 관계를 논리적으로 만들 수 있습니다.

#include <iostream>
using namespace std;

enum class weapon : int { gun , arrow , machine_gun};

class monster {
  public :
  weapon weapon_type;
};

struct weapon_class {
  // 외부에 선언된 열거형을 내부에 사용 선언
  using enum weapon;
};

int main(int argc, char const *argv[])
{
  monster monster_obj;
  weapon_class weapon_obj;

  monster_obj.weapon_type = weapon::gun;
  monster_obj.weapon_type = weapon_obj.arrow;
  monster_obj.weapon_type = weapon_class::machine_gun;
  return 0;
}


// Todo : 별칭 만들기
// typeder 키워드와 마찬가지로 using 키워드를 사용하면 별칭(alias)를 만들 수 있습니다. 가장 큰 차이점은 별칭이 지칭하는 함수 등에 템플릿을 포함할 경우 using
// 만 사용할 수 있다는 것입니다.
// 그리고 using 을 사용하면 키워드 다음에 바로 별칭이 나오므로 코드를 읽기도 좋습니다.

// using 키워드로 별칭을 만들려면 using 다음에 별칭을 적은 후 '='으로 별칭을 부여할 식별자를 작성하면 됩니다.

using 별칭 = 식별자;

// 예제로 보죠
typedef struct _tag {
  //...
};

using DATA = struct _tag;

// 이렇게 하면 struct _tag 구조체_객체명 처럼 복잡한 형식으로 구조체 객체를 생성하지 않고 DATA 구조체_객체명으로 생성할 수 있습니다.
