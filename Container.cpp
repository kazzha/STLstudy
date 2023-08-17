#include <iostream>
#include <set>
using namespace std;

int main()
{
    /*
    1. �����̳� ���� �޼���
    - �̵�: std::vector<int> vec4(std::move(vec3))
            std::vector<int> vec4=std::move(vec3))
    - �Ҹ���: vec5.~vector();
    - ��� �����: vec5.clear();

    1) ũ�� ���� �޼���
    - ũ�� ���ϱ�: cont.size()
    - �����̳ʰ� ����ִ��� ����: cont.empty() -> cont.size == 0 ��� empty() ���

    2) ��� �߰� �޼���
    push_back(); and emplace_back()
    ->push_back�� ���簡 �Ͼ�� emplace_back�� ���ڸ� ���ϱ� ������ �� ȿ����
    
    3) ��ü �޼���
    assign() : ��Ҹ� ������ ��ü

    4) ��� ����
    cont.begin() , cont.end() : ���� �ݺ��� ���� �ݺ��� ��. ��� ���� ����
    cont.cbegin(), cont.cend() : ��� ���� �ݺ� ����. ��� ���� �Ұ�

    5) ��� ��
    set<int> set1{ 1,2,3,4 };
    set<int> set3{ 1,2,3,4,5 };
    set<int> set4{ 1,2,3,-3 };
    cout << (set1 > set4) << endl;

    */

    2. ���� �����̳�
    1) array : ������ ������ �������� �����̳� . <array> ��� �ʿ�
       �ʱ�ȭ ��� : std::array<int, 10> arr{};
      -���� ���� ����: 
      arr[n] : ��� ����x
      arr.at(n) : ��� ������ ����Ǿ ���� n�� ��踦 ����� std::range - error ���ܰ� �߻�
      std::get<n>(arr) : ������ Ÿ�ӿ� �ε����� �����Ǿ�� �ϹǷ� vector���� ���� ���Ѵ�.

    2) vector : ���� �����̳ʷ�, ���� ������ ���� ������ �����ϴ�. <vector> ��� �ʿ�
    * �Ұ�ȣ�� �߰�ȣ�� ����
      std::vector<int> vec(10); : 10���� ��Ҹ� ���� vector ��ü ����
      std::vector<int> vec2{10}; : ���� 10�� �ϳ��� ��Ҹ� ���� vector ��ü ����
    * ũ�� �� �뷮
      ����, vector�� ũ��(size, ��� ����)�� �뷮(�̸� Ȯ���� ����, �ִ� ��� ����)���� �۴�.

      vec.size() : vec�� ũ��, ��� ����
      vec.capacity() : �޸� ���Ҵ� ���� vec�� ���� �� �ִ� �ִ� ��� ����
      vec.resize(n) : ��� n���� ���� �� �ֵ��� vec�� ũ�⸦ �ø�
      vec.reserve(n) : ��� n���� ��Ҹ� ���� �޸𸮸� Ȯ��
      vec.shrink_to_fit() : vec�� �뷮�� ���� ũ�⿡ �°� ���δ� - ���������� �ʰ�, ��Ÿ�ӿ��� ��û ���� ����
          
    * ��� ����
      vec.front() : ������ ù ��� ������
      vec.back() : ������ ������ ��� ������
      vec[n]
      vec.at(n) : vec�� ��踦 ������ ����

    * ��� ����

      vec.assign( ... ) : ��� �ϳ� �Ǵ� ���� ��(���� �Ǵ� �ʱ�ġ ���)�� ���Ϳ� ����
      vec.clear() : vec�� ��� ��� ����
      vec.emplace(pos, arg...) : pos�� ����Ű�� ��ġ �տ� ������ �����ϰ�, �� �ڸ����� args...��
          ������ �μ���� ����� �� ��Ҹ� ����
      vec.emplace_back( args ... ) : vec�� ���� args... �� ������ �μ���� ����� �� ��� ����
      vec.erase(...) :�ϳ� �Ǵ� ���� ���� ��Ҹ� �����ϰ� �� ���� ��ġ�� ����Ű�� �ݺ��ڸ� ������
      vec.insert(pos, ... ) : ��� �ϳ� �Ǵ� �������� �����ϰ� ���� ���Ե� ù ��Ҹ� ����Ű��
          �ݺ��ڸ� ������
      vec.pop_back() : ������ ��� ����
      vec.push_back(elem) : vec�� ���� elem�� ���纻 �߰�


}