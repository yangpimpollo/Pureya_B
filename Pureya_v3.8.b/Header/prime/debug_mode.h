#pragma once
#ifndef DEBUG_MODE_H_INCLUDED
#define DEBUG_MODE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class game_core;

class debug_mode : public sf::Drawable
{
public:
	debug_mode(game_core& arg);
	~debug_mode();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void set_fps(int arg);
	inline int getDebug_toggle() const { return debug_toggle; };
	inline void setDebug_toggle(bool arg) { this->debug_toggle = arg; };

	inline void setD1(sf::String arg) { d1 = arg; };
	inline void setD2(sf::String arg) { d2 = arg; };
	inline void setD3(sf::String arg) { d3 = arg; };
	inline void setD4(sf::String arg) { d4 = arg; };

private:
	game_core* app;
	sf::Text fps_txt, mouse_X, mouse_Y, lang_test, text, pauseStatus;
	sf::Text joyX, joyY, NjoyX, NjoyY;
	sf::Text debug1, debug2, debug3, debug4;
	bool debug_toggle;

	sf::String d1, d2, d3, d4;
};


#endif