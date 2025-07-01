#pragma once
class BackgroundElement :public SpriteGo
{
protected:
	
	// ������ ���⿡ �����ؼ� Get Set ��������
public:
	Elements element;
	BackgroundElement(const std::string& texId = "", const std::string& name = "", Elements element = Elements::Cloud);
	

	float speed = 0.f;
	sf::Vector2f direction;
	void SetSide(Sides side);

	void Reset() override;
	void Update(float dt) override;
	void BeeSide(Sides side);
	void BeeUpdate(float dt);
	void CloudSide(Sides side);
	void CloudUpdate(float dt);
	
};

