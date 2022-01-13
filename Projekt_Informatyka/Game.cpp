#include "Game.h"

#include "SFML/Graphics.hpp"

void Game::initPlayer()
{
	this->player = new Player();

}

Game::Game(int* scena)
{
	this->initPlayer();

}

Game::~Game()
{
	delete this->player;
}

void Game::onEvent(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::KeyPressed:
		if (e.key.code == sf::Keyboard::Key::Escape)
			std::cout << "Wyjscie z gry";
		if (e.key.code == sf::Keyboard::Key::F1)
			std::cout << "Pomoc";
	}
}

void Game::update()
{
	player->update();

}


void Game::draw(sf::RenderWindow& window)
{
	player->draw(window);

}
