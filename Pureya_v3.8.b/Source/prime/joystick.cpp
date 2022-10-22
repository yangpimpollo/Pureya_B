#include "prime/joystick.h"

joystick::joystick()
{
}

joystick::~joystick()
{
}

void joystick::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "A" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		std::cout << "B" << std::endl;
	}
}
