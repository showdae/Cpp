// ǥ�� ���̺귯�� ���
#include <iostream>
#include <iomanip>
#include <string>

// STL ������ �����̳� ���
#include <vector>
#include <deque> // ��
#include <list>

// ���� ���� ���
#include "Doubly_List_STL.h"

using namespace std;

// ���� �Լ�
void myPrint(deque<string> deq)
{
	for (int i = 0; i < deq.size(); i++)
	{ cout << deq.at(i) << "  "; }
	cout << endl;
}

int main()
{
	////////// chapter19: STL //////////
	/*
	Standard Template Library (ǥ�� ���ø� ���̺귯�� [Ŭ����])
	1. �ݺ���: STL�� �ݺ��ڸ� ����� �����̳� ��ҿ� �����ؼ� ó��
	 1) �ݺ����� ����
	  - �����͸� �߻�ȭ (�ݺ��ڴ� �ɹ� ������ ������, �̸� Ȱ���ϴ� �ɹ� �Լ��� ����)
	  - �ݺ��ڴ� �����̳��� �ڷ���, ����� �ڷ����� ������� ���
	  - �����̳ʿ� ������ ��Ҵ� ���� �ڷ����� ������ ���� ����
	    (����� ����� �־ ������� ���𰡸� ����, ���� ����)
	  - �����̳ʴ� "���ιݺ���"�� ���� (�ܺιݺ��� ó��), ����ڴ� "�ܺιݺ���"�� �����̳� ��ҿ� ����
	 2) �ݺ����� ����
	  - �Է� �ݺ���:		��Ҹ� �б⸸ ����
	  - ��� �ݺ���:		��Ҹ� ���⸸ ����
	  - ���� �ݺ���:		��Ҹ� �а� / ���� ����
	  - ����� �ݺ���:		����� ���� ���� (++, --)
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

	 2) �����̳� ������: 
	 3) ���� �����̳�: 

	3. �˰���:	�����̳� ��ҿ� ������ ����
	 1) �񺯰�:	�����̳��� ������ �������� ����
	 2) ����:		�����̳��� ������ ����
	 3) ����:		�����̳��� ��Ҹ� ����
	 4) ��ġ:		���� ��ҿ� ���� ó��

	4. �Լ��� �Լ� ��ü: ?
	*/

	///// vector.1: �ݺ��� ����� Ž�� /////
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
	///////////////////////////////////////


	///// vector.2: �ݺ��ڸ� ����� ����� ���� ���� /////
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
	///////////////////////////////////////


	///// vector.3: 2���� ���� /////
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
	///////////////////////////////////////


	///// deque.1: ����� ���� ȸ���ϱ� /////
	cout << "*** deque.1 ***" << endl;
	deque <string> deq(5);
	string arr[] = { "aa", "bb", "cc", "dd", "ee" };

	for (int i = 0; i < 5; i++)
	{ deq[i] = arr[i]; }
	myPrint(deq); // ���� �Լ� ȣ��

	for (int i = 0; i < deq.size(); i++)
	{
		deq.insert(deq.end() - i, deq.at(0));	// ���ڿ� ����
		//deq.push_front("test");				// ù��° ��� ����
		deq.pop_front();						// ù��° ��� ����
	}
	myPrint(deq);
	cout << endl;
	///////////////////////////////////////


	///// list.1: �ݺ��� ����� Ž�� /////
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
	///////////////////////////////////////


	///// list.2: �ݺ��ڸ� ����� ����� ���� ���� /////
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
	///////////////////////////////////////


	///// list.3: List�� Ȱ���� ������ �����ε� /////
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
	cout << setw(strg3.length()) << right << strg3 << endl;
	///////////////////////////////////////

	return 0; // �Ҹ��� ȣ��
	
}