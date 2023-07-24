#pragma once
/****************************************************************
* ���� ��ũ�� ����Ʈ�� ��Ÿ���� List Ŭ������ �������̽� ����  *
****************************************************************/
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
using namespace std;

// Node ����ü ���� (���ø� Ŭ����)
template<typename T>
struct Node
{
	T  data;		// ��
	Node <T>* next;	// ���� ��带 ����Ŵ
};

// List Ŭ���� ���� (���ø� Ŭ����)
template <typename T>
class List
{
private:
	Node<T>* begin;	// ù��° ��带 ����Ŵ
	int count;		// ����� ��ü ��
	Node<T>* makeNode(const T& value);

public:
	List();
	~List();
	void insert(int pos, const T& value);
	void erase(int pos);
	T& get(int pos) const;
	void print() const;
	int size() const;
};
#endif 