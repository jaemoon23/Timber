#pragma once
#include "GameObject.h"
class SpriteGo : public GameObject
{protected:
	sf::Sprite sprite;
	std::string textureId;

public:

	SpriteGo(const std::string& texId = "", const std::string& name = "");
	virtual ~SpriteGo() = default;
	
	const std::string& GetTextureId() const { return textureId; }
	void SetTextureId(const std::string& texId) { textureId = texId; }

	void SetRotation(float rot) override; 
	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

