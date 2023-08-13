#include <iostream>
#include <algorithm>
#include <utility>
#

using std::cout;

int main() {
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
}