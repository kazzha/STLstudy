#include <iostream>
#include <set>
#include <deque>
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

     3) deque - vector와 비슷한 선형 배열 형태의 순차 컨테이너, <deque> 헤더 필요
     vector와 다른 점: 시작 위치에 요소를 추가 또는 삭제 가능
          -> 이를 위해 deq.push_front(elem), deq.pop_front(),deq.emplace_front(arg...) 를 추가로 제공

     ex) deq.insert(deg.begin(),0) -> 0를 맨 앞에 넣음
         deq.insert(deg.begin()+4,4) -> 맨 마지막에 4를 넣음

     4) list - double linked list. <list> 헤더 필요
     -임의 접근을 지원하지 않음, 임의의 요소에 대한 접근이 느리다. 요소의 삽입과 삭제가 빠르다.
     
     *특별한 메서드
     list.remove(val) : list에서 값이 val인 요소를 모두 제거
     list.remove_if(pre) : 술어 pre를 만족하는 요소를 모두 제거
     list.unique() : 값이 같은 요소를 제거
     list.splice(pos, ...) : pos 앞에 다른 목록의 요소를 삽입
          ex) list1.splice( std::find ( list.begin() , list.end(), 15 ), list2 )

    5) forward_list : single linked list. <forward_list> 헤더 필요
    전진만 가능. 자신의 크기를 알지 못함. 전진 전용이므로 반복자 감소가 불가능(itr-- 가 없다)

    *특별한 메서드

    forw.before_begin() : 첫 요소 앞을 가리키는 반복자를 돌려준다.
          ex)  std::forward_list<int> myList = { 2, 3, 4 };

               auto beforeBeginIt = myList.before_begin();
               myList.insert_after(beforeBeginIt, 1);

               for (const auto& value : myList) {
                  std::cout << value << " ";
               }
    forw.emplace_after(pos, args...)
    forw.emplace_front(args...) : forw의 시작 위치에 args...를 생성자 인수로 사용해 새 요소 생성
    forw.erase_after(pos, ...)
    forw.insert_after(pos, ...)

    3. 연관 컨테이너
    1) 순서 있는 연관 컨테이너
    *키와 값
        키: 정렬 가능해야 함, 복사 가능, 이동 가능이어야 함
        값: 기본 생성 가능해야 하고 복사 가능, 이동 가능이어야 함
    
     -키와 값은 std::pair를 생성, 키: p.first이고 값이 p.second
        ex) std::multimap<char, int> mulm= {{'a', 10}, {'b', 30}}
            for( auto p : mulm ) { std::cout << p.first << "," << p.second }

    *비교 기준
        기본 : std::less(1, 2, 3, 4...로 정렬)
        큰 수 부터 배열하려면...
        ex) std::map<int, std::string, std::greater<int>> int25tr{ {5,"오"}, {1,"일"}, {3,"삼"} };
        
    *특별한 검색 함수
        set.count(key) : 키가 key인 값들의 개수를 돌려줌
        set.find(key) : key에 해당하는 키를 가리키는 반복자를 돌려준다. 없으면 end()를 돌려줌

    *요소의 삽입과 삭제
        insert와 emplace 사용 가능.
        erase(key) : 키가 key에 해당하는 모든 쌍을 삭제하고 그 개수를 돌려줌

   *std::map
        : vector와 비슷하나 색인으로 거의 모든 형식이 가능. at 메서드도 지원

    2) 순서 없는 연관 컨테이너
    std::unordered_map, std::unordered_multimap, std::unordered_set, std::unordered_multiset
        ->순서 있는 연관 컨테이너의 요소 접근 연산: O(log n)
          순서 없는 연관 컨테이너의 요소 접근 연산: 상수 복잡도

    *특징: 비교 함수가 없는 대신, 해시 함수가 존재한다.
     해시 함수: 키를 그에 해당하는 값으로 매핑, 그 값을 해시 값이라고 부른다.
        ->해시 함수 실행에는 상수 시간이 걸리므로 요소 접근 시간 역시 상수이다.

    *버킷: 색인들을 저장. 키 매핑->버킷에 가서 찾음

    *충돌: 서로 다른 키에 대해 같은 색인이 나오는 것. 해시 함수를 만들 때 충돌을 최대한 줄여야 한다.

    *버킷 개수: 용량
     버킷에 담긴 요소들의 평균 개수: 적재율

    4. 컨테이너 적응자
    -순차 컨테이너 형식을 명시적으로 지정하지 않으면 기본적으로 std::deque가 쓰임

    1) std::stack  <stack> 헤더 필요
    stack.push(e) : 새 요소 e를 스택 최상위에 삽입
    stack.pop() : 최상위 요소를 제거
    stack.top() : 최상위 요소에 대한 참조를 돌려줌
    stack.empty() : 비어있으면 true, 안 비어있으면 false를 반환하는 함수
    stack.size() : 크기 반환

    2) std::queue    <queue> 헤더 필요
    que.push(e) : 요소 e를 queue 끝에 추가한다
    que.pop() : 대기열의 첫 번째 요소를 제거
    que.back() : que의 마지막 요소에 대한 참조를 돌려줌
    que.front() : 첫 번째 요소에 대한 참조를 돌려줌

    3) std::priority_queue     <queue> 헤더 필요
    -> 우선순위가 높은 값부터 대기열의 앞쪽에 놓인다
    ex) push(7) -> push(2) -> push(8) -> 결과물: 8 7 2
     단, 비교에는 less가 쓰이나 내림차순임
}