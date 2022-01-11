#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>



class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;


	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	void move(const float dirX, const float dirY);


	void update();
	void render(sf::RenderTarget& target);
};
