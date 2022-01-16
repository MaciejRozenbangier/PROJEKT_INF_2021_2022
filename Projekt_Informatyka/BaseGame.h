#pragma once
#include "SFML/Graphics.hpp"

class BaseGame {
private:


    sf::RenderWindow window;
    sf::Event event;
    int scena = 0;
    int scena_old = 0;

    bool flag = false;

public:
    BaseGame() = default;
    void start();
    
};



