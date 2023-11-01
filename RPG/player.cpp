
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "mathh.h"
void Player::Initialize()
{
   
}

void Player::LoadplayerTexture()
{
	  if (playerTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Player\\Texture\\spritesheet.png"))
    {
        std::cout << "Loaded Successfully" << std::endl;

        int XIndex = 0; // x axes
        int YIndex = 0; // y axes

       playerSprite.setTexture(Player::playerTexture);
       playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64)); // Setting the rectangle for the sprite
       playerSprite.setPosition(sf::Vector2f(600, 600)); // Initial position
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }
}



void Player::Update(Enemy& enemy)
{

    // PLAYERS MOVEMENT
    sf::Vector2f positionPlayer = playerSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerSprite.setPosition(positionPlayer - sf::Vector2f(0, 1)); // curr position - 1 units to the y axis
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerSprite.setPosition(positionPlayer + sf::Vector2f(0, 1)); // curr position + 1 units to the y axis
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite.setPosition(positionPlayer + sf::Vector2f(1, 0)); // curr position + 1 units to the x axis
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerSprite.setPosition(positionPlayer - sf::Vector2f(1, 0)); // curr position - 1 units to the x axis
    }

    // EVENT FOR MOUSE FOR THE BULLETS
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50.f, 25.f)));

        int lastElement = bullets.size() - 1; // last element of the vector
        bullets[lastElement].setPosition(playerSprite.getPosition()); // Bullet Initial Position

    }


    // ---------------- SHOOTING A BULLETS ----------------------
/*
    SHOOTING A BULLET DIRECTION FORMULA : DIRECTION = (TARGET - CURRENT POSITION).normalize()
    the normalize is to convert a vector into a  units.
*/
    /* Moving the bullets to a target*/
    for (size_t i = 0; i < bullets.size(); i++)
    {
        /* Calculating the  direction for the bullet, putting the bullet inside the  for loop is useful so that each bullets has its own calculation
        in each single frame when a player shot.
        */
        sf::Vector2f direction = enemy.enemySprite.getPosition() - bullets[i].getPosition();

        /* Moving the bullets to a target*/
        direction = Math::normalizeVector(direction);
        bullets[i].setPosition(bullets[i].getPosition() + direction * bulletspeed); // multipying of a very small amount to normalize the vector
    }

}


void  Player::Draw(sf::RenderWindow& window)
{
     window.draw(playerSprite);
     for (int i = 0; i < bullets.size(); i++)
     {
         window.draw(bullets[i]);
     }
     
}
