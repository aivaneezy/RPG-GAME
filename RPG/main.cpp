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

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG");

    // SHAPES
    sf::CircleShape shape;
    shape.setRadius(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(100.f ,200.f);
    std::cout << "Radius = " << shape.getRadius() << std::endl;
    shape.setOutlineThickness(10.f);

    sf::CircleShape Polygon;
    Polygon.setRadius(50.0f);
    Polygon.setPointCount(3);
    Polygon.setFillColor(sf::Color::Green);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100.f, 50.f));
    rect.setPosition(100.f, 100.f);
    rect.setFillColor(sf::Color::Blue);
    rect.setOrigin(sf::Vector2f(rect.getSize() / 2.0f));
    rect.setRotation(45.f);

    sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
    line.setPosition(200.f, 150.f);
    std::cout << "Rotate = " << line.getRotation();
    line.rotate(330.f);





    // main game loop
    while (window.isOpen())
    {
        // -------------------------- UPDATE --------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

        } // end whie loop

       



        /* --------------------------- DRAW -----------------
        We are doing all our drwaing before coyping all the data from
        back bufffer to the main screen
        */
        
        // drawing data to the back buffer 
        window.clear(sf::Color::Black);

        window.draw(shape);
        window.draw(Polygon);
        window.draw(rect);
        window.draw(line);

        // copying data from the back buffer
        window.display();
    }

    return 0;
}
