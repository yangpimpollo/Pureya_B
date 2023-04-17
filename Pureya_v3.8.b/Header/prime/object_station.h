#pragma once
#ifndef OBJECT_STATION_H_INCLUDED
#define OBJECT_STATION_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string> 

class object_station
{
public:
	object_station();
	object_station(std::string name);
	~object_station();
	void readObjects();

private:
	std::string name;
};

inline object_station::object_station()
{
}

inline object_station::object_station(std::string name) : name(name)
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






	initFile.close();
}
















#endif