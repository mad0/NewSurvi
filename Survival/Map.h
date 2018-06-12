#pragma once
#include <SFML\Graphics.hpp>

class Map {
private:
	sf::VertexArray oneBox;;
	std::vector<sf::VertexArray> table;
	void createBox(int _pos);
public:
	Map();
	~Map();
	void createMap();
	void DrawMap(sf::RenderWindow & _window);
};

