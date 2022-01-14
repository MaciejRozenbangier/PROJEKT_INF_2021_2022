#pragma once
#include "SFML/Graphics.hpp"
class Serce
{
private:

	sf::Sprite sprite;
	sf::Texture texture;

	
	void initTekstura();
	void initSprite();

public:


	Serce(float pos_x, float pos_y);
	~Serce();

	const sf::FloatRect getBounds() const;

	void update();// co� co si� robi co 1 klatk�
	void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

