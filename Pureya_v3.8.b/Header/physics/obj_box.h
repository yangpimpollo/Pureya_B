#pragma once
#ifndef OBJ_BOX_H_INCLUDED
#define OBJ_BOX_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class game_core;

class obj_box : public sf::Drawable
{
public:
	obj_box();
	obj_box(game_core& arg, sf::Vector2f position, sf::Vector2f size);
	~obj_box();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline sf::Vector2f getPosition() { return position; }
	inline sf::Vector2f getCorner() { return position + size; }

private:

	void clickPress();
	void StatusMode();
	void clickRelease();

	game_core* app;
	sf::RectangleShape drawABox;
	sf::CircleShape r1, r2, r3, r4, r5;
	

	sf::Vector2f position, size, center;
	sf::Vector2f mousePos;
	sf::Vector2f mosPoss0;
	sf::Vector2f size0;
	sf::Vector2f position0;


	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);
	sf::Color color3 = sf::Color(144, 0, 255);

	bool click = false;
	int click_status;
	bool selected = false;
	bool inR1, inR2, inR3, inR4, inBox;
};

#endif
