#include "Parent.h"

// :: Ŭ���� ������ ������ (���� ����): Ŭ������ ����
int CParent::changeCount = 0; // ���� ���� ���� �ʱ�ȭ

CParent::CParent()
	:m_firstName("park") // �ʱ�ȭ ����Ʈ
	,m_lastName("father")
	,m_age(50)
{
}

CParent::~CParent()
{
}

string CParent::getFirstName()
{
	return m_firstName;
}

string CParent::getLastName()
{
	return m_lastName;
}

int CParent::getAge()
{
	return m_age;
}

void CParent::setLastName(string _LastName)
{
	m_lastName = _LastName;
}

void CParent::setAge(int _age)
{
	m_age = _age;
}