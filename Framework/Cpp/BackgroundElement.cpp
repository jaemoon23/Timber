#include "stdafx.h"
#include "BackgroundElement.h"
#include "Player.h"

BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name, Elements element)
	: SpriteGo(texId, name), element(element)
{
}



void BackgroundElement::SetSide(Sides side)
{
	if (element == Elements::Bee)
	{
		BeeSide(side);
	}
	else if (element == Elements::Cloud)
	{
		CloudSide(side);
	}
	
}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	if (element == Elements::Bee)
	{
		SetOrigin(Origins::MC);
		SetSide((Sides)Utils::RandomRange(0, 2));
		SetPosition({ 500.f, Utils::RandomRange(800.f, 50.f) });
	}
	else if (element == Elements::Cloud)
	{
		SetOrigin(Origins::MC);
		SetSide((Sides)Utils::RandomRange(0, 2));
		SetPosition({ Utils::RandomRange(100.f, 1050.f), Utils::RandomRange(100.f, 450.f) });
	}
	
}

void BackgroundElement::Update(float dt)
{
	if (element == Elements::Bee)
	{
		BeeUpdate(dt);
	}
	else if (element == Elements::Cloud)
	{
		CloudUpdate(dt);
	}
}

void BackgroundElement::BeeSide(Sides side)
{
	float scale = Utils::RandomRange(0.5f, 2.0f);
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	switch (side)
	{
	case Sides::Left:
		direction = { 1.f,0.f };
		SetScale({ -1.f,1.f });
		SetPosition({ -150.f, Utils::RandomRange(800.f, 850.f) });
		break;
	case Sides::Right:
		direction = { -1.f,0.f };
		SetScale({ 1.f,1.f });
		SetPosition({ bounds.width + 150.f, Utils::RandomRange(800.f, 850.f) });
		break;

	default:
		break;
	}
}

void BackgroundElement::BeeUpdate(float dt)
{

	auto pos = GetPosition();
	float rd = pos.x * 3.14f / 180;
	pos += direction * Utils::RandomRange(400.f, 201.f) * dt;
	pos.y = (sin(rd) * 50) + 800;

	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		float random = Utils::RandomValue();
		if (random < 0.5f)
		{
			SetSide(Sides::Right);
		}
		else if (random > 0.5f)
		{
			SetSide(Sides::Left);
		}
	}
}

void BackgroundElement::CloudSide(Sides side)
{
	float scale = Utils::RandomRange(0.5f, 2.0f);
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	switch (side)
	{
	case Sides::Left:
		direction = { 1.f,0.f };
		SetScale({ -scale,scale });
		SetPosition({ -150.f, Utils::RandomRange(100.f, 400.f) });
		break;
	case Sides::Right:
		direction = { -1.f,0.f };
		SetScale({ scale,scale });
		SetPosition({ bounds.width + 150.f, Utils::RandomRange(100.f, 400.f) });
		break;

	default:
		break;
	}
}

void BackgroundElement::CloudUpdate(float dt)
{
	auto pos = GetPosition();
	pos += direction * Utils::RandomRange(400.f, 201.f) * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		float random = Utils::RandomValue();
		if (random < 0.5f)
		{
			SetSide(Sides::Right);
		}
		else if (random > 0.5f)
		{
			SetSide(Sides::Left);
		}
	}
}
