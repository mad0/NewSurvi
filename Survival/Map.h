#pragma once
#include <SFML\Graphics.hpp>

class Map {
private:
	sf::VertexArray oneBox;
	std::vector<sf::VertexArray> table;
	std::vector<int> mapCoords;
	sf::Texture textures;
	void createBox();
	sf::Text levelName;
	sf::Font font;
public:
	Map();
	~Map();
	void createMap(int _level);
	void DrawMap(sf::RenderWindow & _window);
	sf::Vector2f startPosition();
	bool nextPosition(int _x, int _y);
};

