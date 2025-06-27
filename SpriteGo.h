#pragma once
#include "GameObject.h"
class SpriteGo : public GameObject
{protected:
	sf::String sprite;

public:
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

