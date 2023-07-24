/**************************************************************
* List 클래스를 테스트하는 애플리케이션 파일                 *
**************************************************************/
#include <Windows.h>	// sleep() 헤더
#include <string>
#include "List.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "Binary_Search_Tree.cpp"

int main()
{
	////////// chapter18: 자료 구조 //////////
	// 자료구조의 구분: 선형 (리스트), 비선형(표, 트리)
	///// 1. 단일 링크드 리스트(선형) /////
	// 리스트 각각의 노드는 데이터(값)와 포인터(다음 노드를 가리킴)로 구성
	// 리스트 객체(스택):	begin(첫번째 노드를 가리킴), count(노드의 전체 수)
	// 노드 객체(힙):	data, next(다음 노드를 가리킴)
	cout << "1. 단일 링크드 리스트" << endl;

	// 리스트 객체를 인스턴스화 (템플릿 클래스)
	List<string> list;	// 생성자 (템플릿 선언 방법)

	// 리스트에 노드 3개를 추가
	list.insert(0, "List_first");
	list.insert(1, "List_second");
	list.insert(2, "List_third");

	// 리스트의 노드들을 출력
	cout << "리스트 출력하기" << endl;
	list.print();

	// 노드 1개만 출력
	cout << "일부 노드만 출력하기" << endl;
	cout << list.get(2) << endl;

	// 노드 1개 제거
	cout << "노드 일부 제거하고 노드 출력하기" << endl;
	list.erase(1);
	list.print();

	// 노드를 제거한 이후에 리스트의 크기 출력
	cout << "리스트 크기 확인하기" << endl;
	cout << "리스트의 크기: " << list.size() << endl << endl;

	///// 2. 스택 (선형) /////
	// 후입선출 자료 구조!
	cout << "2. 스택" << endl;

	// 스택 객체를 인스턴스화
	Stack<string> stack;

	// 스택에 노드 3개 추가
	stack.push("Stack_first");
	stack.push("Stack_second");
	stack.push("Stack_third");

	// 스택의 크기 확인
	cout << "스택의 크기: " << stack.size() << endl;

	// top 멤버 함수를 호출해서 위의 노드를 확인 후 pop 멤버 함수를 호출해서 제거
	while (stack.size() > 0)
	{
		cout << "Stack.top(): " << stack.top() << endl;
		stack.pop();
	}

	// 스택의 크기를 다시 확인
	cout << "스택의 크기: " << stack.size() << endl << endl;

	///// 3. 큐 (선형) /////
	// 선입선출 자료구조!
	cout << "3. 큐" << endl;

	// 큐 객체 인스턴스화
	Queue<string> queue;

	// 큐에 노드 3개 추가
	queue.push("Queue_first");
	queue.push("Queue_second");
	queue.push("Queue_third");
	queue.push("Queue_forth");

	// 노드 추가 후 상태 확인
	cout << "노드 4개를 추가하고 front와 back 호출하기" << endl;
	cout << "front(): " << queue.front() << endl;
	cout << "back(): " << queue.back() << endl;

	// 큐에서 노드 2개 제거
	queue.pop();
	queue.pop();

	// 노드 제거 후 상태 확인
	cout << "노드 2개를 제거하고 front와 back 호출하기" << endl;
	cout << "front(): " << queue.front() << endl;
	cout << "back(): " << queue.back() << endl << endl;
	Sleep(100); // 슬립 안하면 콘솔 출력이 비정상적임

	///// 4. 이진 탐색 트리 (비선형) /////
	// 트리에 있는 각각의 노드는 최대 두개의 노드와 연결, 데이터 중첩 불가
	// 왼쪽 노드: 작은값, 오른쪽 노드: 큰값
	// 순회: 트리의 모든 노드에 한번씩 접근하는 방식
	// pre-order 순회:	루트 -> 왼쪽 트리 -> 오른쪽 트리 (삽입)
	// in-order 순회:	왼쪽 트리 -> 루트 -> 오른쪽 트리 (출력[오름차순 정렬])
	// post-order 순회:	왼쪽 트리 -> 오른쪽 트리 -> 루트 (제거)
	cout << "4. 이진 탐색 트리" << endl;

	// 이진 탐색 트리 생성 
	BinarySearchTree <int> bst;

	// 6개의 노드 추가
	bst.insert(15);
	bst.insert(10);
	bst.insert(20);
	bst.insert(5);
	bst.insert(25);
	bst.insert(30);

	// pre-order 순회 출력
	cout << "pre-order 순회 출력 (삽입할때)" << endl;
	bst.preorder();
	cout << endl;

	// in-order 순회 출력
	cout << "in-order 순회 출력 (오름차순정렬)" << endl;
	bst.inorder();
	cout << endl;

	// post-order 순회 출력
	cout << "post-order 순회 출력 (제거할때)" << endl;
	bst.postorder();
	cout << endl;

	// 값 탐색
	cout << "탐색: " << endl;
	cout << "search('25') = " << boolalpha << bst.search(25) << endl;
	cout << "search('100') = " << boolalpha << bst.search(100) << endl;

	return 0;	// 소멸자
}