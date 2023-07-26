/*************************************************************
* Student Ŭ������ ���� ����                                *
*************************************************************/
#include "Set_STL.h"

// ������
Student::Student(int id, string nm, double gp)
	: identity(id), name(nm), gpa(gp)
{
}

// �Ҹ���
Student::~Student()
{
}

// print ��� �Լ�
void Student::print() const
{
	cout << setw(3) << right << identity << "  ";
	cout << setw(3) << left << name << "  ";
	cout << setw(3) << right << showpoint << setprecision(3);
	cout << gpa << "  " << endl;
}

// < friend ������ �����ε�
bool operator<(const Student& left, const Student& right)
{
	return (left.identity < right.identity);
}