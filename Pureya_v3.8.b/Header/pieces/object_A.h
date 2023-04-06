#pragma once

#ifndef OBJECT_A_H_INCLUDED
#define OBJECT_A_H_INCLUDED

#include "physics/obj_box.h"

class game_core;


class object_A : public obj_box
{
public:
	object_A();
	object_A(game_core& arg);
	~object_A();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void render();
	void destroy();

private:
	//game_core* app;

};


#endif