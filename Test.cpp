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
//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <set>
#include <map>
#include <sstream>
#include <functional>	// ������ �����ε��� ����Ͽ� Ŭ������ �Լ�ó�� ���
//#include <algorithm>
//#include <numeric>

using namespace std;

void myPrint(int val)
{
	cout << val << endl;
}

int main()
{ 

	
	// �Ľ�
	string str2("123 1.23 asd");
	stringstream ss2(str2);
	int itest;
	double dtest;
	string stest;
	ss2 >> itest >> dtest >> stest;
	cout << itest << endl;
	cout << dtest << endl;
	cout << stest << endl;

	return 0;
}