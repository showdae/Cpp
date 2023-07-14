#pragma once

#include <assert.h>
#include <string>		// C++ ���ڿ� Ŭ����
using namespace std;	// �ڷ��� �տ� �̸� ������ �ʱ� ����

class CParent
{
protected:	// �ڽ� Ŭ�������� ���
	const string	m_firstName;	// ���� �ٲ� �� ���� ��� ����

private:	// �θ� Ŭ������ ���
	string			m_lastName;
	int				m_age;
	
public:
	static int		changeCount; // ���� ���� ����

public:		// ��� ���
	CParent();	// ������: ��ü�� �����ɶ� �ڵ� ȣ��, ���� ��� ����Ʈ ������ �ڵ� ����
	~CParent();	// �Ҹ���: ��ü�� �������� ����� �ڵ� ȣ�� (���� ����), ���� ��� ����Ʈ ������ �ڵ� ����

	// ������
	string			getFirstName();
	string			getLastName();
	int				getAge();

	// ������
	void			setLastName(string _LastName);
	void			setAge(int _age);
};

