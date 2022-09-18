#pragma once
#ifndef GAME_WINDOW_H_INCLUDED
#define GAME_WINDOW_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "prime/data_manager.h"

class game_core;

class game_window : public sf::RenderWindow
{
public:
	game_window(game_core& arg);
	~game_window();
	void winEvents(sf::Event event);
	void setWinView();

private:
	game_core* app;

	sf::Cursor cursor;
	bool activeCursor = true;

};


#endif

