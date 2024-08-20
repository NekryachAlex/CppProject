#pragma once

#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

namespace algebra
{
    const sf::Vector2f zero_vector{ 0, 0 };

    inline float dist(const sf::Vector2f& vector1, const sf::Vector2f& vector2) {
        return sqrt(pow(vector1.x - vector2.x, 2) + pow(vector1.y - vector2.y, 2));
    }

    inline float length(const sf::Vector2f& vector) {
        return sqrt(vector.x*vector.x + vector.y*vector.y);
    }

    inline float dot(const sf::Vector2f& vector1, const sf::Vector2f& vector2) {
        return vector1.x * vector2.x + vector1.y * vector2.y;
    }

    inline sf::Vector2f norm(const sf::Vector2f& vector) {
        return vector / length(vector);
    }

    inline sf::Vector2f rotate(const sf::Vector2f& vector, float angle) {
        return  sf::Vector2f(
                (vector.x * cos(angle) + vector.y * sin(angle)),
                (vector.y * cos(angle) - vector.x * sin(angle))
                );
    }

    inline float angle(const sf::Vector2f& vector) {
        if (vector == algebra::zero_vector) return 0;
        return atan(vector.y / vector.x);
    }
}


