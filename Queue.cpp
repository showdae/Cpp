/**************************************************************
* List 클래스의 멤버 함수를 활용하는                         *
* Stack 클래스의 구현 파일                                   *
**************************************************************/
#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"


// push 멤버 함수
template<typename T>
void Queue<T>::push(const T& value)
{
	list.insert(list.size(), value);
}
// pop 멤버 함수
template<typename T>
void Queue<T>::pop()
{
	list.erase(0);
}
// front 멤버 함수
template<typename T>
T& Queue<T>::front() const
{
	return list.get(0);
}
// back 멤버 함수
template<typename T>
T& Queue<T>::back() const
{
	return list.get(list.size() - 1);
}
// size 멤버 함수
template<typename T>
int Queue<T>::size() const
{
	return list.size();
}
// print 멤버 함수
template<typename T>
void Queue<T>::print() const
{
	list.print();
}
#endif