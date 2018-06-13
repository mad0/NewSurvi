#pragma once
#include "GameState.h"
#include "Map.h"
#include "Character.h"

//class Engine;

class Game : public GameState {
private:
	enum Directions { UP, DOWN, LEFT, RIGHT };
	Map mapa;
	std::unique_ptr<Character> player;
public:
	Game(Engine &engine);
	~Game();
	void inputs();
	void update();
	void draw();
};

