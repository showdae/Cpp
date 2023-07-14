// git test1

#include <iostream>

using namespace std;

// ������ ����/���� (���� ����� ŭ)
 int sum_val(int va, int vb)
{
	int vv = va + vb;

	printf("%d\n", vv);

	return vv;
}


// ������ ����/���� (�Ķ��Ÿ �޸� ����)
 int& sum_ref(int& ra, int& rb)
 {
	 int rv = ra + rb;

	 printf("%d\n", rv);

	 return rv;
 }


 // �����ͷ� ���� (���� ����� ŭ, �������� �����ͷ� ���� ����)
 void sum_ptr(int* pa, int* pb)
 {
	 int pv = *pa + *pb;

	 printf("%d\n", pv);
 }


 int testStatic; // ���� ������ 0���� �ʱ�ȭ
 void static_test()
 {
	 // ���� ����: �ѹ��� �ʱ�ȭ�ϸ�, �������� ����� ���ŵ��� ���� (�ڵ� ������ ���� �ϴµ�)
	 static int count = 0;
	 int testStack; // ���� ������ ������ ������ �ʱ�ȭ
	 count++;
 }


 ///////// ����ü /////////
 struct MyType
 {
	 // �ַ� ���� �ڷ����� ���� �ɹ� ������ ���
	 // ����ü: ����Ʈ public (������ ����� ������)
	 // Ŭ����: ����Ʈ private
	 char c = 'A';
	 short s = 0;
	 int i = 0;
	 long long ll = 0;
	 float f = 0.0f;
	 double d = 0.0;
 };


int main()
{
	///////// chapter8: ������ /////////




	return 0;

	/*
	///////// chapter8: �迭 /////////
	// �迭�� �̸��� ù ��ҿ� ���� ������
	// �����Ϸ��� �迭�� �������� �޸� ��ġ�� �Ҵ� (���� �ε���)
	// �迭�� ������ ������ ��� ����Ʈ��: 0
	// �迭�� ������ ������ ��� ����Ʈ��: �����Ⱚ
	
	// 1���� �迭
	// int arr1[3] = { 0 };		// 0 �ʱ�ȭ
	int arr1[3] = { 0,1,2 };	// ����� �ʱ�ȭ
	arr1[2] = 10;				// ��ҿ� ����

	// 2���� �迭
	//int arr2[3][3] = { 0 };	// 0 �ʱ�ȭ
	int arr2[3][3] =	{		// ����� �ʱ�ȭ [��][��]
						{ 1, 2, 3 },
						{ 4, 5, 6 },
						{ 7, 8, 9 }
						};

	int(*ptr)[3] = arr2;		// 2���� �迭�� �����ͷ� ����

	// 2���� �迭�� �̿��� �� ���簢�� ���
	for (int i = 0; i < (*ptr)[2]; i++)		// ��(row)
	{
		for (int j = 0; j < (*ptr)[2]; j++)	// ��(col)
		{
			printf("* ", arr2[i][j]);
		}
		printf("\n");
	}
	*/


	/*
	///////// chapter7: ����ü ��ü ��� /////////
	MyType custom;
	custom.i = 4;	// ����ü ��ü . �ɹ� ���� ������ ����Ͽ� ����

	MyType* ptr = &custom;
	ptr->s = 2;		// ������ ���� -> �ɹ� ���� ������ ����Ͽ� ����
	
	printf("%d\n", ptr->i);
	printf("%d\n", ptr->s);
	*/


	/*
	///////// chapter6: �Լ� ���� ���� /////////
	int a = 10;
	int b = 20;

	// int v = sum_val(a,b);	// ������ ����
	// int v = sum_ref(a, b);	// ������ ����
	// sum_ptr(&a, &b);			// �����ͷ� ����


	for (int i = 0; i < 5; i++)
	{
		static_test();
	}
	*/


	/*
	///////// chapter5: while�� /////////
	int a = 0;
	int count = true;

	while (count)
	{
		printf("%d\n", a);
		a++;
		if (a == 10)
			// break; // �극��ũ�� ��� ����
			count = false;
			continue;
	}
	*/


	/*
	///////// chapter5: do while�� /////////
	int num = 0;

	do
	{
		cout << "0~100" << endl;
		cin >> num;

	} while (num < 0 || num > 100); // 0���� �۰ų� 100���� ũ��
	*/


	/*
	///////// chapter5: for�� /////////
	for (int i = 0; i < 5; i++) // ��
	{
		for (int j = 0; j <= 5; j++) // ��
		{
			printf("*");
		}
		printf("\n");
	}
	*/


	/*
	///////// chapter4: if�� /////////
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
	///////// chapter4: switch�� /////////
	int day;
	cin >> day;

	switch (day)
	{
	case 1: cout << "��" << endl;
		break;
	case 2: cout << "ȭ" << endl;
		break;
	case 3: cout << "��" << endl;
		break;
	case 4: cout << "��" << endl;
		break;
	case 5: cout << "��" << endl;
		break;
	case 6: cout << "��" << endl;
		break;
	case 7: cout << "��" << endl;
		break;

	default: cout << "�߸� �Է�" << endl;
	}
	*/


	/*
	///////// chapter2: ������ /////////
	char first = 'A';	// �ƽ�Ű �ڵ� ���
	char second = 65;	// ���ڵ� ��� ������
	char third = 'B';
	int count = 0;

	printf("%c\n", first);
	printf("%c\n", second);
	*/
}