#include <iostream>
#include "enemy.h"


#define SPRITE_HEIGHT 64
#define SPRITE_WIDTH 64
void Enemy::Initialize()
{
    /*COLLISION DETECTION TEST*/
    boundingshape2.setFillColor(sf::Color::Transparent);
    boundingshape2.setOutlineColor(sf::Color::Blue);
    boundingshape2.setOutlineThickness(1);
    boundingshape2.setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));
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
        enemySprite.setTextureRect(sf::IntRect(XIndex * SPRITE_WIDTH, YIndex * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT)); // Setting the rectangle for the sprite
        enemySprite.setPosition(400, 0); // Initial Position
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }
}

void Enemy::Update(float deltatTime)
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

    /*RECTANGLE FOLLOW THE ENEMY SPRITE*/
    boundingshape2.setPosition(enemySprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow &window)
{

    window.draw(enemySprite);
    window.draw(boundingshape2);
}