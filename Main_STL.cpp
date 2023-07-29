/*
1. 링크드 리스트 (list)
	특징:	노드들이 연결된 구조로 데이터를 저장하는 자료구조. 각 노드는 데이터와 다음 노드를 가리키는 포인터로 이루어져 있습니다.
	장점:	중간에 요소를 삽입하거나 삭제하는 경우 유리합니다.
	단점:	랜덤 접근이 불가능하여 원하는 위치로 바로 접근하는 데에 비효율적입니다.
			각 노드마다 포인터를 사용하기 때문에 메모리 사용이 더 많을 수 있습니다.
	사용예:	데이터의 삽입과 삭제가 빈번하고 랜덤 접근이 필요 없는 경우에 유용합니다.

2. 동적 배열 (vector, deque, stack, queue, priority_queue)
	특징:	동적으로 크기가 조절 가능한 배열로, 데이터가 연속적으로 저장됩니다.
	장점:	랜덤 접근이 가능하여 인덱스를 사용하여 원하는 위치로 바로 접근하는 데에 효율적입니다.
			메모리를 연속적으로 사용하여 메모리 캐시의 활용이 용이합니다.
	단점:	중간에 요소를 삽입하거나 삭제하는 경우 데이터를 이동시켜야 하므로 성능이 느릴 수 있습니다.
			크기가 동적으로 변경될 때, 메모리를 재할당하여 복사해야 하는 경우가 발생하여 성능 저하의 원인이 될 수 있습니다.
	사용예:	랜덤 접근이 필요하고 크기가 동적으로 변하는 경우에 유용합니다.

3. 이진 탐색 트리 (set, map):
	특징:	각 노드가 최대 두 개의 자식 노드를 가지며, 왼쪽 서브트리의 값은 현재 노드보다 작고 오른쪽 서브트리의 값은 현재 노드보다 큰 이진 트리입니다.
	장점:	탐색, 삽입, 삭제 등의 작업이 평균적으로 O(log n) 시간에 이루어집니다. (균형 트리인 경우)
			정렬된 데이터를 효율적으로 저장하고 탐색할 수 있습니다.
	단점:	트리의 높이가 한 쪽으로 치우치는 경우 성능이 저하될 수 있습니다. (균형 트리를 유지하기 위한 추가 작업 필요)
	사용예:	정렬된 데이터를 다루거나 탐색, 삽입, 삭제 작업의 평균 시간 복잡도가 O(log n)으로 충족되는 경우에 유용합니다.
*/

	////////// chapter19: STL //////////
	/*
	Standard Template Library (표준 템플릿 라이브러리 [클래스])
	1. 반복자(iterator): STL은 반복자를 사용해 컨테이너 요소에 접근해서 처리
	 1) 반복자의 구조
	  - 포인터를 추상화 (반복자는 맴버 변수로 포인터, 이를 활용하는 맴버 함수를 가짐)
	  - 반복자는 컨테이너의 자료형, 요소의 자료형과 상관없이 사용
	  - 컨테이너와 내부의 요소는 서로 자료형에 영향을 주지 않음
	    (어떤곳에 어떤것을 넣어도 상관없이 무언가를 저장, 접근 가능)
	  - 사용자는 "외부반복자"로 컨테이너 요소에 접근, 컨테이너는 "내부반복자"를 가짐 (외부반복자 처리)
	 2) 반복자의 종류
	  - 입력 반복자:		요소를 읽기만 가능
	  - 출력 반복자:		요소를 쓰기만 가능
	  - 전방 반복자:		요소를 읽고 / 쓰기 가능
	  - 양방향 반복자:	양방향 접근 가능 (++, --)
	  - 임의 접근 반복자:	양방향 반복자에 연산자를 추가 (한번에 원하는 요소에 접근)
	 3) 이동 방향
	  - 컨테이너는 "기본반복자"(begin/end)와 "역반복자"(rbegin/rend) 2가지 종류의 반복자 정의
	  - 기본반복자는 ++은 오른쪽 -- 왼쪽으로 이동, 역반복자는 ++은 왼쪽 -- 오른쪽으로 이동
	 4) 상수성 (데이터 변경 불가)
	  - const iterator: 한번 요소를 가리키면, 다른 요소를 가리킬 수 없다
	  - const_iterator: 요소의 값을 변경할 수 없다

	2. 컨테이너
	 1) 시퀀스 컨테이너: 요소를 저장하고, 찿는 순서를 제어할 수 있는 컬렉션(객체의 모음)
	  - 크기/용적, 접근, 반복자(기본/역), 삽입, 삭제, 정렬, 스왑 맴버 함수 제공
	  - vector(동적 배열):		장점:	컨테이너 뒤에 빠른 삽입, 제거 및 빠른 접근
	 							단점:	컨테이너 앞과 중간에 느린 추가, 제거
	  - deque(동적 배열):		장점:	컨테이너 앞/뒤로 빠른 추가, 제거 (push_front() 사용 가능)
								단점:	앞쪽에 여유 메모리를 할당하기 때문에 메모리를 많이 차지함
	  - list(이중 연결 리스트):	장점:	컨테이너 원하는 위치에 빠른 삽입과 삭제, sort() 함수 지원
								단점:	양방향 반복자만 접근 가능 (인덱스 또는 at() 함수로 임의 위치 접근 불가)

	 2) 컨테이너 어탭터: 시퀀스 컨테이너보다 가벼운 인터페이스(클래스 맴버 함수가 적다)를 가지며 사용하기 쉽다
						begin, end 처럼 반복자를 만드는 함수를 제공하지 않으므로, 알고리즘 적용 불가
	  - stack: stack.push, stack.pop, stack.top(접근) 맴버 함수 제공 (후입선출)
	  - queue:  queue.push, queue.pop, queue.front(앞에 접근), queue.back(뒤에 접근), queue.size, queue.empty 맴버 함수 제공 (선입선출)
	  - priority_queue: 우선순위 큐는 요소를 삽입할때, 시점이 아닌 우선순위 기준으로 정렬됨 (정렬)
						priority_queue.push, priority_queue.pop, priority_queue.top(앞에 접근)

	 3) 연관 컨테이너(이진 탐색 트리): key를 기반으로 값을 저장하고 접근
	  - set: 키(key)를 갖는 요소를 저장하는 컨테이너 (키를 기준으로 오름차순 정렬, 키 값이 중복될 경우 무시됨)
	  - map: 키(key)와 값(value)을 쌍으로 갖는 요소를 저장하는 컨테이너 (키를 기준으로 오름차순 정렬, 키 값이 중복될 경우 value 값이 증가)
			 pair 구조체: 2개의 템플릿 데이터 맴버로 정의 (<utility> 헤더 정의)

	3. 함수와 함수 객체: 알고리즘은 함수 또는 함수 객체를 활용
	 1) 함수 포인터:	함수를 포인터처럼 사용할 수 있음
					함수의 이름은 함수가 저장된 메모리 위치의 첫번째 바이트를 가리키는 포인터
					A함수의 인자로 B함수를 사용하여 호출
	 2) 함수 객체:	클래스에 () 연산자 오버로딩을 활용하여 함수 객체 생성
					함수를 매개변수로 전달, 함수를 리턴할 수 있음
					함수 객체는 상태를 가질수 있음 (호출시마다 어떤 정보를 가질수 있음)
					상속을 활용해 다른 함수 객체를 추가로 파생할 수도 있음
	 3) STL 함수 객체: 수학(+...), 관계(==...), 논리(&&...) 내장 연산을 구현하고 있는 함수 객체
					
	4. 알고리즘:	컨테이너 요소에 반복자를 사용해서 연산을 처리하는 전역 함수 (시퀀스/연관 컨테이너에 적용 가능, 컨테이너 어댑터 적용 불가)
				모든 알고리즘은 반복자 first 위치부터 last위치 사이에 적용
				컨테이너가 적절한 반복자를 지원하지 않으면, 알고리즘 적용 불가
	 1) 비변경:	컨테이너 구조 변경 불가, 요소값 변경 가능
				count(), count_if(), find(), for_each()
				InIter(입력 반복자)
	 2) 변경:	컨테이너 구조 변경 
				generate(), reverse(), rotate(), random_shuffle(), transform()
				BdIter(양방향 반복자), FwIter(전방 반복자)
	 3) 정렬:	컨테이너의 요소를 정렬
				sort(), binary_search(), min_element(), max_element(), set_union()
				less<T>: < (오름차순 함수 객체), greater<T>: > (내림차순 함수 객체)
	 4) 수치:	숫자 요소에 수학 처리
	*/

