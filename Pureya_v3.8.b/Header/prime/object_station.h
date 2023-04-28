#pragma once
#ifndef OBJECT_STATION_H_INCLUDED
#define OBJECT_STATION_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string> 
#include <vector>
#include <sstream>
#include "physics/math.h"
#include "physics/objTex.h"


class object_station
{
public:
	object_station();
	object_station(game_core& arg, std::vector<sf::Texture> texArray,std::string name);
	~object_station();

	void update(sf::Event event, sf::Time deltaTime);
	void readObjects();

	std::vector<objTex> getAllTexBox() { return all_TexBox; };


private:
	game_core* app;

	std::string name;
	std::vector<sf::Texture> texArray;
	std::vector<objTex> all_TexBox;

};










#endif