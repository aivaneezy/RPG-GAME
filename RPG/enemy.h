#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void setHealth(int damage);
	void Initialize();
	void LoadenemyTexture();
	void Update(float deltatTime);
	void Draw(sf::RenderWindow& window);

public:
	sf::Sprite enemySprite;
	int health;
	// collision detection test
	sf::RectangleShape boundingshape2;
private:
	sf::Texture enemyTexture;
	sf::Text enemyText;
	sf::Font enemyFont;
	
};