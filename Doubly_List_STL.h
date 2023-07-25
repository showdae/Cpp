#pragma once
/*************************************************************
* BigInteger Ŭ������ �������̽�                            *
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
	// friend �Լ�: �ٸ� Ŭ������ �ܺ� �Լ����� private ��� ������ ������ �ʿ䰡 ������ ���	
	friend BigInteger operator+(BigInteger first, BigInteger second); // ������ �����ε�
};
#endif