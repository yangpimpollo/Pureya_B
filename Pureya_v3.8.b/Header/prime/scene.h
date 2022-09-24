#pragma once
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class game_init;

class scene
{
public:
	// abstract class
	//scene(){};
	//~scene(){ std::cout << "delete scene" << std::endl; };
	virtual void update(sf::Event event, sf::Time deltaTime) {};
	virtual void render() {};
	virtual void destroy() {};

private:

};






#endif