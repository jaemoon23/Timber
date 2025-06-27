#pragma once

class GameObject
{
protected:
	std::string name;	// 오브젝트 이름
	bool active;		// 트루인 경우에만 업데이트와 드로우를 하려고 만듬

	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;

	float rotaion;


public:

	virtual void Init();	// 초기화 함수
	virtual void Release(); // 삭제 함수
	virtual void Reset();   // 초기상태 되돌리기

	virtual void Update(float dt);
	virtual void Draw();
};

