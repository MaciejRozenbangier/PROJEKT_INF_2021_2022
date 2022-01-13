#pragma once
#include "SFML/Graphics.hpp"

class Punkty
{
private:
	sf::Font font;
	sf::Text pointText;

	int points;
	void initPunkty();


public:
	Punkty();
	~Punkty();

	void setPoints(int p);
	
	void update();// co� co si� robi co 1 klatk�
	void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

