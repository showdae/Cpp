/*********************************************************************
* ��� ó���� insert, erase, search, ��ȸ ���� ��� �Լ��� ������   *
* BinarySearchTree Ŭ������ �������̽� ����                         *
*********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
using namespace std;

// Node ����ü ����
template<class T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

// BinarySearchTree Ŭ���� ����
template<class T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
	int count;
	TreeNode<T>* makeNode(const T& value);
	// ���� �Լ���: ��� �Լ� (�Ϲ� �Լ����� ȣ�� ����)
	void destroy(TreeNode <T>* ptr);						// ���� �Լ� (post-order)
	void insert(const T& value, TreeNode <T>*& ptr);		// ���� �Լ� (pre-order)
	void inorder(TreeNode <T>* ptr) const;					// ���� �Լ�
	void preorder(TreeNode <T>* ptr) const;					// ���� �Լ�
	void postorder(TreeNode <T>* ptr) const;				// ���� �Լ�
	bool search(const T& value, TreeNode <T>* ptr) const;	// ���� �Լ�

public:
	BinarySearchTree();
	~BinarySearchTree();
	// �Ϲ� �Լ�: ���� ����� �� �ְ� �Ű������� �ּ������θ� ���� ����(���� �Լ� ȣ��)
	void insert(const T& value);							// �Ϲ� �Լ�
	//void erase(const T& value); // �Լ� ���� ����
	bool search(const T& value) const;						// �Ϲ� �Լ�
	void inorder() const;									// �Ϲ� �Լ�
	void preorder() const;									// �Ϲ� �Լ�
	void postorder() const;									// �Ϲ� �Լ�
	int size() const;
	bool empty() const;
};
#endif 