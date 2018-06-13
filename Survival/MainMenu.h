#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include <vector>
#include <memory>
#include "ResourceManager.h"

class MainMenu : public GameState {
private:
	std::vector<std::string> menuString;
	std::vector<sf::Text> menuText;
	sf::Font menuFont;
public:
	MainMenu(Engine &_menu);
	~MainMenu();
	virtual void inputs();
	virtual void update();
	virtual void draw();
};
