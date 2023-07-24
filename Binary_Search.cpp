// 4) 이진 탐색 알고리즘 (재귀)
// 이진 탐색:	정렬된 배열 내부에 어떤 값의 위치를 찿음
//				(정렬된 배열을 탐색하는 것은 정렬되지 않은 배열을 탐색하는 것보다 훨씬 빠르고 쉽다)
// 탐색 방법:
// 배열의 가운데 요소의 값을 확인하면서 시작 (아래의 3가지 상황 발생)
// 1. 가운데 있는 요소의 값이 탐색하려는 값과 같다면, 탐색을 중단
// 2. 가운데 요소값 보다 크다면, 오른쪽 절반으로 다시 탐색
// 3. 가운데 요소값 보다 작다면, 왼쪽 절반으로 다시 탐색

/*************************************************************
* 재귀적 바이너리 탐색으로 배열에서 특정 값을 찾는 프로그램
*************************************************************/
#include <iostream>
using namespace std;

// binarySearch 함수 선언(비재귀 함수 + 재귀 함수)
int binarySearch(const int arr[], int size, int value);
int binarySearch(const int arr[], int low, int high, int value);

int main()
{
	// 탐색 대상 배열 선언
	const int SIZE = 10;
	int array[SIZE] = { 10, 14, 19, 22, 27, 30, 33, 46, 63, 94 };

	// 찾을 값 입력 받기
	int value;
	cout << "찾을 값을 입력해주세요: ";
	cin >> value;
	// 비재귀 함수 binarySearch 호출
	int index = binarySearch(array, SIZE, value);
	if (index == -1)
	{
		cout << "배열에서 값을 찾을 수 없습니다.";
	}
	else
	{
		cout << "해당 값을 찾았습니다: " << index << endl;
	}
	return 0;
}

// 비재귀 binarySearch 함수 정의
int binarySearch(const int arr[], int size, int value) // 오버로딩
{
	int low = 0;
	int high = size - 1;
	return binarySearch(arr, low, high, value);
}

// 재귀 binarySearch 함수 정의
int binarySearch(const int arr[], int low, int high, int value) // 오버로딩
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}
	else if (value == arr[mid]) // 가운데 값 비교
	{
		return mid;
	}
	else if (value < arr[mid])
	{
		return binarySearch(arr, low, mid - 1, value); // 재귀
	}
	else
	{
		return binarySearch(arr, mid + 1, high, value); // 재귀
	}
}