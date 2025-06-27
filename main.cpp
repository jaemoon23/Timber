#include "stdafx.h"
#include "SpriteGo.h"
#include "TextGo.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "TIMBER");

    TEXTURE_MGR.Load({
        "graphics/player.png",
        "graphics/axe.png",
        "graphics/bee.png",
        "graphics/branch.png",
        "graphics/cloud.png",
        "graphics/log.png",
        "graphics/rip.png",
        "graphics/tree.png"
    });

    FONT_MGR.Load(
        "fonts/KOMIKAP_.ttf"
    );

    SpriteGo spriteGo("graphics/player.png");
    spriteGo.Init();
    spriteGo.Reset();
    spriteGo.SetOrigin(Origins::MC);
    
    TextGo testText("fonts/KOMIKAP_.ttf");
    
    testText.Init();
    testText.Reset();
    testText.SetText("hello world");
    testText.SetOrigin(Origins::MC);
    sf::Vector2f vec = { 1280.f * 0.5f, 720.f * 0.5f };
    testText.SetPosition(vec);
    testText.SetColor(sf::Color::White);



    while (window.isOpen()) 
    {
        sf::Event event;

        InputMgr::Clear();

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

            InputMgr::UpdateEvent(event);
        }

        //Update
        InputMgr::Update(0.0f);
        spriteGo.Update(0.0f);

        //Draw
        window.clear();

        spriteGo.Draw(window);
        testText.Draw(window);

        window.display();
    }

    spriteGo.Release();
    testText.Release();

    return 0;
}