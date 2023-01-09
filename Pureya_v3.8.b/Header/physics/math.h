#pragma once
#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <SFML/Graphics.hpp>

sf::Vector2f normalize(sf::Vector2f vector) {

    float modulus = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

    if (!modulus == 0) {
        float vecX = vector.x / modulus;
        float vecY = vector.y / modulus;
        return sf::Vector2f(vecX, vecY);
    }
    else {
        return sf::Vector2f(0.f, 0.f);
    }
}



#endif

