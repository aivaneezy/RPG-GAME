#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "enemy.h"
#include "frameRate.h"
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
    window.setFramerateLimit(60); // setting up the framerate because it will lag idk why??? (to fix )
    /*Player Class Object*/
    Player player;
    player.Initialize();
    player.LoadplayerTexture();

    /*Enemy Class Object*/
    Enemy enemy;
    enemy.Initialize();
    enemy.LoadenemyTexture();

    /*FPS CLASS object*/
    FrameRate framerate;
    framerate.Load();
    
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
        /*DELTA TIME how long it takes to render a single frame.
            Conversion : 1 sec = 1000 ms.
                         1 ms = 1000 us
        */
        sf::Time deltaTimeTimer = clock.restart();;
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0; // dividing by 1000 to convert to to milliseconds

        /* Getting the mouse position relative to the window*/
        sf::Vector2f mousePosition = sf::Vector2f((sf::Mouse::getPosition(window))); 
        
        /*Rendering FPS*/
        framerate.Update(deltaTime, player);
        player.Update(deltaTime, enemy, mousePosition); // player movement
        enemy.Update(deltaTime); // enemy movement
        

 
        /* --------------------------- DRAW -----------------
        We are doing all our drawing before copying all the data from the
        back bufffer to the main screen
        */
        window.clear(sf::Color::Black);

        player.Draw(window); // Drawing the player sprite
        enemy.Draw(window); // Drawing the enemy sprite
        framerate.Draw(window); // Drawing the framerate sprite
      
        // copying data from the back buffer
        window.display();

       
    }

    return 0;
}
