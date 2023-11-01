#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "enemy.h"


class Player
{
public:
	void Initialize(); // called only once
	void LoadplayerTexture(); // called only once
	void Update(Enemy& enemy); // Update called once per frame
	void Draw(sf::RenderWindow& window); // Draw called once per fame


public:
	sf::Sprite playerSprite;
private:
	sf::Texture playerTexture;
	std::vector<sf::RectangleShape> bullets; // vector of multiple bullets
	float bulletspeed = 0.3f;
};