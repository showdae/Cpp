/*
1. ��ũ�� ����Ʈ (list)
	Ư¡:	������ ����� ������ �����͸� �����ϴ� �ڷᱸ��. �� ���� �����Ϳ� ���� ��带 ����Ű�� �����ͷ� �̷���� �ֽ��ϴ�.
	����:	�߰��� ��Ҹ� �����ϰų� �����ϴ� ��� �����մϴ�.
	����:	���� ������ �Ұ����Ͽ� ���ϴ� ��ġ�� �ٷ� �����ϴ� ���� ��ȿ�����Դϴ�.
			�� ��帶�� �����͸� ����ϱ� ������ �޸� ����� �� ���� �� �ֽ��ϴ�.
	��뿹:	�������� ���԰� ������ ����ϰ� ���� ������ �ʿ� ���� ��쿡 �����մϴ�.

2. ���� �迭 (vector, deque, stack, queue, priority_queue)
	Ư¡:	�������� ũ�Ⱑ ���� ������ �迭��, �����Ͱ� ���������� ����˴ϴ�.
	����:	���� ������ �����Ͽ� �ε����� ����Ͽ� ���ϴ� ��ġ�� �ٷ� �����ϴ� ���� ȿ�����Դϴ�.
			�޸𸮸� ���������� ����Ͽ� �޸� ĳ���� Ȱ���� �����մϴ�.
	����:	�߰��� ��Ҹ� �����ϰų� �����ϴ� ��� �����͸� �̵����Ѿ� �ϹǷ� ������ ���� �� �ֽ��ϴ�.
			ũ�Ⱑ �������� ����� ��, �޸𸮸� ���Ҵ��Ͽ� �����ؾ� �ϴ� ��찡 �߻��Ͽ� ���� ������ ������ �� �� �ֽ��ϴ�.
	��뿹:	���� ������ �ʿ��ϰ� ũ�Ⱑ �������� ���ϴ� ��쿡 �����մϴ�.

3. ���� Ž�� Ʈ�� (set, map):
	Ư¡:	�� ��尡 �ִ� �� ���� �ڽ� ��带 ������, ���� ����Ʈ���� ���� ���� ��庸�� �۰� ������ ����Ʈ���� ���� ���� ��庸�� ū ���� Ʈ���Դϴ�.
	����:	Ž��, ����, ���� ���� �۾��� ��������� O(log n) �ð��� �̷�����ϴ�. (���� Ʈ���� ���)
			���ĵ� �����͸� ȿ�������� �����ϰ� Ž���� �� �ֽ��ϴ�.
	����:	Ʈ���� ���̰� �� ������ ġ��ġ�� ��� ������ ���ϵ� �� �ֽ��ϴ�. (���� Ʈ���� �����ϱ� ���� �߰� �۾� �ʿ�)
	��뿹:	���ĵ� �����͸� �ٷ�ų� Ž��, ����, ���� �۾��� ��� �ð� ���⵵�� O(log n)���� �����Ǵ� ��쿡 �����մϴ�.
*/

	////////// chapter19: STL //////////
	/*
	Standard Template Library (ǥ�� ���ø� ���̺귯�� [Ŭ����])
	1. �ݺ���(iterator): STL�� �ݺ��ڸ� ����� �����̳� ��ҿ� �����ؼ� ó��
	 1) �ݺ����� ����
	  - �����͸� �߻�ȭ (�ݺ��ڴ� �ɹ� ������ ������, �̸� Ȱ���ϴ� �ɹ� �Լ��� ����)
	  - �ݺ��ڴ� �����̳��� �ڷ���, ����� �ڷ����� ������� ���
	  - �����̳ʿ� ������ ��Ҵ� ���� �ڷ����� ������ ���� ����
	    (����� ����� �־ ������� ���𰡸� ����, ���� ����)
	  - ����ڴ� "�ܺιݺ���"�� �����̳� ��ҿ� ����, �����̳ʴ� "���ιݺ���"�� ���� (�ܺιݺ��� ó��)
	 2) �ݺ����� ����
	  - �Է� �ݺ���:		��Ҹ� �б⸸ ����
	  - ��� �ݺ���:		��Ҹ� ���⸸ ����
	  - ���� �ݺ���:		��Ҹ� �а� / ���� ����
	  - ����� �ݺ���:	����� ���� ���� (++, --)
	  - ���� ���� �ݺ���:	����� �ݺ��ڿ� �����ڸ� �߰� (�ѹ��� ���ϴ� ��ҿ� ����)
	 3) �̵� ����
	  - �����̳ʴ� "�⺻�ݺ���"(begin/end)�� "���ݺ���"(rbegin/rend) 2���� ������ �ݺ��� ����
	  - �⺻�ݺ��ڴ� ++�� ������ -- �������� �̵�, ���ݺ��ڴ� ++�� ���� -- ���������� �̵�
	 4) ����� (������ ���� �Ұ�)
	  - const iterator: �ѹ� ��Ҹ� ����Ű��, �ٸ� ��Ҹ� ����ų �� ����
	  - const_iterator: ����� ���� ������ �� ����

	2. �����̳�
	 1) ������ �����̳�: ��Ҹ� �����ϰ�, �O�� ������ ������ �� �ִ� �÷���(��ü�� ����)
	  - ũ��/����, ����, �ݺ���(�⺻/��), ����, ����, ����, ���� �ɹ� �Լ� ����
	  - vector(���� �迭):		����:	�����̳� �ڿ� ���� ����, ���� �� ���� ����
	 							����:	�����̳� �հ� �߰��� ���� �߰�, ����
	  - deque(���� �迭):		����:	�����̳� ��/�ڷ� ���� �߰�, ���� (push_front() ��� ����)
								����:	���ʿ� ���� �޸𸮸� �Ҵ��ϱ� ������ �޸𸮸� ���� ������
	  - list(���� ���� ����Ʈ):	����:	�����̳� ���ϴ� ��ġ�� ���� ���԰� ����, sort() �Լ� ����
								����:	����� �ݺ��ڸ� ���� ���� (�ε��� �Ǵ� at() �Լ��� ���� ��ġ ���� �Ұ�)

	 2) �����̳� ������: ������ �����̳ʺ��� ������ �������̽�(Ŭ���� �ɹ� �Լ��� ����)�� ������ ����ϱ� ����
						begin, end ó�� �ݺ��ڸ� ����� �Լ��� �������� �����Ƿ�, �˰��� ���� �Ұ�
	  - stack: stack.push, stack.pop, stack.top(����) �ɹ� �Լ� ���� (���Լ���)
	  - queue:  queue.push, queue.pop, queue.front(�տ� ����), queue.back(�ڿ� ����), queue.size, queue.empty �ɹ� �Լ� ���� (���Լ���)
	  - priority_queue: �켱���� ť�� ��Ҹ� �����Ҷ�, ������ �ƴ� �켱���� �������� ���ĵ� (����)
						priority_queue.push, priority_queue.pop, priority_queue.top(�տ� ����)

	 3) ���� �����̳�(���� Ž�� Ʈ��): key�� ������� ���� �����ϰ� ����
	  - set: Ű(key)�� ���� ��Ҹ� �����ϴ� �����̳� (Ű�� �������� �������� ����, Ű ���� �ߺ��� ��� ���õ�)
	  - map: Ű(key)�� ��(value)�� ������ ���� ��Ҹ� �����ϴ� �����̳� (Ű�� �������� �������� ����, Ű ���� �ߺ��� ��� value ���� ����)
			 pair ����ü: 2���� ���ø� ������ �ɹ��� ���� (<utility> ��� ����)

	3. �Լ��� �Լ� ��ü: �˰����� �Լ� �Ǵ� �Լ� ��ü�� Ȱ��
	 1) �Լ� ������:	�Լ��� �̸��� �Լ��� ����� �޸� ��ġ�� ù��° ����Ʈ�� ����Ű�� ������
					A�Լ��� ���ڷ� B�Լ��� ����Ͽ� ȣ��
	 2) �Լ� ��ü:	Ŭ������ () ������ �Լ��� �����ε��Ͽ� ����
					�Լ��� �Ű������� ����, �Լ��� ������ �� ����
					�Լ� ��ü�� ���¸� ������ ���� (ȣ��ø��� � ������ ������ ����)
					����� Ȱ���� �ٸ� �Լ� ��ü�� �߰��� �Ļ��� ���� ����
					STL �Լ� ��ü (����, ����, ��)
					
	4. �˰���:	�����̳� ��ҿ� ������ ����
	 1) �񺯰�:	�����̳��� ������ �������� ����
	 2) ����:	�����̳��� ������ ����
	 3) ����:	�����̳��� ��Ҹ� ����
	 4) ��ġ:	���� ��ҿ� ���� ó��
	*/

