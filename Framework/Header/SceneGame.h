#pragma once

class Player;
class Tree;
class UiHub;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;
	UiHub* uiHud;
	int score;
	float timer = 0.f;
	float timerMax = 5.f;
	bool isPlaying = false;
	
public:
	SceneGame();
	~SceneGame() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};
