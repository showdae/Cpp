// 3) ������ �˰��� (���)
// ������: �迭�� ����� ���� ������������ ���� (��κ��� ���� �˰����� ��Ƽ�� �˰����̶�� ��Ͱ� �ƴ� �˰��� Ȱ��)
// ��Ƽ�� �˰���: �迭�� ��Ҹ� �ǹ��ϴ� "�ǹ�"�� �������� �ǹ����� ���� ��Ҹ� ������, ū ��Ҹ� �ڷ� �̵�

/**************************************************************
* ��Ƽ�� �˰����� ��������� ȣ���ؼ�
* �迭�� �����ϴ� ����Ʈ �˰���
**************************************************************/
#include <iostream>
using namespace std;

// �Լ� ����
void swap(int& x, int& y);
void print(int array[], int size);
int partition(int arr[], int beg, int end);
void quickSort(int arr[], int beg, int end);

int main()
{
	// ���ĵ��� ���� �迭 ����
	int array[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	// ���� �迭 ���
	cout << "���� �迭: " << endl;
	print(array, 10);
	// ����Ʈ�� �迭 ����
	quickSort(array, 0, 9);
	// ���ĵ� �迭 ���
	cout << "���ĵ� �迭: " << endl;
	print(array, 10);
	return 0;
}

// ���� �Լ�
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// �迭�� ����ϴ� �Լ�
void print(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "   ";
	}
	cout << endl;
}

// ��Ƽ�� �Լ�
int partition(int arr[], int beg, int end)
{
	int p = beg;    // �ǹ� �ʱ�ȭ
	int b = beg;    // begin �ʱ�ȭ
	int e = end;    // end �ʱ�ȭ

	while (b < e)
	{
		// end�� �������� �̵�
		while (arr[e] > arr[p]) // �� ��
		{
			e--;
		}
		swap(arr[e], arr[p]);	// ���尡 ���� ���¿��� swap
		p = e;
		// begin�� ���������� �̵�
		while (arr[b] <  arr[p]) // �� ��
		{
			b++;
		}
		swap(arr[b], arr[p]);
		p = b;
	}
	return p;
}

// ����Ʈ �Լ�
void quickSort(int arr[], int beg, int end)
{
	if (beg >= end || beg < 0)
	{
		return;
	}
	int pivot = partition(arr, beg, end); // ����
	quickSort(arr, beg, pivot - 1); // ���
	quickSort(arr, pivot + 1, end); // ���
}