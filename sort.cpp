// 3) 퀵정렬 알고리즘 (재귀)
// 퀵정렬: 배열의 요소의 값을 오름차순으로 정렬 (대부분의 정렬 알고리즘은 파티션 알고리즘이라는 재귀가 아닌 알고리즘 활용)
// 파티션 알고리즘: 배열의 요소를 의미하는 "피벗"을 기준으로 피벗보다 작은 요소를 앞으로, 큰 요소를 뒤로 이동

/**************************************************************
* 파티션 알고리즘을 재귀적으로 호출해서
* 배열을 정렬하는 퀵소트 알고리즘
**************************************************************/
#include <iostream>
using namespace std;

// 함수 선언
void swap(int& x, int& y);
void print(int array[], int size);
int partition(int arr[], int beg, int end);
void quickSort(int arr[], int beg, int end);

int main()
{
	// 정렬되지 않은 배열 선언
	int array[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	// 원본 배열 출력
	cout << "원본 배열: " << endl;
	print(array, 10);
	// 퀵소트로 배열 정렬
	quickSort(array, 0, 9);
	// 정렬된 배열 출력
	cout << "정렬된 배열: " << endl;
	print(array, 10);
	return 0;
}

// 스왑 함수
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// 배열을 출력하는 함수
void print(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "   ";
	}
	cout << endl;
}

// 파티션 함수
int partition(int arr[], int beg, int end)
{
	int p = beg;    // 피벗 초기화
	int b = beg;    // begin 초기화
	int e = end;    // end 초기화

	while (b < e)
	{
		// end를 왼쪽으로 이동
		while (arr[e] > arr[p]) // 값 비교
		{
			e--;
		}
		swap(arr[e], arr[p]);	// 엔드가 작은 상태에서 swap
		p = e;
		// begin를 오른쪽으로 이동
		while (arr[b] <  arr[p]) // 값 비교
		{
			b++;
		}
		swap(arr[b], arr[p]);
		p = b;
	}
	return p;
}

// 퀵소트 함수
void quickSort(int arr[], int beg, int end)
{
	if (beg >= end || beg < 0)
	{
		return;
	}
	int pivot = partition(arr, beg, end); // 분할
	quickSort(arr, beg, pivot - 1); // 재귀
	quickSort(arr, pivot + 1, end); // 재귀
}