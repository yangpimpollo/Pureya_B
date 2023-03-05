#pragma once
#ifndef AABBOX_H_INCLUDED
#define AABBOX_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class game_core;

class aabbox : public sf::Drawable
{
public:
	aabbox();
	aabbox(game_core& arg, sf::Vector2f position, sf::Vector2f size);
	~aabbox();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline void move(sf::Vector2f arg) { this->direction = normalize(arg); }
	inline void setPosition(sf::Vector2f arg) { this->position = arg; }

	inline sf::Vector2f getPosition() { return position; }
	inline sf::Vector2f getCorner() { return position + size; }
	inline sf::Vector2f getDirection() { return direction; }
	
	inline sf::Vector2f getNexPosition() { return position + (direction * speed); }
	inline sf::Vector2f getNexCorner() { return position + size + (direction * speed); }

	inline void setAllBox(std::vector<aabbox*>& all_ABbox_arg) { this->all_ABbox = all_ABbox_arg; }
	inline void addActiveCollision(int arg) { this->active.push_back(arg);}

private:
	game_core* app;
	std::vector<aabbox*> all_ABbox;



	float speed = 0.10f;
	sf::Vector2f position, size, center;
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);
	sf::RectangleShape drawABox;
	sf::CircleShape r1,r2,r3,r4, r5;
	sf::Vertex lineL[2], lineR[2];

	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);
	sf::Color color3 = sf::Color(144, 0, 255);

	std::vector<int> active;

	//std::vector<ABbox*>* all_ABbox;

	bool clic1 = false;
	bool selected = false;
	sf::Vector2f mosPoss0;

};


#endif