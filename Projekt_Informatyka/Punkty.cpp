#include "Punkty.h"
#include <iostream>

void Punkty::initPunkty()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
		std::cout << "error game failed to load font";



	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(32);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("");

}

Punkty::Punkty()
{
	this->initPunkty();
}

Punkty::~Punkty()
{

}

void Punkty::setPoints(int p)
{
	this->pointText.setString("Punkty: "+std::to_string(p));
}



void Punkty::update()
{

}

void Punkty::draw(sf::RenderWindow& window)
{
	window.draw(this->pointText);
}
