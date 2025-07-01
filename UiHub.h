#pragma once
class UiHub : public GameObject
{
protected:
	sf::Text textScore;
	sf::Text textMessage;
	sf::RectangleShape timeBar;

	std::string fontId;
	bool isShowMessage;

	sf::Vector2f timeBarSize;

public:
	UiHub(const std::string& name = "");
	~UiHub() override = default;
	
	void SetScore(int score);
	void SetMessage(const std::string& msg);
	void SetShowMassage(bool show) { isShowMessage = show; };
	void SetTimeBar(float value);

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

