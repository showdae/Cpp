#include <iostream>
//#include "Parent.h"
#include "Child.h"

void parentInfo()
{
	CParent parent;
	cout << "***Parent info***" << endl;
	cout << "��: " << parent.getFirstName() << endl;
	cout << "�̸�: " << parent.getLastName() << endl;
	cout << "����: " << parent.getAge() << endl << endl;
}

void parentChange(string _last, int _age)
{
	if (_last.size() == 0) { assert(0); } // ���α׷� �ߴ�

	CParent parent;

	CParent::changeCount++; // ���� ���� ī��Ʈ ����

	parent.setLastName(_last);
	parent.setAge(_age);

	cout << "***Parent Name Change***" << endl;
	cout << "��: " << parent.getFirstName() << endl;
	cout << "�̸�: " << parent.getLastName() << endl;
	cout << "����: " << parent.getAge() << endl;
	cout << "�̸� ���� Ƚ��: " << CParent::changeCount << endl << endl;
}

void childInfo()
{
	CChild	child;
	cout << "***Child info***" << endl;
	cout << "��: " << child.getFirstName() << endl;
	cout << "�̸�: " << child.getLastName() << endl;
	cout << "����: " << child.getAge() << endl << endl;
}

void childChange(string _last, int _age)
{
	if (_last.size() == 0) { assert(0); } // ���α׷� �ߴ�

	CChild child;

	CChild::changeCount++; // ���� ���� ī��Ʈ ����

	child.setLastName(_last);
	child.setAge(_age);

	cout << "***Child Name Change***" << endl;
	cout << "��: " << child.getFirstName() << endl;
	cout << "�̸�: " << child.getLastName() << endl;
	cout << "����: " << child.getAge() << endl;
	cout << "�̸� ���� Ƚ��: " << CChild::changeCount << endl << endl;
}

int main()
{
	parentInfo();
	parentChange("Name_Change", 58);

	childInfo();
	childChange("Name_Change", 35);


	// �߰��ؾ� �Ұ� (é�� 7)
	// �Ű����� ������
	// ���� ������
	// �ζ��� �Լ�

	return 0;
}