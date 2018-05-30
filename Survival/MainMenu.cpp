#include <iostream>
#include "MainMenu.h"


MainMenu::MainMenu(Engine* _menu) {
	engine = _menu;
	sf::Vector2f position = static_cast<sf::Vector2f>(engine->window.getSize());
	std::cout << "Wchodze do menu...";
	textures = new ResourceManager();
	std::cout << "OUTSIDE "<<&(textures->getTexture(1)) << "\n";
	test.setTexture(textures->getTexture(1));
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
				//else if ((mItems[0]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
				//	engine->setState(new Game(engine));
				//}
				//else if ((mItems[2]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
					//engine->window.close();
			}
			//for (int x = 0; x < 3; x++) {
				//if (mItems[x]->GetSize().contains(mouse))
				//	mItems[x]->setColor(sf::Color::Red);
				//else
				//	mItems[x]->setColor(sf::Color::White);
			//}
}

void MainMenu::draw() {
	engine->window.clear(sf::Color::Black);
	engine->window.draw(test);
	engine->window.display();

	//rend->drawText();
	//for (auto& p : mItems)
	//	p->draw(engine->window);
}

void MainMenu::update() {

}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
