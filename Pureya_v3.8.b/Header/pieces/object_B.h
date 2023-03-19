#pragma once

#ifndef OBJECT_B_H_INCLUDED
#define OBJECT_B_H_INCLUDED

#include "physics/aabbox.h"

class game_core;


class object_B
{
public:
	object_B(game_core& arg);
	~object_B();
	void update(sf::Event event, sf::Time deltaTime);
	void render();
	void destroy();

private:
	game_core* app;
	aabbox b1;

};


#endif