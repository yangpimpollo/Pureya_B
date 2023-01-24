#pragma once
#ifndef AABB_SYSTEM_H_INCLUDED
#define AABB_SYSTEM_H_INCLUDED

#include "physics/aabbox.h"

class aabb_system
{
public:
	aabb_system();
	~aabb_system();
	void update(sf::Event event, sf::Time deltaTime);
	inline void includeToScene(aabbox& arg){ this->all_ABbox.push_back(&arg); }

	
private:
	std::vector<aabbox*> all_ABbox;
};



#endif