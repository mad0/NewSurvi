#include "Map.h"
#include <iostream>


Map::Map() : oneBox(sf::LineStrip, 5) {
	createMap();
}


Map::~Map() {
}

void Map::createBox(int _pos) {
	oneBox[0].position = sf::Vector2f(550, 300);
	oneBox[1].position = sf::Vector2f(600+(50*_pos), 300);
	oneBox[2].position = sf::Vector2f(600 + (50 * _pos), 350 + (50 * _pos));
	oneBox[3].position = sf::Vector2f(550, 350 + (50 * _pos));
	oneBox[4].position = sf::Vector2f(550, 300);
	oneBox[0].color = sf::Color::Green;
	oneBox[1].color = sf::Color::Green;
	oneBox[2].color = sf::Color::Green;
	oneBox[3].color = sf::Color::Green;
	oneBox[4].color = sf::Color::Green;
	table.push_back(oneBox);
}

void Map::createMap()  {
	createBox(0);
	createBox(1);
	createBox(2);
	createBox(3);
	std::cout << table.size() << "\n";
}


void Map::DrawMap(sf::RenderWindow & _window) {
	for (auto& t : table)
		_window.draw(t);
}
