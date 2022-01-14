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

	void update();// coœ co siê robi co 1 klatkê
	void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów
};

