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
	1) std::move : ���� ��ü�� ���� �� ��ü�� �̵�(����x)
	���� ��ü r-value ������ ��. ���� �̵��ǹ̷��� ������ �� ������ �����ǹ̷��� ���
	* ����: �̵��� �޸� �Ҵ�� ������ �ʿ���� ���纸�� ����, std::thread �� std::lock�� ����
	���簡 �Ұ����� ��찡 �ִ�.
	ex) ��� ���� */
	std::vector<int> myBigVec(10000, 2011);
	std::vector<int> myVec;
	myVec = std::move(myBigVec);

	2) std::forward = ���� ���·� �����ϰ� �״�� �����ϴ� �Լ�
	              ( L-Value�� ������ L-Value�� ����, R-Value�� ������ R-Value�� ����)

	3) std::swap(A, B) : move�� ������
	4) std::pair<Ÿ��, Ÿ��>( , )
		-> �񱳿����ڸ� �����ؼ� ���� pair1�� first�� pair2�� first�� ��,
		���� �� ���� second ��
	* std::make_pair - ��� ������ �������� �ʾƵ� ��
		ex) auto can = std::make_pair("str", 3.14);

	5) std::tuple <tuple> �ʿ�
	-pair�� ����� ���� ��� ���� ����� ����.
	-��Ұ� 2���� tuple�� pair�� ��ȯ ����
	-tuple�� i��° ��� : std::get<i-1>(tuple�̸�)
	-make_tuple ����

	6) std::tie : ���� �������� �����ϴ� ��ҵ�� �̷���� Ʃ�� ���� ����
	   std::ignore : 
	
	
}