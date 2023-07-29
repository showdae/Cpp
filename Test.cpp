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
#include <functional>	// 연산자 오버로딩을 사용하여 클래스를 함수처럼 사용
//#include <algorithm>
//#include <numeric>

using namespace std;

void myPrint(int val)
{
	cout << val << endl;
}

int main()
{ 

	
	// 파싱
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