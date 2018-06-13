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
	std::map<int, std::unique_ptr<T>> resources;
public:
	ResourceManager();
	~ResourceManager();
	void Load(int, const std::string&);
	//T& Get(int);
};
template <typename T>
inline ResourceManager<T>::ResourceManager() {

}

template<typename T>
inline ResourceManager<T>::~ResourceManager() {
}

template<typename T>
inline void ResourceManager<T>::Load(int _id, const std::string & _path) {
	//std::cout << typeid(T).name();
	auto newOne = std::make_unique<T>();
	newOne->loadFromFile(_path);
	resources.insert(std::make_pair(_id, std::move(newOne)));
	std::cout << typeid(resources[0]).name()<<"\n";
	//assert(inserted.second);
}
