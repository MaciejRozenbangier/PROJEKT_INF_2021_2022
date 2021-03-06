#include "BaseGame.h"
#include "Menu.h"
#include "MenuWyjscia.h"
#include "Pomoc.h"
#include "OstatnieWyniki.h"
#include "Game.h"



void BaseGame::start()
{
    Menu m{ &this->scena };
    MenuWyjscia mw{ &this->scena };
    Game g{ &this->scena, &window };
    Pomoc p{ &this->scena };
    OstatnieWyniki ow{ &this->scena };
    this->scena = 0;
    this->window.create(sf::VideoMode(1200, 800), "Statki", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);
   
    while (this->window.isOpen())
    {
        while (this->window.pollEvent(this->event))
        {
            if (event.Event::type == sf::Event::Closed)
                window.close();
            /*if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                window.close();*/
            switch (scena)
            {
            case 0:
                m.onEvent(this->event);
                break;
            case 1:
                if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                    scena = 3;
                if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::F1)
                    scena = 4;
                g.onEvent(this->event);
                break;
            case 2:
                if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                    scena = 3;
                if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::F1)
                    scena = 4;
                g.onEvent(this->event);
                break;
            case 3:
                mw.onEvent(this->event);
                break;
            case 4:
                p.onEvent(this->event);
                break;
            case 5:
                ow.onEvent(this->event);
                break;
            }
        }
        switch (scena) 
        {
        case 0:
            m.update();
            break;
        case 1:
            if (scena_old != scena && scena_old !=3 && scena_old != 4)
                g.start(1);
            if(!flag)
                g.update();
            break;
        case 2:
            if (scena_old != scena && scena_old != 3 && scena_old != 4)
                g.start(2);
            if (!flag)
                g.update();
            break;
        case 3:
            mw.update();
        case 4:
            break;
        case 5:
            if(scena_old!=scena)
                ow.odczyt();
            ow.update();
            break;
        }
        this->window.clear(sf::Color::Black);
        switch (scena) 
        {
        case 0:
            m.draw(this->window);
            break;
        case 1:
            g.draw(this->window);
            break;
        case 2:
            g.draw(this->window);
            break;
        case 3:
            mw.draw(this->window);
            break;
        case 4:
            p.draw(this->window);
            break;
        case 5:
            ow.draw(this->window);
            break;
        }
        scena_old = scena;
        this->window.display();
    }
}

