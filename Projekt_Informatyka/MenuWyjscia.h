#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS_MENUWYJSCIA 2

class MenuWyjscia
{
private:
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_MENUWYJSCIA];

    sf::Text text;

    int selectedItemIndex;
    int* scena;

    void up();
    void down();
    void init(float width, float height);

public:
    MenuWyjscia(int* scena);
    ~MenuWyjscia();


    void onEvent(sf::Event e); // obsu�a zdarze�
    void update();// co� co si� robi co 1 klatk�
    void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

