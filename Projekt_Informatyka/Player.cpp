#include "Player.h"
#include <iostream>



void Player::initZmienne()
{
	this->predkoscGracza = 10.f;

}

void Player::initTesktura()
{
	//zaladowanie tekstury z pliku
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

}

void Player::initSprite()
{
	//ustawienie tekstury
	this->sprite.setTexture(this->texture);

	//Zmniejszenie sprita
	this->sprite.scale(0.1f, 0.1f);

}

Player::Player()
{
	this->initZmienne();
	this->initTesktura();
	this->initSprite();

}

Player::~Player()
{

}



void Player::kolizja()
{



}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->sprite.move(-10, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->sprite.move(10, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->sprite.move(0, -10);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->sprite.move(0, 10);

}

void Player::onEvent(sf::Event e)
{


}

void Player::update()
{
	this->move();
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);

}
