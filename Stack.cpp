/**************************************************************
* List Ŭ������ ��� �Լ��� Ȱ���ϴ�                         *
* Stack Ŭ������ ���� ����                                   *
**************************************************************/
#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

// push ��� �Լ�
template<typename T>
void Stack<T>::push(const T& value)
{
	list.insert(0, value);
}
// pop ��� �Լ�
template<typename T>
void Stack<T>::pop()
{
	list.erase(0);
}
// top ��� �Լ�
template<typename T>
T& Stack<T>::top() const
{
	return list.get(0);
}
// size ��� �Լ�   
template<typename T>
int Stack<T>::size() const
{
	return list.size();
}
#endif