#include "Game.h"
#include <random>

Game::Game(Engine &_engine) : mapa() {
	engine = &_engine;
}

Game::~Game() {
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(engine->window));
	while (engine->window.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			engine->window.close();
		else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::Q)) {
			//engine->delState();
		}
		else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::N)) {

		}
		//else if ((menuText[0].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
		//	engine->setState(new Game(*engine));
		//	std::cout << "DUPA\n";
		//}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		engine->delState();
}

void Game::update() {
	//std::random_device random;
	//std::mt19937_64 mt(random());
	//std::uniform_int_distribution<>rnd(1, 1280);
	//for (int x = 0; x < 20; x++) {
	//	tablica[x].position = sf::Vector2f(rnd(mt), rnd(mt));
	//}
	
}

void Game::draw() {
	engine->window.clear();
	mapa.DrawMap(engine->window);
	engine->window.display();
}
