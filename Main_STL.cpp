#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>	// 덱

using namespace std;

// 전역 print 함수
void print(deque<string> deq)
{
	for (int i = 0; i < deq.size(); i++)
	{ cout << deq.at(i) << "  "; }
	cout << endl;
}

int main()
{
	////////// chapter19: STL //////////
	/*
	Standard Template Library (표준 템플릿 라이브러리 [클래스])
	1. 반복자: STL은 반복자를 사용해 컨테이너 요소에 접근해서 처리
	 1) 반복자의 구조
	  - 포인터를 추상화 (반복자는 맴버 변수로 포인터, 이를 활용하는 맴버 함수를 가짐)
	  - 반복자는 컨테이너의 자료형, 요소의 자료형과 상관없이 사용
	  - 컨테이너와 내부의 요소는 서로 자료형에 영향을 주지 않음
	    (어떤곳에 어떤것을 넣어도 상관없이 무언가를 저장, 접근 가능)
	  - 컨테이너는 "내부반복자"를 가짐 (외부반복자 처리), 사용자는 "외부반복자"로 컨테이너 요소에 접근
	 2) 반복자의 종류
	  - 입력 반복자:		요소를 읽기만 가능
	  - 출력 반복자:		요소를 쓰기만 가능
	  - 전방 반복자:		요소를 읽고 / 쓰기 가능
	  - 양방향 반복자:		양방향 접근 가능 (++, --)
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
	  - vector(동적 배열):	일반적으로 많이 사용함
							장점: 컨테이너 뒤에 빠른 삽입, 제거 및 빠른 접근
	 						단점: 컨테이너 앞과 중간에 느린 추가, 제거
	  - deque(동적 배열):	덱은 목록 내부의 요소를 회전할때 사용
							장점: 컨테이너 앞/뒤로 빠른 추가, 제거 (push_front() 사용 가능)
							단점: 앞쪽에 여유 메모리를 할당하기 때문에 메모리를 많이 차지함
	  - list(이중 연결 리스트):	
	 2) 컨테이너 어탭터: 
	 3) 연관 컨테이너: 

	3. 알고리즘:	컨테이너 요소에 적용할 연산
	 1) 비변경:	컨테이너의 구조를 변경하지 않음
	 2) 변경:		컨테이너의 구조를 변경
	 3) 정렬:		컨테이너의 요소를 정렬
	 4) 수치:		숫자 요소에 수학 처리

	4. 함수와 함수 객체: ?
	*/

	///// vector.1: 반복자 사용한 탐색 /////
	cout << "vector.1" << endl;
	// 10개의 요소를 가진 벡터와 반복자 2개 생성
	vector<float> vec(10);					// 벡터(시퀀스 컨테이너) 객체 인스턴스화
	vector<float>::iterator iter;			// 반복자 객체 인스턴스화 (inner 클래스)
	vector<float>::reverse_iterator rIter;	// 역반복자 객체 인스턴스화 (inner 클래스)

	for (int i = 0; i < 10; i++)
	{ vec.at(i) = i + 10.1f; }	// 요소에 접근

	cout << "   탐색: ";
	for (iter = vec.begin(); iter != vec.end(); ++iter) // 기본 반복자 ++ 이동 (오른쪽)
	{ cout << setw(4) << *iter << "   "; }
	cout << endl;

	cout << "역 탐색: ";
	for (rIter = vec.rbegin(); rIter != vec.rend(); ++rIter) // 역 반복자 ++ 이동 (왼쪽)
	{ cout << setw(4) << *rIter << "   "; }
	cout << endl << endl;


	///// vector.2: 반복자를 사용한 양방향 임의 접근 /////
	cout << "vector.2" << endl;
	// 벡터와 반복자 인스턴스화
	vector<int> vec2;
	vector<int>::iterator iter2;
	vector<int>::reverse_iterator rIter2;
	// 벡터를 10개의 요소로 채우기
	for (int i = 0; i < 10; i++)
	{
		vec2.push_back(i * 10);
	}

	// 컨테이너 뒤에 요소를 삽입/제거하는 것은 별도의 재할당이 없기 때문에 빠르다
	vec2.pop_back();					// 마지막 요소 제거
	vec2.push_back(90);					// 마지막 요소 뒤에 삽입
	// 컨테이너 중간에 요소를 삽입/제거하는 것은 메모리 재할당이 필요하므로 느리다
	vec2.insert(vec2.begin() + 1, 100);	// 컨테이너 중간에 요소 삽입
	vec2.at(1) = 200;;					// 요소에 접근
	vec2.erase(vec2.begin() + 1);		// 컨테이너 중간에 요소 제거
	//vec2.clear();						// 모든 요소 제거

	// 기본 반복자로 출력  
	cout << "기본 반복자로 임의 접근하여 출력  " << endl;
	iter2 = vec2.begin();		// 컨테이너의 첫번째 요소에 기본반복자로 접근
	iter2 += 4;					// + 이동 (오른쪽)
	cout << *iter2 << " ";
	iter2 -= 2;					// - 이동 (왼쪽)
	cout << *iter2 << endl;
	// 역 반복자로 출력
	cout << "역 반복자로 임의 접근하여 출력" << endl;
	rIter2 = vec2.rbegin();		// 컨테이너의 마지막 요소에 역반복자로 접근
	rIter2 += 4;				// + 이동 (왼쪽)
	cout << *rIter2 << " ";
	rIter2 -= 2;				// - 이동 (오른쪽)
	cout << *rIter2 << endl << endl;


	///// vector.3: 2차원 벡터 /////
	cout << "vector.3" << endl;
	// 벡터의 벡터(2차원 벡터) 생성
	int rows = 10;	// 행
	int cols = 10;	// 열
	vector<vector<int>> vecArr(rows, vector <int>(cols)); // 2차원 벡터 선언
	// 2차원 벡터의 값 설정
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ vecArr[i][j] = (i + 1) *(j + 1); } // 2차원 배열처럼 사용
	}
	// 값 추출하기 출력
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ cout << setw(4) << vecArr[i][j] << " "; }
		cout << endl;
	}
	cout << endl;


	///// deque.1: 요소의 순서 회전하기 /////
	cout << "deque.1" << endl;
	// 덱을 생성하고 요소 5개로 초기화
	deque <string> deq(7);
	string arr[5] = { "aaa", "bbb", "ccc", "ddd", "eee" };
	for (int i = 0; i < 5; i++)
	{ deq[i] = arr[i]; }
	print(deq);
	// 시계 방향으로 회전
	deq.push_back(deq.front());
	deq.pop_front();				// 첫번째 요소 제거
	print(deq);
	// 시계 반대 방향으로 회전
	deq.push_front(deq.back());		// 첫번째 요소 추가
	deq.pop_back();
	print(deq);


	return 0; // 소멸자 호출
}