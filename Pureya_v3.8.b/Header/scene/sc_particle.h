#pragma once
#ifndef SC_PARTICLE_H_INCLUDED
#define SC_PARTICLE_H_INCLUDED

#include "prime/scene.h"
#include "pieces/particle.h"

class sc_particle : public scene
{
public:
	sc_particle(game_core& arg);
	~sc_particle();
	void update(sf::Event event, sf::Time deltaTime) override;
	void render() override;
	void destroy() override;

private:
	game_core* app;
	sf::RectangleShape back, bigbox;

	particle p1;

};


#endif
