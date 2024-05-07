# c 언어

### 컴파일러와 디버거
```
1. GCC 와 GDB
GCC (gnu compiler collection)은 GNU의 컴파일러 모음 프로젝트이다.
프로젝트 중에서 C++언어를 위한 컴파일러는 G++이며, 디버거는 GNU의 다른 프로젝트인 GDB 디버거를 사용할 수 있습니다.

GCC로 개발하면 이식성이 높은 애플리케이션을 개발할 수 있습니다.

2. Clang 과 LLDB
Clang은 LLBM(low level virtual machine)을 기반을 둔 C 계열 언어들의 컴파일러입니다.
Clang 은 C와 C++뿐만 아니라 오브젝티브-C 와 같은 C 계열 프로그래밍 언어를 모두 컴파일할 수 있습니다.


3. DPC++ 와 C++
인텔은 자사의 CPU에 최적화되어 최고의 성능을 보장하는 C++ 컴파일러를 유료로 제공했다.
그리고 2020년 12월에 다양할 하드웨어 가속기와 플랫폼을 지원하는 oneAPI 를 출시하면서 컴파일러를 포함해 다양한 소프트웨어를 oneAPI로 통합하여 무료로 배포하고 있다.

oneAPI 에서 C++ 컴파일러는 DPC++ / C++입니다.
```

### 라이브러리
1. 오픈소스 C++ 라이브러리 목록 : kocppreference.com/w/cpp/links/libs
2. C++ 표준 라이브러리 : https://en.cppreference.com/w/cpp/standard_library

3. Boost C++ (boost.org) : 문자열 포인터 , 컨테이너,알고리즘 등 c++ 프로그램에 필요한 라이브러리가 통합되어 있다.

4. OpenCV (opencv.org) : 이론적인 원리를 알지 못하더라도 영상 처리에 필요한 다양한 기능을 사용할 수 있도록 만들어졋다.

5. POCO(pocoproject.org) : C++ 언어에서 사용되는 라이브러리를 다야앟ㄴ 운영체제에서 사용할 수 있도록 지원

6. 텐서플로(tensorflow.org) : 딥러닝을 위한 다양한 라이브러리와 알고리즘을 제공합니다. c++로 구현되어 있다.

7. 언리얼 게임 엔진(unrealengine.com) : 3D 게임을 개발할 때 필요한 그래픽 엔진, 물리적 엔진, 음향과 관련된 다양한 기능을 제공