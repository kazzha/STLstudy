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
	-> std::move : 원본 객체의 값ㅇ르 새 객체로 이동(복사x)
	원본 객체 r-value 참조를 함. 만일 이동의미론을 적용할 수 없으면 복사의미론을 사용
	* 이점: 이동이 메모리 할당과 해제가 필요없어 복사보다 값쌈, std::thread 나 std::lock와 같이
	복사가 불가능한 경우가 있다.
	ex) 사용 예시 */
	std::vector<int> myBigVec(10000, 2011);
	std::vector<int> myVec;
	myVec = std::move(myBigVec);
}