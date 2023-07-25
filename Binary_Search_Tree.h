/*********************************************************************
* ��� ó���� insert, erase, search, ��ȸ ���� ��� �Լ��� ������   *
* BinarySearchTree Ŭ������ �������̽� ����                         *
*********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
using namespace std;

// Node ���ø� ����ü ����
template<class T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

// BinarySearchTree ���ø� Ŭ���� ����
template<class T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
	int count;
	TreeNode<T>* makeNode(const T& value);
	// ���� �Լ���: ��� �Լ� (�Ϲ� �Լ����� ȣ�� ����)
	void destroy(TreeNode <T>* ptr);						// ���� (post-order)
	void insert(const T& value, TreeNode <T>*& ptr);		// ���� (pre-order)
	void inorder(TreeNode <T>* ptr) const;					// ��� (in-order)
	void preorder(TreeNode <T>* ptr) const;
	void postorder(TreeNode <T>* ptr) const;
	bool search(const T& value, TreeNode <T>* ptr) const;

public:
	BinarySearchTree();
	~BinarySearchTree();
	// �ɹ� �Լ�: ���� ����� �� �ְ� �Ű������� �ּ������� ���� (���ο��� �ּ� ���� �߰��Ͽ� ���� �Լ� ȣ��)
	void insert(const T& value);
	bool search(const T& value) const;
	void inorder() const;
	void preorder() const;
	void postorder() const;
	int size() const;
	bool empty() const;
};
#endif 