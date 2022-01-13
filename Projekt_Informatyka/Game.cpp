#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"


void Game::initPlayer()
{
	this->player = new Player();

}

void Game::initTextures()
{
	this->textures["POCISK"] = new sf::Texture();
	this->textures["POCISK"]->loadFromFile("Textures/pocisk.png");
	
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;

}

Game::Game(int* scena, sf::RenderWindow* window)
{
	this->window = window;
	this->initPlayer();
	this->initTextures();
	this->initEnemies();

}

Game::~Game()
{
	delete this->player;

	for (auto& i : this->textures)
	{
		delete i.second;
	}
	for (auto* i : this->pociski)
	{
		delete i;
	}
	for (auto* i : this->enemies)
	{
		delete i;
	}
}

void Game::tworzeniePociskow()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && this->player->mozeAtakowac())
	{
		this->pociski.push_back(new Pocisk(this->textures["POCISK"], this->player->getPos().x + this->player->getBounds().width / 2.35f, this->player->getPos().y - this->player->getBounds().height / 2.5f, 0.f, -1.f, 10.f));
	}
}

void Game::updatePociski()
{
	unsigned counter = 0;
	for (auto* pocisk : this->pociski)
	{
		pocisk->update();

		//Bullet culling (top of screen)
		if (pocisk->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->pociski.at(counter);
			this->pociski.erase(this->pociski.begin() + counter);
			--counter;
			//std::cout << this->pociski.size() << std::endl;
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	this->spawnTimer += 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			//this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}

}

void Game::updateKolizjaGraczPrzeciwnik()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->pociski.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->pociski[k]->getBounds())|| this->enemies[i]->getBounds().intersects(this->player->getBounds()))
			{
				//this->points += this->enemies[i]->getPoints();
				this->points += this->enemies[i]->getPoints();
				this->punkty.setPoints(this->points);
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->pociski[k];
				this->pociski.erase(this->pociski.begin() + k);

				enemy_deleted = true;
			}
		}
	}

}


void Game::kolizjaSciany()
{
	//lewo
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//prawo
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	//gora
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	//dol
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}

}

void Game::onEvent(sf::Event e)
{
	
	switch (e.type)
	{
	case sf::Event::KeyPressed:
		if (e.key.code == sf::Keyboard::Key::Escape)
			
		if (e.key.code == sf::Keyboard::Key::F1)
			std::cout << "Pomoc";
	}
}

void Game::update()
{
	player->update();
	kolizjaSciany();
	tworzeniePociskow();
	updatePociski();
	updateEnemies();
	updateKolizjaGraczPrzeciwnik();

}


void Game::draw(sf::RenderWindow& window)
{
	player->draw(window);
	for (auto* enemy : this->enemies)
	{
		enemy->draw(window);
	}
	punkty.draw(window);

	for (auto* bullet : this->pociski)
	{
		bullet->draw(*this->window);
	}

}
