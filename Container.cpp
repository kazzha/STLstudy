#include <iostream>
#include <set>
#include <deque>
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

     3) deque - vector�� ����� ���� �迭 ������ ���� �����̳�, <deque> ��� �ʿ�
     vector�� �ٸ� ��: ���� ��ġ�� ��Ҹ� �߰� �Ǵ� ���� ����
          -> �̸� ���� deq.push_front(elem), deq.pop_front(),deq.emplace_front(arg...) �� �߰��� ����

     ex) deq.insert(deg.begin(),0) -> 0�� �� �տ� ����
         deq.insert(deg.begin()+4,4) -> �� �������� 4�� ����

     4) list - double linked list. <list> ��� �ʿ�
     -���� ������ �������� ����, ������ ��ҿ� ���� ������ ������. ����� ���԰� ������ ������.
     
     *Ư���� �޼���
     list.remove(val) : list���� ���� val�� ��Ҹ� ��� ����
     list.remove_if(pre) : ���� pre�� �����ϴ� ��Ҹ� ��� ����
     list.unique() : ���� ���� ��Ҹ� ����
     list.splice(pos, ...) : pos �տ� �ٸ� ����� ��Ҹ� ����
          ex) list1.splice( std::find ( list.begin() , list.end(), 15 ), list2 )

    5) forward_list : single linked list. <forward_list> ��� �ʿ�
    ������ ����. �ڽ��� ũ�⸦ ���� ����. ���� �����̹Ƿ� �ݺ��� ���Ұ� �Ұ���(itr-- �� ����)

    *Ư���� �޼���

    forw.before_begin() : ù ��� ���� ����Ű�� �ݺ��ڸ� �����ش�.
          ex)  std::forward_list<int> myList = { 2, 3, 4 };

               auto beforeBeginIt = myList.before_begin();
               myList.insert_after(beforeBeginIt, 1);

               for (const auto& value : myList) {
                  std::cout << value << " ";
               }
    forw.emplace_after(pos, args...)
    forw.emplace_front(args...) : forw�� ���� ��ġ�� args...�� ������ �μ��� ����� �� ��� ����
    forw.erase_after(pos, ...)
    forw.insert_after(pos, ...)

    3. ���� �����̳�
    1) ���� �ִ� ���� �����̳�
    *Ű�� ��
        Ű: ���� �����ؾ� ��, ���� ����, �̵� �����̾�� ��
        ��: �⺻ ���� �����ؾ� �ϰ� ���� ����, �̵� �����̾�� ��
    
     -Ű�� ���� std::pair�� ����, Ű: p.first�̰� ���� p.second
        ex) std::multimap<char, int> mulm= {{'a', 10}, {'b', 30}}
            for( auto p : mulm ) { std::cout << p.first << "," << p.second }

    *�� ����
        �⺻ : std::less(1, 2, 3, 4...�� ����)
        ū �� ���� �迭�Ϸ���...
        ex) std::map<int, std::string, std::greater<int>> int25tr{ {5,"��"}, {1,"��"}, {3,"��"} };
        
    *Ư���� �˻� �Լ�
        set.count(key) : Ű�� key�� ������ ������ ������
        set.find(key) : key�� �ش��ϴ� Ű�� ����Ű�� �ݺ��ڸ� �����ش�. ������ end()�� ������

    *����� ���԰� ����
        insert�� emplace ��� ����.
        erase(key) : Ű�� key�� �ش��ϴ� ��� ���� �����ϰ� �� ������ ������

   *std::map
        : vector�� ����ϳ� �������� ���� ��� ������ ����. at �޼��嵵 ����

    2) ���� ���� ���� �����̳�
    std::unordered_map, std::unordered_multimap, std::unordered_set, std::unordered_multiset
        ->���� �ִ� ���� �����̳��� ��� ���� ����: O(log n)
          ���� ���� ���� �����̳��� ��� ���� ����: ��� ���⵵

    *Ư¡: �� �Լ��� ���� ���, �ؽ� �Լ��� �����Ѵ�.
     �ؽ� �Լ�: Ű�� �׿� �ش��ϴ� ������ ����, �� ���� �ؽ� ���̶�� �θ���.
        ->�ؽ� �Լ� ���࿡�� ��� �ð��� �ɸ��Ƿ� ��� ���� �ð� ���� ����̴�.

    *��Ŷ: ���ε��� ����. Ű ����->��Ŷ�� ���� ã��

    *�浹: ���� �ٸ� Ű�� ���� ���� ������ ������ ��. �ؽ� �Լ��� ���� �� �浹�� �ִ��� �ٿ��� �Ѵ�.

    *��Ŷ ����: �뷮
     ��Ŷ�� ��� ��ҵ��� ��� ����: ������

    4. �����̳� ������
    -���� �����̳� ������ ��������� �������� ������ �⺻������ std::deque�� ����

    1) std::stack  <stack> ��� �ʿ�
    stack.push(e) : �� ��� e�� ���� �ֻ����� ����
    stack.pop() : �ֻ��� ��Ҹ� ����
    stack.top() : �ֻ��� ��ҿ� ���� ������ ������
    stack.empty() : ��������� true, �� ��������� false�� ��ȯ�ϴ� �Լ�
    stack.size() : ũ�� ��ȯ

    2) std::queue    <queue> ��� �ʿ�
    que.push(e) : ��� e�� queue ���� �߰��Ѵ�
    que.pop() : ��⿭�� ù ��° ��Ҹ� ����
    que.back() : que�� ������ ��ҿ� ���� ������ ������
    que.front() : ù ��° ��ҿ� ���� ������ ������

    3) std::priority_queue     <queue> ��� �ʿ�
    -> �켱������ ���� ������ ��⿭�� ���ʿ� ���δ�
    ex) push(7) -> push(2) -> push(8) -> �����: 8 7 2
     ��, �񱳿��� less�� ���̳� ����������
}