#include "Map.h"
#include <iostream>


Map::Map() : oneBox(sf::LineStrip, 5) {
	std::cout << "Map size: " << mapCoords.size() << "\n";
	font.loadFromFile("fonts/CGA.ttf");
	levelName.setFont(font);
	levelName.setPosition(sf::Vector2f(550, 250));
	levelName.setCharacterSize(27);
	mapCoords = {
		{1,0},
		{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},//1
		{1,6},{2,6},{3,6},{4,6},//2
		{4,5},{4,4},//3
		{5,4},{6,4},
		{6,5},{6,6},
		{7,6},{8,6},{9,6},{10,6},
		{10,5},{10,4},{10,3},{10,2},{10,1},//
					{11,3},{12,3},{13,3},
		{9,1},{8,1},{7,1},
		{7,0}
	};
	std::cout << "Map size: "<<mapCoords.size()<<"\n";
	createMap(0);
}

Map::~Map() {
}

void Map::createBox() {
	std::cout << "Map size: " << mapCoords.size() << "\n";
	for (auto & m : mapCoords) {
		oneBox[0].position = sf::Vector2f(550 + (50 * m.x), 300 + (50 * m.y));
		oneBox[1].position = sf::Vector2f(600 + (50 * m.x), 300 + (50 * m.y));
		oneBox[2].position = sf::Vector2f(600 + (50 * m.x), 350 + (50 * m.y));
		oneBox[3].position = sf::Vector2f(550 + (50 * m.x), 350 + (50 * m.y));
		oneBox[4].position = sf::Vector2f(550 + (50 * m.x), 300 + (50 * m.y));
		oneBox[0].color = sf::Color::Magenta;
		oneBox[1].color = sf::Color::Magenta;
		oneBox[2].color = sf::Color::Magenta;
		oneBox[3].color = sf::Color::Magenta;
		oneBox[4].color = sf::Color::Magenta;
		table.push_back(oneBox);
	}
}

void Map::createMap(int _level)  {
	levelName.setString("Level: "+std::to_string(_level));
	createBox();
}

void Map::DrawMap(sf::RenderWindow & _window) {
	for (auto& t : table)
		_window.draw(t);
	_window.draw(levelName);
}

sf::Vector2f Map::startPosition() {
	return sf::Vector2f(table[0].getBounds().left, table[0].getBounds().top+3);
}

bool Map::nextPosition(int _x, int _y) {
	//std::cout <<"NEXT POS: "<< _x << " - " << _y-3 << "\n";
	for (auto& t : table) {
		if (t.getBounds().left == _x && t.getBounds().top == _y-3)
			return true;
	}
}
