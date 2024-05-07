// Todo : 람다 표현식에서 this 포인터 사용하기
// 이번에는 람다 표현식에서 클래스의 멤버 변수를 사용하고자 할때 this 포인터를 캡쳐하는 방법을 알아보겠습니다.
// '=' 이나 '&' 로 전체 변수를 캡처하면 this 포인터도 함께 캡처됩니다.
// 캡처한 변수를 사용할 때는 this 를 명시하면 됩니다.

#include <iostream>
#define loop_count 5
#define change_count 1
using namespace std;

class vending_machine
{
private:
    int price[loop_count];

public:
    vending_machine() : price{450, 390, 11340, 900, 150} {};

    void sale_using_basic_lambda(int payments[], int changes[])
    {
        for (int i = 0; i < loop_count; ++i)
        {
            // This , & 람다 표현식
            cout<< [&](int payment) -> int
            {
                return payment - this->price[i];
            }(payments[i]) << endl;
          
        }
    }
};

int main(int argc, char const *argv[])
{
    vending_machine v1 = vending_machine();

    int payments[loop_count] = {100 , 44 ,55,66,77};
    int changes[change_count] = {0};
    v1.sale_using_basic_lambda(payments ,changes );
    return 0;
}

/*
-350
-346
-11285
-834
-73
*/