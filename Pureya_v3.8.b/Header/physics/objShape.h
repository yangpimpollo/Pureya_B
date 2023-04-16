#pragma once
#ifndef OBJSHAPE_H_INCLUDED
#define OBJSHAPE_H_INCLUDED

#include "physics/objTex.h"
#include "physics/objBox.h"

class objShape : public objTex
{
public:
	objShape();
	objShape(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id = "none");
	~objShape();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline objBox* getObjBox() { return &collision_box; }

	inline void move(sf::Vector2f arg) { collision_box.move(arg); }

private:

	objBox collision_box;
	sf::Vector2f rel_collisionboxPos = sf::Vector2f(30.f, 30.f);
	sf::Vector2f collisionboxSize = sf::Vector2f(30.f, 30.f);

};


#endif

