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
		if (it != resources.end()) // 값을 찾을수 없을때
		{
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(id);
		if (!success)
		{
			return false;
		}

		resources.insert({id, res}); // map에 삽입하는거
		return true;
	}

	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end()) // 값을 찾을수 없을때
		{
			return false;
		}

		// map 삭제하는거
		delete it->secand;
		resources.erase(it);
		return true;
	}

	T& Get(const std::string& id)
	{
		// find 함수에 key를 넣으면 값을 찾을수 있음
		auto it = resources.find(id);
		if (it == resources.end()) // 값을 찾을수 없을때
		{
			return Empty;
		}
		return *(it->second);
	}
};
template<typename T>
T ResourceMgr<T>::Empty;
