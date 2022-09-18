#pragma once
#ifndef GAME_CORE_H_INCLUDED
#define GAME_CORE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "prime/game_window.h"
#include "prime/resource_station.h"
#include "prime/data_manager.h"

class game_core
{
public:
	game_core();
	~game_core();
	void start();

	bool resetRequest = false;
	sf::Context context;
	resource_station<global::res,global::stg>* res;
	game_window* window;

private:
	int fps;

	void init();
	void cicles();
	void update(sf::Event event, sf::Time deltaTime);
	void render();
};



#endif