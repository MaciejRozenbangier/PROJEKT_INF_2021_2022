#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class Menu {
private:


    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];


    int selectedItemIndex;
    int* scena;
    void play();
    void help();
    void up();
    void down();
    void exit();
    void init(float width, float height);





public:
    Menu(int* scena);
    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów

};


