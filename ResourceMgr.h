#pragma once
#include <unordered_map>
#include <string>
#include "Singleton.h" 

template <typename T>

class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;

protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;

	std::unordered_map<std::string, T*> resources;

	static T Empty;

public:
	bool Load(const std::string& id)
	{
		auto it = resources.find(id);
		if (it != resources.end()) // ���� ã���� ������
		{
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(id);
		if (!success)
		{
			return false;
		}

		resources.insert({id, res}); // map�� �����ϴ°�
		return true;
	}

	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end()) // ���� ã���� ������
		{
			return false;
		}

		// map �����ϴ°�
		delete it->secand;
		resources.erase(it);
		return true;
	}

	T& Get(const std::string& id)
	{
		// find �Լ��� key�� ������ ���� ã���� ����
		auto it = resources.find(id);
		if (it == resources.end()) // ���� ã���� ������
		{
			return Empty;
		}
		return *(it->second);
	}
};
template<typename T>
T ResourceMgr<T>::Empty;
