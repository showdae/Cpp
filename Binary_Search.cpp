// 4) ���� Ž�� �˰��� (���)
// ���� Ž��:	���ĵ� �迭 ���ο� � ���� ��ġ�� �O��
//				(���ĵ� �迭�� Ž���ϴ� ���� ���ĵ��� ���� �迭�� Ž���ϴ� �ͺ��� �ξ� ������ ����)
// Ž�� ���:
// �迭�� ��� ����� ���� Ȯ���ϸ鼭 ���� (�Ʒ��� 3���� ��Ȳ �߻�)
// 1. ��� �ִ� ����� ���� Ž���Ϸ��� ���� ���ٸ�, Ž���� �ߴ�
// 2. ��� ��Ұ� ���� ũ�ٸ�, ������ �������� �ٽ� Ž��
// 3. ��� ��Ұ� ���� �۴ٸ�, ���� �������� �ٽ� Ž��

/*************************************************************
* ����� ���̳ʸ� Ž������ �迭���� Ư�� ���� ã�� ���α׷�
*************************************************************/
#include <iostream>
using namespace std;

// binarySearch �Լ� ����(����� �Լ� + ��� �Լ�)
int binarySearch(const int arr[], int size, int value);
int binarySearch(const int arr[], int low, int high, int value);

int main()
{
	// Ž�� ��� �迭 ����
	const int SIZE = 10;
	int array[SIZE] = { 10, 14, 19, 22, 27, 30, 33, 46, 63, 94 };

	// ã�� �� �Է� �ޱ�
	int value;
	cout << "ã�� ���� �Է����ּ���: ";
	cin >> value;
	// ����� �Լ� binarySearch ȣ��
	int index = binarySearch(array, SIZE, value);
	if (index == -1)
	{
		cout << "�迭���� ���� ã�� �� �����ϴ�.";
	}
	else
	{
		cout << "�ش� ���� ã�ҽ��ϴ�: " << index << endl;
	}
	return 0;
}

// ����� binarySearch �Լ� ����
int binarySearch(const int arr[], int size, int value) // �����ε�
{
	int low = 0;
	int high = size - 1;
	return binarySearch(arr, low, high, value);
}

// ��� binarySearch �Լ� ����
int binarySearch(const int arr[], int low, int high, int value) // �����ε�
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}
	else if (value == arr[mid]) // ��� �� ��
	{
		return mid;
	}
	else if (value < arr[mid])
	{
		return binarySearch(arr, low, mid - 1, value); // ���
	}
	else
	{
		return binarySearch(arr, mid + 1, high, value); // ���
	}
}