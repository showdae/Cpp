//#ifndef Templ_CPP // ???
//#define Templ_CPP
#include "Templ.h"

template<typename T> // �ɹ� �Լ����� �ٿ������
CTempl<T>::CTempl(T _data)
	: data(_data) // ���ø��̶� ��� Ÿ���� �����͸� �ʱ�ȭ�� �� �ִ�
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