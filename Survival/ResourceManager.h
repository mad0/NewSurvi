#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures {
	enum ID {Food, Potion, Weapon, Armor};
}
template <typename T>
class ResourceManager {
private:
	static std::map<int, std::unique_ptr<T >> res;
public:
	ResourceManager();
	~ResourceManager();
	void Load(int, const std::string&);
	//T& Get(int);
};

