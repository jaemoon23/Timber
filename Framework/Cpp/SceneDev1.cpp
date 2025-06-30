#include "stdafx.h"
#include "SceneDev1.h"

SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetText("Dev 1");
	go->SetSize(30);
	go->SetColor(sf::Color::White);
	go->SetPosition({ 960.f, 510.f });
	go->SetOrigin(Origins::MC);
	
	AddGameObject(go);
	Scene::Init();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
}
