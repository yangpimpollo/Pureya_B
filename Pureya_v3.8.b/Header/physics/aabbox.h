#pragma once
#ifndef AABBOX_H_INCLUDED
#define AABBOX_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class aabbox : public sf::Drawable
{
public:
	aabbox();
	aabbox(sf::Vector2f position, sf::Vector2f size, bool solid);
	~aabbox();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline void move(sf::Vector2f arg) { this->direction = normalize(arg); }
	inline void setPosition(sf::Vector2f arg) { this->position = arg; }

	inline sf::Vector2f getPosition() { return position; }
	inline sf::Vector2f getDirection() { return direction; }
	
	inline sf::Vector2f getNexPosition() { return position + (direction * speed); }
	inline sf::Vector2f getNexCorner() { return position + size + (direction * speed); }

	inline void addActiveCollision(int arg) { this->active.push_back(arg);}

private:
	bool solid;
	float speed = 0.08f;
	sf::Vector2f position, size;
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);
	sf::RectangleShape drawABox;

	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);

	std::vector<int> active;

	//std::vector<ABbox*>* all_ABbox;
};


#endif