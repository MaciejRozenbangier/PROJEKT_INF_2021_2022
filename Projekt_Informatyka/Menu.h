#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4


class Menu 
{
protected:

    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

    int selectedItemIndex;
    int* scena;

    void play(int a);
    void help();
    void up();
    void down();
    void exit();
    void sele();
    void init(float width, float height);
 
public:

    Menu(int* scena);
    void onEvent(sf::Event e); // obsu?a zdarze?
    void update();// co? co si? robi co 1 klatk?
    void draw(sf::RenderWindow& window);// doda? rysowanie wsztkich element?w

};


