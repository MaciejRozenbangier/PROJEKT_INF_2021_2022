#include "Pocisk.h"



Pocisk::Pocisk() //konstruktor domyslny
{

}

Pocisk::Pocisk(sf::Texture* texture, float pos_x, float pos_y, float kier_x, float kier_y, float predkosc_pocisku)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(sf::Vector2f(0.04f, 0.04f));
	this->shape.setPosition(pos_x, pos_y);
	this->kierunekPocisku.x = kier_x;
	this->kierunekPocisku.y = kier_y;
	this->predkoscPocisku = predkosc_pocisku;
}

Pocisk::~Pocisk()
{

}

const sf::FloatRect Pocisk::getBounds() const
{
	return this->shape.getGlobalBounds();

}

void Pocisk::update()
{
	this->shape.move(this->predkoscPocisku * this->kierunekPocisku);
}

void Pocisk::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}
