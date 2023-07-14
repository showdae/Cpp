#include <iostream>
//#include "Parent.h"
#include "Child.h"

void parentInfo()
{
	CParent parent;
	cout << "***Parent info***" << endl;
	cout << "성: " << parent.getFirstName() << endl;
	cout << "이름: " << parent.getLastName() << endl;
	cout << "나이: " << parent.getAge() << endl << endl;
}

void parentChange(string _last, int _age)
{
	if (_last.size() == 0) { assert(0); } // 프로그램 중단

	CParent parent;

	CParent::changeCount++; // 정적 변수 카운트 증가

	parent.setLastName(_last);
	parent.setAge(_age);

	cout << "***Parent Name Change***" << endl;
	cout << "성: " << parent.getFirstName() << endl;
	cout << "이름: " << parent.getLastName() << endl;
	cout << "나이: " << parent.getAge() << endl;
	cout << "이름 변경 횟수: " << CParent::changeCount << endl << endl;
}

void childInfo()
{
	CChild	child;
	cout << "***Child info***" << endl;
	cout << "성: " << child.getFirstName() << endl;
	cout << "이름: " << child.getLastName() << endl;
	cout << "나이: " << child.getAge() << endl << endl;
}

void childChange(string _last, int _age)
{
	if (_last.size() == 0) { assert(0); } // 프로그램 중단

	CChild child;

	CChild::changeCount++; // 정적 변수 카운트 증가

	child.setLastName(_last);
	child.setAge(_age);

	cout << "***Child Name Change***" << endl;
	cout << "성: " << child.getFirstName() << endl;
	cout << "이름: " << child.getLastName() << endl;
	cout << "나이: " << child.getAge() << endl;
	cout << "이름 변경 횟수: " << CChild::changeCount << endl << endl;
}

int main()
{
	parentInfo();
	parentChange("Name_Change", 58);

	childInfo();
	childChange("Name_Change", 35);


	// 추가해야 할것 (챕터 7)
	// 매개변수 생성자
	// 복사 생성자
	// 인라인 함수

	return 0;
}