/***************************************************************
* 인터페이스 파일에서                                         *
* 선언한 멤버 함수를 정의하는 구현 파일                       *
***************************************************************/
#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
#include "Binary_Search_Tree.h"

// 생성자
template<class T>
BinarySearchTree<T>::BinarySearchTree()
	:root(0), count(0)	// 초기화 리스트
{
}

// 소멸자
template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroy(root);
}

// insert 멤버 함수
template <class T>
void BinarySearchTree<T>::insert(const T& value)
{
	insert(value, root); // 헬퍼 함수 호출
	count++;
}

// Search 멤버 함수
template<class T>
bool BinarySearchTree<T>::search(const T& value) const
{
	return search(value, root);
}

// pre-order 순회
template <class T>
void BinarySearchTree<T>::preorder() const
{
	// 모든 order는 루트 전달
	preorder(root); // 헬퍼 함수 호출
}

// in-order 순회
template<class T>
void BinarySearchTree<T>::inorder() const
{
	inorder(root);
}

// post-order 순회
template<class T>
void BinarySearchTree<T>::postorder() const
{
	postorder(root);
}

// size 멤버 함수
template<class T>
int BinarySearchTree<T>::size() const
{
	return count;
}

// empty 멤버 함수
template<class T>
bool BinarySearchTree<T>::empty() const
{
	return (count == 0);
}

// 소멸자에서 활용하는 헬퍼 함수
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

// insert 함수에서 활용하는 헬퍼 함수
template<class T>
void BinarySearchTree<T>::insert(const T& value, TreeNode <T>*& ptr)
{
	if (!ptr) // null이면
	{
		ptr = makeNode(value); // 루트 생성
		return;
	}
	else if (value < ptr->data)
	{
		insert(value, ptr->left); // 재귀
	}
	else
	{
		insert(value, ptr->right); // 재귀
	}
}

// preorder 함수에서 활용하는 헬퍼 함수
template <typename T>
void BinarySearchTree<T>::preorder(TreeNode<T>* ptr) const
{
	if (!ptr)
	{
		return;
	}
	// 실행 순서에 의해서 order가 결정 (pre, in, post)
	cout << ptr->data << endl;
	preorder(ptr->left);	// 재귀
	preorder(ptr->right);	// 재귀
}

// inorder 함수에서 활용하는 헬퍼 함수
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

// postorder 함수에서 활용하는 헬퍼 함수
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

// search 함수에서 활용하는 헬퍼 함수
template<typename T>
bool BinarySearchTree<T>::search(const T& value, TreeNode<T>* ptr) const
{
	if (!ptr) // null이면
	{ return false; }

	else if (value == ptr->data) // 인자와 같으면
	{ return true; }

	else if (value < ptr->data) // 인자가 작으면
	{ return search(value, ptr->left); } // 재귀 (왼쪽 주소로 호출)

	else
	{ return search(value, ptr->right); } // 재귀 (오른쪽 주소로 호출)
}

// makeNode 함수에서 활용하는 헬퍼 함수
template<typename T>
TreeNode<T>* BinarySearchTree<T>::makeNode(const T& value)
{
	TreeNode<T>* temp = new TreeNode<T>; // 동적 할당
	temp->data = value;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}
#endif