// git test1

#include <iostream>

using namespace std;

// 값으로 전달/리턴 (복사 비용이 큼)
 int sum_val(int va, int vb)
{
	int vv = va + vb;

	printf("%d\n", vv);

	return vv;
}


// 참조로 전달/리턴 (파라메타 메모리 공유)
 int& sum_ref(int& ra, int& rb)
 {
	 int rv = ra + rb;

	 printf("%d\n", rv);

	 return rv;
 }


 // 포인터로 전달 (복사 비용이 큼, 지역변수 포인터로 리턴 못함)
 void sum_ptr(int* pa, int* pb)
 {
	 int pv = *pa + *pb;

	 printf("%d\n", pv);
 }


 int testStatic; // 전역 변수는 0으로 초기화
 void static_test()
 {
	 // 정적 변수: 한번만 초기화하며, 스코프를 벗어나도 제거되지 않음 (코드 영역에 존재 하는듯)
	 static int count = 0;
	 int testStack; // 지역 변수는 쓰레기 값으로 초기화
	 count++;
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
	///////// chapter8: 포인터 /////////




	return 0;

	/*
	///////// chapter8: 배열 /////////
	// 배열의 이름은 첫 요소에 대한 포인터
	// 컴파일러는 배열의 연속적인 메모리 위치를 할당 (제로 인덱스)
	// 배열이 전역에 선언할 경우 디폴트값: 0
	// 배열이 지역에 선언할 경우 디폴트값: 쓰레기값
	
	// 1차원 배열
	// int arr1[3] = { 0 };		// 0 초기화
	int arr1[3] = { 0,1,2 };	// 명시적 초기화
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
	///////// chapter6: 함수 인자 전달 /////////
	int a = 10;
	int b = 20;

	// int v = sum_val(a,b);	// 값으로 전달
	// int v = sum_ref(a, b);	// 참조로 전달
	// sum_ptr(&a, &b);			// 포인터로 전달


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