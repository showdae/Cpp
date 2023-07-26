/*************************************************************
* Student 클래스의 구현 파일                                *
*************************************************************/
#include "Set_STL.h"

// 생성자
Student::Student(int id, string nm, double gp)
	: identity(id), name(nm), gpa(gp)
{
}

// 소멸자
Student::~Student()
{
}

// print 멤버 함수
void Student::print() const
{
	cout << setw(3) << right << identity << "  ";
	cout << setw(3) << left << name << "  ";
	cout << setw(3) << right << showpoint << setprecision(3);
	cout << gpa << "  " << endl;
}

// < friend 연산자 오버로드
bool operator<(const Student& left, const Student& right)
{
	return (left.identity < right.identity);
}