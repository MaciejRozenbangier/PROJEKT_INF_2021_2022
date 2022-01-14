#include "Menu.h"
#include <iostream>

void Menu::onEvent(sf::Event e)
{
    switch (e.type)
    {
    case sf::Event::KeyPressed:
        if (e.key.code == sf::Keyboard::Key::W)
            this->up();
        if (e.key.code == sf::Keyboard::Key::S)
            this->down();
        if (e.key.code == sf::Keyboard::Key::Enter)
            this->sele();
        if (e.key.code == sf::Keyboard::Key::Escape)
            this->exit();
        break;
    case sf::Event::KeyReleased:
        if (e.key.code == sf::Keyboard::Key::Enter)
        {
            if (selectedItemIndex == 3)
                this->exit();
        }
        break;
    }
}

void Menu::update()
{

}

void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

Menu::Menu(int* scena)
{
    this->scena = scena;
    this->init(1200.f, 800.f);
}

void Menu::play(int a)
{

    *scena = a;
}

void Menu::help()
{
    //*scena = 2;

}

void Menu::up()
{

    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::down()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::exit() 
{
    std::exit(0);
}

void Menu::sele()
{
    switch (this->selectedItemIndex)
    {
    case 0:
        play(1);
        break;
    case 1:
        play(2);
        break;
    }
}



void Menu::init(float width, float height)
{
    this->selectedItemIndex = 0;

    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "Could not load font::Menu";
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Poziom latwy");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Poziom trudny");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Ostatnie wyniki");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("WyjdŸ z gry");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
}


