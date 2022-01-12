#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2


class MenuLevels
{
private:

	int selectedItemIndex;
	int* widok;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	void initVariables();
	void initGui(float width, float height);

public:
	MenuLevels(int* widok);
	~MenuLevels();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void update_sterowanie(sf::Event& sfEvent);


};