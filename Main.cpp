// git push - 23071717
// git push - 23071804
// git push - 23071906
// git push - 23072104
 
// 표준 라이브러리
#include <iostream>	// 콘솔 스트림
#include <fstream>	// 파일 스트림
#include <sstream>	// 문자열 스트림
#include <cstring>	// C 문자열 스타일 (API)
#include <string>	// C++ 문자열 스타일 (클래스)
#include <cassert>	// 예외 처리
#include <iomanip>	// 포맷 조작자를 사용하기 위한 헤더 파일

using namespace std;

// 정적 변수
 int testStatic; // 전역 변수는 0으로 초기화
 void static_test()
 {
	 // 정적 변수: 한번만 초기화하며, 스코프를 벗어나도 제거되지 않음 (코드 영역에 존재 하는듯)
	 static int count = 0;
	 count++;
	 int testStack; // 지역 변수는 쓰레기 값으로 초기화
	 testStack = 0;
	 testStack++;

	 printf("정적: %d\n", count);
	 printf("지역: %d\n\n", testStack);
 }


 // 구조체
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


 // 연산자 오버로딩
 class B {
	 // A 클래스를 친구로 선언 (A클래스에서 B클래스 private 맴버 변수에 접근할 수 있다)
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

	 // 연산자 함수
	 // 앞쪽의 const: B클래스 객체 변경 불가
	 // 뒷쪽의 const: A클래스 객체 변경 불가
	 A operator+(const B& other) const
	 {
		 A result;

		 // this->m_i = 100; // A클래스 맴버 변수 값 변경
		 // other.m_i = 200; // B클래스 맴버 변수 값 변경

		 // A와 B를 더한 결과를 result에 할당
		 result.m_i = this->m_i + other.m_i;
		 result.m_d = this->m_d + other.m_d;
		 return result;
	 }
 };


 // C 스타일 예외 처리
 int CExHandling(int _num)
 {
	 if (_num == 0) { return -1; }

	 return _num;
 }


 // try-catch (throw)
 int CppExHandling(int _num3)
 {
	 if (_num3 == 0) { throw runtime_error("runtime_error!"); } // throw -> catch 절로 이동

	 if (_num3 < 0) { throw out_of_range("out_of_range!"); }

	 return _num3;
 }


 // 템플릿 함수
 template <typename T>
 T TempleFunc(const T& _first, const T& _second)
 {
	 if (_first < _second)
	 {
		 return _first;
	 }
	 return _second;
 }


 // 템플릿 특수화: 기존 템플릿 함수에서 기능을 추가 (모든 T를 같은 자료형으로 변경)
 template <>
 const char* TempleFunc(const char* const& _first, const char* const& _second)
 {
	 // strcmp (문자열 비교): 같은면 0을 반환, 첫번째 문자열이 작으면 음수, 크면 양수 반환
	 // C 스타일 문자열은 < 연산자 오버로딩되어 있지 않음 -> strcmp 함수로 대체
	 if (strcmp(_first, _second) < 0)
	 {
		 return _first;
	 }
	 return _second;
 }


 // 템플릿 함수 변형 (배열)
 // N 값은 컴파일러에 의해 "추론"되거나 "명시적"으로 전달 받음
 template <typename T, int N>
 void TempleArr(T (&_arr) [N])
 {
	 for (int i = 0; i < N; i++)
	 {
		 cout << fixed << setprecision(1) << _arr[i] << " ";
	 }
	 cout << endl << endl;
 }


 // 재귀 (펙토리얼)
 int factorial(int n)
 {
	 if (n <= 1) // 베이스 케이스 (탈출 조건)
	 { return 1; } 
	 return n * factorial(n - 1); // 제너럴 케이스 (처리)
 }


 // 재귀 (피보나치 수열)
 long long fib(int n)
 {
 	 if (n == 0 || n == 1)
	 { return n; }
	 return fib(n - 1) + fib(n - 2); // 두 함수의 리턴값을 더해서 이전 스택 함수 파라메타로 사용
 }


