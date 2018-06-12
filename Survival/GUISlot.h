#pragma once
#include <SFML\Graphics.hpp>

class GUISlot {
private:
	bool empty;
	sf::RectangleShape slot;
	//Items *slotItem;
public:
	GUISlot();
	~GUISlot();
	void setPosition(int, int);
	void draw();
};

class GUISlot
{
public:
	GUISlot();
	~GUISlot();
};

