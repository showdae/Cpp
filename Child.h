#pragma once
#include "Parent.h"

class CChild : public CParent // 부모 클래스 상속 받음
{
private:
	string		m_lastName;
	int			m_age;

public:
	static int	changeCount;

public:
	CChild();
	~CChild();

	// 접근자
	string		getLastName();
	int			getAge();

	// 설정자
	void		setLastName(string _LastName);
	void		setAge(int _age);
};

