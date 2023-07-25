/*************************************************************
* BigInterger 클래스의 구현                                 *
*************************************************************/
#include "Doubly_List_STL.h"

// 기본 생성자
BigInteger::BigInteger()
	:lst(list<int>())
{
}

// 매개변수가 있는 생성자
BigInteger::BigInteger(string str)
	: lst(list<int>()) // 리스트 초기화
{
	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - 48;	// 아스키코드 - 48 = 정수
		lst.push_back(num);		// 리스트 컨테이너 뒤에 삽입
	}
}

// 소멸자
BigInteger::~BigInteger()
{
}

// 리스트를 문자열로 변환하는 함수
string BigInteger::toString()
{
	string strg;
	list<int>::iterator iter;		// 기본 반복자
	iter = lst.begin();				// 컨테이너의 시작 요소를 가리킴
	while (iter != lst.end())
	{
		strg.append(1, *iter + 48); // 정수 + 48 = 아스키코드
		iter++;
	}
	return strg;
}

// operator+ friend 함수
BigInteger operator+(BigInteger first, BigInteger second)
{
	list<int>::reverse_iterator iter1;	// 역반복자
	list<int>::reverse_iterator iter2;
	BigInteger result;
	int num1, num2, sum;
	int carry = 0;						// 결과값의 앞에 자리수를 추가해야 하는 경우
	iter1 = first.lst.rbegin();			// 컨테이너의 마지막 요소를 가리킴
	iter2 = second.lst.rbegin();

	// begin:	첫번째 요소를 가리키는 반복자 리턴
	// end:		마지막 요소 뒤에 가상 요소를 가리키는 반복자 리턴 (쓰레기값)
	// rbegin:	마지막 요소를 가리키는 반복자 리턴
	// rend:	첫번째 요소 앞에 가상 요소를 가리키는 반복자 리턴 (쓰레기값)

	// rbegin()	!=	rend(): true
	// rend()	!=	rend(): false
	while ((iter1 != first.lst.rend()) && (iter2 != second.lst.rend()))
	{
		num1 = *iter1;
		num2 = *iter2;
		sum = (num1 + num2 + carry) % 10;	// 나머지
		carry = (num1 + num2 + carry) / 10;	// 몫
		result.lst.push_front(sum);			// 앞에 삽입
		iter1++; // ++ 왼쪽 이동
		iter2++;
	}

	// first가 같지 않으면
	while ((iter1 != first.lst.rend()))
	{
		num1 = *iter1;
		sum = (num1 + carry) % 10;
		carry = (num1 + carry) / 10;
		result.lst.push_front(sum);
		iter1++;
	}

	// second가 같지 않으면
	while ((iter2 != second.lst.rend()))
	{
		num2 = *iter2;
		sum = (num2 + carry) % 10;
		carry = (num2 + carry) / 10;
		result.lst.push_front(sum);
		iter2++;
	}

	// 반복 종료후 결과값의 앞에 자리수를 추가해야 하는 경우
	if (carry == 1)
	{
		result.lst.push_front(carry);
	}

	return result;
}