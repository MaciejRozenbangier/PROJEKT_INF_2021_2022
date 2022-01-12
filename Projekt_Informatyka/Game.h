#pragma once
#include "Menu.h"
#include "MenuLevels.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
private:
	int widok = 0;

	//Window
	sf::RenderWindow* window;
	sf::Event sfEvent;
	//Menu
	Menu menu{ &widok };
	MenuLevels menuLevels{ &widok };
	//player 

	Player* player;


	

	
	//private functions
	void initWindow();
	void initVariables();
	void initPlayer();

	
	
public:
	Game();
	~Game();


	void run();


	
	void updateMenu();
	void updateMoving();
	void update();
	

	void rysowanieRozgrywki();
	void render();

	void update_sterowanie();
};

