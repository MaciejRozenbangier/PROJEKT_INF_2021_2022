#include "Player.h"
#include <iostream>



void Player::initZmienne()
{
	this->predkoscGracza = 10.f;
	this->resetAtakMax = 10.f;
	this->resetAtak = this->resetAtakMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
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
	this->sprite.setPosition(sf::Vector2f(577.f, 750.f));

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

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHp(const int value)
{
	this->hp += value;
	if (this->hp > hpMax)
		this->hp = hpMax;
}





void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->sprite.move(-13, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->sprite.move(13, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->sprite.move(0, -13);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->sprite.move(0, 13);

}
void Player::updateAtak()
{
	if (this->resetAtak < this->resetAtakMax)
	{
		this->resetAtak += 1.f;
	}
}

const bool Player::mozeAtakowac()
{
	if (this->resetAtak >= this->resetAtakMax)
	{
		this->resetAtak = 0.f;
		return true;
	}
	return false;
}


void Player::onEvent(sf::Event e)
{


}

void Player::update()
{
	this->move();
	this->updateAtak();
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);

}
