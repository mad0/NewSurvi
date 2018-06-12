#pragma once
#include "GameState.h"
#include "Map.h"
//class Engine;

class Game : public GameState {
private:
	Map mapa;
public:
	Game(Engine &engine);
	~Game();
	void inputs();
	void update();
	void draw();
};

