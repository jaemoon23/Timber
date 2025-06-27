#pragma once


class Utils
{
public:
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& text, Origins preset);
};