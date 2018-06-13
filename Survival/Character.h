#pragma once
#include <SFML/Graphics.hpp>

class Character {
private:
	int hp;
	int _maxHP;
	int points;
	sf::Sprite player;
	sf::Texture playerTexture;
	std::vector<sf::Text> texts;
	sf::Font font;
	std::vector<std::string> strings;
public:
	Character();
	~Character();
	void setPosition(sf::Vector2f _pos);
	sf::Vector2f getPosition();
	void move(int _x, int _y);
	void update();
	void draw(sf::RenderWindow &_window);
};

