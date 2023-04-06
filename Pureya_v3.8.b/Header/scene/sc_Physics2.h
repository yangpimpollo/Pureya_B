#pragma once
#ifndef SC_PHYSICS2_H_INCLUDED
#define SC_PHYSICS2_H_INCLUDED

#include "prime/scene.h"
#include "physics/obj_box.h"

class sc_Physics2 : public scene
{
public:
	sc_Physics2(game_core& arg);
	~sc_Physics2();
	void update(sf::Event event, sf::Time deltaTime) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void destroy() override;

private:
	game_core* app;
	sf::RectangleShape back;

	obj_box b1, b2;
};


#endif