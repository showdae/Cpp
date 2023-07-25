#include <iostream>
//#include "Parent.h"	// 상속 받은 Child.h만 포함 시키면됨
#include "Child.h"
// App 파일을 컴파일할때 템플릿 함수의 매개변수화가 이루어진 형태를 미리 인지해야함 (구현 파일 포함)
#include "Templ.cpp"	// 템플릿 클래스 구현 파일!
#include <iomanip>		// 포맷 조작자를 사용하기 위한 헤더 파일

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
	// Parent
	parentInfo();
	parentChange("Name_Change", 55);

	// Child
	childInfo();
	childChange("Name_Change", 25);

	// class Template
	CTempl<int>		tem1(10);		// 명시적으로 자료형을 적어서 호출
	CTempl<double>	tem2(10.0);
	CTempl<char>	tem3('A');
	CTempl<string>	tem4("AAA");

	// typedef: 별칭을 정의
	typedef CTempl<int> iTempl;
	iTempl tem5(50);

	tem1.set(20);
	tem2.set(20.0);
	tem3.set('B');
	tem4.set("BBB");

	cout << "템플릿 정수: "<< tem1.get() << endl;
	cout << "템플릿 실수: " << fixed << setprecision(1) << tem2.get() << endl;
	cout << "템플릿 문자: " << tem3.get() << endl;
	cout << "템플릿 문자열: " << tem4.get() << endl;
	 



	return 0;
}