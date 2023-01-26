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
	std::pair <float, float>* intervals = new std::pair <float, float>[all_ABbox.size() * 2];

	for (int i = 0; i < all_ABbox.size(); i++) {
		intervals[2 * i] = std::make_pair(all_ABbox[i]->getNexPosition().x, i);
		intervals[2 * i + 1] = std::make_pair(all_ABbox[i]->getNexCorner().x, i);
	}

	std::cout << "size : " << &intervals.size() << std::endl;


	if (intervals[1].first > 450) {
		std::cout << "=" << all_ABbox.size() << std::endl;
	}

	delete[] intervals;
}
