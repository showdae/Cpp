/**************************************************************
* List Ŭ������ ���� ����                                    *
**************************************************************/
#ifndef LIST_CPP
#define LIST_CPP
#include "Singly_List.h"

// ������
template<typename T>
List<T>::List()
	:begin(nullptr), count(0)	// �ʱ�ȭ ����Ʈ
{
}

// �Ҹ���
template<typename T>
List<T>::~List()
{	// ��� ��带 �� �޸𸮿��� �ϳ��� ����
	Node<T>* del = begin;
	while (begin)
	{
		begin = begin->next;
		delete del;
		del = begin;
	}
}

// insert ��� �Լ�
template<typename T>
void List<T>::insert(int pos, const T& value)
{
	if (pos < 0 || pos > count)
	{
		cout << "������ �Ѵ� ��ġ�� ��带 ������ �� �����ϴ�." << endl;
		return;
	}
	Node<T>* add = makeNode(value);	// ��� ����
	if (pos == 0)	// �տ� ��� ����
	{
		add->next = begin;
		begin = add;
	}
	else			// �߰��� ��� ����
	{
		Node<T>* cur = begin;
		for (int i = 1; i < pos; i++)
		{
			cur = cur->next;
		}
		add->next = cur->next;
		cur->next = add;
	}
	count++;
}

// erase ��� �Լ�
template<typename T>
void List<T>::erase(int pos)
{
	if (pos < 0 || pos > count - 1)
	{
		cout << "������ �Ѵ� ��ġ�� ��带 ������ �� �����ϴ�." << endl;
		return;
	}
	if (pos == 0)	// �տ� ��� ����
	{
		Node<T>* del = begin;
		begin = begin->next;
		delete del;
	}
	else			// �߰��� ��� ����
	{
		Node<T>* cur = begin;
		for (int i = 0; i < pos - 1; i++)
		{
			cur = cur->next;
		}
		Node <T>* del = cur->next;
		cur->next = cur->next->next;
		delete del;
	}
	count--;
}

// get ��� �Լ�
template<typename T>
T& List<T>::get(int pos) const
{
	if (pos < 0 || pos > count - 1)
	{
		cout << "������ �Ѵ� ��ġ�� ��忡 ������ �� �����ϴ�.";
		assert(false);
	}
	else if (pos == 0)
	{
		return begin->data;
	}
	else
	{
		Node<T>* cur = begin;
		for (int i = 0; i < pos; i++)
		{
			cur = cur->next;
		}
		return cur->data;
	}
}

// print ��� �Լ�
template<typename T>
void List<T>::print() const
{
	if (count == 0)
	{
		cout << "����Ʈ�� ������ϴ�." << endl;
		return;
	}
	Node<T>* cur = begin;
	while (cur != 0)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

// size ��� �Լ�
template<typename T>
int List<T>::size() const
{
	return count;
}

// makeNode ��� �Լ�(private)
template<typename T>
Node<T>* List<T>::makeNode(const T& value)
{
	Node<T>* temp = new Node<T>; // ���� �Ҵ�
	temp->data = value;
	temp->next = 0;
	return temp;
}
#endif