#include "physics/aabb_system.h"

aabb_system::aabb_system()
{
}

aabb_system::~aabb_system()
{
	std::cout << "delete aabb_system" << std::endl;
}

void aabb_system::update(sf::Event event, sf::Time deltaTime)
{
	if (all_ABbox.at(0)->getPosition().y < 200) {
		std::cout << "menor a 200" << std::endl;
	}
}
