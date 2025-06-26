#pragma once


template <typename T>
class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	Singleton(const Singleton&) = delete;  // Ư���� �����ڸ� ����� ������ ����Ʈ�ϱ�
	Singleton& operator=(const Singleton&) = delete; 
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};