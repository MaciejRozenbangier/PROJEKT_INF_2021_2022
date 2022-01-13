#pragma once
#include "SFML/Graphics.hpp"

class Player
{
private:
    sf::RenderWindow* window;
    sf::Sprite sprite;
    sf::Texture texture;


    float predkoscGracza;

    void initZmienne();
    void initTesktura();
    void initSprite();

public:
    Player();
    ~Player();
    //gettery



    void kolizja();
    void move();

    void onEvent(sf::Event e); // obsu�a zdarze�
    void update();// co� co si� robi co 1 klatk�
    void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w

};

