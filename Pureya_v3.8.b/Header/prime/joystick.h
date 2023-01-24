#pragma once
#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class joystick
{
public:
	joystick();
	~joystick();
	void update();
	inline sf::Vector2f getLjoystick() { return Ljoystick;  }

private:
	int direction_st = 0;
	float x0, x1, x2, y0, y1, y2, Ljoy_X, Ljoy_Y;
	bool n_st = false, s_st = false, w_st = false, e_st = false;
	sf::Vector2f Ljoystick = sf::Vector2f(0.f, 0.f);
	sf::Vector2f Rjoystick = sf::Vector2f(0.f, 0.f);

};









#endif