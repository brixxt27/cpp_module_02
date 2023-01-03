# Home C++ - Module 02
### Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form
### 이슈 관리: [전체 이슈 list](https://github.com/brixxt27/cpp_module_02/issues/1)
## New rule
이제 모든 class 는 Orthodox Canonical Form 으로 설계 되어야 한다. 그러면, 아래 네 개의 멤버 함수가 필요하다.
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
class 코드는 두 개로 나누어 개발해라. 헤더 파일에는 class 의 정의만 있고, 소스 파일에는 구현이 있으면 된다.
# Exercise 00: My First Class in Orthodox Canonical Form 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex00
make
./
```
## Summary
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
- Forbidden functions : None
## Detail
- 정수와 부동 소수점의 차이는 크다. 정수와 부동 소수점은 반대의 특성을 가지고 있다 가정하는 것이 안전하다. 하지만 이번엔 그 특성을 버리고 새롭고 멋진 숫자 유형인 고정 소수점을 발견할 것이다. 대부분 언어의 scalar types 에서 고정 소수점 숫자는 성능, 정확도, 범위 및 정밀도 간의 중요한 균형을 제공한다. 이것이 특히 컴퓨터 그래픽, 사운드 처리 또는 과학 프로그래밍에 적용되는 이유이다.
- Fixed-point number 를 나타내는 Orthodox Canonical Form 을 가지고 있는 class 를 작성하라:
	- Private member
		- 고정 소수점 숫자의 값을 저장하는 정수
		- 소수 비트 수를 저장하는 static const integer(정적 상수 정수). 그 값은 항상 정수 리터럴 8이다.
	- Public member
		- 고정 소수점 값을 0으로 초기화하는 Default constructor(기본 생성자)
		- Copy constructor(복사 생성자)
		- Copy assignment operator overload.(오버로딩 된 복사 할당 연산자)
		- Destructor(소멸자)
		- int getRawBits(void) const; -> 멤버 함수이며, 고정 소수점 값 그대로를 반환한다.
		- void setRawBits(int const raw); -> 멤버 함수이며, 고정 소수점 그대로의 값을 수정한다.
- 아래의 코드를 실행한다.
```
#include <iostream>
int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
```
- 그렇다면 아래와 비슷한 결과가 나올 것이다.
```
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```
# Exercise 01: Towards a more useful fixed-point number class
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex0x
make
./
```
## Summary
## Detail
- Turn-in directory : ex01/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
- Allowed functions : roundf (from <cmath>)
# Exercise 02: Now we’re talking 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex0x
make
./
```
## Summary
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
- Allowed functions : roundf (from <cmath>)
## Detail
# Exercise 03: BSP
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex0x
make
./
```
## Summary
- Turn-in directory : ex03/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
Point.{h, hpp}, Point.cpp, bsp.cpp
- Allowed functions : roundf (from <cmath>)
## Detail
