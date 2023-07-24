/*********************************************************************
* 재귀 처리로 insert, erase, search, 순회 등의 멤버 함수를 구현한   *
* BinarySearchTree 클래스의 인터페이스 파일                         *
*********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
using namespace std;

// Node 구조체 정의
template<class T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

// BinarySearchTree 클래스 정의
template<class T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
	int count;
	TreeNode<T>* makeNode(const T& value);
	// 헬퍼 함수란: 재귀 함수 (일반 함수에서 호출 받음)
	void destroy(TreeNode <T>* ptr);						// 헬퍼 함수 (post-order)
	void insert(const T& value, TreeNode <T>*& ptr);		// 헬퍼 함수 (pre-order)
	void inorder(TreeNode <T>* ptr) const;					// 헬퍼 함수
	void preorder(TreeNode <T>* ptr) const;					// 헬퍼 함수
	void postorder(TreeNode <T>* ptr) const;				// 헬퍼 함수
	bool search(const T& value, TreeNode <T>* ptr) const;	// 헬퍼 함수

public:
	BinarySearchTree();
	~BinarySearchTree();
	// 일반 함수: 쉽게 사용할 수 있게 매개변수를 최소한으로만 갖고 있음(헬퍼 함수 호출)
	void insert(const T& value);							// 일반 함수
	//void erase(const T& value); // 함수 정의 없음
	bool search(const T& value) const;						// 일반 함수
	void inorder() const;									// 일반 함수
	void preorder() const;									// 일반 함수
	void postorder() const;									// 일반 함수
	int size() const;
	bool empty() const;
};
#endif 