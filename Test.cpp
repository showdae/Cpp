// git push - 23071717
// git push - 23071804
// git push - 23071906
// git push - 23072104
// git push - 23072419
// git push - 23072516
// git push - 23072607
// git push - 23072708
// git push - 23072802



// ����Ʈ ������?
// ifndef, define, endif ��ó����?
// ���۶�?
// �ݹ� �Լ���?
// �߰��ؾ� �Ұ� (é�� 7)
// �Ű����� ������
// ���� ������
// �ζ��� �Լ�

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int myMinus(int a, int b)
{
	return a - b;
}

void myPrint(int val)
{
	printf("%d\n", val);
}

int main() {
	vector<int> vec(10);
	vector<int>::iterator iter;
	vector<int>::reverse_iterator rIter;

	vec.push_back(11);

	for (int i = 0; i < 10; i++)
	{
		vec.at(i) = i + 1;
	}

	for (iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}