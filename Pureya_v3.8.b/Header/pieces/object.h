#pragma once
#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "physics/square.h"

class game_core;

class object : public square
{
public:
	object();
	object(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id = "none");
	~object();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline void setTexture(sf::Texture arg) { obj_texture = arg; }

private:

	std::string id;
	sf::Texture obj_texture;

};



#endif