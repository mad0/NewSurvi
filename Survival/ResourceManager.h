#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures {
	enum ID {Food, Potion, Weapon, Armor};
}

class ResourceManager {
private:
	template <typename T>
	static std::map<int, T*> res;
public:
	ResourceManager();
	~ResourceManager();
	template<typename T>
	void Load(int, const std::string&);
	template<typename T>
	T& Get(int);
};

