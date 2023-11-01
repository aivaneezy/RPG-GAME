#include <iostream>
#include "enemy.h"



void Enemy::Initialize()
{

}

void Enemy::LoadenemyTexture()
{
    // ---------------- LOAD TEXTURE -------------------------------

 
    if (enemyTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Skeleton\\Texture\\spritesheet.png"))
    {
        std::cout << "Enemy texture loaded successfully" << std::endl;
        int XIndex = 1;
        int YIndex = 3;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64)); // Setting the rectangle for the sprite
        enemySprite.setPosition(400, 0); // Initial Position
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }
}

void Enemy::Update()
{
    // Enemy Movement
    sf::Vector2f positionEnemy = enemySprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        enemySprite.setPosition(positionEnemy - sf::Vector2f(0, 1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        enemySprite.setPosition(positionEnemy + sf::Vector2f(0, 1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        enemySprite.setPosition(positionEnemy - sf::Vector2f(1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        enemySprite.setPosition(positionEnemy + sf::Vector2f(1, 0));
    }
}

void Enemy::Draw(sf::RenderWindow &window)
{

    window.draw(enemySprite);
}