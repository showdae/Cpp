#pragma once
/**************************************************************
* List 클래스를 기반(복합)으로                               *
* 구현한 Queue 클래스                                        *
**************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include "Singly_List.cpp"

template<typename T>
class Queue
{
private:
	List<T> list;
public:
	void push(const T& data);
	void pop();
	T& front() const;
	T& back() const;
	int size() const;
	void print() const;
};
#endif 