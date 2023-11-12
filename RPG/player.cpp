
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "mathh.h"
#include "enemy.h"

#define SPRITE_HEIGHT 64
#define SPRITE_WIDTH 64

/*Costructor*/
Player::Player() :
    playerSpeed(2.0f),
    maxFireRate(200),
    fireRateTimer(0),
    bulletSpeed(0.5f)
{
}

/*Decostructor*/
Player::~Player()
{

}



void Player::Initialize()
{
    boudingRectangle.setFillColor(sf::Color::Transparent);
    boudingRectangle.setOutlineColor(sf::Color::Red);
    boudingRectangle.setOutlineThickness(1);
    boudingRectangle.setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));
}

void Player::LoadplayerTexture()
{
	  if (playerTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Player\\Texture\\spritesheet.png"))
    {
        std::cout << "Loaded Successfully" << std::endl;

        int XIndex = 0; // x axes
        int YIndex = 0; // y axes

       playerSprite.setTexture(Player::playerTexture);
       playerSprite.setTextureRect(sf::IntRect(XIndex * SPRITE_WIDTH, YIndex * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT)); // Setting the rectangle for the sprite
       playerSprite.setPosition(sf::Vector2f(600, 600)); // Initial position
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }
}



void Player::Update(float deltaTime, Enemy& enemy, sf::Vector2f &mousePos)
{

    // PLAYERS MOVEMENT
    sf::Vector2f positionPlayer = playerSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerSprite.setPosition(positionPlayer - sf::Vector2f(0, 1) * playerSpeed * deltaTime); // curr position - 1 units to the y axis
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerSprite.setPosition(positionPlayer + sf::Vector2f(0, 1) * playerSpeed * deltaTime); // curr position + 1 units to the y axis
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite.setPosition(positionPlayer + sf::Vector2f(1, 0) * playerSpeed * deltaTime); // curr position + 1 units to the x axis
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerSprite.setPosition(positionPlayer - sf::Vector2f(1, 0) * playerSpeed * deltaTime); // curr position - 1 units to the x axis
    }


    // EVENT FOR MOUSE FOR THE BULLETS
    fireRateTimer += deltaTime; // How much time has passed since i shot my gun.
   
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        /*pushing a bullet using the Bullet class object as a data type*/
        bullets.push_back(Bullet()); 
        int lastElement = bullets.size() - 1; // last element of the vector
        bullets[lastElement].Initialize(playerSprite.getPosition(), mousePos, bulletSpeed); // bullet Initial Position
        fireRateTimer = 0; // resetting the fireRateTimer

    }

    // ---------------- SHOOTING A BULLETS ----------------------
/*
    SHOOTING A BULLET DIRECTION FORMULA : DIRECTION = (TARGET - CURRENT POSITION).normalize()
    the normalize is to convert a vector into a  units.
*/
    /* Moving the bullets to a target*/
    for (size_t i = 0; i < bullets.size(); i++)
    {
        /* Updating the bullet position every frame*/
        bullets[i].Update(deltaTime);

        /*If the enemy is alive check for collision*/
        if (enemy.health > 0)
        {
            /*Collision detection between bulllets and enemy*/
            if (Math::CheckRectCollision(bullets[i].GetGlobalBounds(), enemy.enemySprite.getGlobalBounds()))
            {
                /* bullets.begin() returns an iterator + the index we want to delete*/
                bullets.erase(bullets.begin() + i);
                std::cout << "Collison detection" << std::endl;

                /*Decrementing enemy's health*/
                enemy.setHealth(5);
                std::cout << "Enemy health: " << enemy.health << std::endl;
            }
        }
    }

    // make the rectangle follow the sprite
    boudingRectangle.setPosition(playerSprite.getPosition());


  
  

}


void  Player::Draw(sf::RenderWindow& window)
{
     window.draw(playerSprite);
     window.draw(boudingRectangle);
     for (size_t i = 0; i < bullets.size(); i++)
     {
         bullets[i].Draw(window);
     }
     
}
