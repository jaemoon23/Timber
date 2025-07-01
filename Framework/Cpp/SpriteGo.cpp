#include "stdafx.h"
#include "SpriteGo.h"


SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	:GameObject(name), textureId(texId)
{
}

void SpriteGo::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position);
}

void SpriteGo::SetScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);
}

void SpriteGo::SetRotation(float rot)
{
	rotation = rot;
	sprite.setRotation(rotation);
}

void SpriteGo::SetOrigin(const sf::Vector2f& o)
{
	originPreset = Origins::Custom;
	origin = o;
	sprite.setOrigin(origin);
}

void SpriteGo::SetOrigin(Origins preset)
{
	originPreset = preset;

	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(sprite, originPreset);
	}
}

void SpriteGo::Init()
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	Utils::SetOrigin(sprite, originPreset);
}

void SpriteGo::Update(float dt)
{
	
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(sprite);
	}
}