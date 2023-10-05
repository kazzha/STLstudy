#include <memory>
#include <iostream>

int main()
{
	����Ʈ ������ : <memory> ��� �ʿ�

	1) unique_ptr : �ڿ��� ���� ����, �̵� ����(move), ������ �� ����, ������ ����
	- �Ϲ� ���� : std::unique_ptr<int> uniquePtr1{ new int(100) };
	- move �Լ� : std::unique_ptr<int> uniquePtr2{ move(uniquePtr1) };
	- ����: int* myInt = uniquePtr2.release(); -> uniquePtr2�� �����ϴ� �������� �������� ��ȯ,
		uniquePtr2�� �� �̻� � �����͵� ������ ������ �޸𸮴� �������� ����
	        delete myInt; -> �޸� ����

	-get �Լ�: �ڿ��� ����Ű�� �����͸� ������
	-release �Լ�: �ڿ��� ����Ű�� �����͸� ������ �� �ش� �ڿ��� ����
	* �迭 �����ͷ� ���� �� : std::unique_ptr<int[]> MyArray{int[3]};
	* ������ ���� auto ptr = std::make_unique<int>(2014);

	2) shared_ptr : �ڿ��� ������ ����, �� ���� �ڵ� ��� 1) �ڿ��� ���� ��, 2) ���� Ƚ��
	-> unique_ptr, raw pointer ���� �ð�/�޸� �� ���� ���

    - shared_ptr ��ü ���� �� ���� Ƚ�� 1 ����
    - shared_ptr ��ü�� ������ ����� ���� Ƚ�� 1 ����
	- ���� Ƚ�� 0�� �Ǹ� C++ ��Ÿ���� �ڵ����� �ڿ� ����

	* �Լ�
	unique : ���� std::shared_ptr ��ü�� �ڿ��� ������ ���������� ����
	use_count : ���� Ƚ���� ������

	*make_shared : �ξ� �����⿡ ������ �� �Լ��� ���� ���� ����.

	3) std::weak_ptr : shared_ptr���� ��ȯ ������ ���µ� ����
	���� shared_ptr�κ��� �ڿ��� ��������, ���� Ƚ���� �������� ����
}