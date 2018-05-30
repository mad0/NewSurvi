#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
	LoadTextures(1, "gfx/banana.png");
	LoadTextures(2, "gfx/dagger.png");
	std::cout << "Loaded textures: " << Textures.size() << "\n";
		std::cout << &(*Textures.at(1)) << "\n";
}


ResourceManager::~ResourceManager() {
	for (auto& t : Textures)
		delete t.second;
	Textures.clear();
}

void ResourceManager::LoadTextures(int _id, const std::string &_path){
	sf::Texture *newOne = new sf::Texture();
	newOne->loadFromFile(_path);
	Textures.insert(std::make_pair(_id, newOne));
}

sf::Texture * ResourceManager::getTexture(int _id) {
	for (auto& t : Textures) {
		if (t.first == _id)
			return t.second;
	}
}

