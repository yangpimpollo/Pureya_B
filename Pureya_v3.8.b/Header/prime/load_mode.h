#pragma once
#ifndef LOAD_MODE_H_INCLUDED
#define LOAD_MODE_H_INCLUDED

#include "prime/resource_station.h"
#include "prime/scene.h"

class load_mode : public scene
{
public:
	load_mode(game_core& arg);
	~load_mode();
	void update(sf::Event event, sf::Time deltaTime) override;
	void render() override;
	void destroy() override;
private:
	game_core* app;
	float angle = 0.f;

	sf::Text load_txt;
	sf::RectangleShape back, load1, load2;
	sf::Texture load1Tex, load2Tex;
	sf::Time totalTime;

	resource_station<load_res::res, load_res::stg>* res;

};


#endif