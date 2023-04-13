#pragma once
#ifndef OBJTEX_H_INCLUDED
#define OBJTEX_H_INCLUDED

#include "physics/square.h"


class objTex : public square
{
public:
	objTex();
	objTex(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id = "none");
	~objTex();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline std::string getID() { return id; }

	inline void setTexture(sf::Texture arg) { obj_texture = arg; }
	inline void setID(std::string arg) { id = arg; }

private:

	std::string id;
	sf::Texture obj_texture;
};



#endif