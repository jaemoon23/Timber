#pragma once


class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;
	static std::list<sf::Keyboard::Key> upKeys;

	static std::vector<int> downKeysVec;
	static std::vector<int> heldKeysVec;
	static std::vector<int> upKeysVec;

public:
	static void Init();
	static void Clear();

	

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);

	static bool Contains(const std::vector<int>& vector, sf::Keyboard::Key key);
	//static void Remove(std::vector<int>& list, sf::Keyboard::Key key);

};

