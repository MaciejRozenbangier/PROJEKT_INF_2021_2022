#pragma once
#include "Menu.h"
#include "MenuLevels.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Event sfEvent;
	//Menu
	Menu menu;
	MenuLevels menuLevels{ 1200.f, 800.f };
	//player 

	Player* player;

	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	//private functions
	void initWindow();
	void initVariables();
	void initBackground();
	void initPlayer();

	
	bool isMenuOpen;
	bool isMenuLevelsOpen;
	bool isGameRun;

public:
	Game();
	~Game();


	void run();


	
	void updateMenu();
	void updateMoving();
	void updateMovingMenu();
	void update();

	void renderBackground();
	void renderMenu();
	void renderMenuLevels();
	void render();
};

