#include <memory>
#include <iostream>

int main()
{
	스마트 포인터 : <memory> 헤더 필요

	1) unique_ptr : 자원을 독점 소유, 이동 가능(move), 복사할 수 없음, 가볍고 빠름
	- 일반 사용법 : std::unique_ptr<int> uniquePtr1{ new int(100) };
	- move 함수 : std::unique_ptr<int> uniquePtr2{ move(uniquePtr1) };
	- 삭제: int* myInt = uniquePtr2.release(); -> uniquePtr2가 소유하던 포인터의 소유권을 반환,
		uniquePtr2는 더 이상 어떤 포인터도 가지지 않지만 메모리는 해제되지 않음
	        delete myInt; -> 메모리 해제

	-get 함수: 자원을 가리키는 포인터를 돌려줌
	-release 함수: 자원을 가리키는 포인터를 돌려준 후 해당 자원을 해제
	* 배열 포인터로 만들 때 : std::unique_ptr<int[]> MyArray{int[3]};
	* 간결한 사용법 auto ptr = std::make_unique<int>(2014);

	2) shared_ptr : 자원의 소유권 공유, 두 개의 핸들 사용 1) 자원에 대한 것, 2) 참조 횟수
	-> unique_ptr, raw pointer 보다 시간/메모리 더 많이 사용

    - shared_ptr 객체 복사 시 참조 횟수 1 증가
    - shared_ptr 객체가 범위를 벗어나면 참조 횟수 1 감소
	- 참조 횟수 0이 되면 C++ 런타임이 자동으로 자원 해제

	* 함수
	unique : 현재 std::shared_ptr 객체가 자원의 독점적 소유자인지 판정
	use_count : 참조 횟수를 돌려줌

	*make_shared : 훨씬 빠르기에 생성에 이 함수를 쓰는 것이 낫다.

	3) std::weak_ptr : shared_ptr들의 순환 참조를 깨는데 도움
	단지 shared_ptr로부터 자원을 빌려오고, 참조 횟수를 변경하지 않음
}