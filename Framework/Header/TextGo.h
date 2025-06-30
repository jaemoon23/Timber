#pragma once
#include "GameObject.h"


class TextGo : public GameObject
{
protected:
    sf::Text text;
    int size;
    sf::Color color = color.White;
    std::string FontId;

public:
    // GameObject을(를) 통해 상속됨
    TextGo(const std::string& texId = "", const std::string& name = "", int size = 100);
    ~TextGo() override = default;

    void SetPosition(const sf::Vector2f& pos) override;
    void SetScale(const sf::Vector2f& s) override;
    void SetRotation(float rot) override;
    void SetOrigin(const sf::Vector2f& o) override;

    void SetOrigin(Origins preset) override;
    void SetSize(int size);
    void SetColor(sf::Color color);
    void SetText(std::string message);

    //set origin
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

