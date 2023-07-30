/*
���۶�: 
C++���� "����"�� �����͸� �ӽ÷� �����ϴ� �޸� ������ ����Ű�� ���
�Ź� ������ �ϳ��� ó���ϱ⺸�ٴ� ���۸� �̿��Ͽ� ���� ���� �����͸� �� ���� ó���ϴ� ���� ȿ����
���۴� ���� �迭(����)�̳� ���� �Ҵ�� �޸�(��)�� ����Ͽ� ����
*/

// ����Ʈ ������?
// ifndef, define, endif ��ó����?
// �ζ��� �Լ�?

// �߰��ؾ� �Ұ� (é�� 7)
// �Ű����� ������
// ���� ������

#include <iostream>
#include <sstream>		// ���ڿ� ��Ʈ��
#include <bitset>		// ������ �������� ��� (��Ʈ ������)

using namespace std;

void callbackFunction(int value);					// �ݹ� �Լ�
void performAction(int data, void(*callback)(int));	// �ݹ� �Լ��� ���ڷ� �޴� �Լ�

// ��Ʈ �����ڿ� enum ����
enum File
{	// 1,2,4,8,16,32 ... ���� �Ҵ��ؾ� ��
	Read = 1,      // 1 (2^0): 00000001
	Write = 2,     // 2 (2^1): 00000010
	Execute = 4    // 4 (2^2): 00000100
};

// enum
enum Game
{	// ���� ���������� ����
	rock,			// 0
	paper,			// 1
	scissors,		// 2
	enumSize		// 4
};

