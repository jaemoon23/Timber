#include "stdafx.h"
#include "InputMgr.h"
#include "ResourceMgr.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ResourceMgr<sf::Texture>::Instance().Load(
        {
            "graphics/player.png" ,
            "graphics/axe.png" ,
            "graphics/bee.png" ,
            "graphics/branch.png" ,
            "graphics/cloud.png" ,
            "graphics/log.png" ,
            "graphics/rip.png" ,
            "graphics/tree.png"
        }
            );
    sf::Sprite sprite;
    sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));
    
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
        InputMgr::Update(0);

        if (InputMgr::GetKeyDown(sf::Keyboard::A)) 
        {
            std::cout << "Key Down: A" << std::endl;
        }
        if (InputMgr::GetKey(sf::Keyboard::B)) 
        {
            std::cout << "Key Held: B" << std::endl;
        }
        if (InputMgr::GetKeyUp(sf::Keyboard::A)) 
        {
            std::cout << "Key Up: A" << std::endl;
        }

        //Draw
        window.clear();

        
        window.draw(sprite);
        
        
        window.display();
        
    }

    return 0;
}