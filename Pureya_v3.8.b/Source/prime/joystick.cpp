#include "prime/joystick.h"

joystick::joystick()
{
}

joystick::~joystick()
{
}

void joystick::update()
{
    x1 = (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ? -1.f : 0.f;
    x2 = (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ? 1.f : 0.f;
    y1 = (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ? -1.f : 0.f;
    y2 = (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ? 1.f : 0.f;

    Ljoy_X = x1 + x2;
    Ljoy_Y = y1 + y2;

    x0 = std::floor(sf::Joystick::getAxisPosition(0, sf::Joystick::X));
    y0 = std::floor(sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

    if (!(x0 == 0 && y0 == 0)) {
        Ljoy_X = x0 / 100.f;
        Ljoy_Y = y0 / 100.f;
    }

    Ljoystick = normalize(sf::Vector2f(Ljoy_X, Ljoy_Y));

    if (std::abs(Ljoystick.x) < 0.5f && Ljoystick.y <= -1) {
        //std::cout << "n" << std::endl;
        direction_st = 1;
    }
    if (std::abs(Ljoystick.x) < 0.5f && Ljoystick.y >= 1) {
        //std::cout << "s" << std::endl;
        direction_st = 2;
    }
    if (std::abs(Ljoystick.y) < 0.5f && Ljoystick.x <= -1) {
        //std::cout << "w" << std::endl;
        direction_st = 3;
    }
    if (std::abs(Ljoystick.y) < 0.5f && Ljoystick.x >= 1) {
        //std::cout << "e" << std::endl;
        direction_st = 4;
    }

    if (Ljoystick == sf::Vector2f(0.f, 0.f)) {
        switch (direction_st) {
        case 1: n_st = true; direction_st = 0; break;  //std::cout << "n" << std::endl; break;
        case 2: s_st = true; direction_st = 0; break;  //std::cout << "s" << std::endl; break;
        case 3: w_st = true; direction_st = 0; break;  //std::cout << "w" << std::endl; break;
        case 4: e_st = true; direction_st = 0; break;  //std::cout << "e" << std::endl; break;
        default: n_st = false; s_st = false; w_st = false; e_st = false; break;
        }
    }
}
