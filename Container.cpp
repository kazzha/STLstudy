#include <iostream>

int main()
{
    /* 1. �����̳� ���� �޼���
    - �̵�: std::vector<int> vec4(std::move(vec3))
            std::vector<int> vec4=std::move(vec3))
    - �Ҹ���: vec5.~vector()
    - ��� �����: vec5.clear()

    2. ũ�� ���� �޼���
    - ũ�� ���ϱ�: cont.size()
    - �����̳ʰ� ����ִ��� ����: cont.empty() -> cont.size == 0 ��� empty() ���

    3. ��� �߰� �޼���
    push_back(); and emplace_back()
    ->push_back�� ���簡 �Ͼ�� emplace_back�� ���ڸ� ���ϱ� ������ �� ȿ����
    
    4. ��ü �޼���
    assign() : ��Ҹ� ������ ��ü

}