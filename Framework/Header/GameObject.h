#pragma once


class GameObject
{
protected:
	std::string name;
	bool active;

	sf::Vector2f position;
	float rotation = 0.f;
	sf::Vector2f scale;
	sf::Vector2f origin;

	Origins originPreset = Origins::TL;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();


	const std::string& GetName() { return name; }
	void SetName(const std::string& n) { name = n; }

	bool GetActive() const { return active; }
	virtual void SetActive(bool a) { active = a; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetScale() const { return scale; }
	virtual void SetScale(const sf::Vector2f& s) { scale = s; }

	float GetRotation() const { return rotation; }
	virtual void SetRotation(float rot) { rotation = rot; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(const sf::Vector2f& o) { origin = o; }
	virtual void SetOrigin(Origins preset) { originPreset = preset; }

	virtual void Init() = 0;    // 초기화
	virtual void Release() = 0; // 삭제
	virtual void Reset() = 0;   // 초기 상태로 되돌리기
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};