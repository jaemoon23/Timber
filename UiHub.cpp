#include "stdafx.h"
#include "UiHub.h"

UiHub::UiHub(const std::string& name)
	: GameObject(name)
{
}

void UiHub::SetScore(int score)
{
	static std::string formatScore = "SCORE: ";
	textScore.setString(formatScore + std::to_string(score));
	Utils::SetOrigin(textScore, Origins::TL);
}

void UiHub::SetMessage(const std::string& msg)
{
	textMessage.setString(msg);
	Utils::SetOrigin(textMessage, Origins::MC);
}

void UiHub::SetTimeBar(float value)
{
	timeBar.setSize({ timeBarSize.x * value, timeBarSize.y });
}

void UiHub::Init()
{
	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	textScore.setCharacterSize(100);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(20, 20);

	textMessage.setCharacterSize(100);
	textMessage.setFillColor(sf::Color::White);
	textMessage.setPosition(bounds.width * 0.5f, bounds.height * 0.5f);

	timeBarSize = { 400.f, 80.f };
	timeBar.setFillColor(sf::Color::Red);
	timeBar.setSize(timeBarSize);

	Utils::SetOrigin(timeBar, Origins::BL);

	timeBar.setPosition(bounds.width * 0.5f - timeBarSize.x * 0.5f,
		bounds.height - 100.f);

}

void UiHub::Release()
{
}

void UiHub::Reset()
{
	textScore.setFont(FONT_MGR.Get(fontId));
	textMessage.setFont(FONT_MGR.Get(fontId));

	SetScore(0);
	isShowMessage = true;
	SetMessage("Message!");
	SetTimeBar(1.f);
}

void UiHub::Update(float dt)
{
}

void UiHub::Draw(sf::RenderWindow& window)
{
	window.draw(textScore);
	if (isShowMessage)
	{
		window.draw(textMessage);
	}
	window.draw(timeBar);
}
