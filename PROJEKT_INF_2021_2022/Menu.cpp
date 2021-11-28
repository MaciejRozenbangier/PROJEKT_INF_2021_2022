#include "Menu.h"
#include "SFML/Graphics.hpp"


Menu::Menu(float height, float width) 
{
	if (!font.loadFromFile("Fonts/dosis.light.ttf")) 
	{
		//
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Nowa gra");
	menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBERS_OF_MENU + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Opcje");
	menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBERS_OF_MENU + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Wyjdz");
	menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBERS_OF_MENU + 1) * 3));
}

Menu::~Menu()
{

}

void Menu::sterowanieMenu() 
{
	//przesowanie w gore


}

void Menu::rysowanie(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBERS_OF_MENU; i++) {
		window.draw(menu[i]);
	}
}




