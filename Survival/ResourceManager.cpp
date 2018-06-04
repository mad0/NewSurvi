#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
	Load<sf::Texture>(1, "gfx/banana.png");
	Load<sf::Texture>(2, "gfx/dagger.png");
	//std::cout << "Loaded textures: " << Resources.size() << "\n";
	//std::cout << &(*Textures.at(2))<< "\n";
}

ResourceManager::~ResourceManager() {
	
}
template<typename T>
void ResourceManager::Load(int _id, const std::string &_path){
	//auto newOne = std::make_unique<T>(T());
	T *newOne = new T();
	newOne->loadFromFile(_path);
	//res.insert(std::make_pair(_id, std::move(newOne)));
	res.insert(_id, <T>newOne);
}

template<typename T>
T& ResourceManager::Get(int _id) {
		return *res.at(_id);
}

