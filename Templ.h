#pragma once

// 템플릿 클래스는 "데이터 맴버"와 "맴버 함수" 모두 템플릿이여야 한다

template <typename T> // 템플릿 클래스
class CTempl
{
private:
	T data;

public:
	CTempl(T data);
	~CTempl();

	T get()const ;
	void set(T data);
};