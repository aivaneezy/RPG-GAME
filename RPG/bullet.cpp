#include "bullet.h"
#include <iostream>
#include "mathh.h"

Bullet::Bullet() :
	b_speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f &position, const sf::Vector2f &target, float speed)
{
	this->b_speed = speed;
	rectangleShape.setSize(sf::Vector2f(50, 25));
	rectangleShape.setPosition(position);
	/*Getting the direction target - current position*/
	direction = Math::normalizeVector(target - position);
}

void Bullet::Load()
{

}

void Bullet::Update(float deltatime)
{
	// movting the bullets
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * b_speed * deltatime);
	
}

void Bullet::Draw(sf::RenderWindow &window)
{
	window.draw(rectangleShape);
}