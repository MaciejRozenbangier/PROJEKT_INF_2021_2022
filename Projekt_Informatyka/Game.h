#pragma once
#include <map>
#include <iostream>
#include "BaseGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Punkty.h"
#include "Pocisk.h"
#include "Serce.h"

struct saveStruct
{
    uint32_t score;
    uint8_t level;
};

class Game
{
private:
    sf::Texture tloTexture;
    sf::Sprite tloSprite;

    //zasoby
    std::map<std::string, sf::Texture*> textures;
    std::vector<Pocisk*> pociski;

    //okno
    sf::RenderWindow *window;
    //player
    Player* player;
    //punkty
    Punkty punkty;
    
    uint32_t points;

    uint8_t leveltype;

    //std::vector<Przeciwnik*> przeciwnicy;
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    sf::Font font;
    sf::Text koniecGry;

    //Enemies
    float spawnTimer;
    float spawnTimerMax;

    //serca
    float sercaSpawnTimer;
    float sercaSpawnTimerMax;

    std::vector<Enemy*> enemies;
    std::vector<Serce*> serca;

    void initBackground();
    void initPlayer();
    void initTextures();
    void initEnemies();
    void initSerca();
    void initPasekZycia();
    void save();


public:
    Game(int* scena, sf::RenderWindow* window);
    ~Game();

    void tworzeniePociskow();
    void updatePociski();
    void updateEnemies();
    void updateSerca();
    void updateKolizjaGraczPrzeciwnik();
    void updatePasekZycia();
    void start(int a);

    void kolizjaSciany(); 
    void drawGUI();
    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);//rysowanie wsztkich elementów
};

