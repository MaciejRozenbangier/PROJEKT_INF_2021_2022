#include "Menu.h"


void Menu::initVariables()
{
	this->selectedItemIndex = 0;
}



void Menu::initGui(float width, float height)
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "Could not load font::Menu";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

}

Menu::Menu(int* widok)
{
	this->widok = widok;
	this->initVariables();
	this->initGui(1200.f,800.f);

}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::sterowanieMenu()
{
	

}

void Menu::update_sterowanie(sf::Event& sfEvent)
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

		case sf::Keyboard::Return:
			//Glowne Menu
			
				switch (GetPressedItem())
				{
				case 0:
					std::cout << "Play button has been pressed" << std::endl;
					*widok = 1;
					break;
				case 1:
					std::cout << "Option button has been pressed" << std::endl;
					//*widok = 3; // Ranking
					break;
				case 2:
					exit(0);
					break;
				}
				break;
		}
		break;
	}
}
