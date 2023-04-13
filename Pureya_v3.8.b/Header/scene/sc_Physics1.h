#pragma once
#ifndef SC_PHYSICS1_H_INCLUDED
#define SC_PHYSICS1_H_INCLUDED

#include "prime/scene.h"
#include "physics/objBox.h"
#include "pieces/object_A.h"

class sc_Physics1 : public scene
{
public:
	sc_Physics1(game_core& arg);
	~sc_Physics1();
	void update(sf::Event event, sf::Time deltaTime) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void destroy() override;

private:
	game_core* app;
	sf::RectangleShape back;

	objBox b1;
	objBox b2;
	objBox b3;

	object_A aa1;
};


#endif