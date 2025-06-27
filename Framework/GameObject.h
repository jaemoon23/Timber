#pragma once

class GameObject
{
protected:
	std::string name;	// ������Ʈ �̸�
	bool active;		// Ʈ���� ��쿡�� ������Ʈ�� ��ο츦 �Ϸ��� ����

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

	virtual void Init() = 0;	// �ʱ�ȭ �Լ�
	virtual void Release() = 0; // ���� �Լ�
	virtual void Reset() = 0;  // �ʱ���� �ǵ�����

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0; // ���۷����� �޾ƾ���
};

