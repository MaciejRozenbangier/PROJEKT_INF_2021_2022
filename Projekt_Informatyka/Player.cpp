#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;

}

void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

}

void Player::initSprite()
{
	//ustawienie tekstury do sprite
	this->sprite.setTexture(this->texture);

	//Zmniejszenie sprita
	this->sprite.scale(0.1f, 0.1f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
	
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(dirX,dirY);
}

void Player::update()
{


}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
