#pragma once
#ifndef OBJECT_STATION_H_INCLUDED
#define OBJECT_STATION_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <sstream>
#include "prime/resource_station.h"
#include "physics/objTex.h"

class object_station
{
public:
	object_station();
	object_station(game_core& arg, std::string name);
	~object_station();
	void readObjects();

private:
	game_core* app;
	std::string name;

	std::vector<objTex*> all_TexBox;

};

inline object_station::object_station()
{
}

inline object_station::object_station(game_core& arg, std::string name) : app(&arg), name(name)
{
	std::cout << "load scene objects" << std::endl;
	readObjects();
}

inline object_station::~object_station()
{
	std::cout << "delete " << name << " objects" << std::endl;
}

inline void object_station::readObjects()
{
	int ftsx[3];
	std::string datatext;
	std::fstream initFile;
	initFile.open("../data/" + name + ".wo", std::ios::in | std::ios::out | std::ios::app);
	if (!initFile) {
		std::cout << "Error occurred: file not loaded" << std::endl;
		exit(-1);
	}
	getline(initFile, datatext);
	getline(initFile, datatext);
	std::cout << "   name:  " << datatext << std::endl;
	getline(initFile, datatext);
	getline(initFile, datatext);
	auto ini = 0;
	auto end = datatext.find(":", ini);
	for (int i = 0; i < 3; i++) {
		ftsx[i] = std::stoi(datatext.substr(ini, datatext.find(":", ini)));
		ini = end + 1;
		end = datatext.find(":", ini);
	}

	getline(initFile, datatext);
	getline(initFile, datatext);

	for (int i = 0; i < ftsx[0]; i++) {
		
		std::stringstream s_stream(datatext);
		std::vector<std::string> s_array;
		std::string temp;
		while (std::getline(s_stream, temp, '#')) {
			s_array.push_back(temp);
		}

		sf::Vector2f post = sf::Vector2f(std::stof(s_array[1]), std::stof(s_array[2]));
		sf::Vector2f size = sf::Vector2f(std::stof(s_array[3]), std::stof(s_array[4]));
		float b = std::stof(s_array[5]);
		float t = std::stoi(s_array[6]);

		objTex obj = objTex(*app, post, size, s_array[7]);

		std::cout << "   size:  " << s_array.size() << std::endl;
		getline(initFile, datatext);
	}



	initFile.close();
}
















#endif