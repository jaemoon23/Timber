#pragma once

class GameObject
{
protected:
	std::string name;	// ������Ʈ �̸�
	bool active;		// Ʈ���� ��쿡�� ������Ʈ�� ��ο츦 �Ϸ��� ����

	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;

	float rotaion;


public:

	virtual void Init();	// �ʱ�ȭ �Լ�
	virtual void Release(); // ���� �Լ�
	virtual void Reset();   // �ʱ���� �ǵ�����

	virtual void Update(float dt);
	virtual void Draw();
};