// ǥ�� ���̺귯��
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>	// pair ����ü ����
#include <sstream>	// ���ڿ� ��Ʈ�� (��ūȭ)

// STL
// ������ �����̳� (�ݺ��� ���)
#include <vector>		// �ڷ� ����, ���� (���� �迭)
#include <deque>		// double-ended-queque �յڷ� ����, ���� (���� �迭)
#include <list>			// ���ϴ� ��ġ�� ����, ���� (���� ���� ����Ʈ)

// �����̳� ����� (������ Ŭ���� �������̽�, �ݺ��� �̻��)
#include <stack>		// ���Լ��� ���� (���� �迭)
#include <queue>		// ���Լ��� ���� (���� �迭)
						// priority_queue(�켱���� ť): ���Խ� �켱������ ���� (���� �迭)

// ���� �����̳� (�ݺ��� ���, Ž�� ���)
#include <set>			// key�� ��� (���� Ž�� Ʈ��)
#include <map>			// key�� value ��� (���� Ž�� Ʈ��, pair ����ü)

// �Լ��� �Լ� ��ü
#include <functional>	// STL �Լ� ��ü

// ���� ���� ���
#include "Doubly_List_STL.h"
#include "Set_STL.h"

using namespace std;

// deque Print �Լ�
void dequePrint(deque<string> deq)
{
	for (int i = 0; i < deq.size(); i++)
	{ cout << deq.at(i) << "  "; }
	cout << endl;
}

