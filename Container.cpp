#include <iostream>

int main()
{
    /* 1. 컨테이너 관련 메서드
    - 이동: std::vector<int> vec4(std::move(vec3))
            std::vector<int> vec4=std::move(vec3))
    - 소멸자: vec5.~vector()
    - 요소 지우기: vec5.clear()

    2. 크기 관련 메서드
    - 크기 구하기: cont.size()
    - 컨테이너가 비어있는지 여부: cont.empty() -> cont.size == 0 대신 empty() 사용

    3. 요소 추가 메서드
    push_back(); and emplace_back()
    ->push_back는 복사가 일어나고 emplace_back는 인자를 더하기 때문에 더 효율적
    
    4. 대체 메서드
    assign() : 요소를 완전히 대체

}