#pragma once

#include <assert.h>
#include <string>		// C++ 문자열 클래스
using namespace std;	// 자료형 앞에 이름 붙이지 않기 위해

class CParent
{
protected:	// 자식 클래스에게 상속
	const string	m_firstName;	// 성은 바꿀 수 없어 상수 선언

private:	// 부모 클래스만 사용
	string			m_lastName;
	int				m_age;
	
public:
	static int		changeCount; // 정적 변수 선언

public:		// 모두 사용
	CParent();	// 생성자: 객체가 생성될때 자동 호출, 없을 경우 디폴트 생성자 자동 생성
	~CParent();	// 소멸자: 객체가 스코프를 벗어날때 자동 호출 (스택 구조), 없을 경우 디폴트 생성자 자동 생성

	// 접근자
	string			getFirstName();
	string			getLastName();
	int				getAge();

	// 설정자
	void			setLastName(string _LastName);
	void			setAge(int _age);
};

