#pragma once
#include <SFML/Graphics.hpp>

class Pomoc
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int* scena;

	void initTexture();
public:
	Pomoc(int* scena);
	~Pomoc();
	void onEvent(sf::Event e); // obsu³a zdarzeñ
	void draw(sf::RenderWindow& window);// dodaæ rysowanie wsztkich elementów
};

