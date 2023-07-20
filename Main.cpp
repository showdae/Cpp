// git push - 23071717
// git push - 23071804
// git push - 23071906
// git push - 23072104
 
// ǥ�� ���̺귯��
#include <iostream>	// �ܼ� ��Ʈ��
#include <fstream>	// ���� ��Ʈ��
#include <sstream>	// ���ڿ� ��Ʈ��
#include <cstring>	// C ���ڿ� ��Ÿ�� (API)
#include <string>	// C++ ���ڿ� ��Ÿ�� (Ŭ����)
#include <cassert>	// ���� ó��
#include <iomanip>	// ���� �����ڸ� ����ϱ� ���� ��� ����

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


 // try-catch (throw)
 int CppExHandling(int _num3)
 {
	 if (_num3 == 0) { throw runtime_error("runtime_error!"); } // throw -> catch ���� �̵�

	 if (_num3 < 0) { throw out_of_range("out_of_range!"); }

	 return _num3;
 }


 // ���ø� �Լ�
 template <typename T>
 T TempleFunc(const T& _first, const T& _second)
 {
	 if (_first < _second)
	 {
		 return _first;
	 }
	 return _second;
 }


 // ���ø� Ư��ȭ: ���� ���ø� �Լ����� ����� �߰� (��� T�� ���� �ڷ������� ����)
 template <>
 const char* TempleFunc(const char* const& _first, const char* const& _second)
 {
	 // strcmp (���ڿ� ��): ������ 0�� ��ȯ, ù��° ���ڿ��� ������ ����, ũ�� ��� ��ȯ
	 // C ��Ÿ�� ���ڿ��� < ������ �����ε��Ǿ� ���� ���� -> strcmp �Լ��� ��ü
	 if (strcmp(_first, _second) < 0)
	 {
		 return _first;
	 }
	 return _second;
 }


 // ���ø� �Լ� ���� (�迭)
 // N ���� �����Ϸ��� ���� "�߷�"�ǰų� "�����"���� ���� ����
 template <typename T, int N>
 void TempleArr(T (&_arr) [N])
 {
	 for (int i = 0; i < N; i++)
	 {
		 cout << fixed << setprecision(1) << _arr[i] << " ";
	 }
	 cout << endl << endl;
 }


 // ��� (���丮��)
 int factorial(int n)
 {
	 if (n <= 1) // ���̽� ���̽� (Ż�� ����)
	 { return 1; } 
	 return n * factorial(n - 1); // ���ʷ� ���̽� (ó��)
 }


 // ��� (�Ǻ���ġ ����)
 long long fib(int n)
 {
 	 if (n == 0 || n == 1)
	 { return n; }
	 return fib(n - 1) + fib(n - 2); // �� �Լ��� ���ϰ��� ���ؼ� ���� ���� �Լ� �Ķ��Ÿ�� ���
 }


