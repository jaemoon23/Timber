#include "stdafx.h"

void Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
	
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigins(rect.width, rect.height);
	newOrigins.x *= ((int)preset % 3) * 0.5f;
	newOrigins.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigins);
}