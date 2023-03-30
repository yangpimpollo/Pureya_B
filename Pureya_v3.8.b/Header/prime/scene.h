#pragma once
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "physics/aabb_system.h"


class game_core;

class scene : public sf::Drawable
{
public:
	// abstract class
	//scene(){};
	//~scene(){ std::cout << "delete scene" << std::endl; };
	virtual void update(sf::Event event, sf::Time deltaTime) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) {};
	//virtual void render() {};
	virtual void destroy() {};
	

private:

protected:
	aabb_system aabbSystem;
	

};






#endif