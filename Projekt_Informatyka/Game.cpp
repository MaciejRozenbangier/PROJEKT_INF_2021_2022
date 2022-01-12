#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Asteroids gone wrong", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{

}




Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initPlayer();

}
Game::~Game()
{
	delete this->window;
	delete this->player;

}



void Game::initPlayer()
{
	this->player = new Player();
}


void Game::run()
{
	while (window->isOpen())
	{
		this->update();
		this->render();
	}
}




void Game::updateMenu()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		
		if(sfEvent.type == sf::Event::Closed)
			this->window->close();

		switch (widok)
		{
		case 0:
			menu.update_sterowanie(sfEvent);
			break;
		case 1:
			menuLevels.update_sterowanie(sfEvent);
			break;
		case 2:
			
			update_sterowanie();
			break;
		}		
	}
}



void Game::updateMoving()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
}







void Game::update()
{

	this->updateMenu();
	
	//this->updateMoving();
}

void Game::rysowanieRozgrywki()
{
	this->player->render(*this->window);
}


void Game::render()
{
	this->window->clear();

	//rendering
	//Draw open menu

	switch (widok)
	{
		//this->renderBackground();
	case 0:
		menu.draw(*window);
		break;
	case 1:
		menuLevels.draw(*window);
		break;
	case 2:
		rysowanieRozgrywki();
		break;
	}

	//draw game level

	this->window->display();
}

void Game::update_sterowanie()
{
	//this->updateMoving();
}


