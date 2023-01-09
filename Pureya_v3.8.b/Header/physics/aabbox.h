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
	aabbox(float x, float y, float w, float h, bool solid);
	~aabbox();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void move(float _x, float _y);
	void setPosition(float x, float y);


private:
	bool solid;
	float x, y, w, h;
	float speed = 0.5f;
	sf::RectangleShape drawABox;
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);

	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);

	//std::vector<ABbox*>* all_ABbox;
};


#endif