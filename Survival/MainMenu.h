#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include <vector>
#include <memory>
#include "ResourceManager.h"

class MainMenu : public GameState {
private:
	std::vector<std::string> mTxt;
	sf::Sprite test;
	ResourceManager *textures;
public:
	MainMenu(Engine* _menu);
	~MainMenu();
	virtual void inputs();
	virtual void update();
	virtual void draw();
};
