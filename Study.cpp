/*
버퍼란: 
C++에서 "버퍼"란 데이터를 임시로 저장하는 메모리 공간을 가리키는 용어
매번 데이터 하나를 처리하기보다는 버퍼를 이용하여 여러 개의 데이터를 한 번에 처리하는 것이 효율적
버퍼는 보통 배열(스택)이나 동적 할당된 메모리(힙)를 사용하여 구현
*/

// 스마트 포인터?
// ifndef, define, endif 전처리기?
// 인라인 함수?

// 추가해야 할것 (챕터 7)
// 매개변수 생성자
// 복사 생성자

#include <iostream>
#include <sstream>		// 문자열 스트림
#include <bitset>		// 정수를 이진수로 출력 (비트 연산자)

using namespace std;

void callbackFunction(int value);					// 콜백 함수
void performAction(int data, void(*callback)(int));	// 콜백 함수를 인자로 받는 함수

// 비트 연산자와 enum 조합
enum File
{	// 1,2,4,8,16,32 ... 으로 할당해야 함
	Read = 1,      // 1 (2^0): 00000001
	Write = 2,     // 2 (2^1): 00000010
	Execute = 4    // 4 (2^2): 00000100
};

// enum
enum Game
{	// 값이 순차적으로 증가
	rock,			// 0
	paper,			// 1
	scissors,		// 2
	enumSize		// 4
};

int main()
{
	/////////////////////////////////////////////////
	// enum
	/////////////////////////////////////////////////
	/*
	데이터 형식 중 하나로, enum은 정수 상수들의 집합을 정의, 각 상수에는 고유한 이름이 부여
	기본적으로 enum에서 정의된 상수들은 0부터 시작하여 순차적으로 증가하는 값을 할당
	하지만 사용자가 직접 값을 할당하여 변경할 수도 있음
	*/
	for (int show = rock; show < enumSize; show++) // int 자료형으로 시작
	{
		switch (static_cast<Game>(show)) // enum 자료형으로 형변환
		{
			case 0:
				cout << "rock" << endl;
				break;
			case 1:
				cout << "paper" << endl;
				break;
			case 2:
				cout << "scissors" << endl;
				break;
			default: cout << "error" << endl;
				break;
		}
	}
	cout << endl;


	/////////////////////////////////////////////////
	// 비트 연산자와 enum 조합
	/////////////////////////////////////////////////
	int user = Read | Write; // 비트합 

	if (user & Read) // 비트곱
	{ cout << "읽기 권한" << endl; }

	if (user & Write)
	{ cout << "쓰기 권한" << endl; }

	if (user & Execute)
	{ cout << "실행 권한" << endl; }

	else
	{ cout << "실행 권한 없음" << endl << endl; }


	/////////////////////////////////////////////////
	// 비트 연산자
	/////////////////////////////////////////////////
	/*
	비트 연산자는 데이터의 비트 수준에서 연산을 수행하는 연산자들을 의미
	이러한 비트 연산자는 정수형 변수들에 사용되며, 변수 내의 개별 비트들을 조작하고 결합
	비트 연산자를 사용하여 비트 필드를 구현하여 메모리를 절약하고 효율적으로 데이터를 저장
	*/
	cout << "비트값 확인" << endl;
	int abit = 15; // 00001111
	int bbit = 10; // 00001010
	cout << "abit:    " << abit << "      " << bitset<8>(abit) << endl;
	cout << "bbit:    " << bbit << "      " << bitset<8>(bbit) << endl << endl;

	// 비트 연산자의 종류
	cout << "& (AND, 비트곱): 두 개의 비트가 모두 1인 경우에만 결과 비트가 1이 됩니다" << endl;
	int aAnd = 15;
	int bAnd = 10;
	int rAnd = aAnd & bAnd;
	cout << "rAnd:    " << rAnd << "      " << bitset<8>(rAnd) << endl << endl;

	cout << "| (OR, 비트합): 두 개의 비트 중 하나라도 1이면 결과 비트가 1이 됩니다" << endl;
	int aOr = 15;
	int bOr = 10;
	int rOr = aOr | bOr;
	cout << "rOr:     " << rOr << "      " << bitset<8>(rOr) << endl << endl;

	cout << "^ (XOR, 배타적 논리합): 두 개의 비트가 서로 다른 경우에만 결과 비트가 1이 됩니다" << endl;
	int aXor = 15;
	int bXor = 10;
	int rXor = aXor ^ bXor;
	cout << "rXor:    " << rXor << "       " << bitset<8>(rXor) << endl << endl;

	// ~ (NOT, 부정): 마스킹 이미지 반전할때 사용
	cout << "~ (NOT, 부정): 단항 연산자로, 비트를 반전시킵니다. 0은 1로, 1은 0으로 바꿉니다" << endl;
	int aNot = 15;
	int rNot = ~aNot;
	cout << "rNot:   " << rNot << "      " << bitset<8>(rNot) << endl << endl;

	cout << "<< (LeftShift): 피연산자의 비트를 왼쪽으로 지정된 수만큼 이동시킵니다.이동한 빈공간은 0으로 채워집니다" << endl;
	int aLshift = 15;
	int rLshift = aLshift << 2;
	cout << "rLshift: " << rLshift << "      " << bitset<8>(rLshift) << endl << endl;

	cout << ">> (RightShift): 피연산자의 비트를 오른쪽으로 지정된 수만큼 이동시킵니다.이동한 빈공간은 부호 비트 또는 0으로 채워집니다" << endl;
	int aRshift = 15;
	int rRshift = aRshift >> 2;
	cout << "rRshift: " << rRshift << "       " << bitset<8>(rRshift) << endl << endl;


	/////////////////////////////////////////////////
	// 콜백 함수
	/////////////////////////////////////////////////
	/*
	함수 포인터가 가리키는 함수가 콜백 함수
	콜백 함수는 이벤트 처리, 비동기 프로그래밍, GUI 프로그래밍 등 다양한 상황에서 유용하게 활용
	메모리 누수나 다른 문제를 발생시킬 수 있는 점을 주의
	C++ 표준에서는 더 유연한 콜백 방식을 지원하는 람다 함수 또는 std::function을 사용하여 콜백을 구현하는 것을 권장
	*/
	int data = 10;
	// 콜백 함수를 인자(함수 포인터)로 전달
	performAction(data, callbackFunction);


	/////////////////////////////////////////////////
	// 문자열 파싱
	/////////////////////////////////////////////////
	string str1("123 1.23 asd");
	stringstream ss2(str1);
	int itest;
	double dtest;
	string stest;
	ss2 >> itest >> dtest >> stest; // 파싱
	cout << itest << endl;
	cout << dtest << endl;
	cout << stest << endl;

	return 0;
}


void callbackFunction(int value)
{
	cout << "Callback function called with value: " << value << endl;
}


void performAction(int data, void(*callback)(int))
{
	// 콜백 함수는 특정 이벤트나 조건이 발생했을때 호출
	callback(data);
}