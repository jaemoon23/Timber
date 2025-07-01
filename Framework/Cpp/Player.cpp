#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{

}

void Player::SetSide(Sides s)
{
	side = s;
	playerSprite.setPosition(position + positions[(int)side]);
	playerSprite.setScale(scales[(int)side]);

	axeSprite.setPosition(position + axePositions[(int)side]);
	axeSprite.setScale(axeScales[(int)side]);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	playerSprite.setPosition(position + positions[(int)side]);
	axeSprite.setPosition(position + axePositions[(int)side]);


}

void Player::SetIsAlive(bool b)
{
	isAlive = b;
	if (isAlive)
	{
		playerSprite.setTexture(TEXTURE_MGR.Get(playerTexId));
	}
	else
	{
		playerSprite.setTexture(TEXTURE_MGR.Get(ripTexId));
		playerSprite.setScale(1.f, 1.f);
		drawAxe = false;
	}
	Utils::SetOrigin(playerSprite, Origins::BC);
}


void Player::Init()
{
	playerTexId = "graphics/player.png";
	axeTexId = "graphics/axe.png";
	ripTexId = "graphics/rip.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f, 0.f };
	positions[(int)Sides::Right] = { 300.f, 0.f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f, 1.f };
	scales[(int)Sides::Right] = { 1.f, 1.f };

	axePositions.resize(2);
	axePositions[(int)Sides::Left] = { -180.f, -70.f };
	axePositions[(int)Sides::Right] = { 180.f, -70.f };

	axeScales.resize(2);
	axeScales[(int)Sides::Left] = { 1.f, 1.f };
	axeScales[(int)Sides::Right] = { -1.f, 1.f };
}

void Player::Release()
{
}

void Player::Reset()
{
	playerSprite.setTexture(TEXTURE_MGR.Get(playerTexId));
	Utils::SetOrigin(playerSprite, Origins::BC);
	/*SetSide(Sides::Right);*/

	axeSprite.setTexture(TEXTURE_MGR.Get(axeTexId));
	Utils::SetOrigin(axeSprite, Origins::MC);
	SetSide(Sides::Right);
}

void Player::Update(float dt)
{

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
	if (drawAxe)
	{
		window.draw(axeSprite);
	}
	
}
