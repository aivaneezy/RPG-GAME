#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Initialize(const sf::Vector2f &position, const sf::Vector2f &target, float speed);
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow &window);



	/*Returning a globalBounds*/
	inline const sf::FloatRect& GetGlobalBounds() 
	{ 
		return rectangleShape.getGlobalBounds();
	}

public:


private:
	sf::RectangleShape rectangleShape;
	float b_speed;
	sf::Vector2f direction;



};