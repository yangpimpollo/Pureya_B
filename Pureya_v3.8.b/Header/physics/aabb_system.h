#pragma once
#ifndef AABB_SYSTEM_H_INCLUDED
#define AABB_SYSTEM_H_INCLUDED

#include "physics/objBox.h"

class aabb_system
{
public:
	aabb_system();
	~aabb_system();
	void update(sf::Event event, sf::Time deltaTime);
	inline void includeToScene(objBox& arg){ this->all_ABbox.push_back(&arg); }

	
private:
	std::vector<objBox*> all_ABbox;

};



#endif