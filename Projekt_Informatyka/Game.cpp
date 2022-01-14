#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <fstream>

void Game::initBackground()
{
	if (!this->tloTexture.loadFromFile("Textures/tlo.jpg"))
	{
		std::cout << "Coudnt load image";
	}
	this->tloSprite.setTexture(this->tloTexture);
}

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

void Game::initSerca()
{
	this->sercaSpawnTimerMax = 250.f;
	this->sercaSpawnTimer = this->sercaSpawnTimerMax;
}

void Game::initPasekZycia()
{
	this->playerHpBar.setSize(sf::Vector2f(350.f, 30.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(800.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	this->koniecGry.setFont(this->font);
	this->koniecGry.setCharacterSize(80);
	this->koniecGry.setFillColor(sf::Color::White);
	this->koniecGry.setString("Game Over!");
	this->koniecGry.setPosition(sf::Vector2f(550.f,400.f));
}

void Game::save()
{
	saveStruct buffor;
	buffor.score = this->points;
	buffor.level = this->leveltype;
	std::ofstream stream("wyniki.txt", std::ios::app | std::ios::binary);
	stream.write((const char*)&buffor, sizeof(saveStruct));
	stream.close();
}

Game::Game(int* scena, sf::RenderWindow* window)
{
	this->window = window;
	this->initBackground();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
	this->initPasekZycia();
	this->initSerca();
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
	for (auto* i : this->serca)
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
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
			this->player->loseHp(10);
		}
		++counter;
	}

}

void Game::updateSerca()
{
	this->sercaSpawnTimer += 1.f;
	if (this->sercaSpawnTimer >= this->sercaSpawnTimerMax)
	{
		this->serca.push_back(new Serce(rand() % this->window->getSize().x - 20.f, -100.f));
		this->sercaSpawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* serce : this->serca)
	{
		serce->update();

		//serca culling (top of screen)
		if (serce->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->serca.at(counter);
			this->serca.erase(this->serca.begin() + counter);
		}
		else if (serce->getBounds().intersects(this->player->getBounds()))
		{
			delete this->serca.at(counter);
			this->serca.erase(this->serca.begin() + counter);
			--counter;
			this->player->gainHp(5);
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

void Game::updatePasekZycia()
{
	
	float procentZycia = (float)this->player->getHp() / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(350.f * procentZycia, this->playerHpBar.getSize().y));

}

void Game::start(int a)
{
	this->leveltype = a;
	this->points = 0;
	this->enemies.clear();
	this->serca.clear();
	switch (a)
	{
	case 1:
		this->spawnTimerMax = 120;
		break;
	case 2:
		this->spawnTimerMax = 10;
		break;
	
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

void Game::drawGUI()
{
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
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
	if (this->player->getHp() > 0)
	{
		player->update();
		kolizjaSciany();
		tworzeniePociskow();
		updatePociski();
		updateEnemies();
		updateSerca();
		updateKolizjaGraczPrzeciwnik();
		updatePasekZycia();
	}
}


void Game::draw(sf::RenderWindow& window)
{
	this->window->draw(this->tloSprite);

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
	for (auto* serce : this->serca)
	{
		serce->draw(window);
	}
	this->drawGUI();
	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->koniecGry);
		this->save();
	}
}
