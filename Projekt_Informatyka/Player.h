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

    int hp;
    int hpMax;

    void initZmienne();
    void initTesktura();
    void initSprite();

public:
    Player();
    ~Player();

    //accesors
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    const int& getHp() const;
    const int& getHpMax() const;


    //modifers
    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);
    void setHp(const int hp);
    void loseHp(const int value);
    void gainHp(const int value);

    
    void move();
    const bool mozeAtakowac();


    void updateAtak();
    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów
};

