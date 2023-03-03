#pragma once
#ifndef SC_PHYSICS1_H_INCLUDED
#define SC_PHYSICS1_H_INCLUDED

#include "prime/scene.h"
#include "physics/aabbox.h"

class sc_Physics1 : public scene
{
public:
	sc_Physics1(game_core& arg);
	~sc_Physics1();
	void update(sf::Event event, sf::Time deltaTime) override;
	void render() override;
	void destroy() override;

private:
	game_core* app;
	sf::RectangleShape back;

	aabbox b1;
	aabbox b2;
	aabbox b3;
	aabbox c1;
	aabbox c2;
	aabbox c3;
};


#endif