/**************************************************************
* List Ŭ������ �׽�Ʈ�ϴ� ���ø����̼� ����                 *
**************************************************************/
#include <Windows.h>	// sleep() ���
#include <string>
#include "List.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "Binary_Search_Tree.cpp"

int main()
{
	////////// chapter18: �ڷ� ���� //////////
	// �ڷᱸ���� ����: ���� (����Ʈ), ����(ǥ, Ʈ��)
	///// 1. ���� ��ũ�� ����Ʈ(����) /////
	// ����Ʈ ������ ���� ������(��)�� ������(���� ��带 ����Ŵ)�� ����
	// ����Ʈ ��ü(����):	begin(ù��° ��带 ����Ŵ), count(����� ��ü ��)
	// ��� ��ü(��):	data, next(���� ��带 ����Ŵ)
	cout << "1. ���� ��ũ�� ����Ʈ" << endl;

	// ����Ʈ ��ü�� �ν��Ͻ�ȭ (���ø� Ŭ����)
	List<string> list;	// ������ (���ø� ���� ���)

	// ����Ʈ�� ��� 3���� �߰�
	list.insert(0, "List_first");
	list.insert(1, "List_second");
	list.insert(2, "List_third");

	// ����Ʈ�� ������ ���
	cout << "����Ʈ ����ϱ�" << endl;
	list.print();

	// ��� 1���� ���
	cout << "�Ϻ� ��常 ����ϱ�" << endl;
	cout << list.get(2) << endl;

	// ��� 1�� ����
	cout << "��� �Ϻ� �����ϰ� ��� ����ϱ�" << endl;
	list.erase(1);
	list.print();

	// ��带 ������ ���Ŀ� ����Ʈ�� ũ�� ���
	cout << "����Ʈ ũ�� Ȯ���ϱ�" << endl;
	cout << "����Ʈ�� ũ��: " << list.size() << endl << endl;

	///// 2. ���� (����) /////
	// ���Լ��� �ڷ� ����!
	cout << "2. ����" << endl;

	// ���� ��ü�� �ν��Ͻ�ȭ
	Stack<string> stack;

	// ���ÿ� ��� 3�� �߰�
	stack.push("Stack_first");
	stack.push("Stack_second");
	stack.push("Stack_third");

	// ������ ũ�� Ȯ��
	cout << "������ ũ��: " << stack.size() << endl;

	// top ��� �Լ��� ȣ���ؼ� ���� ��带 Ȯ�� �� pop ��� �Լ��� ȣ���ؼ� ����
	while (stack.size() > 0)
	{
		cout << "Stack.top(): " << stack.top() << endl;
		stack.pop();
	}

	// ������ ũ�⸦ �ٽ� Ȯ��
	cout << "������ ũ��: " << stack.size() << endl << endl;

	///// 3. ť (����) /////
	// ���Լ��� �ڷᱸ��!
	cout << "3. ť" << endl;

	// ť ��ü �ν��Ͻ�ȭ
	Queue<string> queue;

	// ť�� ��� 3�� �߰�
	queue.push("Queue_first");
	queue.push("Queue_second");
	queue.push("Queue_third");
	queue.push("Queue_forth");

	// ��� �߰� �� ���� Ȯ��
	cout << "��� 4���� �߰��ϰ� front�� back ȣ���ϱ�" << endl;
	cout << "front(): " << queue.front() << endl;
	cout << "back(): " << queue.back() << endl;

	// ť���� ��� 2�� ����
	queue.pop();
	queue.pop();

	// ��� ���� �� ���� Ȯ��
	cout << "��� 2���� �����ϰ� front�� back ȣ���ϱ�" << endl;
	cout << "front(): " << queue.front() << endl;
	cout << "back(): " << queue.back() << endl << endl;
	Sleep(100); // ���� ���ϸ� �ܼ� ����� ����������

	///// 4. ���� Ž�� Ʈ�� (����) /////
	// Ʈ���� �ִ� ������ ���� �ִ� �ΰ��� ���� ����, ������ ��ø �Ұ�
	// ���� ���: ������, ������ ���: ū��
	// ��ȸ: Ʈ���� ��� ��忡 �ѹ��� �����ϴ� ���
	// pre-order ��ȸ:	��Ʈ -> ���� Ʈ�� -> ������ Ʈ�� (����)
	// in-order ��ȸ:	���� Ʈ�� -> ��Ʈ -> ������ Ʈ�� (���[�������� ����])
	// post-order ��ȸ:	���� Ʈ�� -> ������ Ʈ�� -> ��Ʈ (����)
	cout << "4. ���� Ž�� Ʈ��" << endl;

	// ���� Ž�� Ʈ�� ���� 
	BinarySearchTree <int> bst;

	// 6���� ��� �߰�
	bst.insert(15);
	bst.insert(10);
	bst.insert(20);
	bst.insert(5);
	bst.insert(25);
	bst.insert(30);

	// pre-order ��ȸ ���
	cout << "pre-order ��ȸ ��� (�����Ҷ�)" << endl;
	bst.preorder();
	cout << endl;

	// in-order ��ȸ ���
	cout << "in-order ��ȸ ��� (������������)" << endl;
	bst.inorder();
	cout << endl;

	// post-order ��ȸ ���
	cout << "post-order ��ȸ ��� (�����Ҷ�)" << endl;
	bst.postorder();
	cout << endl;

	// �� Ž��
	cout << "Ž��: " << endl;
	cout << "search('25') = " << boolalpha << bst.search(25) << endl;
	cout << "search('100') = " << boolalpha << bst.search(100) << endl;

	return 0;	// �Ҹ���
}