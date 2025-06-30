#include "stdafx.h"
#include "SceneDev2.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");
	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetText("Dev 2");
	go->SetSize(30);
	go->SetColor(sf::Color::White);
	go->SetPosition({ 960.f, 510 });
	go->SetOrigin(Origins::MC);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}
