#pragma once
#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "physics/math.h"

class game_core;

class square : public sf::Drawable
{
public:
	square();
	square(game_core& arg, sf::Vector2f position, sf::Vector2f size);
	~square();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline sf::Vector2f getPosition() { return position; }
	inline sf::Vector2f getSize() { return size; }
	inline sf::Vector2f getDirection() { return direction; }
	inline sf::Vector2f getCorner() { return position + size; }
	inline bool getSelected() { return selected; }

	inline void setPosition(sf::Vector2f arg) { position = arg; }
	inline void setSize(sf::Vector2f arg) { size = arg; }
	inline void move(sf::Vector2f arg) { direction = normalize(arg); }
	inline void setEditMode(bool arg) { edit_mode = arg; }

protected:
	game_core* app;
	sf::Vector2f position, size;

	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);
	float speed = 0.10f;

	sf::RectangleShape drawABox;
	sf::CircleShape r1, r2, r3, r4, r5;
	sf::Vertex lineL[2], lineR[2];
	sf::Color color1 = sf::Color(64, 224, 208);
	sf::Color color2 = sf::Color(224, 62, 78);
	sf::Color color3 = sf::Color(144, 0, 255);

	//   ...  temporal funtions ........

	void clickPress();
	void StatusMode();
	void clickRelease();

	//   ...  temporal variables .......

	sf::Vector2f mousePos;
	sf::Vector2f mosPoss0;
	sf::Vector2f size0;
	sf::Vector2f position0;

	int click_mode;
	bool click = false;
	bool selected = false;
	bool inR1, inR2, inR3, inR4, inR5, inBox;
	bool edit_mode = true;

};





#endif