int main()
{
	///////// chapter18: 자료 구조 /////////

	///////////////////////////////////////

	/*
	///////// chapter17: 재귀 함수 /////////
	// 재귀: 함수 자체를 n-1번 호출해서 반복
	// 제너럴 케이스: 처리를 하는 함수 호출
	// 베이스 케이스: 반복을 종료하기 위한 함수 호출
	// 리턴형 재귀 함수: 각가의 함수를 호출해서 어떤값을 리턴하기 전까지 별로의 정보를 저장
	// 1) 펙토리얼 문제
	cout << "펙토리얼" << endl;
	cout << factorial(4) << endl << endl;

	// 2) 피보나치 수열 문제
	cout << "0~10 범위의 피보나치 수열" << endl;
	for (int i = 0; i <= 10; i++)
	{ cout << "fib(" << i  << ") :" << fib(i) << endl; }

	// 3) 정렬(재귀): Sort.cpp 파일 참조

	// 4) 탐색(재귀): Binary_Search.cpp 파일 참조
	///////////////////////////////////////
	*/


	/*
	///////// chapter16: 입출력 스트림 /////////
	// 스트림이란: 프로그램과 데이터소스 or 데이터싱크의 연결 다리(자동 변환)
	// 데이터소스: 키보드, 파일, 문자열
	// 데이터싱크: 모니터, 파일, 문자열
	// 데이터소스(Byte) -> 입력스트림(자료형 변환) -> PG -> 출력스트림(Byte열 변환) -> 데이터싱크(Byte)
	// iostream: istream(입력), ostream(출력) 상속받아 iostream(입출력) 사용: stringStream(문자열), fStream(파일)

	///// 1. 콘솔 스트림 (일시적인 형태, 키보드 -> 모니터) /////
	// 헤더: <iostream>
	// 사용 클래스: istream, ostream, iostream
	// 사용 목적: 키보드와 콘솔 프로그램에 입출력할때 사용
	int iNum;
	cin >> iNum; // 데이터소스 10 입력
	// 프로그램 메모리: 0x0000003831cffb64 [0a 00 00 00]
	cout << iNum << endl << endl; // 데이터싱크 10 출력

	///// 2. 파일 스트림 (영구적인 형태, csv -> csv) /////
	// 헤더: <fstream>
	// 사용 클래스: ifstream, ofstream, fstream
	// 사용 목적: 파일과 프로그램을 연결해서 파일을 읽고 쓸때 사용
	// 파일이란:		8비트 바이트열, 파일에서 데이터를 읽고 쓸때는 스트림 객체를 활용
	//				스트림 객체가 파일을 읽는다면, 시스템에 의해서 파일의 내용이 대량으로 버퍼에 복사됨
	//				스트림 객체가 파일을 쓸때도, 시스템에 의해서 버퍼에서 파일로 데이터가 대량으로 전달됨
	// 스트림 종류:	파일 생성: ofstream, 파일 읽기 ifstream, 수정 fstream
	// 마커:			파일의 바이트 위치를 가리킴 (현재 마커 위치 리턴: inStream tellg(), outStream tellp())
	// 순차 접근:	마커가 버퍼에 순차적으로 접근
	// 임의 접근:	마커가 특정 위치에 곧바로 접근

	ofstream outStream; // 출력 스트림 객체 인스턴스화
	outStream.open("test1.csv"); // 파일 열기 (확장자명으로 열기)
	//outStream.open("integerFile.csv", ios::out | ios::app); // 열기 모드: 파일 뒤에 추가할때
	if (!outStream.is_open()) // 파일이 제대로 열렸는지 확인
	{ cout << "파일 생성 실패" << endl; }

	for (int i = 0; i < 3; i++)
	{
		outStream << i + 1;		// 파일에 값 쓰기
		if (i != 2) {
			outStream << ",";	// 쉼표로 구분
		}
	}
	outStream.close(); // 파일 연결 끊기 (파일 스트림은 한 번에 하나의 파일만 연결)

	ifstream inStream;
	inStream.open("test1.csv");
	if (!inStream.is_open())
	{ cout << "파일 읽기 실패" << endl; }
	
	string line;
	getline(inStream, line); // 한 줄씩 읽기

	stringstream ss(line);
	string token;

	while (getline(ss, token, ',')) {	// 쉼표를 구분자로 사용하여 숫자 추출
		int number = stoi(token);		// stoi(): 문자열을 정수로 변환하는 함수
		cout << number << ",";
	}
	cout << endl;
	inStream.close(); // 파일 연결 끊기

	///// 3. 이진 파일 스트림 (이진데이터 -> 이진데이터) /////
	// 텍스트 파일이 아닌 데이터를 처리할때 사용 (이미지 파일...)
	int iNum1 = 12345; double dNim1 = 12.345;

	ofstream binaryOut;
	binaryOut.open("test2.txt", ios::out | ios::binary); // 열기모드: out 출력목적, binary 이진
	if (!binaryOut.is_open())
	{ cout << "파일 생성 실패" << endl; }

	// write(): sizeof()개의 글자를 배열에서 스트림 버퍼로 출력
	// int 변수 주소를 받고 char 포인터로 변환한뒤 파일에 쓰기
	binaryOut.write(reinterpret_cast<char*>(&iNum1), sizeof(int));
	binaryOut.write(reinterpret_cast<char*>(&dNim1), sizeof(double));
	binaryOut.close();

	int iNum2; double dNum2;

	ifstream binaryIn;
	binaryIn.open("test2.txt", ios::in, ios::binary); // 엵기모드: in 읽기목적, binary 이진
	if (!binaryIn.is_open())
	{ cout << "파일 읽기 실패" << endl; }

	// read(): 스트림 버퍼에서 sizeof()개의 글자를 읽고, Num2에 문자 배열을 채움
	// int 변수 주소를 기반으로 메모리에 예약되어 있는 위치를 char 포인터로 변환한뒤 파일 읽기
	binaryIn.read(reinterpret_cast<char*>(&iNum2), sizeof(int));
	binaryIn.read(reinterpret_cast<char*>(&dNum2), sizeof(double));
	binaryIn.close();

	cout << "iNum2: " << iNum2 << endl;
	cout << "dNum2: " << dNum2 << endl;

	///// 4. 문자열 스트림 (문자열 -> 문자열) /////
	// 헤더: <sstream>
	// 사용 클래스: istringstream, ostringstream, stringstream
	// 사용 목적: 문자열에서 데이터를 읽어 들이거나, 문자열로 데이터를 출력할때 사용
	// 콘솔스트림, 파일스트림은 데이터 소스와 싱크가 프로그램 외부에 있지만, 문자열 스트림은 내부에 있다
	// 데이터 소스와 싱크가 내부에 있으므로 열고 닫을 필요가 없다 (open, close 함수가 없다)
	// 어댑터: stringstream 객체를 어댑터로 사용하여 형변환
	// 랩: 다른 자료형 -> 문자열 자료형으로 변환 (ostringstream)
	// 언랩: 문자열 자료형 -> 다른 자료형으로 변환 (istringstream)

	stringstream strStream("AAA AAA");	// 생성자 초기화
	cout << strStream.str() << endl;
	strStream.str("BBB BBB");			// str(): 매개변수를 호스트객체와 연결
	cout << strStream.str() << endl;	// str(): 호스트 객체에 연결된 문자열 리턴

	///// 5. 데이터 형식화 (조정자) /////
	// 헤더: <iomanip>
	// 사용 클래스: ios
	// 사용 목적: 입출력 형태 조정
	// 형식화 플래그(fmtFlag):	ios 클래스는 7개의 값이 조합된 fmtFlag라는 자료형을 정의
	//							fmtFlags::setf(flag): 플래그 설정, fmtFlags::unsetf(flag): 플래그 해제 
	// 형식화 필드:				ios 클래스는 3개의 필드 그룹을 제공
	//							fmtField::setf(addingField, field): 필드 설정, fmtField::unsetf(field): 필드 해제 
	// 형식화 변수:				width, precision, fill
	//							int ios::width(int n), int ios::precision(int n), int ios::fill(char c)
	
	bool b = true;
	double d = 12.3456;
	bool b2 = true;
	double d2 = 12.3456;

	// 플래그, 필드, 변수를 사용한 형식화
	cout << "형식화 없이 출력" << endl;
	cout << "b: " << b << endl;
	cout << "d: " << d << endl << endl;

	cout << "bool 형식화" << endl;
	cout.setf(ios::boolalpha);				// 형식화 플래그: 불 자료형을 true or false 형태로 출력
	cout << "b: " << b << endl << endl;

	cout << "double 형식화" << endl;
	cout.setf(ios::fixed, ios::floatfield);	// 형식화 필드: 부동 소수점을 고정 표기법으로 출력
	cout.width(10);							// 형식화 변수: 출력할 필드의 크기 지정
	cout.precision(1);						// 형식화 변수: 소수점 아래의 몇 자리까지 출력할지 지정
	cout.fill('*');							// 형식화 변수: 사용되지 않는 공간을 채우기 위한 문자 지정
	cout << "d: " << d << endl << endl;

	// 표준 조정자를 사용한 형식화 (<iomanip> 헤더를 읽어야 사용할 수 있음)
	cout << "표준 조정자 사용" << endl;
	cout << "b2: " << boolalpha << b2 << endl;
	cout << "d2: " << showpoint << right << fixed << setw(16) << setprecision(2)
		 << setfill('*') << d2 << endl;
	///////////////////////////////////////
	*/


	/*
	///////// chapter15: 템플릿 /////////
	// 템플릿: 코드를 처리만 작성하고, 컴파일될때 자료형에 해당하는 함수를 만들어낸다
	// 템플릿 함수로 오버로딩이 가능

	// 1. 템플릿 함수
	int iFirst = 10;	int iSecond = 1;
	float fFirst = 10;	float fSecond = 1;
	char cFirst = 'A';	char cSecond = 'B';

	cout << "템플릿 함수" << endl;
	cout << TempleFunc(iFirst, iSecond) << endl;
	cout << TempleFunc(fFirst, fSecond) << endl;
	cout << TempleFunc(cFirst, cSecond) << endl;
	//cout << TempleFunc(10, 1.12) << endl;				// 컴파일 error: 자료형을 복합적으로 쓸 수 없다
	cout << TempleFunc<int>(10, 1.12) << endl << endl;	// 명시적 형변환

	// 2. 템플릿 함수 변형 (배열)
	int iArr[3]		= { 1, 2, 3 };
	double dArr[3]	= { 1.0, 2.0, 3.0 };

	cout << "템플릿 함수 변형" << endl;
	//TempleArr(iArr); // N값을 암묵적으로 전달
	//TempleArr(dArr);

	TempleArr<int, 3>(iArr); // N값을 명시적으로 전달
	TempleArr<double, 3>(dArr);

	// 3. 템플릿 특수화
	string str1 = "aaa"; // C++ 스타일
	string str2 = "bbb";
	const char* s1 = "ccc"; // C 스타일
	const char* s2 = "ddd";

	cout << "특수화" << endl;
	cout << TempleFunc(str1, str2) << endl;
	cout << TempleFunc(s1, s2) << endl;		// 특수화 함수 호출

	// 4. 템플릿 클래스
	// Templ 클래스 참조

	// 5. 분산된 템플릿의 컴파일
	// 포함 컴파일: h -> cpp -> app(include cpp) -> 컴파일러 -> exe
	// 분할 컴파일: 모든 템플릿 함수/클래스를 export 키워드를 붙여준다
	//			   컴파일러가 export 키워드를 지원하지 않으면 포함 컴파일을 사용해야 한다 (구버젼 지원 X)
	//			   export template <typename T> 
	///////////////////////////////////////
	*/


	/*
	///////// chapter14: 예외 처리 /////////
	// 1. C 스타일 예외처리
	// 1) 매크로 함수: assert(false);
	// 2) if / else
	// 3) 함수 리턴값
	int num1 = -1, result1 = 0;

	result1 = CExHandling(num1);
	if (result1 == -1)	{ cout << "error1: " << num1 << endl << endl; }
	else				{ cout << "result1: " << result1 << endl << endl; }

	// 2. C++ 스타일 예외처리
	// try-catch 장점: 리턴을 원래 목정성에 맞게 사용
	int num2 = -1;

	try { if (num2 < 0) { throw -1; } }

	catch (int exceptionValue) {
		cout << "error2: " << exceptionValue << endl << endl;
	}

	// 3. 표준 예외 클래스
	// stdexcept: C++ 표준 라이브러리에는 다양한 예외 클래스가 정의되어 있음
	// logic_error; : domain_error; out_of_range; length_error; invalid_argument;
	// runtime_error; : overflow_error; underflow_error; range_error;
	
	int num3 = -1;

	try // 예외가 발생할 수 있는 코드
	{ CppExHandling(num3); }

	catch (runtime_error& e)	// runtime_error 예외 처리
	{ cout << "error3: " << e.what() << endl; }
	catch (out_of_range& e)	// out_of_range 예외 처리
	{ cout << "error3: " << e.what() << endl; }
	///////////////////////////////////////
	*/


	/*
	///////// chapter13: 연산자 로버로딩 /////////
	// 연산자 로버로딩:	사용자 자료형 객체간에 연산자를 활용할 수 있는 기능
	// 연산자 함수:		리턴자료형 operator 연산자()
	// 스마트 포인터:		원하는 자료형을 가리킬수 있는 포인터를 데이터 맴버로 갖는 객체
	// friend 클래스:	친구 클래스의 private 맴버 변수에 접근할 수 있다		

	A testA;
	B testB;

	A result = testA + testB; // + 연산자를 사용하여 더합니다.

	result.Aprintf();
	///////////////////////////////////////
	*/


	/*
	///////// chapter12: 다형성 /////////
	// 다형성이란: 같은 이름, 인자를 갖는 함수를 클래스별로 구분
	//			  (베이스/파생)ptr -> 객체 -> 가상테이블 -> 함수호출(베이스/파생)
	// 가상소멸자: 베이스 클래스에서 가상 함수를 사용시 가상소멸자 사용

	// 바인딩:	  함수 호출과 함수 본문을 연결
	// 정적바인딩: 컴파일 시점 바인딩
	// 동적바인딩: 런타임 시점 바인딩 (다형성)
	
	// 동적자료형 변환
	// 업캐스트:		Person* ptr1 =  new Student;
	// 다운캐스트:	Student* ptr2 = dynamic_cast<Student*>(ptr1)

	// 추상클래스:	하나 이상의 "순수가상함수" 포함하는 클래스 (인스턴스 불가!)
	// 순수가상함수:	선언시 0을 할당, 정의하지 않음
	//				vertual int getTest() = 0; (파생 클래스에서 순수가상함수 정의)
	// 클래스 인터페이스:	모든 함수가 순수가상함수 (구현 파일 없음)

	// 다중 상속:	둘 이상의 베이스 클래스를 하나의 파생클래스에서 상속
	//				classB : vertual public classA
	//				classC : vertual public classA
	//				classD : public classB, public classC
	///////////////////////////////////////
	*/


	/*
	///////// chapter11: 클래스의 관계 /////////
	// Parent, Child 클래스 참조
	// 상속: classB에서 classA의 멤버 변수를 상속
	// classA		classB : public classA
		  
	// 연관: classA 멤버 변수에서 classB 자료형을 사용
	// classA		classB
		  
	// 종속: classA 맴버 함수에서 매개변수, 리턴값, 지역변수로 classB 자료형 사용
	// classA		classB
	///////////////////////////////////////
	*/


	/*
	///////// chapter10: 문자열 /////////
	// C 문자열 스타일 (API) : 헤더파일 <cstring>
	// C 문자열은 널문자로 끝나는 문자 배열이다 (배열의 이름은 첫 요소에 대한 포인터)
	// 널문자로 크기를 간접적으로 알 수 있어서 리턴할 수 있다
	char str1[10] = "AAA";			// 선언
	char str2[] = "BBB";
	str2[0] = 'A';					// 접근

	char* pStr = str1;				// 포인터

	// API 함수
	cout << "문자열 길이: " << strlen(str1) << endl;
	cout << "문자열 비교: " << strcmp(str1, str2) << endl;
	cout << "문자열 결합: " << strcat(str1, str2) << endl;
	cout << "문자열 복사: " << strcpy(str1, str2) << endl << endl;

	// C++ 문자열 스타일 (클래스): 헤더파일 <string>
	// C++ 문자열은 널문자로 끝나지 않음, 힙메모리에 할당

	string str3;			// 기본 생성자
	string str4("CCC");		// 매개변수 생성자
	string str5("DDD");

	// 소멸자: 클래스 내부적 자동으로 힙 메모리 Delete[] 하는듯

	str4.reserve(10); // 용적 예약
	cout << "문자열 길이: " << str4.size() << endl;
	cout << "문자열 용량: " << str4.capacity() << endl;
	cout << "문자열 비교: " << str4.compare(str5) << endl;
	cout << "문자열 결합: " << str4.append(str5) << endl;
	cout << "중간에 삽입: " << str4.insert(0,"A") << endl;
	str4.clear(); // 문자열 제거
	///////////////////////////////////////
	*/


	/*
	///////// chapter9: 포인터 /////////
	// 포인터: 복합 자료형, x86: 4byte x64: 8byte
	// * 간접 참조 연산자: 값 <- * <- 주소
	// & 주소 연산자: 주소 <- & <- 변수

	//////////////////////////////////////
	// 메모리 영역의 종류
	// 코드 메모리: 프로그램 명령어가 올라가는 영역
	// 정적 메모리: 정적 변수, 전역 변수 저장하는 영역
	// 스택 메모리: 지역 변수 , 매개변수, 리턴주소를 추적 (선입 후출 구조)
	// 힙 메모리:   함수의 수명보다 오래 유지되어야 하는 정보를 저장하는 영역 (런타임 시점, 동적 할당 후 해제 필요!	)
	//				이미지등 사이즈가 클 경우 무조건 힙 메모리에 올려야 한다
	////////////////////////////////////// 

	// 1) 포인터 자료형: 주소를 받는다
	int a = 10;
	int* ptrA = &a; // a 주소를 받아 포인터 자료형에 대입한다
	int** ptrB = &ptrA; // 이중 포인터

	cout << "a 주소: "		<< &a << endl;				// a 주소	(000000D6A8AFF704)
	cout << "a 주소: "		<< ptrA << endl;			// a 주소	(000000D6A8AFF704)
	cout << "a 값: "			<< *ptrA << endl;			// a 값		(10)
	cout << "ptrA 주소: "	<< &ptrA << endl;			// ptrA 주소	(000000D6A8AFF728)
	cout << "ptrA 주소: "	<< ptrB << endl;			// ptrA 주소	(000000D6A8AFF728)
	cout << "a 주소: "		<< *ptrB << endl;			// a 주소	(000000D6A8AFF704)
	cout << "ptrB 주소: "	<< &ptrB << endl << endl;	// ptrB 주소	(000000D6A8AFF748)


	// 2) 참조 자료형: 메모리를 공유 한다
	int b = 20;
	int& refB = b;

	cout << &b << endl;				// b 주소 (0000000544DDF794)
	cout << refB << endl;			// b 값   (20)
	// cout << *refB << endl;		// error
	cout << &refB << endl << endl;	// b 주소 (0000000544DDF794)


	// 3) const 한정자
	int c = 30;
	const int d = 30;				// 직접 참조, 값 변경 불가
	const int* ptrE = &c;			// 간접 참조, 값 변경 불가
	int* const ptrF = &c;			// 간접 참조, 주소 변경 불가


	// 4) 동적 할당 연산자
	// C++: new / delete (C: malloc, free)
	int* pNew = new int[10];
	delete[] pNew;

	// 2차원 배열 동적 할당
	int** pNewArr = new int*[10]; // row
	for (int i = 0; i < 10; i++)
	{
		pNewArr[i] = new int[10]; // col
	}
	
	delete[] pNewArr;
	///////////////////////////////////////
	*/


	/*
	///////// chapter8: 배열 /////////
	// 배열의 이름은 첫 요소에 대한 포인터
	// 컴파일러는 배열의 연속적인 메모리 위치를 할당 (제로 인덱스)
	// 배열이 전역에 선언할 경우 디폴트값: 0
	// 배열이 지역에 선언할 경우 디폴트값: 쓰레기값
	
	// 1차원 배열
	// int arr1[3] = { 0 };		// 0 초기화
	int arr1[3] = { 0,1,2 };	// 명시적 초기화

	// arr1[2] 는 *(arr1 + 2) 와 같다
	// &arr1[2] 는 arr1 + 2 와 같다
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter7: 구조체 객체 사용 /////////
	MyType custom;
	custom.i = 4;	// 구조체 객체 . 맴버 선택 연산자 사용하여 접근

	MyType* ptr = &custom;
	ptr->s = 2;		// 포인터 변수 -> 맴버 선택 연산자 사용하여 접근
	
	printf("%d\n", ptr->i);
	printf("%d\n", ptr->s);
	///////////////////////////////////////
	*/


	/*
	///////// chapter6: 정적 변수 /////////
	// 1) 함수 호출 방법: CallBy.cpp 파일 참조
	
	// 2) 정적 변수
	for (int i = 0; i < 5; i++)
	{
		static_test();
	}
	///////////////////////////////////////
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter5: do while문 /////////
	int num = 0;

	do
	{
		cout << "0~100" << endl;
		cin >> num;

	} while (num < 0 || num > 100); // 0보다 작거나 100보다 크다
	///////////////////////////////////////
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
	///////////////////////////////////////
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
	///////////////////////////////////////
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
	///////////////////////////////////////
	*/


	/*
	///////// chapter2: 문자형 /////////
	char first = 'A';	// 아스키 코드 사용
	char second = 65;	// 숫자도 사용 가능함
	char third = 'B';
	int count = 0;

	printf("%c\n", first);
	printf("%c\n", second);
	///////////////////////////////////////
	*/
}