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
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	string str("asd asd zxc");
	map<string, int> strcopy;
	string token;
	stringstream ss(str);
	
	while (getline(ss, token, ' '))
	{
		cout << token << endl;
		++strcopy[token];
	}


	return 0;
}