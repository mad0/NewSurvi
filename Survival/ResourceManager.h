#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <typeinfo>

namespace Textures {
	enum ID {Food, Potion, Weapon, Armor};
}
template <typename T>
class ResourceManager {
private:
	//static std::map<int, std::unique_ptr<T >> res;
public:
	ResourceManager();
	~ResourceManager();
	//template <typename T>
	void Load(int, const std::string&);
	//T& Get(int);
};

template<typename T>
inline ResourceManager<T>::ResourceManager() {
	std::cout << typeid(T).name();
	//Load<sf::Texture>(1, "fdfd");
}

template<typename T>
inline ResourceManager<T>::~ResourceManager() {
}

template<typename T>
inline void ResourceManager<T>::Load(int, const std::string &) {
	std::cout << typeid(T).name();
}
