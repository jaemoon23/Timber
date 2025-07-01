#include "stdafx.h"
#include "Axe.h"

Axe::Axe(const std::string& name)
{
}
void Axe::SetSide(Sides s)
{

}
void Axe::SetPosition(const sf::Vector2f& pos)
{

}

void Axe::Init()
{
	texId = "graphics/axe.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f, 0.f };
	positions[(int)Sides::Right] = { 300.f, 0.f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f, 1.f };
	scales[(int)Sides::Right] = { 1.f, 1.f };
}

void Axe::Release()
{
}

void Axe::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));
	Utils::SetOrigin(sprite, Origins::MC);
	SetSide(Sides::Right);
}

void Axe::Update(float dt)
{
}

void Axe::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
