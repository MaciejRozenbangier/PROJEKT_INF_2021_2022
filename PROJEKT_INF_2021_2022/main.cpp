/*Temat projektu: Asteroids gone wrong
Zakres indywidualny: Gra bêdzie polega³a na tym ¿e bêdziemy lataæ statkiem kosmicznym i
strzelaæ w lec¹ce w nas asteroidki. Ka¿da zestrzelona asteroidka bêdzie nam dawa³a punkty, a ta która w nas uderzy
bêdzie nam zabiera³a punkty. Najprawdopodobniej bêd¹ te¿ elementy sprawiaj¹ce u³atwianie rozgrywki takie jak
np. lec¹ce paliwo, które nas przyspieszy , b¹dŸ lec¹cy inny przedmiot który nas spowolni. Poziomy trudnoœci gry, bêd¹
sprawia³y najprawdopodobniej, ¿e bêdziemy mieli wiecej lub mniej ¿ycia, oraz asteroidki bêd¹ siê szybciej poruszaæ.
Sceneri¹ bêdzie wszechœwiat.
Gracz bêdzie najprawdopodobniej jeden, mo¿e jeœli pozwoli czas stworzê rozgrywkê dla dwóch graczy, 
którzy bêd¹ grali w tym samym momencie. 
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