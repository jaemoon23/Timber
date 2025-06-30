#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{

}
SceneGame::~SceneGame()
{

}

void SceneGame::Init()
{
    texIds.push_back("graphics/player.png");
    fontIds.push_back("fonts/KOMIKAP_.ttf");

    SpriteGo* spriteGo = new SpriteGo("graphics/player.png");
    spriteGo->SetOrigin(Origins::MC);

    sf::Vector2f vec = { 1980.f * 0.5f, 1020.f * 0.5f };
    TextGo* textGo = new TextGo("fonts/KOMIKAP_.ttf");
    
    textGo->SetText("hello world");
    textGo->SetOrigin(Origins::MC);
    textGo->SetColor(sf::Color::White);
    textGo->SetPosition(vec);
    
    AddGameObject(spriteGo);
    AddGameObject(textGo);

    Scene::Init();
    
}

void SceneGame::Enter()
{
    Scene::Enter();
}

void SceneGame::Exit()
{
    Scene::Exit();
}
