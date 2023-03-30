#pragma once
#ifndef BOX_CONTROL_H_INCLUDED
#define BOX_CONTROL_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class game_core;

class box_control : public sf::Drawable
{
public:
	box_control();
	box_control(game_core& arg);
	~box_control();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	game_core* app;

	sf::CircleShape r1;
	sf::Vector2f position, size, center;

	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);
	sf::Color color3 = sf::Color(144, 0, 255);

	bool clic1 = false;
	bool selected = false;
	sf::Vector2f mosPoss0;
};


#endif