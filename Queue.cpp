/**************************************************************
* List Ŭ������ ��� �Լ��� Ȱ���ϴ�                         *
* Stack Ŭ������ ���� ����                                   *
**************************************************************/
#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"


// push ��� �Լ�
template<typename T>
void Queue<T>::push(const T& value)
{
	list.insert(list.size(), value);
}
// pop ��� �Լ�
template<typename T>
void Queue<T>::pop()
{
	list.erase(0);
}
// front ��� �Լ�
template<typename T>
T& Queue<T>::front() const
{
	return list.get(0);
}
// back ��� �Լ�
template<typename T>
T& Queue<T>::back() const
{
	return list.get(list.size() - 1);
}
// size ��� �Լ�
template<typename T>
int Queue<T>::size() const
{
	return list.size();
}
// print ��� �Լ�
template<typename T>
void Queue<T>::print() const
{
	list.print();
}
#endif