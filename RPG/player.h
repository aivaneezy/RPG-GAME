#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "enemy.h"
#include "bullet.h"

class Player
{
public:
	Player();
	~Player();
	void Initialize(); // called only once
	void LoadplayerTexture(); // called only once
	void Update(float deltatTime, Enemy& enemy, sf::Vector2f &mousePos); // Update called once per frame
	void Draw(sf::RenderWindow& window); // Draw called once per fame

	// collision detection test
	sf::RectangleShape boudingRectangle;


public:
	sf::Sprite playerSprite;
private:
	
	sf::Texture playerTexture;
	std::vector<Bullet> bullets; // vector of multiple bullets
	float playerSpeed;
	float maxFireRate;
	float fireRateTimer;
	float bulletSpeed;
};