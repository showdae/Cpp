#pragma once
#include "Parent.h"

class CChild : public CParent // �θ� Ŭ���� ��� ����
{
private:
	string		m_lastName;
	int			m_age;

public:
	static int	changeCount;

public:
	CChild();
	~CChild();

	// ������
	string		getLastName();
	int			getAge();

	// ������
	void		setLastName(string _LastName);
	void		setAge(int _age);
};

