#include <algorithm>
#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::upKeys;

void InputMgr::Init()
{

}
void InputMgr::Clear() 
{
	downKeys.clear();
	upKeys.clear();
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
		}
		break;

	case sf::Event::KeyReleased:
		
		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
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
	// find 함수가 컨테이너 범위에서 값을 찾아준다 1, 2번째 매개변수가 찾을 범위 3번째가 찾을 값
	// 이터레이터로 받음
	return std::find(list.begin(), list.end(), key) != list.end();  
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
