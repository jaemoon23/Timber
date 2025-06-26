#include <algorithm>
#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::upKeys;

std::vector<int> InputMgr::downKeysVec(sf::Keyboard::KeyCount);
std::vector<int> InputMgr::heldKeysVec(sf::Keyboard::KeyCount);
std::vector<int> InputMgr::upKeysVec(sf::Keyboard::KeyCount);

void InputMgr::Init()
{

}
void InputMgr::Clear() 
{
	downKeys.clear();
	upKeys.clear();
	downKeysVec.assign(downKeysVec.size(), 0);
	upKeysVec.assign(downKeysVec.size(), 0);
}

void InputMgr::UpdateEvent(const sf::Event& ev) 
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:

		if (!Contains(heldKeys, ev.key.code))
		{
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
			downKeysVec[ev.key.code] = 1;
			heldKeysVec[ev.key.code] = 1;
		}
		break;

	case sf::Event::KeyReleased:

		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
		if (Contains(heldKeys, ev.key.code))
		{
			upKeysVec[ev.key.code] = 1;
			heldKeysVec[ev.key.code] = 0;
		}
		break;
	
	default:
	
		break;		
	}
}
void InputMgr::Update(float dt) 
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key) 
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key) 
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key) 
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

bool InputMgr::Contains(const std::vector<int>& vector, sf::Keyboard::Key key)
{
	// find �Լ��� �����̳� �������� ���� ã���ش� 1, 2��° �Ű������� ã�� ���� 3��°�� ã�� ��
	// ���ͷ����ͷ� ����
	
	return vector[key];
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
