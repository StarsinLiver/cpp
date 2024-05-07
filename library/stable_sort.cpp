// Todo : 안정 정렬 (std::stable_sort)
// 정렬에는 퀵 정렬 외에도 삽입 , 병합 , 버블 , 선택 정렬 등 여러가지 종료가 있습니다.

// 안정 정렬(stable sort) : 같은 원소가 정렬 후에도 원본의 순서와 일치
// 불안정 정렬(unstable sort) : 같은 원소가 정렬 후에는 원본의 순서와 일치하지 않음

//! stable_sort 함수 원형
template <class RandomIt , class Compare>
void stable_sort(RandomIt first , RandomIt last , Compare comp);


#include <iostream>
#include <algorithm>
#include <vector>

struct Student 
{
    int id;
    int score;
};

bool compare(const Student& s1, const Student& s2) 
{
    return s1.score < s2.score;
}

int main() 
{
    std::vector<Student> students = 
    {
        {1, 90},
        {2, 90},
        {3, 80},
    };

    std::cout << "unstable sort: ";
    std::sort(students.begin(), students.end(), compare);

    for (const auto& student : students) 
        std::cout << "ID: " << student.id << ", Score: " << student.score << '\n';
    

    std::cout << "stable sort: ";
    std::stable_sort(students.begin(), students.end(), compare);

    for (const auto& student : students)
        std::cout << "ID: " << student.id << ", Score: " << student.score << '\n';

    return 0;
}