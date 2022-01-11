#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Asteroids gone wrong", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
	this->isMenuOpen = true;
	this->isMenuLevelsOpen = false;
	this->isGameRun = false;
}



Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initBackground();
	this->initPlayer();

}
Game::~Game()
{
	delete this->window;
	delete this->player;

}

void Game::initBackground()
{
	if(!this->worldBackgroundTex.loadFromFile("Textures/background1.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
	}

	this->worldBackground.setTexture(this->worldBackgroundTex);

}

void Game::initPlayer()
{
	this->player = new Player();
}


void Game::run()
{
	while (window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updateMovingMenu()
{
	switch (this->sfEvent.type)
	{
	case sf::Event::Closed:
		this->window->close();
		break;
	case sf::Event::KeyReleased:
		switch (sfEvent.key.code)
		{
		case sf::Keyboard::Up:
			if (isMenuOpen)
				//mainmenu
				menu.MoveUp();
			//menuLevels
			if (menu.GetPressedItem() == 0 && !isMenuOpen && isGameRun)
				menuLevels.MoveUp();
			break;
		case sf::Keyboard::Down:
			if (isMenuOpen)
				//maindmenu
				menu.MoveDown();
			//menuLevels
			if (menu.GetPressedItem() == 0 && !isMenuOpen && !isGameRun)
				menuLevels.MoveDown();
			break;

		}
	}
}



void Game::updateMenu()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		//this->menuControl();
		switch (this->sfEvent.type) 
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyReleased:
			switch (sfEvent.key.code)
			{
			case sf::Keyboard::Up:
				if (isMenuOpen)
				//mainmenu
					menu.MoveUp();
				//menuLevels
				if (menu.GetPressedItem() == 0 && !isMenuOpen && isGameRun)
					menuLevels.MoveUp();
				break;
			case sf::Keyboard::Down:
				if (isMenuOpen)
					//maindmenu
					menu.MoveDown();
				//menuLevels
				if (menu.GetPressedItem() == 0 && !isMenuOpen && !isGameRun)
					menuLevels.MoveDown();
				break;

			case sf::Keyboard::Escape:
				if (isGameRun)
				{
					this->isMenuLevelsOpen = true;
					this->isGameRun = false;
				}
				else 
				{
					this->isMenuLevelsOpen = false;
					this->isMenuOpen = true;
					this->isGameRun = false;
				}
				break;

			case sf::Keyboard::Return:
				//Glowne Menu
				if (isMenuOpen)
				{
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						isMenuLevelsOpen = true;
						isMenuOpen = false;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						isMenuOpen = false;
						break;
					case 2:
						this->window->close();
						break;
					}
					break;
				}
				//menu wyborow
				else if (menu.GetPressedItem() == 0 && !isMenuOpen && !isGameRun)
				{
					switch (menuLevels.GetPressedItem())
					{
					case 0:
						std::cout << "Poziom 1" << std::endl;
						isMenuLevelsOpen = false;
						isGameRun = true;
						break;
					case 1:
						std::cout << "Poziom 2" << std::endl;
						isMenuLevelsOpen = false;
						isGameRun = true;
						break;
					}
					break;
				}
			}
			break;
		}

	}
}



void Game::updateMoving()
{
	sf::Vector2f currentVelocity;
	sf::Vector2f direction;
	float acceleration = 1.f;
	float maxVelocity = 25.f;
	float drag = 0.5f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction.x = -1.f;
		if (currentVelocity.x > -maxVelocity)
			currentVelocity.x += acceleration * direction.x;
	}
	this->player->move(currentVelocity.x, currentVelocity.y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (currentVelocity.x > 0.f)
		{
		currentVelocity.x -= drag;

		if (currentVelocity.x < 0.f)
			currentVelocity.x = 0.f;
		}
		else if (currentVelocity.x < 0.f)
		{
		currentVelocity.x += drag;
		
		if (currentVelocity.x > 0.f)
			currentVelocity.x = 0.f;
		}
		if (currentVelocity.y > 0.f)
		{
			currentVelocity.y -= drag;
		
			if (currentVelocity.y < 0.f)
				currentVelocity.y = 0.f;
		}
		else if (currentVelocity.y < 0.f)
		{
			currentVelocity.y += drag;
		
			if (currentVelocity.y > 0.f)
				currentVelocity.y = 0.f;
		}
}


void Game::renderMenu()
{
	if (isMenuOpen == true)
	{
		this->menu.draw(*this->window);
	}
	else if (menu.GetPressedItem() == 0 && isMenuLevelsOpen)
	{
		this->menuLevels.draw(*this->window);
	}
	//Draw option
	else if (menu.GetPressedItem() == 1)
	{
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(500.f, 100.f));
		shape.setFillColor(sf::Color::Green);
		this->window->draw(shape);
	}
}

void Game::renderBackground()
{
	this->window->draw(this->worldBackground);
}


void Game::renderMenuLevels()
{
	if (isGameRun)
	{
		if (menuLevels.GetPressedItem() == 0)
		{
			this->player->render(*this->window);
		}
		if(menuLevels.GetPressedItem() == 1)
		{
			
			sf::RectangleShape shape;
			shape.setSize(sf::Vector2f(500.f, 100.f));
			shape.setFillColor(sf::Color::Blue);
			this->window->draw(shape);
		}
	}
}

void Game::update()
{
	this->updateMenu();
	this->updateMoving();
}


void Game::render()
{
	this->window->clear();
	//rendering
	//Draw open menu

	this->renderBackground();
	this->renderMenu();
	this->renderMenuLevels();

	//draw game level

	this->window->display();
}


