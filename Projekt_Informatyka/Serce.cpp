#include "Serce.h"
#include <iostream>

void Serce::initTekstura()
{
	if (!this->texture.loadFromFile("Textures/serce.png"))
	{
		std::cout << "Coudnt load image";
	}
}

void Serce::initSprite()
{
	this->sprite.setTexture(this->texture);
	//resize the sprite
	this->sprite.setScale(sf::Vector2f(0.05f, 0.05f));
}

Serce::Serce(float pos_x, float pos_y)
{
	this->initTekstura();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

Serce::~Serce()
{

}

const sf::FloatRect Serce::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Serce::update()
{
	this->sprite.move(0.f, 10.f);
}

void Serce::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
