#pragma once
#include "SFML/Graphics.hpp"

class Player
{
private:
    
    sf::Sprite sprite;
    sf::Texture texture;

    float predkoscGracza;


    float resetAtak;
    float resetAtakMax;

    void initZmienne();
    void initTesktura();
    void initSprite();

public:
    Player();
    ~Player();

    //accesors
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    //modifers
    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);




    void kolizja();
    void move();
    const bool mozeAtakowac();

    void updateAtak();
    void onEvent(sf::Event e); // obsu�a zdarze�
    void update();// co� co si� robi co 1 klatk�
    void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w

};

