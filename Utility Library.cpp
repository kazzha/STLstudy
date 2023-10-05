#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cout;

int main() {
	// using namespace std; : std 네임스페이스에 속하는 요소를 끌어올려서 std::를 명시할 필요가
	// 없어진다. 그러나 다른 네임스페이스에 예를들면 cout이라는 동명의 함수가 있으면 충돌발생가능.
	/* 1. <algorithm> header
	-> min, max, minmax function
	: 최대, 최소 판정은 기본으로 미만 연산자(<)가 쓰이지만, 비교함수를 직접 지정할 수 있고
	그 함수는 인수 두개를 받고 하나의 bool값을 반환하는 함수여야 한다.
	*true 또는 false를 반환하는 함수를 술어(predicate)라고 함

	ex) 사용 예시 */
	auto pairSeq = std::minmax({ 3, 1, 2011, 2014, -5 });
	cout << pairSeq.first << "," << pairSeq.second;

	/* 2. <utility> header
	1) std::move : 원본 객체의 값을 새 객체로 이동(복사x)
	원본 객체 r-value 참조를 함. 만일 이동의미론을 적용할 수 없으면 복사의미론을 사용
	* 이점: 이동이 메모리 할당과 해제가 필요없어 복사보다 값쌈, std::thread 나 std::lock와 같이
	복사가 불가능한 경우가 있다.
	ex) 사용 예시 */
	std::vector<int> myBigVec(10000, 2011);
	std::vector<int> myVec;
	myVec = std::move(myBigVec);

	2) std::forward = 받은 형태로 안전하게 그대로 전달하는 함수
	              ( L-Value로 들어오면 L-Value로 리턴, R-Value로 들어오면 R-Value로 리턴)

	3) std::swap(A, B) : move로 구현됨
	4) std::pair<타입, 타입>( , )
		-> 비교연산자를 지원해서 먼저 pair1의 first와 pair2의 first를 비교,
		같을 시 둘의 second 비교
	* std::make_pair - 요소 형식을 지정하지 않아도 됨
		ex) auto can = std::make_pair("str", 3.14);

	5) std::tuple <tuple> 필요
	-pair와 방식은 같고 요소 개수 상관이 없다.
	-요소가 2개인 tuple은 pair로 변환 가능
	-tuple의 i번째 요소 : std::get<i-1>(tuple이름)
	-make_tuple 가능

	6) std::tie : 기존 변수들을 참조하는 요소들로 이루어진 튜플 생성 가능
	   std::ignore : 
	
	
}