#pragma once
#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>

class particle : public sf::Drawable
{
public:
	particle();
	particle(float r, float x, float y);
	~particle();
	void update(sf::Event event, sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	float radius, px, py, dx, dy;

	sf::CircleShape circle;

};

#endif