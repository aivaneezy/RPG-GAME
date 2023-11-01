#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	void Initialize();
	void LoadenemyTexture();
	void Update();
	void Draw(sf::RenderWindow& window);

public:
	sf::Sprite enemySprite;
private:
	sf::Texture enemyTexture;
	
};