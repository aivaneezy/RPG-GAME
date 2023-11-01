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