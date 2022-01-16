#pragma once
#include "SFML/Graphics.hpp"
class Enemy
{
private:
	unsigned pointCount;
	sf::Sprite sprite;
	sf::Texture texture;

	
	float speed;
	int points = 1;
	
	void initZmienne();
	void initTekstura();
	void initSprite();

public:

	Enemy(float pos_x, float pos_y);
	~Enemy();

	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& setPoints(int points) const;

	void update();// co� co si� robi co 1 klatk�
	void draw(sf::RenderWindow& window);// doda� rysowanie wsztkich element�w
};

