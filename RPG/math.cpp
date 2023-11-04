#include "mathh.h"


sf::Vector2f Math::normalizeVector(sf::Vector2f vector)
{
    // calculating the magnitude of the vector
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    // normalizzing the vector
    sf::Vector2f normalizeVector;
    normalizeVector.x = vector.x / magnitude;
    normalizeVector.y = vector.y / magnitude;

    return normalizeVector; 

}

/*

rect1.right > rect2.left &&
rect2.right > rect1.left &&

rect2.bottom > rect1.top &&
rect1.bottom > rect2.top

*/

bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.left + rect1.width > rect2.left &&
        rect2.left + rect2.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top) return true;
    return false;


    /*SFML SIMPLE VERSION*/
   /* if (rect1.intersects(rect2)) return true;
    return false;*/
}
