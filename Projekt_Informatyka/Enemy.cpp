#include "Enemy.h"
#include <iostream>

void Enemy::initZmienne()
{
	this->speed = 1;
}

void Enemy::initTekstura()
{
	//zaladowanie tekstury z pliku
	if (!this->texture.loadFromFile("Textures/przeciwnik.png"))
	{
		std::cout << "Coudnt load image";
	}
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->texture);
	//resize the sprite
	this->sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}



Enemy::Enemy(float pos_x, float pos_y)
{
	this->initZmienne();
	this->initTekstura();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
	
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

void Enemy::update()
{
	this->sprite.move(0.f,10.f);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
