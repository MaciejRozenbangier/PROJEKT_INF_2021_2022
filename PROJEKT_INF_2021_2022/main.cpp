/*Temat projektu: Asteroids gone wrong
Zakres indywidualny: Gra b�dzie polega�a na tym �e b�dziemy lata� statkiem kosmicznym i
strzela� w lec�ce w nas asteroidki. Ka�da zestrzelona asteroidka b�dzie nam dawa�a punkty, a ta kt�ra w nas uderzy
b�dzie nam zabiera�a punkty. Najprawdopodobniej b�d� te� elementy sprawiaj�ce u�atwianie rozgrywki takie jak
np. lec�ce paliwo, kt�re nas przyspieszy , b�d� lec�cy inny przedmiot kt�ry nas spowolni. Poziomy trudno�ci gry, b�d�
sprawia�y najprawdopodobniej, �e b�dziemy mieli wiecej lub mniej �ycia, oraz asteroidki b�d� si� szybciej porusza�.
Sceneri� b�dzie wszech�wiat.
Gracz b�dzie najprawdopodobniej jeden, mo�e je�li pozwoli czas stworz� rozgrywk� dla dw�ch graczy, 
kt�rzy b�d� grali w tym samym momencie. 
*/
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "Asteroids gone wrong!");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		menu.rysowanie(window);
		window.display();
	}
	return 0;
}