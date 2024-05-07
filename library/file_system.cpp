// Todo : 파일 시스템
// 파일 시스템이란 데이터를 저장하고 관리하는 체계를 의미한다.

// 파일 시스템 라이브러리는 데이터의 입출력을 담당하는 fstream 과는 다릅니다.
// fstream은 해당 파일의 내용을 읽어내는 역할을 하지만, 파일 이름이나 위치 같은 파일에 관한 정보
// (metadata)를 수정할 수는 없습니다. 반면에 파일 시스템 라이브러리는 파일에 관한 정보에 접근할 수 있지만
// 파일 자체를 읽을 수는 없습니다.

// C++17에서 드디어 C++ 도 파일 시스템 라이브러리를 지원하게 되었습니다.
// C++ 파일 시스템 라이브러리의 모든 형식과 함수는 std::filesystem 네임스페이스에 속해 있으며,
// 이름 사용하려면 소스 파일에 <filesystem> 헤더를 포함해야합니다.

// Todo : 파일 시스템 클래스
// path : 파일과 디렉터리 경로를 나타내는 클래스
// directory_entry : 디렉터리 내의 항목을 나타내는 클래스
// directory_iterator : 디렉터리 내의 모든 항목을 순회하기 위한 반복자 클래스
// file_status : 파일이나 디렉터리의 상태 정보를 나타내는 열거형 클래스
// file_time_type : 파일의 시간 정보를 나타내는 file_time 과 같은 형식
// space_info : 디스크 공간에 대한 정보를 제공하는 클래스

// Todo : 파일 시스템 열거형
// perms : 파일이나 디렉터리의 권한을 나타내는 열거형 상수 집합
// file_type : 파일이나 디렉터리의 유형을 나타내는 열거형 상수 집합

// Todo : 파일 시스템 함수
// exists : 주어진 경로에 파일이나 디렉터리가 존재하는지 확인
// is_directory : 주어진 경로가 디렉터리인지 확인
// is_regular_file : 주어진 경로가 일반 파일인지 확인
// create_directory : 디렉터리 생성
// create_directories : 경로에 지정된 디렉터리나 중간 디렉터리 생성
// remove : 파일이나 디렉터리 삭제
// rename : 파일이나 디렉터리의 이름 변경
// copy : 파일이나 디렉터리 복사
// copy_file : 파일을 복사
// copy_directory : 디렉터리를 복사
// copy_symlink : 심벌릭 링크 복사
// file_size : 파일 크기 반환
// last_write_time : 파일이나 디렉터리의 마지막 수정 시간 반환
// current_path : 현재 작업 디렉터리의 경로 반환
// equivalent : 두 경로가 같은 파일이나 디렉터리를 가리키는지확인
// is_empty : 주어진 디렉터리가 비었는지 확인
// remove_all : 디렉터리와 하위 항목 모두 삭제
// resize_file : 파일 크기 변경
// status : 파일이나 디렉터리의 상태 정보 반환
// temp_directory_path : 임시 디렉터리의 경로 반환

// Todo : 경로를 나타내는 path 객체
// 1. 원하는 경로에 있는 파일/디렉터리의 path 정의
// 2. 해당 path 로 파일/디렉터리 정보 수집

//! 중요한 것은 path 객체만으로는 실제 해당 경로에 파일이 존재하는 지 모름 따라서 exists 함수를 사용
// bool exists(const std::filesystem::path &p)

// Todo : 파일 시스템을 활용해보자
#include <iostream>
#include <string>
#include <filesystem>
// #include <experimental/filesystem> // depricated
#include <fstream>

using namespace std;

namespace fs = filesystem;
// namespace fs = std::experimental::filesystem;

int main(int argc, char const *argv[])
{
  // 디렉터리 생성
  fs::create_directories("MyDirectory");

  // 파일 생성과 쓰기
  ofstream outFile("MyDirectory/myfile.txt");
  outFile<<"Hello,FileSystem Library"<<endl;
  outFile.close();

  // 디렉터리 내의 파일 확인
  cout<<"Files in MyDirectory :\n"<<endl;
  for(const fs::directory_entry& entry : fs::directory_iterator("MyDirectory")) {
      cout<<entry.path().filename()<<endl;
  }

  // 파일 읽기
  ifstream inFile("MyDirectory/myFile.txt");
  string line;
  while(getline(inFile , line)) {
    cout<<line<<endl;
  }

  inFile.close();

  // 파일과 디렉터리 삭제
  fs::remove_all("MyDirectory");
  return 0;
}
