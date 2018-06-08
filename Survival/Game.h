#pragma once
#include "GameState.h"

//class Engine;

class Game : public GameState {
public:
	Game(Engine &engine);
	~Game();
	void input();
	void update();
	void draw();
};

