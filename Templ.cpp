//#ifndef Templ_CPP // ???
//#define Templ_CPP
#include "Templ.h"

template<typename T> // 맴버 함수마다 붙여줘야함
CTempl<T>::CTempl(T _data)
	: data(_data) // 템플릿이라 모든 타입의 데이터를 초기화할 수 있다
{
}

template<typename T>
CTempl<T>::~CTempl()
{
}

template<typename T>
T CTempl<T>::get() const
{
	return data;
}

template<typename T>
void CTempl<T>::set(T _data)
{
	data = _data;
}

//#endif