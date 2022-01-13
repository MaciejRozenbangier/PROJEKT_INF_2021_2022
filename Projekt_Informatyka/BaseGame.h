#pragma once
#include "SFML/Graphics.hpp"

class BaseGame {
private:

    sf::RenderWindow window;
    sf::Event event;
    int scena = 0;

public:
   
    BaseGame() = default;
    void start();
};



