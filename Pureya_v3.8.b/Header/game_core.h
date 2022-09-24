#pragma once
#ifndef GAME_CORE_H_INCLUDED
#define GAME_CORE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "prime/debug_mode.h"
#include "prime/game_window.h"
#include "prime/resource_station.h"
#include "prime/scene_manager.h"

class game_core
{
public:
	game_core();
	~game_core();
	void start();
	inline bool setReset(bool arg) { this->resetRequest=arg; };
	
	debug_mode* debug;
	game_window* window; 
	scene_Manager* scene_mng;
	resource_station<global::res, global::stg>* res;
	
private:
	int fps;
	bool resetRequest = false;

	void init();
	void cicles();
	void update(sf::Event event, sf::Time deltaTime);
	void render();

	sf::Context context;

};



#endif