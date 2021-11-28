#include "SFML/Graphics.hpp"

#define MAX_NUMBERS_OF_MENU 3

class Menu
{
public:
	Menu(float height, float width); //konstruktor
	~Menu();//destruktor

	void rysowanie(sf::RenderWindow& window);
	void sterowanieMenu();
private: 
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBERS_OF_MENU];

};

