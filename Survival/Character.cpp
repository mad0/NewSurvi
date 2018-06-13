#include "Character.h"
#include <iostream>
#include "Game.h"

Character::Character() {
	hp = 100;
	_maxHP = hp;
	points = 0;
	playerTexture.loadFromFile("gfx/player.png");
	player.setTexture(playerTexture);
	font.loadFromFile("fonts/CGA.ttf");
	strings = { "Points:", "Health points:" };
	texts.emplace_back(sf::Text(strings[0], font, 27));
	texts[0].setPosition(900, 260);
}

Character::~Character(){
}

void Character::setPosition(sf::Vector2f _pos){
	
	player.setPosition(_pos);
}

sf::Vector2f Character::getPosition() {
	return player.getPosition();
}

void Character::move(int _x, int _y){
	sf::Vector2f acctPos(player.getPosition());
	sf::Vector2f nextPos(acctPos.x + _x, acctPos.y + _y);
	//std::cout << acctPos.x << " " << acctPos.y << "\n";
	std::cout << nextPos.x << " " << nextPos.y << "\n";
	player.move(_x, _y);
}

void Character::update(){
	texts[0].setString(strings[0] + std::to_string(hp));
}

void Character::draw(sf::RenderWindow &_window){
	_window.draw(player);
	for (auto& t : texts)
		_window.draw(t);
}
