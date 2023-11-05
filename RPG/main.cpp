#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "enemy.h"

constexpr int WIDTH = 720;
constexpr int HEIGHT = 720;


/*
 normalizing the vector Formula :a
 1 calculate its length, then,
 2 divide each of its (xy or xyz) components by its length
 */


int main()
{
    // ------------------- INIALIZE -----------------
    // antiliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG", sf::Style::Default, settings);
    window.setFramerateLimit(240); // setting up the framerate because it will lag idk why??? (to fix )
    /*Player Class Object*/
    Player player;
    player.Initialize();
    player.LoadplayerTexture();

    /*Enemy Class Object*/
    Enemy enemy;
    enemy.Initialize();
    enemy.LoadenemyTexture();
    
    // ----------------------  GAME LOOP ----------------------

    sf::Clock clock;
    while (window.isOpen())
    {
     
        // -------------------------- UPDATE --------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // FRAME CAPPING
        sf::Time deltaTimeTimer = clock.restart();;
        float deltaTime = deltaTimeTimer.asMilliseconds();

     

        player.Update(deltaTime, enemy); // player movement
        enemy.Update(deltaTime); // enemy movement
        

 
        /* --------------------------- DRAW -----------------
        We are doing all our drawing before copying all the data from the
        back bufffer to the main screen
        */
        window.clear(sf::Color::Black);

        player.Draw(window); // Drawing the player sprite
        enemy.Draw(window); // Drawing the enemy sprite

      
        // copying data from the back buffer
        window.display();

   
    }

    return 0;
}
