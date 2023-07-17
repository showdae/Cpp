#include "Parent.h"

// :: 클래스 스코프 연산자 (범위 지정): 클래스에 접근
int CParent::changeCount = 0; // 정적 전역 변수 초기화

CParent::CParent()
	:m_firstName("park") // 초기화 리스트
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