#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cout;

int main() {
	// using namespace std; : std ���ӽ����̽��� ���ϴ� ��Ҹ� ����÷��� std::�� ����� �ʿ䰡
	// ��������. �׷��� �ٸ� ���ӽ����̽��� ������� cout�̶�� ������ �Լ��� ������ �浹�߻�����.
	/* 1. <algorithm> header
	-> min, max, minmax function
	: �ִ�, �ּ� ������ �⺻���� �̸� ������(<)�� ��������, ���Լ��� ���� ������ �� �ְ�
	�� �Լ��� �μ� �ΰ��� �ް� �ϳ��� bool���� ��ȯ�ϴ� �Լ����� �Ѵ�.
	*true �Ǵ� false�� ��ȯ�ϴ� �Լ��� ����(predicate)��� ��

	ex) ��� ���� */
	auto pairSeq = std::minmax({ 3, 1, 2011, 2014, -5 });
	cout << pairSeq.first << "," << pairSeq.second;

	/* 2. <utility> header
	-> std::move : ���� ��ü�� ������ �� ��ü�� �̵�(����x)
	���� ��ü r-value ������ ��. ���� �̵��ǹ̷��� ������ �� ������ �����ǹ̷��� ���
	* ����: �̵��� �޸� �Ҵ�� ������ �ʿ���� ���纸�� ����, std::thread �� std::lock�� ����
	���簡 �Ұ����� ��찡 �ִ�.
	ex) ��� ���� */
	std::vector<int> myBigVec(10000, 2011);
	std::vector<int> myVec;
	myVec = std::move(myBigVec);
}