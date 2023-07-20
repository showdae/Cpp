#include <iostream>
//#include "Parent.h"	// ��� ���� Child.h�� ���� ��Ű���
#include "Child.h"
// App ������ �������Ҷ� ���ø� �Լ��� �Ű�����ȭ�� �̷���� ���¸� �̸� �����ؾ��� (���� ���� ����)
#include "Templ.cpp"	// ���ø� Ŭ���� ���� ����!
#include <iomanip>		// ���� �����ڸ� ����ϱ� ���� ��� ����

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
	// Parent
	parentInfo();
	parentChange("Name_Change", 55);

	// Child
	childInfo();
	childChange("Name_Change", 25);

	// class Template
	CTempl<int>		tem1(10);		// ��������� �ڷ����� ��� ȣ��
	CTempl<double>	tem2(10.0);
	CTempl<char>	tem3('A');
	CTempl<string>	tem4("AAA");

	// typedef: ��Ī�� ����
	typedef CTempl<int> iTempl;
	iTempl tem5(50);

	tem1.set(20);
	tem2.set(20.0);
	tem3.set('B');
	tem4.set("BBB");

	cout << "���ø� ����: "<< tem1.get() << endl;
	cout << "���ø� �Ǽ�: " << fixed << setprecision(1) << tem2.get() << endl;
	cout << "���ø� ����: " << tem3.get() << endl;
	cout << "���ø� ���ڿ�: " << tem4.get() << endl;
	 



	return 0;
}