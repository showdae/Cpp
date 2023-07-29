// git push - 23071717
// git push - 23071804
// git push - 23071906
// git push - 23072104
// git push - 23072419
// git push - 23072516
// git push - 23072607
// git push - 23072708
// git push - 23072802



// 스마트 포인터?
// ifndef, define, endif 전처리기?
// 버퍼란?
// 콜백 함수란?
// 추가해야 할것 (챕터 7)
// 매개변수 생성자
// 복사 생성자
// 인라인 함수

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