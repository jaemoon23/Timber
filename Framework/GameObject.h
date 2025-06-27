#pragma once

class GameObject
{
protected:
	std::string name;	// 오브젝트 이름
	bool active;		// 트루인 경우에만 업데이트와 드로우를 하려고 만듬

	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;

	float rotation;


public:

	const std::string& GetName() const { return name; }
	void SetName(const std::string& n) { name = n; };

	bool getActive() const { return active; }
	virtual void setActive(bool a) { active = a; }
	
	float GetRotation() const { return rotation; }
	virtual void SetRotation(float rot) { rotation = rot; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetScale() const { return scale; }
	virtual void SetScale(const sf::Vector2f& s) { position = s; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(const sf::Vector2f& o){ origin = o; }


	GameObject(const std::string& name = "");
	virtual ~GameObject();

	virtual void Init() = 0;	// 초기화 함수
	virtual void Release() = 0; // 삭제 함수
	virtual void Reset() = 0;  // 초기상태 되돌리기

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0; // 레퍼런스로 받아야함
};

