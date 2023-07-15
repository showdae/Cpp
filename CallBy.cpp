#include <iostream>

// Call By Value
void CallVal(int _a)
{
	_a = 100; // 스코프를 벗어나면 값이 제거됨
}

// Return By Value
int ReturnVal(int _a)
{
	_a = 200;

	return _a;
}

// Call By Ref
void CallRef(int& _a)
{
	_a = 300;
}

// Return By Ref
int& ReturnRef(int& _a)
{
	_a = 400;

	return _a;
}

// Call By Ptr
void CallPtr(int* _a)
{
	*_a = 500;
}

// Return By Ptr
// 포인터로 리턴은 파라메타만 가능 하다 (지역변수 불가!)
int* ReturnPtr(int* _a)
{
	*_a = 600;

	return _a;
}

// Call By Array
void CallPtrArr(int* pArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("요소: %d 값: %d\n", i, pArr[i]);
	}
}

int main()
{
	int a = 0;

	// Call By Value (복사 비용이 큼)
	CallVal(a);
	printf("%d\n",a);			// 0 (값 변경 안됨
	a = ReturnVal(a);
	printf("%d\n", a);			// 200

	// Call By Ref(파라메타 메모리 공유)
	CallRef(a);
	printf("%d\n", a);			// 300
	a = ReturnRef(a);
	printf("%d\n", a);			// 400

	// Call By Ptr(복사 비용 8Byte)
	CallPtr(&a);
	printf("%d\n", a);			// 500
	int* ptrA = ReturnPtr(&a);
	printf("%d\n", *ptrA);		// 600 (파라메타만 리턴 가능, 지역 변수 불가!)

	// Call By Array
	int arr[3] = { 0,10,20 };

	CallPtrArr(arr, 3); // 포인터 변수, 배열의 용적
	// 배열은 포인터와 배열 크기를 함께 가진 데이터라 리턴할 수 없다

	return 0;
}