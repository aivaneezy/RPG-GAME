#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Initialize();
	void LoadenemyTexture();
	void Update(float deltatTime);
	void Draw(sf::RenderWindow& window);

	
	// collision detection test
	sf::RectangleShape boundingshape2;

public:
	sf::Sprite enemySprite;
private:
	sf::Texture enemyTexture;
	
};