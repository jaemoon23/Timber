#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds Id)
    : Id(Id)
{

}
void Scene::Init()
{
    for (auto obj : gameObjects)
    {
        obj->Init();
    }
}

void Scene::Release()
{
    for (auto obj : gameObjects)
    {
        obj->Release();
        delete obj;     // 동적할당 되어 있어서 딜리트
    }
    gameObjects.clear(); // 리스트 비우기
}

void Scene::Enter()
{
    TEXTURE_MGR.Load(texIds);
    FONT_MGR.Load(fontIds);
    SOUNDBUFFER_MGR.Load(soundIds);

    for (auto obj : gameObjects)
    {
        obj->Reset();
    }
}

void Scene::Exit()
{
    TEXTURE_MGR.Unload(texIds);
    FONT_MGR.Unload(fontIds);
    SOUNDBUFFER_MGR.Unload(soundIds);
}

void Scene::Update(float dt)
{
    for (auto obj : gameObjects)
    {
        obj->Update(dt);
    }
}

void Scene::Draw(sf::RenderWindow& window)
{
    for (auto obj : gameObjects)
    {
        obj->Draw(window);
    }
}

void Scene::AddGameObject(GameObject* go)
{
    if (std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end())
    {
        gameObjects.push_back(go); // 추가하기
    }
    
}

void Scene::RemoveGameObject(GameObject* go)
{
    gameObjects.remove(go); // 지우기
}

GameObject* Scene::FindGameObject(const std::string& name)
{
    for (auto obj : gameObjects)
    {
        if (obj->GetName() == name)
        {
            return obj;
        }
    }
    return nullptr;
}
