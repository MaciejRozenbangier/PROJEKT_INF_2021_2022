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

    void onEvent(sf::Event e); // obsu�a zdarze�
    void update();// co� co si� robi co 1 klatk�
    void draw(sf::RenderWindow& window);//rysowanie wsztkich element�w
};

