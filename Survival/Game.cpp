#include "Game.h"
#include <random>

Game::Game(Engine &_engine) : mapa() {
	engine = &_engine;
	player = std::make_unique<Character>();
	player->setPosition(mapa.startPosition());
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
			
		if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Up)) {
			if (mapa.nextPosition(player->getPosition().x, player->getPosition().y-50) == true)
				player->move(0, -50);
		}
		if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Down)) {
			if (mapa.nextPosition(player->getPosition().x, player->getPosition().y +50) == true)
				player->move(0, 50);
		}
		if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Left)) {
			if (mapa.nextPosition(player->getPosition().x-50, player->getPosition().y) == true)
				player->move(-50, 0);
		}
		if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Right)) {
			if (mapa.nextPosition(player->getPosition().x+50, player->getPosition().y) == true)
				player->move(50, 0);
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
	//player->setPosition(mapa.startPosition());
	//player->update();
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
	player->draw(engine->window);
	engine->window.display();
}