// 표준 라이브러리
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>	// pair 구조체 정의
#include <sstream>	// 문자열 스트림 (토큰화)

// 분할 구현 헤더
#include "Doubly_List_STL.h"
#include "Set_STL.h"

// STL
// 시퀀스 컨테이너 (반복자 사용)
#include <vector>		// 뒤로 삽입, 제거 (동적 배열)
#include <deque>		// double-ended-queque 앞뒤로 삽입, 제거 (동적 배열)
#include <list>			// 원하는 위치에 삽입, 제거 (이중 연결 리스트)

// 컨테이너 어댑터 (가벼운 클래스 인터페이스, 반복자 미사용)
#include <stack>		// 후입선출 구조 (동적 배열)
#include <queue>		// 선입선출 구조 (동적 배열)
						// priority_queue(우선순위 큐): 삽입시 우선순위로 정렬 (동적 배열)

// 연관 컨테이너 (반복자 사용, 탐색 기능)
#include <set>			// key를 사용 (이진 탐색 트리)
#include <map>			// key와 value 사용 (이진 탐색 트리, pair 구조체)

// 함수 객체
#include <functional>	// 연산자 오버로딩을 사용하여 클래스를 함수처럼 사용

// 알고리즘 (함수)
#include <algorithm>	// 비변경, 변경, 정렬 알고리즘
#include <numeric>		// 수치 알고리즘

