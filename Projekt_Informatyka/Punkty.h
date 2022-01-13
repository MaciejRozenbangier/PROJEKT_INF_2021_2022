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
	
	void update();// coœ co siê robi co 1 klatkê
	void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów
};

