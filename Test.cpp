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