
#include "OstatnieWyniki.h"

OstatnieWyniki::OstatnieWyniki(int* scena)
{
	this->scena = scena;
}

OstatnieWyniki::~OstatnieWyniki()
{
}

void OstatnieWyniki::odczyt()
{
	f.loadFromFile("Fonts/Dosis-Light.ttf");
	std::ifstream stream = std::ifstream("wyniki.txt", std::ios::binary);
	stream.seekg(0, stream.end);
	length = stream.tellg();
	length =length/ sizeof(saveStruct);

	if (length < N)
	{
		stream.seekg(0, stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStruct)*length);
	}
	else
	{
		stream.seekg(sizeof(saveStruct)*(length-N), stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStruct)*N);
		length = N;
	}
	
	stream.close();
	for (size_t i = 0; i < N; i++)
	{
		this->text[i].setFont(this->f);
		this->text[i].setFillColor(sf::Color::White);
		this->text[i].setPosition(sf::Vector2f(400.f,200.0f+100*i));
		
	}
	for (size_t i = 0; i < length; i++)
	{
		this->text[i].setString("Punkty: " + std::to_string(this->buffor[i].score) + " Poziom: " + ((this->buffor[i].level == 2) ?  "Trudny": "Latwy" ));
	}
}

void OstatnieWyniki::drukuj()
{
	/*for (int i = 0;i < N; i++)
	{

	}*/
}

void OstatnieWyniki::onEvent(sf::Event e)
{
	if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Key::Escape)
	{
		*scena = 0;
	}
}

void OstatnieWyniki::update()
{
	
}

void OstatnieWyniki::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < length ; i++)
	{
		window.draw(this->text[i]);
	}
}
