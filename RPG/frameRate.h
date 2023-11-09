#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class FrameRate
{

public:
	/*Constructor*/
	FrameRate();

	/*Destructors*/
	~FrameRate(); // object is destroy

	void Initialize();
	void Load();
	void Update(double deltaTime, Player player);
	void Draw(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Font font;
	double timer;
};