/*********************************************************************
* 재귀 처리로 insert, erase, search, 순회 등의 멤버 함수를 구현한   *
* BinarySearchTree 클래스의 인터페이스 파일                         *
*********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
using namespace std;

// Node 템플릿 구조체 정의
template<class T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

// BinarySearchTree 템플릿 클래스 정의
template<class T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
	int count;
	TreeNode<T>* makeNode(const T& value);
	// 헬퍼 함수란: 재귀 함수 (일반 함수에서 호출 받음)
	void destroy(TreeNode <T>* ptr);						// 제거 (post-order)
	void insert(const T& value, TreeNode <T>*& ptr);		// 삽입 (pre-order)
	void inorder(TreeNode <T>* ptr) const;					// 출력 (in-order)
	void preorder(TreeNode <T>* ptr) const;
	void postorder(TreeNode <T>* ptr) const;
	bool search(const T& value, TreeNode <T>* ptr) const;

public:
	BinarySearchTree();
	~BinarySearchTree();
	// 맴버 함수: 쉽게 사용할 수 있게 매개변수를 최소한으로 받음 (내부에서 주소 인자 추가하여 헬퍼 함수 호출)
	void insert(const T& value);
	bool search(const T& value) const;
	void inorder() const;
	void preorder() const;
	void postorder() const;
	int size() const;
	bool empty() const;
};
#endif 