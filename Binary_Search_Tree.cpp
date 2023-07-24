/***************************************************************
* �������̽� ���Ͽ���                                         *
* ������ ��� �Լ��� �����ϴ� ���� ����                       *
***************************************************************/
#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
#include "Binary_Search_Tree.h"

// ������
template<class T>
BinarySearchTree<T>::BinarySearchTree()
	:root(0), count(0)	// �ʱ�ȭ ����Ʈ
{
}

// �Ҹ���
template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroy(root);
}

// insert ��� �Լ�
template <class T>
void BinarySearchTree<T>::insert(const T& value)
{
	insert(value, root);
	count++;
}

// Search ��� �Լ�
template<class T>
bool BinarySearchTree<T>::search(const T& value) const
{
	return search(value, root);
}

// pre-order ��ȸ
template <class T>
void BinarySearchTree<T>::preorder() const
{
	preorder(root);
}

// in-order ��ȸ
template<class T>
void BinarySearchTree<T>::inorder() const
{
	inorder(root);
}

// post-order ��ȸ
template<class T>
void BinarySearchTree<T>::postorder() const
{
	postorder(root);
}

// size ��� �Լ�
template<class T>
int BinarySearchTree<T>::size() const
{
	return count;
}

// empty ��� �Լ�
template<class T>
bool BinarySearchTree<T>::empty() const
{
	return (count == 0);
}

// �Ҹ��ڿ��� Ȱ���ϴ� ���� �Լ�
template<class T>
void BinarySearchTree<T>::destroy(TreeNode <T>* ptr)
{
	if (!ptr)
	{
		return;
	}
	destroy(ptr->left);
	destroy(ptr->right);
	delete ptr;
}

// insert �Լ����� Ȱ���ϴ� ���� �Լ�
template<class T>
void BinarySearchTree<T>::insert(const T& value, TreeNode <T>*& ptr)
{
	if (!ptr) // null�̸�
	{
		ptr = makeNode(value); // ��Ʈ ����
		return;
	}
	else if (value < ptr->data)
	{
		insert(value, ptr->left);
	}
	else
	{
		insert(value, ptr->right);
	}
}

// preorder �Լ����� Ȱ���ϴ� ���� �Լ�
template <typename T>
void BinarySearchTree<T>::preorder(TreeNode<T>* ptr) const
{
	if (!ptr)
	{
		return;
	}
	cout << ptr->data << endl;
	preorder(ptr->left);
	preorder(ptr->right);
}

// inorder �Լ����� Ȱ���ϴ� ���� �Լ�
template<class T>
void BinarySearchTree<T>::inorder(TreeNode<T>* ptr) const
{
	if (!ptr)
	{
		return;
	}
	inorder(ptr->left);
	cout << ptr->data << endl;
	inorder(ptr->right);
}

// postorder �Լ����� Ȱ���ϴ� ���� �Լ�
template<class T>
void BinarySearchTree<T>::postorder(TreeNode <T>* ptr) const
{
	if (!ptr)
	{
		return;
	}
	postorder(ptr->right);
	postorder(ptr->left);
	cout << ptr->data << endl;
}

// search �Լ����� Ȱ���ϴ� ���� �Լ�
template<typename T>
bool BinarySearchTree<T>::search(const T& value, TreeNode<T>* ptr) const
{
	if (!ptr)
	{
		return false;
	}
	else if (ptr->data == value)
	{
		return true;
	}
	else if (value < ptr->data)
	{
		return search(value, ptr->left);
	}
	else
	{
		return search(value, ptr->right);
	}
}

// makeNode �Լ����� Ȱ���ϴ� ���� �Լ�
template<typename T>
TreeNode<T>* BinarySearchTree<T>::makeNode(const T& value)
{
	TreeNode<T>* temp = new TreeNode<T>;
	temp->data = value;
	temp->left = 0;
	temp->right = 0;
	return temp;
}
#endif