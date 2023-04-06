#pragma once
#ifndef AABB_SYSTEM_H_INCLUDED
#define AABB_SYSTEM_H_INCLUDED

#include "physics/obj_box.h"

class aabb_system
{
public:
	aabb_system();
	~aabb_system();
	void update(sf::Event event, sf::Time deltaTime);
	inline void includeToScene(obj_box& arg){ this->all_ABbox.push_back(&arg); }

	
private:
	std::vector<obj_box*> all_ABbox;

};



#endif