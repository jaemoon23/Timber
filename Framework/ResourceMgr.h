#pragma once
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
		auto it = resources.find(id); // �� ã�ƺ��� ģ�� ������ end��ȯ
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
	void Load(const std::vector<std::string>& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			Load(str[i]);
		}
	}

	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end()) // ���� ã���� ������
		{
			return false;
		}

		// map �����ϴ°�
		delete it->second;
		resources.erase(it);
		return true;
	}
	void Unload(const std::vector<std::string>& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			Unload(str[i]);
		}
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


#define TEXTURE_MGR (ResourceMgr<sf::Texture>::Instance())
#define FONT_MGR (ResourceMgr<sf::Font>::Instance())
#define SOUNDBUFFER_MGR (ResourceMgr<sf::SoundBuffer>::Instance())