// queue Print �Լ�
void queuePrint(queue<int> queue)
{
	while (!queue.empty()) // ������ üũ
	{
		cout << queue.front() << " "; // ù��° ��� ����
		queue.pop(); // ù��° ��� ����
	}
	cout << endl;
}

// int Print �Լ�
void intPrint(int value)
{
	cout << value << endl;
}

// �Լ��� ���� ������
void funcPtr(int x, void(*f)(int))
{
	f(x);
}

// �Լ� ��ü
class classPrint
{
public:
	void operator()(int value) { cout << value << endl << endl; }
};

int main()
{
	/////////////////////////////////////////////////
	///// vector.1: �ݺ��� ����� Ž��
	/////////////////////////////////////////////////
	cout << "*** vector.1 ***" << endl;
	// 10���� ��Ҹ� ���� ���Ϳ� �ݺ��� 2�� ����
	vector<float> vec(10);					// ����(������ �����̳�) ��ü �ν��Ͻ�ȭ
	vector<float>::iterator iter;			// �ݺ��� ��ü �ν��Ͻ�ȭ (inner Ŭ����)
	vector<float>::reverse_iterator rIter;	// ���ݺ��� ��ü �ν��Ͻ�ȭ (inner Ŭ����)

	for (int i = 0; i < 10; i++)
	{ vec.at(i) = i + 10.1f; }	// ��ҿ� ����

	cout << "�⺻Ž��: ";
	for (iter = vec.begin(); iter != vec.end(); ++iter) // �⺻ �ݺ��� ++ �̵� (������)
	{ cout << setw(4) << *iter << "   "; }
	cout << endl;

	cout << "��  Ž��: ";
	for (rIter = vec.rbegin(); rIter != vec.rend(); ++rIter) // �� �ݺ��� ++ �̵� (����)
	{ cout << setw(4) << *rIter << "   "; }
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// vector.2: �ݺ��ڸ� ����� ����� ���� ����
	/////////////////////////////////////////////////
	cout << "*** vector.2 ***" << endl;
	// ���Ϳ� �ݺ��� �ν��Ͻ�ȭ
	vector<int> vec2;
	vector<int>::iterator iter2;
	vector<int>::reverse_iterator rIter2;
	// ���͸� 10���� ��ҷ� ä���
	for (int i = 0; i < 10; i++)
	{ vec2.push_back(i * 10); }

	// �����̳� �ڿ� ��Ҹ� ����/�����ϴ� ���� ������ ���Ҵ��� ���� ������ ������
	vec2.pop_back();					// ������ ��� ����
	vec2.push_back(90);					// ������ ��� �ڿ� ����
	// �����̳� �߰��� ��Ҹ� ����/�����ϴ� ���� �޸� ���Ҵ��� �ʿ��ϹǷ� ������
	vec2.insert(vec2.begin() + 1, 100);	// �����̳� �߰��� ��� ����
	vec2.at(1) = 200;;					// ��ҿ� ����
	vec2.erase(vec2.begin() + 1);		// �����̳� �߰��� ��� ����
	//vec2.clear();						// ��� ��� ����

	cout << "�⺻ �ݺ��ڷ� ���� �����Ͽ� ���  " << endl;
	iter2 = vec2.begin();				// �����̳��� ù��° ��ҿ� �⺻�ݺ��ڷ� ����
	iter2 += 4;							// + �̵� (������)
	cout << *iter2 << " ";
	iter2 -= 2;							// - �̵� (����)
	cout << *iter2 << endl;

	cout << "�� �ݺ��ڷ� ���� �����Ͽ� ���" << endl;
	rIter2 = vec2.rbegin();				// �����̳��� ������ ��ҿ� ���ݺ��ڷ� ����
	rIter2 += 4;						// + �̵� (����)
	cout << *rIter2 << " ";
	rIter2 -= 2;						// - �̵� (������)
	cout << *rIter2 << endl << endl;


	/////////////////////////////////////////////////
	///// vector.3: 2���� ����
	/////////////////////////////////////////////////
	cout << "*** vector.3 ***" << endl;
	// ������ ����(2���� ����) ����
	int rows = 10;	// ��
	int cols = 10;	// ��
	vector<vector<int>> vecArr(rows, vector <int>(cols)); // 2���� ���� ����

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ vecArr[i][j] = (i + 1) *(j + 1); } // �� �Ҵ�
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ cout << setw(4) << vecArr[i][j] << " "; } // �� ���
		cout << endl;
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// deque.1: ����� ���� ȸ���ϱ�
	/////////////////////////////////////////////////
	cout << "*** deque.1 ***" << endl;
	deque <string> deq(5);
	string arr[] = { "aa", "bb", "cc", "dd", "ee" };

	for (int i = 0; i < 5; i++)
	{ deq[i] = arr[i]; }

	dequePrint(deq); // ���� �Լ� ȣ��

	for (int i = 0; i < deq.size(); i++)
	{
		deq.insert(deq.end() - i, deq.at(0));	// ���ڿ� ����
		//deq.push_front("test");				// ù��° ��� ����
		deq.pop_front();						// ù��° ��� ����
	}
	dequePrint(deq);
	cout << endl;


	/////////////////////////////////////////////////
	///// list.1: �ݺ��� ����� Ž��
	/////////////////////////////////////////////////
	cout << "*** list.1 ***" << endl;
	// list ������ �ݺ��ڸ� ��� ����
	list<int> lst;
	list<int>::iterator iter3;
	list<int>::reverse_iterator rIter3;

	for (int i = 0; i < 5; i++)
	{ lst.push_back(i + 10); } // �ڿ� ����

	cout << "�⺻ ����" << endl;
	for (iter3 = lst.begin(); iter3 != lst.end(); iter3++)
	{ cout << *iter3 << "  "; }
	cout << endl;

	cout << "�� ����" << endl;
	for (rIter3 = lst.rbegin(); rIter3 != lst.rend(); rIter3++)
	{ cout << *rIter3 << "  "; }
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// list.2: �ݺ��ڸ� ����� ����� ���� ����
	/////////////////////////////////////////////////
	cout << "*** list.2 ***" << endl;
	// ����Ʈ�� �ݺ��� ����
	list<int> lst2;
	list<int>::iterator iter4;
	list<int>::reverse_iterator rIter4;

	// ����Ʈ�� ��� 10�� �Է�
	for (int i = 0; i < 10; i++)
	{ lst2.push_back(i * 10); }

	cout << "�⺻ �ݺ��ڷ� ���� �����Ͽ� ���" << endl;
	iter4 = lst2.begin(); // ����Ʈ�� ���� �ּҸ� ����Ŵ
	iter4++; // ������ �̉� (list + ������ �Լ� ����)
	iter4++;
	iter4--;
	cout << *iter4 << endl;

	cout << "�� �ݺ��ڷ� ���� �����Ͽ� ���" << endl;
	rIter4 = lst2.rbegin(); // ����Ʈ�� ������ �ּҸ� ����Ŵ
	rIter4++; // ���� �̵�
	rIter4++;
	rIter4--;
	cout << *rIter4 << endl << endl;


	/////////////////////////////////////////////////
	///// list.3: List�� Ȱ���� ������ �����ε�
	/////////////////////////////////////////////////
	cout << "*** list.3 ***" << endl;
	string strg1 = "9991";
	string strg2 = "992";
	string strg3 = { };

	// �ƽ�Ű�ڵ� -> ������ ��Ÿ���� ������ ����
	BigInteger first(strg1);
	BigInteger second(strg2);

	// ������ ���� �� + ������ �Լ� ȣ��
	BigInteger result = first + second;

	// ���� -> �ƽ�Ű�ڵ带 ��Ÿ���� ������ ����
	strg1 = first.toString();
	strg2 = second.toString();
	strg3 = result.toString();

	cout << setw(strg3.length()) << right << strg1 << " + " << endl;
	cout << setw(strg3.length()) << right << strg2 << endl;
	string dashes(strg3.length(), '-'); // �迭 '-' �ʱ�ȭ
	cout << dashes << endl;
	cout << setw(strg3.length()) << right << strg3 << endl << endl;


	/////////////////////////////////////////////////
	///// stack.1: 10���� -> 16���� ����
	/////////////////////////////////////////////////
	cout << "*** stack.1 ***" << endl;
	stack<char> stk;
	string converter("0123456789ABCDEF"); // 16���� ����
	int decimal = 10;

	// 16���� ���ڷ� ��ȯ�ϰ� ���ÿ� �Է�  
	while (decimal != 0)
	{
		stk.push(converter[decimal % 16]);	// ������ ���� �����Ͽ� �����̳ʿ� ���� 
		decimal = decimal / 16;				// while Ż�� ����
	}
	cout << "10���� = " << decimal << ", 16���� = " << stk.top() << endl << endl; // ����
	stk.pop(); // ����


	/////////////////////////////////////////////////
	///// queue.1: queue�� Ȱ���� �з�
	/////////////////////////////////////////////////
	cout << "*** queue.1 ***" << endl;
	queue<int> queue1, queue2, queue3;
	int rNum;
	int donation;

	srand(time(0)); // �ð��� �̿��� ���� �õ� ����
	for (int i = 0; i < 10; i++)
	{
		rNum = rand(); // ���� ����
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
	///// priority_queue.1: �켱���� ť ���
	/////////////////////////////////////////////////
	cout << "*** priority_queue.1 ***" << endl;
	priority_queue<int> line;

	line.push(4);
	line.push(7);
	line.push(2);
	line.push(6);
	line.push(7);
	line.push(8);
	line.push(2); // push�ϴ� ������ ���� ���� �켱����(��) �������� ���ĵ�

	// �켱 ������ ���� ��� ���
	while (!line.empty())
	{
		cout << line.top() << " "; // ù��° ��ҿ� ����
		line.pop(); // ����
	}
	cout << endl << endl;


	/////////////////////////////////////////////////
	///// set.1: �������� �������� ����
	/////////////////////////////////////////////////
	cout << "*** set.1 ***" << endl;
	set<int> st;

	// ���Խ� ���� �������� ����
	st.insert(10);
	st.insert(30);
	st.insert(20);
	st.insert(20); // �ߺ� ������ ���� ��� ���õ�

	cout << "�������� ���" << endl;
	set <int>::iterator iter5;
	for (iter5 = st.begin(); iter5 != st.end(); iter5++)
	{
		cout << *iter5 << " ";
	}
	cout << endl;

	cout << "�������� ���" << endl;
	set <int>::reverse_iterator riter5;
	for (riter5 = st.rbegin(); riter5 != st.rend(); riter5++)
	{
		cout << *riter5 << " ";
	}
	cout << endl;

	set <int>::iterator iter7 = st.find(20); // Ž��
	iter7--;
	cout << "Ž�� = " << *iter7 << endl << endl;
	

	/////////////////////////////////////////////////
	///// set.2: Set�� Ȱ���� < ������ �����ε�
	/////////////////////////////////////////////////
	cout << "*** set.2 ***" << endl;
	Student student1(111, "aaa", 1.11); // ��ü ����
	Student student3(333, "ccc", 3.33);
	Student student2(222, "bbb", 2.22);
	
	set<Student> stdSet;		// �����̳� ����
	stdSet.insert(student1);
	stdSet.insert(student3);	// < ������ �Լ� ȣ���Ͽ� �켱���� ���Ͽ� ����
	stdSet.insert(student2);

	set <Student>::iterator iter8;
	for (iter8 = stdSet.begin(); iter8 != stdSet.end(); iter8++)
	{
		iter8->print(); // ���
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// map.1: Key�� value �����ϱ�
	/////////////////////////////////////////////////
	cout << "*** map.1 ***" << endl;
	map<string, int> scores; // �ɹ� ������ pair ����ü ���
	
	// key ���� �������� �������� ����
	scores["aaa"] = 10;	// Key:"aaa", value: 10
	scores["ccc"] = 20;
	scores["bbb"] = 30;

	map<string, int>::iterator iter9;
	for (iter9 = scores.begin(); iter9 != scores.end(); iter9++)
	{
		// pair ����ü�� ù��° / �ι�° �ɹ� ���� (���� �ڷ����� �ٸ��� �ִ�)
		cout << iter9->first << "  ";	// string
		cout << iter9->second << endl;	// int
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// map.2: ��ūȭ�Ͽ� key ����
	/////////////////////////////////////////////////
	cout << "*** map.2 ***" << endl;
	map<string, int> freq;
	string word("asd zxc asd");
	string token;
	stringstream ss(word);	// ���ڿ� ��Ʈ������ ����

	while (getline(ss, token, ' ')) // ���й��� �������� ���ڿ� �и�
	{
		// key: ��ū ���ڿ�, value: 1 (defalt)
		++freq[token]; // key�� ���� ��� value++ ����
	}

	map<string, int>::iterator iter10;
	for (iter10 = freq.begin(); iter10 != freq.end(); iter10++)
	{
		cout << iter10->first << "   " << iter10->second << endl; // pair ����ü ���
	}
	cout << endl;


	/////////////////////////////////////////////////
	///// �Լ��� �Լ� ��ü.1: �Լ� ������ ����� �Լ� Ȱ��
	/////////////////////////////////////////////////
	cout << "*** �Լ��� �Լ� ��ü.1 ***" << endl;
	funcPtr(10, intPrint);	// �Լ� ������: intPrint �Լ��� ���� �����͸� �����ؼ� ȣ��
	funcPtr(20, intPrint);
	cout << endl;


	/////////////////////////////////////////////////
	///// �Լ��� �Լ� ��ü.2: �Լ� ������ STL �Լ� Ȱ��
	/////////////////////////////////////////////////
	cout << "*** �Լ��� �Լ� ��ü.2 ***" << endl;
	vector<int> vec3;
	vec3.push_back(10);
	vec3.push_back(20);

	// for_each: STL �˰���
	// �ݺ��ڷ� ���� ����, ������ �Ű������� �Լ��� ���� �����͸� ����
	// ���� ���ο� �ִ� ��ҵ鿡 �Լ��� ����
	// intPrint() �Լ��� �ݺ��ڰ� ����Ű�� ���(*iterator)�� �ڷ����� �Ķ��Ÿ�� ����
	for_each(vec3.begin(), vec3.end(), intPrint); // �Լ� ������
	cout << endl;


	/////////////////////////////////////////////////
	///// �Լ��� �Լ� ��ü.3: �Լ� ��ü ���� �� ȣ��
	/////////////////////////////////////////////////
	cout << "*** �Լ��� �Լ� ��ü.3 ***" << endl;
	classPrint print;
	print(10);	// () ������ �����ε� �Լ��� ȣ��


	/////////////////////////////////////////////////
	///// �Լ��� �Լ� ��ü.4: STL �Լ� ��ü
	/////////////////////////////////////////////////
	cout << "*** �Լ��� �Լ� ��ü.4 ***" << endl;
	// 4���� ��Ҹ� ���� ���� ����
	vector <int> vec4;
	vec4.push_back(24);
	vec4.push_back(42);
	vec4.push_back(73);
	vec4.push_back(92);

	// �Լ��� ���� �����ͷ� ��� ���
	for_each(vec4.begin(), vec4.end(), intPrint);
	cout << endl;

	// ��� ����� ��ȣ�� �����ϰ� ���
	transform(vec4.begin(), vec4.end(), vec4.begin(), negate<int>());
	for_each(vec4.begin(), vec4.end(), intPrint);

	return 0; // �Ҹ��� ȣ��
}