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
    texIds.push_back("graphics/background.png");

    AddGameObject(new SpriteGo("graphics/background.png"));

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
