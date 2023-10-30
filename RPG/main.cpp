#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

constexpr int WIDTH = 720;
constexpr int HEIGHT = 720;
constexpr float BULLETSPEED = 0.3f;

/*
 normalizing the vector Formula :a
 1 calculate its length, then,
 2 divide each of its (xy or xyz) components by its length
 */
sf::Vector2f normalizeVector(sf::Vector2f vector)
{
    // calculating the magnitude of the vector
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    // normalizzing the vector
    sf::Vector2f normalizeVector;
    normalizeVector.x = vector.x / magnitude;
    normalizeVector.y = vector.y / magnitude;

    return normalizeVector;

}

int main()
{
    // ------------------- INIALIZE -----------------
    // antiliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG", sf::Style::Default, settings);

    // ---------------- SHOOTING A BULLETS ----------------------
   /*
       SHOOTING A BULLET DIRECTION FORMULA : DIRECTION = (TARGET - CURRENT POSITION).normalize()
       the normalize is to convert a vector into a  units.
   */
   // vector of multiple bullets
    std::vector<sf::RectangleShape> bullets;
  
   


    // ---------------- LOAD TEXTURE -------------------------------
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
        enemySprite.setPosition(400, 0); // Initial Position
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
        playersprite.setPosition(sf::Vector2f(600, 600)); // Initial position
    }
    else
    {
        std::cout << "Cannot Load an Image" << std::endl;
    }


    // ----------------------  GAME LOOP ----------------------

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
            playersprite.setPosition(positionPlayer - sf::Vector2f(0, 1)); // curr position - 1 units to the y axis
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
            playersprite.setPosition(positionPlayer - sf::Vector2f(1, 0)); // curr position - 1 units to the x axis
        }

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

        // EVENT FOR MOUSE FOR THE BULLETS
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50.f, 25.f)));

            int lastElement = bullets.size() - 1; // last element of the vector
            bullets[lastElement].setPosition(playersprite.getPosition()); // Bullet Initial Position

        }

        /* Moving the bullets to a target*/
        //sf::Vector2f bullet_direction = bullet.getPosition();
        //bullet.setPosition(bullet_direction + direction * BULLETSPEED); // multipying of a very small amount to normalize the vector
        for (int i = 0; i < bullets.size(); i++)
        {
            /* Calculating the  direction for the bullet, putting the bullet inside the  for loop is useful so that each bullets has its own calculation 
            in each single frame when a player shot.
            */
            sf::Vector2f direction = enemySprite.getPosition() - bullets[i].getPosition();
          
            /* Moving the bullets to a target*/
            direction = normalizeVector(direction);
            bullets[i].setPosition(bullets[i].getPosition() + direction * BULLETSPEED);
        }





        /* --------------------------- DRAW -----------------
        We are doing all our drwaing before coyping all the data from
        back bufffer to the main screen
        */

        // drawing data to the back buffer 
        window.clear(sf::Color::Black);


        window.draw(playersprite);
        window.draw(enemySprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        
        // copying data from the back buffer
        window.display();
    }

    return 0;
}
