#pragma once
/**************************************************************
* List Ŭ������ ���(����)���� ������                        *
* Stack Ŭ������ �������̽� ����                             *
**************************************************************/
#ifndef STACK_H
#define STACK_H
#include "list.cpp"	// ���� ��ũ�� ����Ʈ Ȱ��

// Stack Ŭ���� ����(List Ŭ������ �������� ����)
template<typename T>
class Stack
{
private:
	List<T> list;

public:
	// �⺻ ������
	// �⺻ �Ҹ���
	void push(const T& data);
	void pop();
	T& top() const;
	int size() const;
};
#endif