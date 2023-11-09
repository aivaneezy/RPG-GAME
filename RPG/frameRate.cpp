#include "frameRate.h"
#include <iostream>

/*Costructors*/
FrameRate::FrameRate() :
	timer(0)
{

}

/*Desturctors*/
FrameRate::~FrameRate() 
{

}

void FrameRate::Initialize()
{

}

void FrameRate::Load()
{
	if (font.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Fonts\\arial.ttf"))
	{
		text.setFont(font);
		std::cout << "Font is loaded succesfully" << std::endl;
	}
	else
	{
		std::cout << "Font Failed " << std::endl;
	}
}

void FrameRate::Update(double deltaTime, Player player)
{
	timer += deltaTime;
	if (timer >= 100.0)
	{
		double result = 1000.0 / deltaTime;
		std::string frameRateText = "FPS: " + std::to_string((int)result) + " frameTime: " + std::to_string(deltaTime);
		text.setString(frameRateText);
		text.setFillColor(sf::Color::Red);
		

		timer = 0; // timer is reset to 0 every 100 milliseconds
	}
	text.setPosition(player.playerSprite.getPosition());
	
}

void FrameRate::Draw(sf::RenderWindow &window)
{
	window.draw(text);
}