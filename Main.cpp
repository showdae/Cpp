// git push - 23071717

#include <iostream>	// �����
#include <cstring>	// C ���ڿ� ��Ÿ�� (API)
#include <string>	// C++ ���ڿ� ��Ÿ�� (Ŭ����)
#include <cassert>	// ���� ó��

using namespace std;

// ���� ����
 int testStatic; // ���� ������ 0���� �ʱ�ȭ
 void static_test()
 {
	 // ���� ����: �ѹ��� �ʱ�ȭ�ϸ�, �������� ����� ���ŵ��� ���� (�ڵ� ������ ���� �ϴµ�)
	 static int count = 0;
	 count++;
	 int testStack; // ���� ������ ������ ������ �ʱ�ȭ
	 testStack = 0;
	 testStack++;

	 printf("����: %d\n", count);
	 printf("����: %d\n\n", testStack);
 }


 // ����ü
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


 // ������ �����ε�
 class B {
	 // A Ŭ������ ģ���� ���� (AŬ�������� BŬ���� private �ɹ� ������ ������ �� �ִ�)
	 friend class A;

 private:
	 int m_i = 2;
	 double m_d = 2.0;
	 char m_c = 'A';
 };


 class A {
 private:
	 int m_i = 10;
	 double m_d = 10.0;

 public:
	 void Aprintf() { printf("m_i: %d\n", m_i); 
					  printf("m_d: %.2f\n", m_d); }

	 // ������ �Լ�
	 // ������ const: BŬ���� ��ü ���� �Ұ�
	 // ������ const: AŬ���� ��ü ���� �Ұ�
	 A operator+(const B& other) const
	 {
		 A result;

		 // this->m_i = 100; // AŬ���� �ɹ� ���� �� ����
		 // other.m_i = 200; // BŬ���� �ɹ� ���� �� ����

		 // A�� B�� ���� ����� result�� �Ҵ�
		 result.m_i = this->m_i + other.m_i;
		 result.m_d = this->m_d + other.m_d;
		 return result;
	 }
 };


 // C ��Ÿ�� ���� ó��
 int CExHandling(int _num)
 {
	 if (_num == 0) { return -1; }

	 return _num;
 }


 // C++ ��Ÿ�� ���� ó��
 int CppExHandling(int _num3)
 {
	 if (_num3 == 0) { throw runtime_error("runtime_error!"); } // throw -> catch ���� �̵�

	 if (_num3 < 0) { throw out_of_range("out_of_range!"); }

	 return _num3;
 }


