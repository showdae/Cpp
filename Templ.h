#pragma once

// ���ø� Ŭ������ "������ �ɹ�"�� "�ɹ� �Լ�" ��� ���ø��̿��� �Ѵ�

template <typename T> // ���ø� Ŭ����
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