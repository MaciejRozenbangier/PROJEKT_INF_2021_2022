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

	void update();// co� co si� robi co 1 klatk�
	void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

