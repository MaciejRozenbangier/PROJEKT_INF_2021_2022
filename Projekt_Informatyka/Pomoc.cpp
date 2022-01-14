#include "Pomoc.h"
#include <iostream>

void Pomoc::initTexture()
{
	if (!this->texture.loadFromFile("Textures/pomoc.png"))
	{
		std::cout << "Coudnt load image";
	}
	this->sprite.setTexture(this->texture);
	
	this->sprite.setPosition(sf::Vector2f(400.f, 500.f));
}

Pomoc::Pomoc(int* scena)
{
	this->scena = scena;
	this->initTexture();
}

Pomoc::~Pomoc()
{
}

void Pomoc::onEvent(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::KeyReleased:
		if (e.key.code == sf::Keyboard::Key::F1)
			*scena = 1;
	}
}

void Pomoc::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
