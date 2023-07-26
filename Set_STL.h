#pragma once
/*************************************************************
* Student Ŭ������ �������̽� ����                          *
*************************************************************/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
	int identity;
	string name;
	double gpa;

public:
	Student(int identity, string name, double gpa);
	~Student();
	void print() const;
	bool friend operator<(const Student& left, const Student& right);
};
#endif