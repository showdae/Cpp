#include "Child.h"

int CChild::changeCount = 0; // 정적 변수 초기화

CChild::CChild()
	: m_lastName("daesung")
	, m_age(35)
{
}

CChild::~CChild()
{
}

string CChild::getLastName()
{
	return m_lastName;
}

int CChild::getAge()
{
	return m_age;
}

void CChild::setLastName(string _LastName)
{
	m_lastName = _LastName;
}

void CChild::setAge(int _age)
{
	m_age = _age;
}