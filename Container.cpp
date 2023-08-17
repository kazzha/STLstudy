#include <iostream>
#include <set>
using namespace std;

int main()
{
    /*
    1. 컨테이너 관련 메서드
    - 이동: std::vector<int> vec4(std::move(vec3))
            std::vector<int> vec4=std::move(vec3))
    - 소멸자: vec5.~vector();
    - 요소 지우기: vec5.clear();

    1) 크기 관련 메서드
    - 크기 구하기: cont.size()
    - 컨테이너가 비어있는지 여부: cont.empty() -> cont.size == 0 대신 empty() 사용

    2) 요소 추가 메서드
    push_back(); and emplace_back()
    ->push_back는 복사가 일어나고 emplace_back는 인자를 더하기 때문에 더 효율적
    
    3) 대체 메서드
    assign() : 요소를 완전히 대체

    4) 요소 접근
    cont.begin() , cont.end() : 전진 반복을 위한 반복자 쌍. 요소 수정 가능
    cont.cbegin(), cont.cend() : 상수 전진 반복 가능. 요소 수정 불가

    5) 요소 비교
    set<int> set1{ 1,2,3,4 };
    set<int> set3{ 1,2,3,4,5 };
    set<int> set4{ 1,2,3,-3 };
    cout << (set1 > set4) << endl;

    */

    2. 순차 컨테이너
    1) array : 고정된 길이의 단일형식 컨테이너 . <array> 헤더 필요
       초기화 방법 : std::array<int, 10> arr{};
      -색인 접근 지원: 
      arr[n] : 경계 점검x
      arr.at(n) : 경계 점검이 적용되어서 색인 n이 경계를 벗어나면 std::range - error 예외가 발생
      std::get<n>(arr) : 컴파일 타임에 인덱스가 결정되어야 하므로 vector에서 쓰지 못한다.

    2) vector : 동종 컨테이너로, 실행 시점에 길이 변경이 가능하다. <vector> 헤더 필요
    * 소괄호와 중괄호의 차이
      std::vector<int> vec(10); : 10개의 요소를 가진 vector 객체 생성
      std::vector<int> vec2{10}; : 값이 10인 하나의 요소를 담은 vector 객체 생성
    * 크기 대 용량
      보통, vector의 크기(size, 요소 개수)는 용량(미리 확보된 공간, 최대 요소 개수)보다 작다.

      vec.size() : vec의 크기, 요소 개수
      vec.capacity() : 메모리 재할당 없이 vec에 담을 수 있는 최대 요소 개수
      vec.resize(n) : 요소 n개를 담을 수 있도록 vec의 크기를 늘림
      vec.reserve(n) : 적어도 n개의 요소를 담을 메모리를 확보
      vec.shrink_to_fit() : vec의 용량을 현재 크기에 맞게 줄인다 - 절대적이지 않고, 런타임에서 요청 무시 가능
          
    * 요소 접근
      vec.front() : 벡터의 첫 요소 돌려줌
      vec.back() : 벡터의 마지막 요소 돌려줌
      vec[n]
      vec.at(n) : vec의 경계를 점검해 색인

    * 요소 조작

      vec.assign( ... ) : 요소 하나 또는 여러 개(범위 또는 초기치 목록)를 벡터에 배정
      vec.clear() : vec의 모든 요소 제거
      vec.emplace(pos, arg...) : pos가 가리키는 위치 앞에 공간을 마련하고, 그 자리에서 args...을
          생성자 인수들로 사용해 새 요소를 생성
      vec.emplace_back( args ... ) : vec의 끝에 args... 를 생성자 인수들로 사용해 새 요소 생성
      vec.erase(...) :하나 또는 여러 개의 요소를 제거하고 그 다음 위치를 가리키는 반복자를 돌려줌
      vec.insert(pos, ... ) : 요소 하나 또는 여러개를 삽입하고 새로 삽입된 첫 요소를 가리키는
          반복자를 돌려줌
      vec.pop_back() : 마지막 요소 제거
      vec.push_back(elem) : vec의 끝에 elem의 복사본 추가


}