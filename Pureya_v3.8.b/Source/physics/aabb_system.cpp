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
	std::vector<std::pair <float, int>> intervals;

	for (int i = 0; i < all_ABbox.size(); i++) {
		intervals.push_back(std::make_pair(all_ABbox[i]->getNexPosition().x, i));
		intervals.push_back(std::make_pair(all_ABbox[i]->getNexCorner().x, i));
	}
	quickSort(intervals, 0, intervals.size() - 1);

	std::vector<int> active;

	for (int i = 0; i < intervals.size(); i++) {
		bool isActive = false;
		for (int j = 0; j < active.size(); j++) {

			if (intervals[i].second != active[j]) {
				//collision
				if (!(all_ABbox[i]->getNexPosition().y > all_ABbox[j]->getNexCorner().y ||
					all_ABbox[i]->getNexCorner().y < all_ABbox[j]->getNexPosition().y)) {

					all_ABbox[i]->addActiveCollision(j);
					all_ABbox[j]->addActiveCollision(i);
				}
				//std::cout << "(" << intervals[i] << " - " << active[j] << ")" << std::endl;
			}
			else {
				active.erase(active.begin() + j);
				isActive = true;
				break;
			}
		}
		if (!isActive) active.push_back(intervals[i].second);
	}
}
