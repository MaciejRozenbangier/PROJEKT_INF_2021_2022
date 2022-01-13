#pragma once
#include <iostream>
#include "Player.h"

class Game
{
private:

    void initPlayer();

    Player* player;

public:
    Game(int* scena);
    ~Game();

    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);//rysowanie wsztkich elementów
};