int main()
{
	///////// chapter15: ���ø� /////////


	//return 0; // main �Լ����� ������ ������ 0�� ����, ������ ������ �ٸ� ���� ����


	
	///////// chapter14: ���� ó�� /////////
	// 1. C ��Ÿ�� ����ó��
	// 1) ��ũ�� �Լ�: assert(false);
	// 2) if / else
	// 3) �Լ� ���ϰ�
	int num1 = -1, result1 = 0;

	result1 = CExHandling(num1);
	if (result1 == -1)	{ cout << "error1: " << num1 << endl << endl; }
	else				{ cout << "result1: " << result1 << endl << endl; }

	// 2. C++ ��Ÿ�� ����ó��
	// try-catch ����: ������ ���� �������� �°� ���

	// 1) try-catch ���� ����ϴ� ��
	int num2 = -1;

	try { if (num2 < 0) { throw -1; } }

	catch (int exceptionValue) {
		cout << "error2: " << exceptionValue << endl << endl;
	}

	// 2) throw, catch �б��Ͽ� ����ϴ� ��
	// stdexcept: C++ ǥ�� ���̺귯������ �پ��� ���� Ŭ������ ���ǵǾ� ����
	int num3 = -1;

	try // ���ܰ� �߻��� �� �ִ� �ڵ�
	{ CppExHandling(num3); }

	catch (runtime_error& e)	// runtime_error ���� ó��
	{ cout << "error3: " << e.what() << endl; }
	catch (out_of_range& e)	// out_of_range ���� ó��
	{ cout << "error3: " << e.what() << endl; }
	///////////////////////////////////////
	


	/*
	///////// chapter13: ������ �ι��ε� /////////
	// ������ �ι��ε�:	����� �ڷ��� ��ü���� �����ڸ� Ȱ���� �� �ִ� ���
	// ������ �Լ�:		�����ڷ��� operator ������()
	// ����Ʈ ������:		���ϴ� �ڷ����� ����ų�� �ִ� �����͸� ������ �ɹ��� ���� ��ü
	// friend Ŭ����:	ģ�� Ŭ������ private �ɹ� ������ ������ �� �ִ�		

	A testA;
	B testB;

	A result = testA + testB; // + �����ڸ� ����Ͽ� ���մϴ�.

	result.Aprintf();
	///////////////////////////////////////
	*/


	/*
	///////// chapter12: ������ /////////
	// �������̶�: ���� �̸�, ���ڸ� ���� �Լ��� Ŭ�������� ����
	//			  (���̽�/�Ļ�)ptr -> ��ü -> �������̺� -> �Լ�ȣ��(���̽�/�Ļ�)
	// ����Ҹ���: ���̽� Ŭ�������� ���� �Լ��� ���� ����Ҹ��� ���

	// ���ε�:	  �Լ� ȣ��� �Լ� ������ ����
	// �������ε�: ������ ���� ���ε�
	// �������ε�: ��Ÿ�� ���� ���ε� (������)
	
	// �����ڷ��� ��ȯ
	// ��ĳ��Ʈ:		Person* ptr1 =  new Student;
	// �ٿ�ĳ��Ʈ:	Student* ptr2 = dynamic_cast<Student*>(ptr1)

	// �߻�Ŭ����:	�ϳ� �̻��� "���������Լ�" �����ϴ� Ŭ���� (�ν��Ͻ� �Ұ�!)
	// ���������Լ�:	����� 0�� �Ҵ�, �������� ����
	//				vertual int getTest() = 0; (�Ļ� Ŭ�������� ���������Լ� ����)
	// Ŭ���� �������̽�:	��� �Լ��� ���������Լ� (���� ���� ����)

	// ���� ���:	�� �̻��� ���̽� Ŭ������ �ϳ��� �Ļ�Ŭ�������� ���
	//				classB : vertual public classA
	//				classC : vertual public classA
	//				classD : public classB, public classC
	///////////////////////////////////////
	*/


	/*
	///////// chapter11: Ŭ������ ���� /////////
	// ���: classB���� classA�� ��� ������ ���
	// classA		classB : public classA
		  
	// ����: classA ��� �������� classB �ڷ����� ���
	// classA		classB
		  
	// ����: classA �ɹ� �Լ����� �Ű�����, ���ϰ�, ���������� classB �ڷ��� ���
	// classA		classB
	///////////////////////////////////////
	*/


	/*
	///////// chapter10: ���ڿ� /////////
	// C ���ڿ� ��Ÿ�� (API) : ������� <cstring>
	// C ���ڿ��� �ι��ڷ� ������ ���� �迭�̴� (�迭�� �̸��� ù ��ҿ� ���� ������)
	// �ι��ڷ� ũ�⸦ ���������� �� �� �־ ������ �� �ִ�
	char str1[10] = "AAA";			// ����
	char str2[] = "BBB";
	str2[0] = 'A';					// ����

	char* pStr = str1;				// ������

	// API �Լ�
	cout << "���ڿ� ����: " << strlen(str1) << endl;
	cout << "���ڿ� ��: " << strcmp(str1, str2) << endl;
	cout << "���ڿ� ����: " << strcat(str1, str2) << endl;
	cout << "���ڿ� ����: " << strcpy(str1, str2) << endl << endl;

	// C++ ���ڿ� ��Ÿ�� (Ŭ����): ������� <string>
	// C++ ���ڿ��� �ι��ڷ� ������ ����, ���޸𸮿� �Ҵ�

	string str3;			// �⺻ ������
	string str4("CCC");		// �Ű����� ������
	string str5("DDD");

	// �Ҹ���: Ŭ���� ������ �ڵ����� �� �޸� Delete[] �ϴµ�

	str4.reserve(10); // ���� ����
	cout << "���ڿ� ����: " << str4.size() << endl;
	cout << "���ڿ� �뷮: " << str4.capacity() << endl;
	cout << "���ڿ� ��: " << str4.compare(str5) << endl;
	cout << "���ڿ� ����: " << str4.append(str5) << endl;
	cout << "�߰��� ����: " << str4.insert(0,"A") << endl;
	str4.clear(); // ���ڿ� ����
	///////////////////////////////////////
	*/


	/*
	///////// chapter9: ������ /////////
	// ������: ���� �ڷ���, x86: 4byte x64: 8byte
	// * ���� ���� ������: �� <- * <- �ּ�
	// & �ּ� ������: �ּ� <- & <- ����

	//////////////////////////////////////
	// �޸� ������ ����
	// �ڵ� �޸�: ���α׷� ��ɾ �ö󰡴� ����
	// ���� �޸�: ���� ����, ���� ���� �����ϴ� ����
	// ���� �޸�: ���� ���� , �Ű�����, �����ּҸ� ���� (���� ���� ����)
	// �� �޸�:   �Լ��� ������ ���� �����Ǿ�� �ϴ� ������ �����ϴ� ���� (��Ÿ�� ����, ���� �Ҵ� �� ���� �ʿ�!	)
	//				�̹����� ����� Ŭ ��� ������ �� �޸𸮿� �÷��� �Ѵ�
	////////////////////////////////////// 

	// 1) ������ �ڷ���: �ּҸ� �޴´�
	int a = 10;
	int* ptrA = &a; // a �ּҸ� �޾� ������ �ڷ����� �����Ѵ�
	int** ptrB = &ptrA; // ���� ������

	cout << "a �ּ�: "		<< &a << endl;				// a �ּ�	(000000D6A8AFF704)
	cout << "a �ּ�: "		<< ptrA << endl;			// a �ּ�	(000000D6A8AFF704)
	cout << "a ��: "			<< *ptrA << endl;			// a ��		(10)
	cout << "ptrA �ּ�: "	<< &ptrA << endl;			// ptrA �ּ�	(000000D6A8AFF728)
	cout << "ptrA �ּ�: "	<< ptrB << endl;			// ptrA �ּ�	(000000D6A8AFF728)
	cout << "a �ּ�: "		<< *ptrB << endl;			// a �ּ�	(000000D6A8AFF704)
	cout << "ptrB �ּ�: "	<< &ptrB << endl << endl;	// ptrB �ּ�	(000000D6A8AFF748)


	// 2) ���� �ڷ���: �޸𸮸� ���� �Ѵ�
	int b = 20;
	int& refB = b;

	cout << &b << endl;				// b �ּ� (0000000544DDF794)
	cout << refB << endl;			// b ��   (20)
	// cout << *refB << endl;		// error
	cout << &refB << endl << endl;	// b �ּ� (0000000544DDF794)


	// 3) const ������
	int c = 30;
	const int d = 30;				// ���� ����, �� ���� �Ұ�
	const int* ptrE = &c;			// ���� ����, �� ���� �Ұ�
	int* const ptrF = &c;			// ���� ����, �ּ� ���� �Ұ�


	// 4) ���� �Ҵ� ������
	// C++: new / delete (C: malloc, free)
	int* pNew = new int[10];
	delete[] pNew;

	// 2���� �迭 ���� �Ҵ�
	int** pNewArr = new int*[10]; // row
	for (int i = 0; i < 10; i++)
	{
		pNewArr[i] = new int[10]; // col
	}
	
	delete[] pNewArr;
	///////////////////////////////////////
	*/


	/*
	///////// chapter8: �迭 /////////
	// �迭�� �̸��� ù ��ҿ� ���� ������
	// �����Ϸ��� �迭�� �������� �޸� ��ġ�� �Ҵ� (���� �ε���)
	// �迭�� ������ ������ ��� ����Ʈ��: 0
	// �迭�� ������ ������ ��� ����Ʈ��: �����Ⱚ
	
	// 1���� �迭
	// int arr1[3] = { 0 };		// 0 �ʱ�ȭ
	int arr1[3] = { 0,1,2 };	// ����� �ʱ�ȭ

	// arr1[2] �� *(arr1 + 2) �� ����
	// &arr1[2] �� arr1 + 2 �� ����
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter7: ����ü ��ü ��� /////////
	MyType custom;
	custom.i = 4;	// ����ü ��ü . �ɹ� ���� ������ ����Ͽ� ����

	MyType* ptr = &custom;
	ptr->s = 2;		// ������ ���� -> �ɹ� ���� ������ ����Ͽ� ����
	
	printf("%d\n", ptr->i);
	printf("%d\n", ptr->s);
	///////////////////////////////////////
	*/


	/*
	///////// chapter6: ���� ���� /////////
	// �Լ� ȣ�� ���: CallBy.cpp ���� ����

	// ���� ����
	for (int i = 0; i < 5; i++)
	{
		static_test();
	}
	///////////////////////////////////////
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter5: do while�� /////////
	int num = 0;

	do
	{
		cout << "0~100" << endl;
		cin >> num;

	} while (num < 0 || num > 100); // 0���� �۰ų� 100���� ũ��
	///////////////////////////////////////
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
	///////////////////////////////////////
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
	///////////////////////////////////////
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter2: ������ /////////
	char first = 'A';	// �ƽ�Ű �ڵ� ���
	char second = 65;	// ���ڵ� ��� ������
	char third = 'B';
	int count = 0;

	printf("%c\n", first);
	printf("%c\n", second);
	///////////////////////////////////////
	*/
}