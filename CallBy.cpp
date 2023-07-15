#include <iostream>

// Call By Value
void CallVal(int _a)
{
	_a = 100; // �������� ����� ���� ���ŵ�
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
// �����ͷ� ������ �Ķ��Ÿ�� ���� �ϴ� (�������� �Ұ�!)
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
		printf("���: %d ��: %d\n", i, pArr[i]);
	}
}

int main()
{
	int a = 0;

	// Call By Value (���� ����� ŭ)
	CallVal(a);
	printf("%d\n",a);			// 0 (�� ���� �ȵ�
	a = ReturnVal(a);
	printf("%d\n", a);			// 200

	// Call By Ref(�Ķ��Ÿ �޸� ����)
	CallRef(a);
	printf("%d\n", a);			// 300
	a = ReturnRef(a);
	printf("%d\n", a);			// 400

	// Call By Ptr(���� ��� 8Byte)
	CallPtr(&a);
	printf("%d\n", a);			// 500
	int* ptrA = ReturnPtr(&a);
	printf("%d\n", *ptrA);		// 600 (�Ķ��Ÿ�� ���� ����, ���� ���� �Ұ�!)

	// Call By Array
	int arr[3] = { 0,10,20 };

	CallPtrArr(arr, 3); // ������ ����, �迭�� ����
	// �迭�� �����Ϳ� �迭 ũ�⸦ �Բ� ���� �����Ͷ� ������ �� ����

	return 0;
}