int main()
{
	/////////////////////////////////////////////////
	// enum
	/////////////////////////////////////////////////
	/*
	������ ���� �� �ϳ���, enum�� ���� ������� ������ ����, �� ������� ������ �̸��� �ο�
	�⺻������ enum���� ���ǵ� ������� 0���� �����Ͽ� ���������� �����ϴ� ���� �Ҵ�
	������ ����ڰ� ���� ���� �Ҵ��Ͽ� ������ ���� ����
	*/
	for (int show = rock; show < enumSize; show++) // int �ڷ������� ����
	{
		switch (static_cast<Game>(show)) // enum �ڷ������� ����ȯ
		{
			case 0:
				cout << "rock" << endl;
				break;
			case 1:
				cout << "paper" << endl;
				break;
			case 2:
				cout << "scissors" << endl;
				break;
			default: cout << "error" << endl;
				break;
		}
	}
	cout << endl;


	/////////////////////////////////////////////////
	// ��Ʈ �����ڿ� enum ����
	/////////////////////////////////////////////////
	int user = Read | Write; // ��Ʈ�� 

	if (user & Read) // ��Ʈ��
	{ cout << "�б� ����" << endl; }

	if (user & Write)
	{ cout << "���� ����" << endl; }

	if (user & Execute)
	{ cout << "���� ����" << endl; }

	else
	{ cout << "���� ���� ����" << endl << endl; }


	/////////////////////////////////////////////////
	// ��Ʈ ������
	/////////////////////////////////////////////////
	/*
	��Ʈ �����ڴ� �������� ��Ʈ ���ؿ��� ������ �����ϴ� �����ڵ��� �ǹ�
	�̷��� ��Ʈ �����ڴ� ������ �����鿡 ���Ǹ�, ���� ���� ���� ��Ʈ���� �����ϰ� ����
	��Ʈ �����ڸ� ����Ͽ� ��Ʈ �ʵ带 �����Ͽ� �޸𸮸� �����ϰ� ȿ�������� �����͸� ����
	*/
	cout << "��Ʈ�� Ȯ��" << endl;
	int abit = 15; // 00001111
	int bbit = 10; // 00001010
	cout << "abit:    " << abit << "      " << bitset<8>(abit) << endl;
	cout << "bbit:    " << bbit << "      " << bitset<8>(bbit) << endl << endl;

	// ��Ʈ �������� ����
	cout << "& (AND, ��Ʈ��): �� ���� ��Ʈ�� ��� 1�� ��쿡�� ��� ��Ʈ�� 1�� �˴ϴ�" << endl;
	int aAnd = 15;
	int bAnd = 10;
	int rAnd = aAnd & bAnd;
	cout << "rAnd:    " << rAnd << "      " << bitset<8>(rAnd) << endl << endl;

	cout << "| (OR, ��Ʈ��): �� ���� ��Ʈ �� �ϳ��� 1�̸� ��� ��Ʈ�� 1�� �˴ϴ�" << endl;
	int aOr = 15;
	int bOr = 10;
	int rOr = aOr | bOr;
	cout << "rOr:     " << rOr << "      " << bitset<8>(rOr) << endl << endl;

	cout << "^ (XOR, ��Ÿ�� ����): �� ���� ��Ʈ�� ���� �ٸ� ��쿡�� ��� ��Ʈ�� 1�� �˴ϴ�" << endl;
	int aXor = 15;
	int bXor = 10;
	int rXor = aXor ^ bXor;
	cout << "rXor:    " << rXor << "       " << bitset<8>(rXor) << endl << endl;

	// ~ (NOT, ����): ����ŷ �̹��� �����Ҷ� ���
	cout << "~ (NOT, ����): ���� �����ڷ�, ��Ʈ�� ������ŵ�ϴ�. 0�� 1��, 1�� 0���� �ٲߴϴ�" << endl;
	int aNot = 15;
	int rNot = ~aNot;
	cout << "rNot:   " << rNot << "      " << bitset<8>(rNot) << endl << endl;

	cout << "<< (LeftShift): �ǿ������� ��Ʈ�� �������� ������ ����ŭ �̵���ŵ�ϴ�.�̵��� ������� 0���� ä�����ϴ�" << endl;
	int aLshift = 15;
	int rLshift = aLshift << 2;
	cout << "rLshift: " << rLshift << "      " << bitset<8>(rLshift) << endl << endl;

	cout << ">> (RightShift): �ǿ������� ��Ʈ�� ���������� ������ ����ŭ �̵���ŵ�ϴ�.�̵��� ������� ��ȣ ��Ʈ �Ǵ� 0���� ä�����ϴ�" << endl;
	int aRshift = 15;
	int rRshift = aRshift >> 2;
	cout << "rRshift: " << rRshift << "       " << bitset<8>(rRshift) << endl << endl;


	/////////////////////////////////////////////////
	// �ݹ� �Լ�
	/////////////////////////////////////////////////
	/*
	�Լ� �����Ͱ� ����Ű�� �Լ��� �ݹ� �Լ�
	�ݹ� �Լ��� �̺�Ʈ ó��, �񵿱� ���α׷���, GUI ���α׷��� �� �پ��� ��Ȳ���� �����ϰ� Ȱ��
	�޸� ������ �ٸ� ������ �߻���ų �� �ִ� ���� ����
	C++ ǥ�ؿ����� �� ������ �ݹ� ����� �����ϴ� ���� �Լ� �Ǵ� std::function�� ����Ͽ� �ݹ��� �����ϴ� ���� ����
	*/
	int data = 10;
	// �ݹ� �Լ��� ����(�Լ� ������)�� ����
	performAction(data, callbackFunction);


	/////////////////////////////////////////////////
	// ���ڿ� �Ľ�
	/////////////////////////////////////////////////
	string str1("123 1.23 asd");
	stringstream ss2(str1);
	int itest;
	double dtest;
	string stest;
	ss2 >> itest >> dtest >> stest; // �Ľ�
	cout << itest << endl;
	cout << dtest << endl;
	cout << stest << endl;

	return 0;
}


void callbackFunction(int value)
{
	cout << "Callback function called with value: " << value << endl;
}


void performAction(int data, void(*callback)(int))
{
	// �ݹ� �Լ��� Ư�� �̺�Ʈ�� ������ �߻������� ȣ��
	callback(data);
}