int main()
{
	///////// chapter18: �ڷ� ���� /////////

	///////////////////////////////////////

	/*
	///////// chapter17: ��� �Լ� /////////
	// ���: �Լ� ��ü�� n-1�� ȣ���ؼ� �ݺ�
	// ���ʷ� ���̽�: ó���� �ϴ� �Լ� ȣ��
	// ���̽� ���̽�: �ݺ��� �����ϱ� ���� �Լ� ȣ��
	// ������ ��� �Լ�: ������ �Լ��� ȣ���ؼ� ����� �����ϱ� ������ ������ ������ ����
	// 1) ���丮�� ����
	cout << "���丮��" << endl;
	cout << factorial(4) << endl << endl;

	// 2) �Ǻ���ġ ���� ����
	cout << "0~10 ������ �Ǻ���ġ ����" << endl;
	for (int i = 0; i <= 10; i++)
	{ cout << "fib(" << i  << ") :" << fib(i) << endl; }

	// 3) ����(���): Sort.cpp ���� ����

	// 4) Ž��(���): Binary_Search.cpp ���� ����
	///////////////////////////////////////
	*/


	/*
	///////// chapter16: ����� ��Ʈ�� /////////
	// ��Ʈ���̶�: ���α׷��� �����ͼҽ� or �����ͽ�ũ�� ���� �ٸ�(�ڵ� ��ȯ)
	// �����ͼҽ�: Ű����, ����, ���ڿ�
	// �����ͽ�ũ: �����, ����, ���ڿ�
	// �����ͼҽ�(Byte) -> �Է½�Ʈ��(�ڷ��� ��ȯ) -> PG -> ��½�Ʈ��(Byte�� ��ȯ) -> �����ͽ�ũ(Byte)
	// iostream: istream(�Է�), ostream(���) ��ӹ޾� iostream(�����) ���: stringStream(���ڿ�), fStream(����)

	///// 1. �ܼ� ��Ʈ�� (�Ͻ����� ����, Ű���� -> �����) /////
	// ���: <iostream>
	// ��� Ŭ����: istream, ostream, iostream
	// ��� ����: Ű����� �ܼ� ���α׷��� ������Ҷ� ���
	int iNum;
	cin >> iNum; // �����ͼҽ� 10 �Է�
	// ���α׷� �޸�: 0x0000003831cffb64 [0a 00 00 00]
	cout << iNum << endl << endl; // �����ͽ�ũ 10 ���

	///// 2. ���� ��Ʈ�� (�������� ����, csv -> csv) /////
	// ���: <fstream>
	// ��� Ŭ����: ifstream, ofstream, fstream
	// ��� ����: ���ϰ� ���α׷��� �����ؼ� ������ �а� ���� ���
	// �����̶�:		8��Ʈ ����Ʈ��, ���Ͽ��� �����͸� �а� ������ ��Ʈ�� ��ü�� Ȱ��
	//				��Ʈ�� ��ü�� ������ �д´ٸ�, �ý��ۿ� ���ؼ� ������ ������ �뷮���� ���ۿ� �����
	//				��Ʈ�� ��ü�� ������ ������, �ý��ۿ� ���ؼ� ���ۿ��� ���Ϸ� �����Ͱ� �뷮���� ���޵�
	// ��Ʈ�� ����:	���� ����: ofstream, ���� �б� ifstream, ���� fstream
	// ��Ŀ:			������ ����Ʈ ��ġ�� ����Ŵ (���� ��Ŀ ��ġ ����: inStream tellg(), outStream tellp())
	// ���� ����:	��Ŀ�� ���ۿ� ���������� ����
	// ���� ����:	��Ŀ�� Ư�� ��ġ�� ��ٷ� ����

	ofstream outStream; // ��� ��Ʈ�� ��ü �ν��Ͻ�ȭ
	outStream.open("test1.csv"); // ���� ���� (Ȯ���ڸ����� ����)
	//outStream.open("integerFile.csv", ios::out | ios::app); // ���� ���: ���� �ڿ� �߰��Ҷ�
	if (!outStream.is_open()) // ������ ����� ���ȴ��� Ȯ��
	{ cout << "���� ���� ����" << endl; }

	for (int i = 0; i < 3; i++)
	{
		outStream << i + 1;		// ���Ͽ� �� ����
		if (i != 2) {
			outStream << ",";	// ��ǥ�� ����
		}
	}
	outStream.close(); // ���� ���� ���� (���� ��Ʈ���� �� ���� �ϳ��� ���ϸ� ����)

	ifstream inStream;
	inStream.open("test1.csv");
	if (!inStream.is_open())
	{ cout << "���� �б� ����" << endl; }
	
	string line;
	getline(inStream, line); // �� �پ� �б�

	stringstream ss(line);
	string token;

	while (getline(ss, token, ',')) {	// ��ǥ�� �����ڷ� ����Ͽ� ���� ����
		int number = stoi(token);		// stoi(): ���ڿ��� ������ ��ȯ�ϴ� �Լ�
		cout << number << ",";
	}
	cout << endl;
	inStream.close(); // ���� ���� ����

	///// 3. ���� ���� ��Ʈ�� (���������� -> ����������) /////
	// �ؽ�Ʈ ������ �ƴ� �����͸� ó���Ҷ� ��� (�̹��� ����...)
	int iNum1 = 12345; double dNim1 = 12.345;

	ofstream binaryOut;
	binaryOut.open("test2.txt", ios::out | ios::binary); // ������: out ��¸���, binary ����
	if (!binaryOut.is_open())
	{ cout << "���� ���� ����" << endl; }

	// write(): sizeof()���� ���ڸ� �迭���� ��Ʈ�� ���۷� ���
	// int ���� �ּҸ� �ް� char �����ͷ� ��ȯ�ѵ� ���Ͽ� ����
	binaryOut.write(reinterpret_cast<char*>(&iNum1), sizeof(int));
	binaryOut.write(reinterpret_cast<char*>(&dNim1), sizeof(double));
	binaryOut.close();

	int iNum2; double dNum2;

	ifstream binaryIn;
	binaryIn.open("test2.txt", ios::in, ios::binary); // ������: in �б����, binary ����
	if (!binaryIn.is_open())
	{ cout << "���� �б� ����" << endl; }

	// read(): ��Ʈ�� ���ۿ��� sizeof()���� ���ڸ� �а�, Num2�� ���� �迭�� ä��
	// int ���� �ּҸ� ������� �޸𸮿� ����Ǿ� �ִ� ��ġ�� char �����ͷ� ��ȯ�ѵ� ���� �б�
	binaryIn.read(reinterpret_cast<char*>(&iNum2), sizeof(int));
	binaryIn.read(reinterpret_cast<char*>(&dNum2), sizeof(double));
	binaryIn.close();

	cout << "iNum2: " << iNum2 << endl;
	cout << "dNum2: " << dNum2 << endl;

	///// 4. ���ڿ� ��Ʈ�� (���ڿ� -> ���ڿ�) /////
	// ���: <sstream>
	// ��� Ŭ����: istringstream, ostringstream, stringstream
	// ��� ����: ���ڿ����� �����͸� �о� ���̰ų�, ���ڿ��� �����͸� ����Ҷ� ���
	// �ֽܼ�Ʈ��, ���Ͻ�Ʈ���� ������ �ҽ��� ��ũ�� ���α׷� �ܺο� ������, ���ڿ� ��Ʈ���� ���ο� �ִ�
	// ������ �ҽ��� ��ũ�� ���ο� �����Ƿ� ���� ���� �ʿ䰡 ���� (open, close �Լ��� ����)
	// �����: stringstream ��ü�� ����ͷ� ����Ͽ� ����ȯ
	// ��: �ٸ� �ڷ��� -> ���ڿ� �ڷ������� ��ȯ (ostringstream)
	// ��: ���ڿ� �ڷ��� -> �ٸ� �ڷ������� ��ȯ (istringstream)

	stringstream strStream("AAA AAA");	// ������ �ʱ�ȭ
	cout << strStream.str() << endl;
	strStream.str("BBB BBB");			// str(): �Ű������� ȣ��Ʈ��ü�� ����
	cout << strStream.str() << endl;	// str(): ȣ��Ʈ ��ü�� ����� ���ڿ� ����

	///// 5. ������ ����ȭ (������) /////
	// ���: <iomanip>
	// ��� Ŭ����: ios
	// ��� ����: ����� ���� ����
	// ����ȭ �÷���(fmtFlag):	ios Ŭ������ 7���� ���� ���յ� fmtFlag��� �ڷ����� ����
	//							fmtFlags::setf(flag): �÷��� ����, fmtFlags::unsetf(flag): �÷��� ���� 
	// ����ȭ �ʵ�:				ios Ŭ������ 3���� �ʵ� �׷��� ����
	//							fmtField::setf(addingField, field): �ʵ� ����, fmtField::unsetf(field): �ʵ� ���� 
	// ����ȭ ����:				width, precision, fill
	//							int ios::width(int n), int ios::precision(int n), int ios::fill(char c)
	
	bool b = true;
	double d = 12.3456;
	bool b2 = true;
	double d2 = 12.3456;

	// �÷���, �ʵ�, ������ ����� ����ȭ
	cout << "����ȭ ���� ���" << endl;
	cout << "b: " << b << endl;
	cout << "d: " << d << endl << endl;

	cout << "bool ����ȭ" << endl;
	cout.setf(ios::boolalpha);				// ����ȭ �÷���: �� �ڷ����� true or false ���·� ���
	cout << "b: " << b << endl << endl;

	cout << "double ����ȭ" << endl;
	cout.setf(ios::fixed, ios::floatfield);	// ����ȭ �ʵ�: �ε� �Ҽ����� ���� ǥ������� ���
	cout.width(10);							// ����ȭ ����: ����� �ʵ��� ũ�� ����
	cout.precision(1);						// ����ȭ ����: �Ҽ��� �Ʒ��� �� �ڸ����� ������� ����
	cout.fill('*');							// ����ȭ ����: ������ �ʴ� ������ ä��� ���� ���� ����
	cout << "d: " << d << endl << endl;

	// ǥ�� �����ڸ� ����� ����ȭ (<iomanip> ����� �о�� ����� �� ����)
	cout << "ǥ�� ������ ���" << endl;
	cout << "b2: " << boolalpha << b2 << endl;
	cout << "d2: " << showpoint << right << fixed << setw(16) << setprecision(2)
		 << setfill('*') << d2 << endl;
	///////////////////////////////////////
	*/


	/*
	///////// chapter15: ���ø� /////////
	// ���ø�: �ڵ带 ó���� �ۼ��ϰ�, �����ϵɶ� �ڷ����� �ش��ϴ� �Լ��� ������
	// ���ø� �Լ��� �����ε��� ����

	// 1. ���ø� �Լ�
	int iFirst = 10;	int iSecond = 1;
	float fFirst = 10;	float fSecond = 1;
	char cFirst = 'A';	char cSecond = 'B';

	cout << "���ø� �Լ�" << endl;
	cout << TempleFunc(iFirst, iSecond) << endl;
	cout << TempleFunc(fFirst, fSecond) << endl;
	cout << TempleFunc(cFirst, cSecond) << endl;
	//cout << TempleFunc(10, 1.12) << endl;				// ������ error: �ڷ����� ���������� �� �� ����
	cout << TempleFunc<int>(10, 1.12) << endl << endl;	// ����� ����ȯ

	// 2. ���ø� �Լ� ���� (�迭)
	int iArr[3]		= { 1, 2, 3 };
	double dArr[3]	= { 1.0, 2.0, 3.0 };

	cout << "���ø� �Լ� ����" << endl;
	//TempleArr(iArr); // N���� �Ϲ������� ����
	//TempleArr(dArr);

	TempleArr<int, 3>(iArr); // N���� ��������� ����
	TempleArr<double, 3>(dArr);

	// 3. ���ø� Ư��ȭ
	string str1 = "aaa"; // C++ ��Ÿ��
	string str2 = "bbb";
	const char* s1 = "ccc"; // C ��Ÿ��
	const char* s2 = "ddd";

	cout << "Ư��ȭ" << endl;
	cout << TempleFunc(str1, str2) << endl;
	cout << TempleFunc(s1, s2) << endl;		// Ư��ȭ �Լ� ȣ��

	// 4. ���ø� Ŭ����
	// Templ Ŭ���� ����

	// 5. �л�� ���ø��� ������
	// ���� ������: h -> cpp -> app(include cpp) -> �����Ϸ� -> exe
	// ���� ������: ��� ���ø� �Լ�/Ŭ������ export Ű���带 �ٿ��ش�
	//			   �����Ϸ��� export Ű���带 �������� ������ ���� �������� ����ؾ� �Ѵ� (������ ���� X)
	//			   export template <typename T> 
	///////////////////////////////////////
	*/


	/*
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
	int num2 = -1;

	try { if (num2 < 0) { throw -1; } }

	catch (int exceptionValue) {
		cout << "error2: " << exceptionValue << endl << endl;
	}

	// 3. ǥ�� ���� Ŭ����
	// stdexcept: C++ ǥ�� ���̺귯������ �پ��� ���� Ŭ������ ���ǵǾ� ����
	// logic_error; : domain_error; out_of_range; length_error; invalid_argument;
	// runtime_error; : overflow_error; underflow_error; range_error;
	
	int num3 = -1;

	try // ���ܰ� �߻��� �� �ִ� �ڵ�
	{ CppExHandling(num3); }

	catch (runtime_error& e)	// runtime_error ���� ó��
	{ cout << "error3: " << e.what() << endl; }
	catch (out_of_range& e)	// out_of_range ���� ó��
	{ cout << "error3: " << e.what() << endl; }
	///////////////////////////////////////
	*/


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
	// Parent, Child Ŭ���� ����
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
	// 1) �Լ� ȣ�� ���: CallBy.cpp ���� ����
	
	// 2) ���� ����
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