#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class ResourceManager {
private:
	std::map<int, sf::Texture*> Textures;
public:
	ResourceManager();
	~ResourceManager();
	void LoadTextures(int, const std::string&);
	sf::Texture* getTexture(int);
};

