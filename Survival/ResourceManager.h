#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures {
	enum ID {Food, Potion, Weapon, Armor};
}

class ResourceManager {
private:
	template<typename T>
	static std::map<int, std::unique_ptr<T >> res;
public:
	ResourceManager();
	~ResourceManager();
	template<typename T>
	void Load(int, const std::string&);
	//T& Get(int);
};

