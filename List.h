#pragma once
/****************************************************************
* 단일 링크드 리스트를 나타내는 List 클래스의 인터페이스 파일  *
****************************************************************/
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
using namespace std;

// Node 구조체 정의 (템플릿 클래스)
template<typename T>
struct Node
{
	T  data;		// 값
	Node <T>* next;	// 다음 노드를 가리킴
};

// List 클래스 선언 (템플릿 클래스)
template <typename T>
class List
{
private:
	Node<T>* begin;	// 첫번째 노드를 가리킴
	int count;		// 노드의 전체 수
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