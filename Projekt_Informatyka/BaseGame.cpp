#include "BaseGame.h"
#include "Menu.h"
#include "Game.h"

void BaseGame::start()
{

    Menu m{ &this->scena };
    Game g{ &this->scena };
    this->scena = 1;
    this->window.create(sf::VideoMode(1200, 800), "Tytul", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);

    while (this->window.isOpen())
    {
        while (this->window.pollEvent(this->event))
        {
            switch (scena) {
            case 0:
                m.onEvent(this->event);
                break;
            case 1:
                g.onEvent(this->event);
                break;
            case 2:

                break;
            case 3:

                break;
            }
        }
        switch (scena) {
        case 0:
            m.update();
            break;
        case 1:
            g.update();
            break;
        case 2:

            break;
        }
        this->window.clear(sf::Color::Black);
        switch (scena) {
        case 0:
            m.draw(this->window);
            break;
        case 1:
            g.draw(this->window);
            break;
        case 2:

            break;
        }
        this->window.display();
    }
}
