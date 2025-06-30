#include "stdafx.h"
#include "TextGo.h"


TextGo::TextGo(const std::string& texId, const std::string& name, int size)
	:GameObject(name), FontId(texId), size(size)
{
}

void TextGo::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	text.setPosition(position);
}

void TextGo::SetScale(const sf::Vector2f& s)
{
	scale = s;
	text.setScale(scale);
}

void TextGo::SetRotation(float rot)
{
	rotation = rot;
	text.setRotation(rotation);
}

void TextGo::SetOrigin(const sf::Vector2f& o)
{
	originPreset = Origins::Custom;
	origin = o;
	text.setOrigin(origin);
}

void TextGo::SetOrigin(Origins preset)
{
	originPreset = preset;

	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(text, originPreset);
	}
}

void TextGo::SetSize(int s)
{
	size = s;
	text.setCharacterSize(size);
	SetOrigin(originPreset);
}

void TextGo::SetColor(sf::Color color)
{
	text.setFillColor(color);
}

void TextGo::SetText(std::string message)
{
	text.setString(message);
	SetOrigin(originPreset);
}


void TextGo::Init()
{
}

void TextGo::Release()
{

}

void TextGo::Reset()
{
	text.setFont(FONT_MGR.Get(FontId));    // 폰트 설정
	Utils::SetOrigin(text, originPreset);
	SetSize(size);
}

void TextGo::Update(float dt)
{
}

void TextGo::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(text);
	}
}