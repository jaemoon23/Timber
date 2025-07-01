#pragma once
#include "GameObject.h"
class Player : public GameObject
{
protected:
	
	bool drawAxe = false;
	bool isAlive = true;
	sf::Sprite playerSprite;
	sf::Sprite axeSprite;
	SceneGame* game = nullptr;
	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> axePositions;
	std::vector<sf::Vector2f> scales;
	std::vector<sf::Vector2f> axeScales;

	std::string playerTexId;
	std::string axeTexId;
	std::string ripTexId;

public:
	Player(const std::string& name = "");
	~Player() override = default;
	void SetSide(Sides s);
	Sides GetSide() const { return side; };
	

	void SetPosition(const sf::Vector2f& pos) override;

	void SetDrawAxe(bool b) { drawAxe = b; };
	void SetIsAlive(bool b);
	void Die();


	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

