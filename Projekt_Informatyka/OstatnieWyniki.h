#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Game.h"
#define N 5
class OstatnieWyniki
{
private:
	int* scena;
	saveStruct buffor[N];
	int length = 0;
	sf::Text text[N];
	sf::Font f;
public:
	OstatnieWyniki(int* scena);
	~OstatnieWyniki();

	void odczyt();
	void drukuj();

	void onEvent(sf::Event e); // obsu�a zdarze�
	void update();// co� co si� robi co 1 klatk�
	void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

