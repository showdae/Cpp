// git push - 230716

#include <iostream>
#include <cstring>	// C 문자열 스타일 (API)
#include <string>	// C++ 문자열 스타일 (클래스)

using namespace std;

 int testStatic; // 전역 변수는 0으로 초기화
 void static_test()
 {
	 // 정적 변수: 한번만 초기화하며, 스코프를 벗어나도 제거되지 않음 (코드 영역에 존재 하는듯)
	 static int count = 0;
	 count++;
	 int testStack; // 지역 변수는 쓰레기 값으로 초기화
	 testStack = 0;
	 testStack++;

	 printf("정적: %d\n", count);
	 printf("지역: %d\n\n", testStack);
 }


 ///////// 구조체 /////////
 struct MyType
 {
	 // 주로 여러 자료형을 묶어 맴버 변수로 사용
	 // 구조체: 디폴트 public (나머지 기능은 동일함)
	 // 클래스: 디폴트 private
	 char c = 'A';
	 short s = 0;
	 int i = 0;
	 long long ll = 0;
	 float f = 0.0f;
	 double d = 0.0;
 };


int main()
{
	///////// chapter11:  /////////



	/*
	///////// chapter10: 문자열 /////////
	// C 문자열 스타일 (API) : 헤더파일 <cstring>
	// C 문자열은 널문자로 끝나는 문자 배열이다 (배열의 이름은 첫 요소에 대한 포인터)
	// 널문자로 크기를 간접적으로 알 수 있어서 리턴할 수 있다
	char str1[10] = "AAA";			// 선언
	char str2[] = "BBB";
	str2[0] = 'A';					// 접근

	char* pStr = str1;				// 포인터

	// API 함수
	cout << "문자열 길이: " << strlen(str1) << endl;
	cout << "문자열 비교: " << strcmp(str1, str2) << endl;
	cout << "문자열 결합: " << strcat(str1, str2) << endl;
	cout << "문자열 복사: " << strcpy(str1, str2) << endl << endl;

	// C++ 문자열 스타일 (클래스): 헤더파일 <string>
	// C++ 문자열은 널문자로 끝나지 않음, 힙메모리에 할당

	string str3;			// 기본 생성자
	string str4("CCC");		// 매개변수 생성자
	string str5("DDD");

	// 소멸자: 클래스 내부적 자동으로 힙 메모리 Delete[] 하는듯

	str4.reserve(10); // 용적 예약
	cout << "문자열 길이: " << str4.size() << endl;
	cout << "문자열 용량: " << str4.capacity() << endl;
	cout << "문자열 비교: " << str4.compare(str5) << endl;
	cout << "문자열 결합: " << str4.append(str5) << endl;
	cout << "중간에 삽입: " << str4.insert(0,"A") << endl;
	str4.clear(); // 문자열 제거
	*/


	/*
	///////// chapter9: 포인터 /////////
	// 포인터: 복합 자료형, x86: 4byte x64: 8byte
	// * 간접 참조 연산자: 값 <- * <- 주소
	// & 주소 연산자: 주소 <- & <- 변수

	//////////////////////////////////////
	// 메모리 영역
	// 코드 메모리: 프로그램 코드 보유
	// 정적 메모리: 정적 변수, 전역 변수 보유
	// 스택 메모리: 지역 변수 , 함수 파라메타 보유
	// 힙 메로리:   런타임 시점에  객체를 저장 (동적 할당 후 해제 필요!)
	////////////////////////////////////// 

	// 1) 포인터 자료형: 주소를 받는다
	int a = 10;
	int* ptrA = &a; // a 주소를 받아 포인터 자료형에 대입한다
	int** ptrB = &ptrA; // 이중 포인터

	cout << "a 주소: "		<< &a << endl;				// a 주소	(000000D6A8AFF704)
	cout << "a 주소: "		<< ptrA << endl;			// a 주소	(000000D6A8AFF704)
	cout << "a 값: "			<< *ptrA << endl;			// a 값		(10)
	cout << "ptrA 주소: "	<< &ptrA << endl;			// ptrA 주소	(000000D6A8AFF728)
	cout << "ptrA 주소: "	<< ptrB << endl;			// ptrA 주소	(000000D6A8AFF728)
	cout << "a 주소: "		<< *ptrB << endl;			// a 주소	(000000D6A8AFF704)
	cout << "ptrB 주소: "	<< &ptrB << endl << endl;	// ptrB 주소	(000000D6A8AFF748)


	// 2) 참조 자료형: 메모리를 공유 한다
	int b = 20;
	int& refB = b;

	cout << &b << endl;				// b 주소 (0000000544DDF794)
	cout << refB << endl;			// b 값   (20)
	// cout << *refB << endl;		// error
	cout << &refB << endl << endl;	// b 주소 (0000000544DDF794)


	// 3) const 한정자
	int c = 30;
	const int d = 30;				// 직접 참조, 값 변경 불가
	const int* ptrE = &c;			// 간접 참조, 값 변경 불가
	int* const ptrF = &c;			// 간접 참조, 주소 변경 불가


	// 4) 동적 할당 연산자
	// C++: new / delete (C: malloc, free)
	int* pNew = new int[10];
	delete[] pNew;

	// 2차원 배열 동적 할당
	int** pNewArr = new int*[10]; // row
	for (int i = 0; i < 10; i++)
	{
		pNewArr[i] = new int[10]; // col
	}
	
	delete[] pNewArr;
	*/


	/*
	///////// chapter8: 배열 /////////
	// 배열의 이름은 첫 요소에 대한 포인터
	// 컴파일러는 배열의 연속적인 메모리 위치를 할당 (제로 인덱스)
	// 배열이 전역에 선언할 경우 디폴트값: 0
	// 배열이 지역에 선언할 경우 디폴트값: 쓰레기값
	
	// 1차원 배열
	// int arr1[3] = { 0 };		// 0 초기화
	int arr1[3] = { 0,1,2 };	// 명시적 초기화

	// arr1[2] 는 *(arr1 + 2) 와 같다
	// &arr1[2] 는 arr1 + 2 와 같다
	arr1[2] = 10;				// 요소에 접근

	// 2차원 배열
	//int arr2[3][3] = { 0 };	// 0 초기화
	int arr2[3][3] =	{		// 명시적 초기화 [행][열]
						{ 1, 2, 3 },
						{ 4, 5, 6 },
						{ 7, 8, 9 }
						};

	int(*ptr)[3] = arr2;		// 2차원 배열을 포인터로 받음

	// 2차원 배열을 이용해 별 정사각형 출력
	for (int i = 0; i < (*ptr)[2]; i++)		// 행(row)
	{
		for (int j = 0; j < (*ptr)[2]; j++)	// 열(col)
		{
			printf("* ", arr2[i][j]);
		}
		printf("\n");
	}
	*/


	/*
	///////// chapter7: 구조체 객체 사용 /////////
	MyType custom;
	custom.i = 4;	// 구조체 객체 . 맴버 선택 연산자 사용하여 접근

	MyType* ptr = &custom;
	ptr->s = 2;		// 포인터 변수 -> 맴버 선택 연산자 사용하여 접근
	
	printf("%d\n", ptr->i);
	printf("%d\n", ptr->s);
	*/


	/*
	///////// chapter6: 정적 변수 /////////
	// 함수 호출 방법: CallBy.cpp 파일 참조

	// 정적 변수
	for (int i = 0; i < 5; i++)
	{
		static_test();
	}
	*/


	/*
	///////// chapter5: while문 /////////
	int a = 0;
	int count = true;

	while (count)
	{
		printf("%d\n", a);
		a++;
		if (a == 10)
			// break; // 브레이크문 사용 가능
			count = false;
			continue;
	}
	*/


	/*
	///////// chapter5: do while문 /////////
	int num = 0;

	do
	{
		cout << "0~100" << endl;
		cin >> num;

	} while (num < 0 || num > 100); // 0보다 작거나 100보다 크다
	*/


	/*
	///////// chapter5: for문 /////////
	for (int i = 0; i < 5; i++) // 행
	{
		for (int j = 0; j <= 5; j++) // 열
		{
			printf("*");
		}
		printf("\n");
	}
	*/


	/*
	///////// chapter4: if문 /////////
	if (first == second)
	{
		count++;
	}
	else if (second == third)
	{
		count++;
	}
	else
	{
		count++;
	}
	*/

	
	/*
	///////// chapter4: switch문 /////////
	int day;
	cin >> day;

	switch (day)
	{
	case 1: cout << "월" << endl;
		break;
	case 2: cout << "화" << endl;
		break;
	case 3: cout << "수" << endl;
		break;
	case 4: cout << "목" << endl;
		break;
	case 5: cout << "금" << endl;
		break;
	case 6: cout << "토" << endl;
		break;
	case 7: cout << "일" << endl;
		break;

	default: cout << "잘못 입력" << endl;
	}
	*/


	/*
	///////// chapter2: 문자형 /////////
	char first = 'A';	// 아스키 코드 사용
	char second = 65;	// 숫자도 사용 가능함
	char third = 'B';
	int count = 0;

	printf("%c\n", first);
	printf("%c\n", second);
	*/
}