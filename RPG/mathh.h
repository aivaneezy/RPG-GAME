#pragma once
#include <SFML/Graphics.hpp>
class Math
{
public:
	/*Static allow us to use the method without creating an object*/
	static sf::Vector2f normalizeVector(sf::Vector2f vector);
};