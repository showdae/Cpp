/**************************************************************
* List 클래스의 멤버 함수를 활용하는                         *
* Stack 클래스의 구현 파일                                   *
**************************************************************/
#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

// push 멤버 함수
template<typename T>
void Stack<T>::push(const T& value)
{
	list.insert(0, value);
}
// pop 멤버 함수
template<typename T>
void Stack<T>::pop()
{
	list.erase(0);
}
// top 멤버 함수
template<typename T>
T& Stack<T>::top() const
{
	return list.get(0);
}
// size 멤버 함수   
template<typename T>
int Stack<T>::size() const
{
	return list.size();
}
#endif