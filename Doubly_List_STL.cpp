/*************************************************************
* BigInterger Ŭ������ ����                                 *
*************************************************************/
#include "Doubly_List_STL.h"

// �⺻ ������
BigInteger::BigInteger()
	:lst(list<int>())
{
}

// �Ű������� �ִ� ������
BigInteger::BigInteger(string str)
	: lst(list<int>()) // ����Ʈ �ʱ�ȭ
{
	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - 48;	// �ƽ�Ű�ڵ� - 48 = ����
		lst.push_back(num);		// ����Ʈ �����̳� �ڿ� ����
	}
}

// �Ҹ���
BigInteger::~BigInteger()
{
}

// ����Ʈ�� ���ڿ��� ��ȯ�ϴ� �Լ�
string BigInteger::toString()
{
	string strg;
	list<int>::iterator iter;		// �⺻ �ݺ���
	iter = lst.begin();				// �����̳��� ���� ��Ҹ� ����Ŵ
	while (iter != lst.end())
	{
		strg.append(1, *iter + 48); // ���� + 48 = �ƽ�Ű�ڵ�
		iter++;
	}
	return strg;
}

// operator+ friend �Լ�
BigInteger operator+(BigInteger first, BigInteger second)
{
	list<int>::reverse_iterator iter1;	// ���ݺ���
	list<int>::reverse_iterator iter2;
	BigInteger result;
	int num1, num2, sum;
	int carry = 0;						// ������� �տ� �ڸ����� �߰��ؾ� �ϴ� ���
	iter1 = first.lst.rbegin();			// �����̳��� ������ ��Ҹ� ����Ŵ
	iter2 = second.lst.rbegin();

	// begin:	ù��° ��Ҹ� ����Ű�� �ݺ��� ����
	// end:		������ ��� �ڿ� ���� ��Ҹ� ����Ű�� �ݺ��� ���� (�����Ⱚ)
	// rbegin:	������ ��Ҹ� ����Ű�� �ݺ��� ����
	// rend:	ù��° ��� �տ� ���� ��Ҹ� ����Ű�� �ݺ��� ���� (�����Ⱚ)

	// rbegin()	!=	rend(): true
	// rend()	!=	rend(): false
	while ((iter1 != first.lst.rend()) && (iter2 != second.lst.rend()))
	{
		num1 = *iter1;
		num2 = *iter2;
		sum = (num1 + num2 + carry) % 10;	// ������
		carry = (num1 + num2 + carry) / 10;	// ��
		result.lst.push_front(sum);			// �տ� ����
		iter1++; // ++ ���� �̵�
		iter2++;
	}

	// first�� ���� ������
	while ((iter1 != first.lst.rend()))
	{
		num1 = *iter1;
		sum = (num1 + carry) % 10;
		carry = (num1 + carry) / 10;
		result.lst.push_front(sum);
		iter1++;
	}

	// second�� ���� ������
	while ((iter2 != second.lst.rend()))
	{
		num2 = *iter2;
		sum = (num2 + carry) % 10;
		carry = (num2 + carry) / 10;
		result.lst.push_front(sum);
		iter2++;
	}

	// �ݺ� ������ ������� �տ� �ڸ����� �߰��ؾ� �ϴ� ���
	if (carry == 1)
	{
		result.lst.push_front(carry);
	}

	return result;
}