#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class Menu
{
private:
	//zmienne
	int selectedItemIndex;

	//czcionka
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];


	//tlo
	

	//funkcje prywatne
	void initVariables();
	void initGui(float width, float height);

public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void sterowanieMenu();
	int GetPressedItem() { return selectedItemIndex; }


};