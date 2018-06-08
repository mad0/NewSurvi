#include <iostream>
#include "MainMenu.h"


MainMenu::MainMenu(Engine &_menu)  {
	engine = &_menu;
	sf::Vector2f position = static_cast<sf::Vector2f>(engine->window.getSize());
	std::cout << "Wchodze do menu...\n";
	menuFont.loadFromFile("fonts/Game2.ttf");
	menuString = { "NEW", "OPTIONS", "EXIT" };
	for (int x=0;x<menuString.size();x++) {
		menuText.emplace_back(sf::Text(menuString[x], menuFont, 15));
		menuText[x].setPosition(position.x / 2 - menuText[x].getGlobalBounds().width / 2, position.y / 4 + x * 130);
	}
		
	//resources = std::move(std::make_unique<ResourceManager>());
	//resources->Load<sf::Texture>(1, "gfx/banana.png");
	//ResourceManager<sf::Texture> res;
	//textures.Load(1, "gfx/banana.png");
	//ResourceManager <sf::Font>texts;
	//texts.Load(1, "fdfdfd");
	//std::cout << "OUTSIDE "<<&(resources->getTexture(2))<< "\n";
	//test.setTexture(resources.Get(1));
}

void MainMenu::inputs() {
		sf::Event zdarz;
		sf::Vector2f mouse(sf::Mouse::getPosition(engine->window));
			while (engine->window.pollEvent(zdarz)) {
				if (zdarz.type == sf::Event::Closed)
					engine->window.close();
				else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::Q)) {
					engine->window.close();
				}
				else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::N)) {
	
				}
				else if ((menuText[0].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
					//engine->setState(new Game(engine));
					std::cout << "DUPA\n";
				}
				else if ((menuText[2].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
					engine->window.close();
			}
			for (auto& m : menuText) {
				if (m.getGlobalBounds().contains(mouse))
					m.setFillColor(sf::Color::Red);
				else
					m.setFillColor(sf::Color::White);
			}
}

void MainMenu::draw() {
	engine->window.clear(sf::Color::Black);
	for (const auto& m : menuText)
		engine->window.draw(m);
	engine->window.display();
}

void MainMenu::update() {

}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
