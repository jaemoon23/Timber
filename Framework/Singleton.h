#pragma once


template <typename T>
class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	Singleton(const Singleton&) = delete;  // 특정한 생성자를 지우고 싶으면 딜리트하기
	Singleton& operator=(const Singleton&) = delete; 
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};