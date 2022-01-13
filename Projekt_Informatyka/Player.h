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

    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów

};

