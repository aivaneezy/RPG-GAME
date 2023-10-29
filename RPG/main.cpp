#include <SFML/Graphics.hpp>
#include <iostream>


constexpr int WIDTH = 720;
constexpr int HEIGHT = 720;

int main()
{
    // ------------------- INIALIZE -----------------
    // antiliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG", sf::Style::Default, settings);
  
    // ----- LOAD ENEMY TEXTURE ------ 
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if (enemyTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Skeleton\\Texture\\spritesheet.png"))
    {
        std::cout << "Enemy texture loaded successfully" << std::endl;
        int XIndex = 1;
        int YIndex = 3;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64)); // Setting the rectangle for the sprite
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }

    // ----- LOAD PLAYER TEXTURE ------ 
    sf::Texture playertexture;
    sf::Sprite playersprite;
    // loading a texture
    if (playertexture.loadFromFile("C:\\Users\\Golden\\Desktop\\rpg-game-tutorial\\RPG\\assets\\Player\\Texture\\spritesheet.png"))
    {
        std::cout << "Loaded Successfully" << std::endl;

        int XIndex = 0; // x axes
        int YIndex = 0; // y axes

        playersprite.setTexture(playertexture);
        playersprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64)); // Setting the rectangle for the sprite
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }
  
    
    printf("Hello");

    // ------- GANE LOOP ------

    // main game loop
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

        // PLAYERS MOVEMENT
        sf::Vector2f positionPlayer = playersprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {   
            playersprite.setPosition(positionPlayer + sf::Vector2f(0, -1)); // curr position - 1 units to the y axis
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {      
            playersprite.setPosition(positionPlayer + sf::Vector2f(0, 1)); // curr position + 1 units to the y axis
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playersprite.setPosition(positionPlayer + sf::Vector2f(1, 0)); // curr position + 1 units to the x axis
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playersprite.setPosition(positionPlayer + sf::Vector2f(-1, 0)); // curr position - 1 units to the x axis
        }
           
        // Enemy Movement
        sf::Vector2f positionEnemy = enemySprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            enemySprite.setPosition(positionEnemy + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            enemySprite.setPosition(positionEnemy + sf::Vector2f(0, 1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            enemySprite.setPosition(positionEnemy + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            enemySprite.setPosition(positionEnemy + sf::Vector2f(1,0));
        }


        /* --------------------------- DRAW -----------------
        We are doing all our drwaing before coyping all the data from
        back bufffer to the main screen
        */
        
        // drawing data to the back buffer 
        window.clear(sf::Color::Blue);

      
        window.draw(playersprite);
        window.draw(enemySprite);
        // copying data from the back buffer
        window.display();
    }

    return 0;
}
