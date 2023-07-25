#pragma once
/*************************************************************
* BigInteger 클래스의 인터페이스                            *
*************************************************************/
#include <list>

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;

class BigInteger
{
private:
	list<int> lst;

public:
	BigInteger();
	BigInteger(string str);
	~BigInteger();
	string toString();
	// friend 함수: 다른 클래스나 외부 함수에서 private 멤버 변수에 접근할 필요가 있을때 사용	
	friend BigInteger operator+(BigInteger first, BigInteger second); // 연산자 오버로딩
};
#endif