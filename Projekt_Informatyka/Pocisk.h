#pragma once
#include "SFML/Graphics.hpp"
class Pocisk
{
private:
	sf::Sprite shape;
	

	sf::Vector2f kierunekPocisku;
	float predkoscPocisku;

public:
	Pocisk();
	Pocisk(sf::Texture* texture, float pos_x,float pox_y, float kier_x, float kier_y, float predkosc_pocisku);
	~Pocisk();

	//getter
	const sf::FloatRect getBounds() const;

	void update();// coœ co siê robi co 1 klatkê
	void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów
};

