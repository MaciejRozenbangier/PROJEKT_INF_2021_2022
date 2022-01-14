#include "MenuWyjscia.h"
#include <iostream>

void MenuWyjscia::up()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MenuWyjscia::down()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_MENUWYJSCIA)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MenuWyjscia::init(float width, float height)
{
    this->selectedItemIndex = 0;

    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "Could not load font::Menu";
    }
    this->text.setFont(this->font);
    this->text.setCharacterSize(40);
    this->text.setFillColor(sf::Color::White);
    this->text.setString("Czy chcesz wyjsc z gry ?");
    this->text.setPosition(sf::Vector2f(500.f, 60.f));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Tak");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_MENUWYJSCIA + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Nie");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_MENUWYJSCIA + 1) * 2));

   
}

MenuWyjscia::MenuWyjscia(int* scena)
{
    this->scena = scena;
    this->init(1200,800);
}

MenuWyjscia::~MenuWyjscia()
{
}

void MenuWyjscia::onEvent(sf::Event e)
{
    switch (e.type)
    {
    case sf::Event::KeyPressed:
        if (e.key.code == sf::Keyboard::Key::W)
            this->up();
        if (e.key.code == sf::Keyboard::Key::S)
            this->down();
    case sf::Event::KeyReleased:
        if (e.key.code == sf::Keyboard::Key::Enter)
        {
            if(selectedItemIndex == 0)
                *scena = 0;
            if (selectedItemIndex == 1)
                *scena = 1;
        }
            
        break;
    }
}

void MenuWyjscia::update()
{
}

void MenuWyjscia::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS_MENUWYJSCIA; i++)
    {
        window.draw(menu[i]);
    }
    window.draw(this->text);
}
