// Todo : 튜플과 구조적 바인딩
// C++ 언어에서 함수는 기본적으로 한가지 데이터 형식의 값만 반환할 수 있스빈다.
// 만약 값을 여러개 반환하려면 구조체나 클래스의 객체로 반환해야합니다
// 하지만 최근 프로그래밍 언어에서는 컬렉션(collection)을 사용해 한번에 많은 자료를 반환이 가능합니다.

// 이런 추세에 따라 모던 C++ 에서도 값을 여러개 반환할 수 있는 튜플과 구조적 바인딩 구문이 추가되었스빈다.
// 튜플은 구조적 바인딩보다 이전에 표준으로 확립되었지만, 구조적 바인딩과 함께 사용하면 좀 더 쉽게 활용이 가능합니다

// Todo : 튜플 (tuple)
// 튜플은 C++14에서 표준으로 재정된 커네팅너의 한 종류입니다.
// 12장에서 list,array , map 등과 같은 종류이며 사용법도 같습니다.
// 다만, list 와 array 같은 형식의 데이터 집합을 만들어 주는 컨테이너 지만, 튜플은 다른 종류의 데이터 형식을 한 집합으로 묶을 수 있습니다.

// Todo : 튜플 생성과 활용 방법
// 튜플은 크기가 고정된 자료구조입니다. 따라서 튜플을 선언할 때는 데이터 형식을 원소의 개수만큼 나열하고 이름을 선언합니다.

// std::tuple<자료형 1, 자료형 2 , 자료형 3 , .... > 튜플 이름;

// 튜플을 만들 때는 make_tuple 함수 호출 , 복사 생성자 호출 , 유니폼 초기화등을 이용할 수 있습니다.

#include <iostream>
#include <cstring>

using namespace std;

void print_out_tuple(tuple<int, string, double> tup)
{
	cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
}

int main(int argc, char const* argv[])
{
	tuple<int, string, double> tp1 = make_tuple(1, "ㅎㅇ", 1.1);
	tuple<int, string, double> tp1_temp = make_tuple(3, "ㅎㅇ3", 3.3);
	auto tp2 = make_tuple(2, "ㅎㅇ2", 2.2);

	// 튜플의 원소값 서로 교환
	swap(tp1, tp1_temp);

	print_out_tuple(tp1);
	print_out_tuple(tp1_temp);
	print_out_tuple(tp2);

	// 튜플 합치기
	auto tp3 = tuple_cat(tp1, tp2);
	cout << get<0>(tp3) << " " << get<1>(tp3) << " " << get<2>(tp3) <<" "<<
		get<3>(tp3) << " " << get<4>(tp3) << " " << get<5>(tp3) <<
		endl;

	return 0;
}

/*
3 ㅎㅇ3 3.3
1 ㅎㅇ 1.1
2 ㅎㅇ2 2.2

3 ㅎㅇ3 3.3 2 ㅎㅇ2 2.2
*/

// Todo : 원소를 변수에 매칭하기
// 튜플의 원소값을 활용하는 또 다른 방법은 std::tie 함수를 이용하는 것입니다.
// tie 함수는 튜플을 해체하여 각각의 원소를 변수에 매칭해 주비낟.
// tie 함수로 원소를 해체할 때 std::ignore 을 사용하면 해당 위치의 변수에 매칭하지 않고 넘어갑니다.

// Todo : 구조적 바인딩 (structured binding)
// 앞서 살펴본것 처럼 튜플은 여러 데이터 형식을 한데 묶을 수 있는 자료구조입니다. 그런데 사용 방법이 복잡하고 함수 호출이 만항져 번거롭게 느껴질 수 있습니다.
// C++17에서 추가된 구조적 바인딩을 사용하면 튜플의 사용성을 좋게 변경할 수 있습니다.

// 구조적 바인딩은 특정 구조의 데이터 형식을 해체하여 낱낱의 변수에 저장하는 기능입니다. 구조적 바인딩의 대상은 배열이나 구조체, 튜플 , 맵이 될 수 있습니다.
// 해체한 원소는 auto[] 또는 const auto []처럼 대괄호로 둘러 쌓인 변수 집합에 저장됩니다.

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

struct data_struct {
	int number;
	string sentence;
	float decimal;
};

int main() {
	int numbers[3] = { 1 , 2 ,3 };
	auto [number0, number1, number2] = numbers;
	cout << "배열의 구조적 바인딩" << endl;
	cout << numbers[0] << " : " << number0 << endl;
	cout << numbers[1] << " : " << number1 << endl;
	cout << numbers[2] << " : " << number2 << endl;

	struct data_struct struct_object {20 , "구조체" , 10.5f };
	auto [number3, string0, decimal0] = struct_object;
	cout << "구조체의 구조적 바인딩" << endl;
	cout << struct_object.number << " : " << number3 << endl;
	cout << struct_object.sentence << " : " << string0 << endl;
	cout << struct_object.decimal << " : " << decimal0 << endl;

	tuple<int, char, double > tuple_object(5, 'C', 20.1f);
	auto [number4, char1, decimal1] = tuple_object;
	cout << "튜플의 구조적 바인딩" << endl;
	cout << get<0>(tuple_object) << " : " << number4 << endl;
	cout << get<1>(tuple_object) << " : " << char1 << endl;
	cout << get<2>(tuple_object) << " : " << decimal1 << endl;

	map<int, string> map_object;
	map_object.insert({ 0  , "첫 번째" });
	map_object.insert({ 1  , "두 번째" });
	map_object.insert({ 2  , "세 번째" });
	cout << "맵의 구조적 바인딩" << endl;
	for (auto [number5, string1] : map_object) {
		cout << "[" << number5 << "]" << map_object[number5] << " : " << string1 << endl;
	}

}

/*
배열의 구조적 바인딩
1 : 1
2 : 2
3 : 3

구조체의 구조적 바인딩
20 : 20
구조체 : 구조체
10.5 : 10.5

튜플의 구조적 바인딩
5 : 5
C : C
20.1 : 20.1

맵의 구조적 바인딩
[0]첫 번째 : 첫 번째
[1]두 번째 : 두 번째
[2]세 번째 : 세 번째
*/

// Todo : 튜플과 주조적 바인딩 조합
// 튜플을 구조적 바인딩과 함께 사용하면 매우 유용합니다.
// 튜플은 원소에 접근할 때 get<0>(tuple_object) 처럼 인덱스를 사용하거나 tie 함수를 이용해 변수로 매핑하는 과정을 거처야 하므로 사용하는 방법이 번거롭습니다.
// 특히 반환값으로 튜플을 전달받을때 꽤나 번거로웠습니다.

// 하지만 구조적 바인딩을 사용하면 편리하게 사용할 수 있습니다. 반환값을 tie 함수로 매핑하는 방법을 구조적 바인딩으로 수정하면 됩니다.
// 그러면 여러개의 반환값을 구조체나 튜플 같이 데이터 집합이 아닌 개별 변수로 사용이 가능합니다.

auto [a , b , c , d] = make_tuple(1 , "2" , 3.3 , 'd');