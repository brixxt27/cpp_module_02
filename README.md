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
cd cpp_module_02/ex01
make
./
```
## Summary
- Turn-in directory : ex01/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
- Allowed functions : roundf (from [cmath])
## Detail
- 이전 과제는 시작하기에 좋지만, 이번 과제는 꽤나 까다로울 것이다. 이번엔 오직 0.0의 값을 나타낼 수 있다.
- 아래 있는 public 생성자와 public 멤버 함수를 class에 추가해라.
	- constant integer 를 매개변수로 받는 생성자: 상수 정수 값은 고정 소수점 값으로 변환된다. 분모에 해당하는 bit는 ex00처럼 8로 초기화 된다.
	- constant floating-point number 를 매개변수로 받는 생성자: 상수 부동 소수점 수는 고정 소수점 수로 변환된다. 분모에 해당하는 bit는 8로 초기화 된다.
	- 멤버 함수 float toFloat(void) const; 고정 소수점 수를 부동 소수점 수로 변환한다.
	- 멤버 함수 int toInt(void) const; 고정 소수점 수를 정수형으로 변환한다.
	- 그리고 아래 함수를 Fixed class 파일에 추가하라.
		- 인자로 들어온 출력 스트림에 고정 소수점 수의 부동 소수점 표현을 삽입하는 오버로딩 된 "<<" 부호(operator)
```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```
```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```
# Exercise 02: Now we’re talking 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex02
make
./
```
## Summary
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
- Allowed functions : roundf (from [cmath])
## Detail
-  class 에 public 멤버 함수로 다음 따라오는 오버로딩 된 부호를 추가해라:
	- 6개의 비교 연산자(>, <, >=, <=, ==, !=)
	- 4개의 산술 연산자(+, -, *, /)
- 4개의 증감 연산자(전위, 후위 증감 연산자), 고정 소수점 값을 1 + e > 1 같이 가장 작은 e 값에서 고정 소수점 값을 증가시키거나 감소시킨다.
<br> </br>

- class에 오버로딩 된 네 개의 public 멤버 함수를 추가해라.
	- static 멤버함수 min 은 두 개의 고정 소수 값의 레퍼런스를 인자로 받고, 둘 중 더 작은 것을 레퍼런스로 반환한다.
	- static 멤버함수 min 은 두 개의 constant 고정 소수 값의 레퍼런스를 인자로 받고, 둘 중 더 작은 것을 레퍼런스로 반환한다.
	- static 멤버함수 max 는 두 개의 고정 소수의 레퍼런스를 인자로 받고, 둘 중 더 큰 것을 레퍼런스로 반환한다.
	- static 멤버함수 max 는 두 개의 constant 고정 소수를 인자로 받고, 둘 중 더 큰 것을 레퍼런스로 반환한다.
- 모든 기능을 테스트하는 것은 당신에게 달렸습니다. 그러나 아래의 코드를 실행해야 합니다.
```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```
다음과 같이 출력되어야 합니다.(생성자와 소멸자의 메시지는 가독성을 위해 없앴다)
```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```
# Exercise 03: BSP
## Usage
```
git clone https://github.com/brixxt27/cpp_module_02.git
cd cpp_module_02/ex03
make
./
```
## Summary
- Turn-in directory : ex03/
- Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
Point.{h, hpp}, Point.cpp, bsp.cpp
- Allowed functions : roundf (from [cmath])
## Detail
이제 너만의 Fixed class 를 만들자! 그건 앞으로 아주 유용할 거야!
점이 삼각형 안에 있는지에 대한 여부를 나타내는 함수를 구현할 것이다. 매우 유용하지 않을까?
```
BSP 는 Binary Space Partitioning 를 나타낸다. 환영한다! :)
ex03을 하지 않아도 통과할 수 있다.
```
- 신발끈 방식으로 진행. 삼각형 변 위에 점이 있을 경우에 대한 예외처리만 해두면 점을 찍은 뒤 삼각형의 각 꼭지점에서 그 점으로 이으면 세 개의 삼각형이 만들어지는데 이 세 개의 삼각형 합이 가장 큰 삼각형의 크기와 같으면 true.
- private 멤버:
	-  A Fixed const attribute x.
	-  A Fixed const attribute y.
	-  Anything else useful.
- public 멤버:
	- x, y 를 각각 0으로 초기화 하는 기본 생성자.
	- 두 개의 const 부동 소수를 인자로 받는 생성자. x, y가 인자로 들어온 값으로 각각 초기화 된다.
	- 복사 생성자
	- operator= 오버로딩
	- 소멸자
	- 유용한 여러 함수들...
- 결론적으로 아래의 함수를 적절한 파일 안에 구현합니다.
```
bool bsp( Point const a, Point const b, Point const c, Point const point );
```
- a, b, c: 삼각형의 꼭지점
- point: 확인할 점
- Return: 삼각형 내부에 있으면 참 값이고, 그렇지 않으면 거짓이다. 결론적으로 만약 점이 삼각형 정점이나 가장자리에 있으면 거짓을 반환한다.
- 마지막으로 구현을 테스트할 코드를 구현하라.
