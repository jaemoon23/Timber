#include "stdafx.h"
#include "Framework.h"

void Framework::Init(int w, int h, const std::string& t)
{
	window.create(sf::VideoMode(w, h), t);

	TEXTURE_MGR.Load(texIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	InputMgr::Init();
	SCENE_MGR.Init();
	
}

void Framework::Do()
{
    
    Utils::Init();
    while (window.isOpen())
    {
        
        sf::Time dt = clock.restart();
        realDeltaTime = deltaTime = dt.asSeconds();
        deltaTime *= timeScale;
        time += deltaTime;
        realTime = realDeltaTime;

        InputMgr::Clear();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            InputMgr::UpdateEvent(event);
        } 
        
        //Update
        InputMgr::Update(deltaTime);
        SCENE_MGR.Update(deltaTime);
       
        //Drawb
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
        

       
    }
}

void Framework::Release()
{
	SCENE_MGR.Release();

	SOUNDBUFFER_MGR.Unload(soundIds);
	FONT_MGR.Unload(fontIds);
	TEXTURE_MGR.Unload(texIds);
}