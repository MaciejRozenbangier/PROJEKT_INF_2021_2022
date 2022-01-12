#include "MenuLevels.h"


void MenuLevels::initVariables()
{
	this->selectedItemIndex = 0;
}

void MenuLevels::initGui(float width, float height)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "Could not load font::Menu";
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Poziom 1");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Poziom 2");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

MenuLevels::MenuLevels(int* widok)
{
	this->widok = widok;
	this->initVariables();
	this->initGui(1200.f, 800.f);
}


MenuLevels::~MenuLevels()
{
}

void MenuLevels::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void MenuLevels::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuLevels::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuLevels::update_sterowanie(sf::Event& sfEvent)
{
	switch (sfEvent.type)
	{
	case sf::Event::KeyReleased:
		switch (sfEvent.key.code)
		{
		case sf::Keyboard::Up:
			MoveUp();
			break;
		case sf::Keyboard::Down:
			MoveDown();
			break;
		
		case sf::Keyboard::Escape:
			*widok = 0;
			break;

		case sf::Keyboard::Return:
			//Glowne Menu

			switch (GetPressedItem())
			{
			case 0:
				*widok = 2;
				//funkcja albo odnoœnik od ³adowania poziom 1

				if (sf::Event::KeyReleased == sf::Keyboard::Escape)
					*widok = 1;
				break;
			case 1:
				*widok = 2;
				//funkcja albo odnoœnik od ³adowania poziom 2
				break;
			}
			break;
		}
		break;
	}
}