#pragma once
#include <map>
#include <iostream>
#include "BaseGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Punkty.h"
#include "Pocisk.h"


class Game
{
private:
    //zasoby
    std::map<std::string, sf::Texture*> textures;
    std::vector<Pocisk*> pociski;

    //okno
    sf::RenderWindow *window;
    //player
    Player* player;
    //punkty
    Punkty punkty;
    
    unsigned points;

    //std::vector<Przeciwnik*> przeciwnicy;


    //Enemies
    float spawnTimer;
    float spawnTimerMax;

    std::vector<Enemy*> enemies;



    void initPlayer();
    void initTextures();
    void initEnemies();



public:

    Game(int* scena, sf::RenderWindow* window);
    ~Game();


    void tworzeniePociskow();
    void updatePociski();
    void updateEnemies();
    void updateKolizjaGraczPrzeciwnik();
   
    void kolizjaSciany(); // do zrobienia
    void onEvent(sf::Event e); // obsu³a zdarzeñ
    void update();// coœ co siê robi co 1 klatkê
    void draw(sf::RenderWindow& window);//rysowanie wsztkich elementów
};

