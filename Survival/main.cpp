#include "Engine.h"
#include "MainMenu.h"
#include <iostream>
#//include "vld.h"

int main() {
	Engine start;
	start.setState(new MainMenu(&start));
	start.mainLoop();
return 0;
};