using namespace std;

// deque Print 함수
void dequePrint(deque<string> deq)
{
	for (int i = 0; i < deq.size(); i++)
	{ cout << deq.at(i) << "  "; }
	cout << endl;
}

// queue Print 함수
void queuePrint(queue<int> queue)
{
	while (!queue.empty()) // 사이즈 체크
	{
		cout << queue.front() << " "; // 첫번째 요소 접근
		queue.pop(); // 첫번째 요소 제거
	}
	cout << endl;
}

// int Print 함수
void intPrint(int value)
{
	cout << value << "   ";
}

// 함수에 대한 포인터
void funcPtr(int x, void(*f)(int))
{
	f(x);
}

// 함수 객체 (클래스를 함수처럼 사용)
class classPrint
{
public:
	void operator()(int value) { cout << value << endl << endl; }
};

// 비변경 알고리즘 (짝수 찿기)
bool isEven(int value)
{
	return (value % 2 == 0);
}

// 비변경 알고리즘 (곱하기)
void timesTwo(int& value)
{
	value = value * 2;
}

int main()
{
	/////////////////////////////////////////////////
	///// vector.1: 반복자 사용한 탐색
	/////////////////////////////////////////////////
	cout << "*** vector.1 ***" << endl;
	// 10개의 요소를 가진 벡터와 반복자 2개 생성
	vector<float> vec(10);					// 벡터(시퀀스 컨테이너) 객체 인스턴스화
	vector<float>::iterator iter;			// 반복자 객체 인스턴스화 (inner 클래스)
	vector<float>::reverse_iterator rIter;	// 역반복자 객체 인스턴스화 (inner 클래스)

	for (int i = 0; i < 10; i++)
	{ vec.at(i) = i + 10.1f; }	// 요소에 접근

	cout << "기본탐색: ";
	for (iter = vec.begin(); iter != vec.end(); ++iter) // 기본 반복자 ++ 이동 (오른쪽)
	{ cout << setw(4) << *iter << "   "; }
	cout << endl;

	cout << "역  탐색: ";
	for (rIter = vec.rbegin(); rIter != vec.rend(); ++rIter) // 역 반복자 ++ 이동 (왼쪽)
	{ cout << setw(4) << *rIter << "   "; }
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// vector.2: 반복자를 사용한 양방향 임의 접근
	/////////////////////////////////////////////////
	cout << "*** vector.2 ***" << endl;
	// 벡터와 반복자 인스턴스화
	vector<int> vec2;
	vector<int>::iterator iter2;
	vector<int>::reverse_iterator rIter2;
	// 벡터를 10개의 요소로 채우기
	for (int i = 0; i < 10; i++)
	{ vec2.push_back(i * 10); }

	// 컨테이너 뒤에 요소를 삽입/제거하는 것은 별도의 재할당이 없기 때문에 빠르다
	vec2.pop_back();					// 마지막 요소 제거
	vec2.push_back(90);					// 마지막 요소 뒤에 삽입
	// 컨테이너 중간에 요소를 삽입/제거하는 것은 메모리 재할당이 필요하므로 느리다
	vec2.insert(vec2.begin() + 1, 100);	// 컨테이너 중간에 요소 삽입
	vec2.at(1) = 200;;					// 요소에 접근
	vec2.erase(vec2.begin() + 1);		// 컨테이너 중간에 요소 제거
	//vec2.clear();						// 모든 요소 제거

	cout << "기본 반복자로 임의 접근하여 출력  " << endl;
	iter2 = vec2.begin();				// 컨테이너의 첫번째 요소에 기본반복자로 접근
	iter2 += 4;							// + 이동 (오른쪽)
	cout << *iter2 << " ";
	iter2 -= 2;							// - 이동 (왼쪽)
	cout << *iter2 << endl;

	cout << "역 반복자로 임의 접근하여 출력" << endl;
	rIter2 = vec2.rbegin();				// 컨테이너의 마지막 요소에 역반복자로 접근
	rIter2 += 4;						// + 이동 (왼쪽)
	cout << *rIter2 << " ";
	rIter2 -= 2;						// - 이동 (오른쪽)
	cout << *rIter2 << endl << endl;


	/////////////////////////////////////////////////
	///// vector.3: 2차원 벡터
	/////////////////////////////////////////////////
	cout << "*** vector.3 ***" << endl;
	// 벡터의 벡터(2차원 벡터) 생성
	int rows = 10;	// 행
	int cols = 10;	// 열
	vector<vector<int>> vecArr(rows, vector <int>(cols)); // 2차원 벡터 선언

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ vecArr[i][j] = (i + 1) *(j + 1); } // 값 할당
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ cout << setw(4) << vecArr[i][j] << " "; } // 값 출력
		cout << endl;
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// deque.1: 요소의 순서 회전하기
	/////////////////////////////////////////////////
	cout << "*** deque.1 ***" << endl;
	deque <string> deq(5);
	string arr[] = { "aa", "bb", "cc", "dd", "ee" };

	for (int i = 0; i < 5; i++)
	{ deq[i] = arr[i]; }

	dequePrint(deq); // 전역 함수 호출

	for (int i = 0; i < deq.size(); i++)
	{
		deq.insert(deq.end() - i, deq.at(0));	// 문자열 반전
		//deq.push_front("test");				// 첫번째 요소 삽입
		deq.pop_front();						// 첫번째 요소 제거
	}
	dequePrint(deq);
	cout << endl;


	/////////////////////////////////////////////////
	///// list.1: 반복자 사용한 탐색
	/////////////////////////////////////////////////
	cout << "*** list.1 ***" << endl;
	// list 양항향 반복자만 사용 가능
	list<int> lst;
	list<int>::iterator iter3;
	list<int>::reverse_iterator rIter3;

	for (int i = 0; i < 5; i++)
	{ lst.push_back(i + 10); } // 뒤에 삽입

	cout << "기본 방향" << endl;
	for (iter3 = lst.begin(); iter3 != lst.end(); iter3++)
	{ cout << *iter3 << "  "; }
	cout << endl;

	cout << "역 방향" << endl;
	for (rIter3 = lst.rbegin(); rIter3 != lst.rend(); rIter3++)
	{ cout << *rIter3 << "  "; }
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// list.2: 반복자를 사용한 양방향 임의 접근
	/////////////////////////////////////////////////
	cout << "*** list.2 ***" << endl;
	// 리스트와 반복자 생성
	list<int> lst2;
	list<int>::iterator iter4;
	list<int>::reverse_iterator rIter4;

	// 리스트에 요소 10개 입력
	for (int i = 0; i < 10; i++)
	{ lst2.push_back(i * 10); }

	cout << "기본 반복자로 임의 접근하여 출력" << endl;
	iter4 = lst2.begin(); // 리스트의 시작 주소를 가리킴
	iter4++; // 오른쪽 이돟 (list + 연산자 함수 없음)
	iter4++;
	iter4--;
	cout << *iter4 << endl;

	cout << "역 반복자로 임의 접근하여 출력" << endl;
	rIter4 = lst2.rbegin(); // 리스트의 마지막 주소를 가리킴
	rIter4++; // 왼쪽 이동
	rIter4++;
	rIter4--;
	cout << *rIter4 << endl << endl;


	/////////////////////////////////////////////////
	///// list.3: List를 활용한 연산자 오버로딩
	/////////////////////////////////////////////////
	cout << "*** list.3 ***" << endl;
	string strg1 = "9991";
	string strg2 = "992";
	string strg3 = { };

	// 아스키코드 -> 정수를 나타내는 값으로 변경
	BigInteger first(strg1);
	BigInteger second(strg2);

	// 정수로 변경 후 + 연산자 함수 호출
	BigInteger result = first + second;

	// 정수 -> 아스키코드를 나타내는 값으로 변경
	strg1 = first.toString();
	strg2 = second.toString();
	strg3 = result.toString();

	cout << setw(strg3.length()) << right << strg1 << " + " << endl;
	cout << setw(strg3.length()) << right << strg2 << endl;
	string dashes(strg3.length(), '-'); // 배열 '-' 초기화
	cout << dashes << endl;
	cout << setw(strg3.length()) << right << strg3 << endl << endl;


	/////////////////////////////////////////////////
	///// stack.1: 10진수 -> 16진수 변경
	/////////////////////////////////////////////////
	cout << "*** stack.1 ***" << endl;
	stack<char> stk;
	string converter("0123456789ABCDEF"); // 16진수 종류
	int decimal = 10;

	// 16진수 문자로 변환하고 스택에 입력  
	while (decimal != 0)
	{
		stk.push(converter[decimal % 16]);	// 나머지 값에 접근하여 컨테이너에 삽입 
		decimal = decimal / 16;				// while 탈출 조건
	}
	cout << "10진수 = " << decimal << ", 16진수 = " << stk.top() << endl << endl; // 접근
	stk.pop(); // 제거


	/////////////////////////////////////////////////
	///// queue.1: queue를 활용한 분류
	/////////////////////////////////////////////////
	cout << "*** queue.1 ***" << endl;
	queue<int> queue1, queue2, queue3;
	int rNum;
	int donation;

	srand(time(0)); // 시간을 이용한 랜덤 시드 생성
	for (int i = 0; i < 10; i++)
	{
		rNum = rand(); // 난수 생성
		donation = rNum % 30;
		switch (donation / 10)
		{
		case 0:  queue1.push(donation); // 0 ~ 9
			break;
		case 1:  queue2.push(donation); // 10 ~ 19
			break;
		case 2:  queue3.push(donation); // 20 ~ 29
			break;
		default: cout << "error" << endl;
			break;
		}
	}
	queuePrint(queue1);
	queuePrint(queue2);
	queuePrint(queue3);
	cout << endl;


	/////////////////////////////////////////////////
	///// priority_queue.1: 우선순위 큐 사용
	/////////////////////////////////////////////////
	cout << "*** priority_queue.1 ***" << endl;
	priority_queue<int> line;

	line.push(4);
	line.push(7);
	line.push(2);
	line.push(6);
	line.push(7);
	line.push(8);
	line.push(2); // push하는 시점과 관계 없이 우선순위(값) 기준으로 정렬됨

	// 우선 순위에 따라 요소 출력
	while (!line.empty())
	{
		cout << line.top() << " "; // 첫번째 요소에 접근
		line.pop(); // 제거
	}
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// set.1: 오름차순 내림차순 정렬
	/////////////////////////////////////////////////
	cout << "*** set.1 ***" << endl;
	set<int> st;

	// 삽입시 오름 차순으로 정렬
	st.insert(10);
	st.insert(30);
	st.insert(20);
	st.insert(20); // 중복 데이터 있을 경우 무시됨

	cout << "오름차순 출력" << endl;
	set <int>::iterator iter5;
	for (iter5 = st.begin(); iter5 != st.end(); iter5++)
	{
		cout << *iter5 << " ";
	}
	cout << endl;

	cout << "내림차순 출력" << endl;
	set <int>::reverse_iterator riter5;
	for (riter5 = st.rbegin(); riter5 != st.rend(); riter5++)
	{
		cout << *riter5 << " ";
	}
	cout << endl;

	set <int>::iterator iter7 = st.find(20); // 탐색
	iter7--;
	cout << "탐색 = " << *iter7 << endl << endl;
	

	/////////////////////////////////////////////////
	///// set.2: Set을 활용한 < 연산자 오버로딩
	/////////////////////////////////////////////////
	cout << "*** set.2 ***" << endl;
	Student student1(111, "aaa", 1.11); // 객체 생성
	Student student3(333, "ccc", 3.33);
	Student student2(222, "bbb", 2.22);
	
	set<Student> Set2;		// 컨테이너 생성
	Set2.insert(student1);
	Set2.insert(student3);	// < 연산자 함수 호출하여 우선순위 비교하여 정렬
	Set2.insert(student2);

	set <Student>::iterator iter8;
	for (iter8 = Set2.begin(); iter8 != Set2.end(); iter8++)
	{
		iter8->print(); // 출력
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// map.1: Key와 value 저장하기
	/////////////////////////////////////////////////
	cout << "*** map.1 ***" << endl;
	map<string, int> scores; // 맴버 변수로 pair 구조체 사용
	
	// key 값을 기준으로 오름차순 정렬
	scores["aaa"] = 10;	// Key:"aaa", value: 10
	scores["ccc"] = 20;
	scores["bbb"] = 30;

	map<string, int>::iterator iter9;
	for (iter9 = scores.begin(); iter9 != scores.end(); iter9++)
	{
		// pair 구조체의 첫번째 / 두번째 맴버 변수 (각각 자료형이 다를수 있다)
		cout << iter9->first << "  ";	// string
		cout << iter9->second << endl;	// int
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// map.2: 토큰화하여 key 삽입
	/////////////////////////////////////////////////
	cout << "*** map.2 ***" << endl;
	map<string, int> freq;
	string word("asd zxc asd");
	string token;
	stringstream ss(word);	// 문자열 스트림으로 변경

	while (getline(ss, token, ' ')) // 구분문자 기준으로 문자열 분리
	{
		// key: 토큰 문자열, value: 1 (defalt)
		++freq[token]; // key가 같을 경우 value++ 증가
	}

	map<string, int>::iterator iter10;
	for (iter10 = freq.begin(); iter10 != freq.end(); iter10++)
	{
		cout << iter10->first << "   " << iter10->second << endl; // pair 구조체 출력
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// 함수와 함수 객체.1: 함수 포인터 사용자 함수 활용
	/////////////////////////////////////////////////
	cout << "*** 함수와 함수 객체.1 ***" << endl;
	funcPtr(10, intPrint);	// 함수 포인터: intPrint 함수에 대한 포인터를 전달해서 호출
	funcPtr(20, intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 함수와 함수 객체.2: 함수 객체 생성 및 호출
	/////////////////////////////////////////////////
	cout << "*** 함수와 함수 객체.2 ***" << endl;
	classPrint print;	// 객체 생성
	print(10);			// () 연산자 오버로드 객체 함수를 호출


	/////////////////////////////////////////////////
	///// 함수와 함수 객체.3: STL 함수 및 함수 객체 사용
	/////////////////////////////////////////////////
	cout << "*** 함수와 함수 객체.3 ***" << endl;
	vector<int> vec3;
	vec3.push_back(10);
	vec3.push_back(20);

	// for_each: STL 알고리즘
	//			 반복자로 범위 지정, 마지막 매개변수에 함수에 대한 포인터를 지정
	//			 범위 내부에 있는 요소들에 함수를 적용
	//			 intPrint() 함수는 반복자가 가리키는 대상(*iterator)의 자료형을 파라메타로 받음
	for_each(vec3.begin(), vec3.end(), intPrint); // 함수 포인터로 요소 출력

	// transform:	STL 알고리즘, transform() 함수에서 내부적으로 negate 객체를 호출
	//				transform(inIter first, inIter second, outIter start, oper);
	//				first와 second 사이의 요소에 oper 함수를 적용하고, 리턴된 결과를 start 위치부터 씀
	// negate:		STL 함수객체, (-) 음수 연산자 함수 객체	
	transform(vec3.begin(), vec3.end(), vec3.begin(), negate<int>()); // 요소들의 음수화
	for_each(vec3.begin(), vec3.end(), intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 비변경 알고리즘.1
	/////////////////////////////////////////////////
	cout << "*** 비변경 알고리즘.1 ***" << endl;
	vector<int> vec4;
	vec4.push_back(10);
	vec4.push_back(12);
	vec4.push_back(15);

	cout << "원본 벡터의 값" << endl;
	for_each(vec4.begin(), vec4.end(), intPrint);
	cout << endl;

	cout << "벡터 내부에 있는 10의 개수 = ";
	cout << count(vec4.begin(), vec4.end(), 10);		// count: 인자로 전달한 값과 동일한 요소수를 셈
	cout << endl;

	cout << "벡터 내부에 있는 짝수의 개수 = ";
	cout << count_if(vec4.begin(), vec4.end(), isEven);	// count_if: 인자로 전달한 함수 포인터가 true를 리턴하면 요소수를 셈
	cout << endl;

	cout << "벡터 내부의 요소에 2 곱하기" << endl;
	for_each(vec4.begin(), vec4.end(), timesTwo);		// for_each: 인자로 전달한 함수 포인터가 무언가를 리턴하면 요소를 변경
	for_each(vec4.begin(), vec4.end(), intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 변경 알고리즘.1
	/////////////////////////////////////////////////
	cout << "*** 변경 알고리즘.1 ***" << endl;
	vector <int> vec5;
	vec5.push_back(10);
	vec5.push_back(20);
	vec5.push_back(30);

	cout << "원본 벡터의 값" << endl;
	for_each(vec5.begin(), vec5.end(), intPrint);
	cout << endl;

	cout << "반전한 벡터" << endl;
	reverse(vec5.begin(), vec5.end()); // reverse(): 컨테이너 순서를 반전
	for_each(vec5.begin(), vec5.end(), intPrint);
	cout << endl;

	cout << "회전한 벡터" << endl;
	rotate(vec5.begin(), vec5.begin() + 2, vec5.end()); // rotate(): 첫 요소를 마지막으로 옮겨서 회전
	for_each(vec5.begin(), vec5.end(), intPrint);
	cout << endl;

	cout << "셔플한 벡터" << endl;
	random_shuffle(vec5.begin(), vec5.end()); // random_shuffle(): 임의의 순서로 요소를 정렬
	for_each(vec5.begin(), vec5.end(), intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 정렬 알고리즘.1: Sort
	/////////////////////////////////////////////////
	cout << "*** 정렬 알고리즘.1: Sort ***" << endl;
	vector <int> vec6;
	vec6.push_back(10);
	vec6.push_back(30);
	vec6.push_back(20);

	cout << "원본 벡터의 값" << endl;
	for_each(vec6.begin(), vec6.end(), intPrint);
	cout << endl;

	cout << "오름차순 정렬" << endl;
	sort(vec6.begin(), vec6.end());		// sort(): 정렬 함수 (디폴트: 오름차순)
	for_each(vec6.begin(), vec6.end(), intPrint);
	cout << endl;

	cout << "내림차순 정렬" << endl;
	sort(vec6.begin(), vec6.end(), greater <int>());	// greater<T>: 내림차순 함수 객체
	for_each(vec6.begin(), vec6.end(), intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 정렬 알고리즘.2: binary_search (정렬되어 있는 컨테이너에 적용할 수 있는 알고리즘)
	/////////////////////////////////////////////////
	cout << "*** 정렬 알고리즘.2: binary_search ***" << endl;
	vector <int> vec7;
	vec7.push_back(10);
	vec7.push_back(30);
	vec7.push_back(20);

	sort(vec7.begin(), vec7.end());

	cout << "10 탐색 결과 = " << boolalpha;
	cout << binary_search(vec7.begin(), vec7.end(), 10) << endl; // binary_search(): 요소를 찿음
	cout << "40 탐색 결과 = " << boolalpha;
	cout << binary_search(vec7.begin(), vec7.end(), 40) << endl << endl;


	/////////////////////////////////////////////////
	///// 정렬 알고리즘.3: 합집합
	/////////////////////////////////////////////////
	cout << "*** 정렬 알고리즘.3: ***" << endl;

	// 첫 번째 세트(집합) 생성
	set<int> set_1st;
	set_1st.insert(10);
	set_1st.insert(20);
	cout << "첫 번째 세트의 요소" << endl;
	for_each(set_1st.begin(), set_1st.end(), intPrint);
	cout << endl;

	// 두 번째 세트(집합) 생성
	set<int> set_2nd;
	set_2nd.insert(20);
	set_2nd.insert(30);
	cout << "두 번째 세트의 요소" << endl;
	for_each(set_2nd.begin(), set_2nd.end(), intPrint);
	cout << endl;

	// 세트는 처음 생성될때 비어있으므로, 세트만으로 구현할 수 없음,
	// 따라서 결과를 일시적으로 저장하는 벡터를 만든뒤, 세트에 복사
	// 합집합 구하고 벡터에 저장
	vector<int> temp(10);
	vector<int>::iterator startIter;
	vector<int>::iterator endIter;
	endIter = set_union(set_1st.begin(), set_1st.end(), set_2nd.begin(), // set_union(): 합집합
		set_2nd.end(), temp.begin());

	// 벡터에서 결과 세트로 요소 복사
	set<int> set_result;
	for (startIter = temp.begin(); startIter != endIter; startIter++)
	{
		set_result.insert(*startIter);
	}

	cout << "결과 세트의 요소" << endl;
	for_each(set_result.begin(), set_result.end(), intPrint);
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// 수치 알고리즘.1
	/////////////////////////////////////////////////
	cout << "*** 수치 알고리즘.1: ***" << endl;
	// 벡터 인스턴스화하고 출력
	vector<int> vec8;
	vec8.push_back(10);
	vec8.push_back(20);
	vec8.push_back(30);

	cout << "원본 벡터의 값" << endl;
	for_each(vec8.begin(), vec8.end(), intPrint);
	cout << endl;

	// accumulate():	T accumulate(InIter first, InIter second, T init)
	//					first, second 범위에 있는 숫자의 합을 구하고, init과 더해서 리턴
	int sum = accumulate(vec8.begin(), vec8.end(), 0);
	cout << "누적합 = " << sum << endl;

	int mul = accumulate(vec8.begin(), vec8.end(), 1, multiplies<int>());
	cout << "누적곱 = " << mul << endl;

	return 0; // 소멸자 호출
}