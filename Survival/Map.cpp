#include "Map.h"
#include <iostream>


Map::Map() : oneBox(sf::Quads, 4) {
	std::cout << "Map size: " << mapCoords.size() << "\n";
	font.loadFromFile("fonts/CGA.ttf");
	textures.loadFromFile("gfx/7.png");
	levelName.setFont(font);
	levelName.setPosition(sf::Vector2f(550, 260));
	levelName.setCharacterSize(27);
	mapCoords = { //15x10
		0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
		0,6,0,2,2,2,2,2,2,2,2,2,2,2,2,
		0,6,0,0,0,0,0,0,0,0,0,0,0,0,2,
		0,6,0,0,0,0,0,2,2,2,2,2,2,0,2,
		0,6,0,6,6,6,0,2,0,0,0,0,2,0,2,
		0,6,0,6,0,6,0,6,6,6,0,0,2,0,2,
		0,6,6,6,0,6,0,0,0,6,0,0,2,0,2,
		0,0,15,0,0,6,0,0,0,6,0,0,2,0,2,
		15,15,15,0,0,6,6,6,6,6,0,0,2,0,2,
		15,0,0,0,0,0,0,0,0,0,0,0,2,2,2
	};
	createMap(0);
}

Map::~Map() {
}

void Map::createBox() {
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 10; y++) {
			int textureNumber = mapCoords[x + (y * 15)];
			if (textureNumber > 0) {
				oneBox[0].position = sf::Vector2f(550 + (50 * x), 300 + (50 * y));
				oneBox[1].position = sf::Vector2f(600 + (50 * x), 300 + (50 * y));
				oneBox[2].position = sf::Vector2f(600 + (50 * x), 350 + (50 * y));
				oneBox[3].position = sf::Vector2f(550 + (50 * x), 350 + (50 * y));
				int tX = (textureNumber % 10)-1;
				int tY = (textureNumber / 10);
				std::cout << tX << " = " << tY << "\n";
				oneBox[0].texCoords = sf::Vector2f(tX*50, tY*50);
				oneBox[1].texCoords = sf::Vector2f((tX*50)+50, tY*50);
				oneBox[2].texCoords = sf::Vector2f((tX*50)+50, (tY*50)+50);
				oneBox[3].texCoords = sf::Vector2f(tX*50, (tY*50)+50);

				table.push_back(oneBox);
			}
		}
	}
	std::cout << "TABLE SIZE: " << table.size() << "\n";
}

void Map::createMap(int _level)  {
	levelName.setString("Level: "+std::to_string(_level));
	createBox();
}

void Map::DrawMap(sf::RenderWindow & _window) {
	for (auto& t : table)
		_window.draw(t, &textures);
	_window.draw(levelName);
}

sf::Vector2f Map::startPosition() {
	return sf::Vector2f(table[0].getBounds().left, table[0].getBounds().top+3);
}

bool Map::nextPosition(int _x, int _y) {
	//std::cout <<"NEXT POS: "<< _x << " - " << _y-3 << "\n";
	for (auto& t : table) {
		if (t.getBounds().left == _x && t.getBounds().top == _y - 3) {
			t[0].color = sf::Color(255,255,255, 230);
			t[1].color = sf::Color(255, 255,255,230);
			t[2].color = sf::Color(255, 255,255, 230);
			t[3].color = sf::Color(255, 255, 255, 230);
			return true;
		}	
	}
}
