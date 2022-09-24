#pragma once
#ifndef GAME_WINDOW_H_INCLUDED
#define GAME_WINDOW_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class game_core;

class game_window : public sf::RenderWindow
{
public:
	game_window(game_core& arg);
	~game_window();
	void winEvents(sf::Event event);
	inline void setWinView(){ this->setView(*view); };
	inline bool getPauseStatus() const { return this->pause; };
	inline sf::Vector2i getMousePosition() const { return mouse_pos; };

private:
	game_core* app;

	bool pause = false;
	bool activeCursor = true;

	sf::View* view;
	sf::Cursor cursor;
	sf::Vector2i mouse_pos;
	sf::Vector2f viewSize;

};


#endif

