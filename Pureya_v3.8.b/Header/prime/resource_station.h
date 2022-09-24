#pragma once
#ifndef RESOURCE_STATION_H_INCLUDED
#define RESOURCE_STATION_H_INCLUDED

#define set_path "../config/settings.wo"

#include <codecvt>
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "prime/label_space.h"

template <typename EnumA, typename EnumB>

class resource_station
{
public:
	resource_station(std::string name);
	~resource_station();
	void loadSettings();
	void readResources();
	void setLanguaje(language arg);

	inline sf::Font& getFont(EnumA id) { return font.at(id); };
	inline sf::Texture& getTexture(EnumA id) { return texture.at(id); };
	inline sf::SoundBuffer& getSound(EnumA id) { return sound.at(id); };

	inline std::wstring& getStg(EnumB id) { return stg[stgmap.at(id)]; };
	inline int& getSet(settings id) { return setmap.at(id); };

	inline bool getComplete() { return complete; };
	std::wstring to_wstring(std::string str);

	
private:
	bool complete = false;
	std::string name;
	std::wstring* en_pack;
	std::wstring* zh_pack;
	std::wstring* sp_pack;
	std::wstring* stg;

	std::map<EnumA, sf::Font> font;
	std::map<EnumA, sf::Texture> texture;
	std::map<EnumA, sf::SoundBuffer> sound;
	std::map<EnumB, int> stgmap;
	std::map<settings, int> setmap;

};

template<typename EnumA, typename EnumB>
inline resource_station<EnumA, typename EnumB>::resource_station(std::string name) : name(name)
{
	std::cout << "load scene resources" << std::endl;
	loadSettings();
	readResources();
	setLanguaje(language(getSet(settings::lan)));
	complete = true;
}

template<typename EnumA, typename EnumB>
inline resource_station<EnumA, typename EnumB>::~resource_station()
{
	delete[] en_pack;
	delete[] zh_pack;
	delete[] sp_pack;
	std::cout << "delete " << name << " resources" << std::endl;
}

template<typename EnumA, typename EnumB>
inline void resource_station<EnumA, EnumB>::loadSettings()
{
	setmap.clear();
	std::string setDat;
	std::fstream settingFile;
	settingFile.open(set_path, std::ios::in | std::ios::out | std::ios::app);
	for (int i = 0; i < 7; i++) {
		getline(settingFile, setDat);
		std::string delim = ":";
		auto end = setDat.find(delim) + 1;
		setmap.insert(std::make_pair(settings(i), std::stoi(setDat.substr(end, setDat.length() - end))));
	}
	settingFile.close();
}

template<typename EnumA, typename EnumB>
inline void resource_station<EnumA, typename EnumB>::readResources()
{
	int ftsx[4];
	std::string datatext;
	std::fstream initFile;
	initFile.open("../config/" + name + ".txt", std::ios::in | std::ios::out | std::ios::app);

	getline(initFile, datatext);
	getline(initFile, datatext);
	std::cout << "   name:  " << datatext << std::endl;
	getline(initFile, datatext);
	getline(initFile, datatext);
	auto ini = 0;
	auto end = datatext.find(":", ini);
	for (int i = 0; i < 4; i++) {
		ftsx[i] = std::stoi(datatext.substr(ini, datatext.find(":", ini)));
		ini = end + 1;
		end = datatext.find(":", ini);
	}

	en_pack = new std::wstring[ftsx[3]];
	zh_pack = new std::wstring[ftsx[3]];
	sp_pack = new std::wstring[ftsx[3]];


	getline(initFile, datatext);
	getline(initFile, datatext);

	for (int i = 0; i < (ftsx[0] + ftsx[1] + ftsx[2]); i++) {
		auto ini = datatext.find("#", 0) + 3;
		auto end = datatext.length() - ini;
		//std::cout << "   -" << datatext.substr(ini,end-ini) << std::endl;

		if (i < ftsx[0]) {
			sf::Font res;
			if (!res.loadFromFile("../res/" + name + "/" + datatext.substr(ini, end - ini))){}
			font.insert(std::make_pair(EnumA(i), res));
			std::cout << "   -" << datatext.substr(ini, end - ini) << std::endl;
		}
		if (i>= ftsx[0] && i<(ftsx[0] + ftsx[1])) {
			sf::Texture res;
			if (!res.loadFromFile("../res/" + name + "/" + datatext.substr(ini, end - ini))){}
			texture.insert(std::make_pair(EnumA(i), res));
			std::cout << "   -" << datatext.substr(ini, end - ini) << std::endl;
		}
		if (i >= (ftsx[0] + ftsx[1])) {
			sf::SoundBuffer res;
			if (!res.loadFromFile("../res/" + name + "/" + datatext.substr(ini, end - ini))){}
			sound.insert(std::make_pair(EnumA(i), res));
			std::cout << "   -" << datatext.substr(ini, end - ini) << std::endl;
		}


		getline(initFile, datatext);
	}

	getline(initFile, datatext);
	for (int i = 0; i < ftsx[3]; i++) {
		auto ini = datatext.find("#", 0) + 1;
		auto end = datatext.find("#", ini);
		en_pack[i] = to_wstring(datatext.substr(ini, end - ini));
		ini = end + 1;
		end = datatext.find("#", ini);
		zh_pack[i] = to_wstring(datatext.substr(ini, end - ini));
		ini = end + 1;
		end = datatext.find("#", ini);
		sp_pack[i] = to_wstring(datatext.substr(ini, end - ini));

		stgmap.insert(std::make_pair(EnumB(i), i));
		getline(initFile, datatext);
	}
	
}

template<typename EnumA, typename EnumB>
inline void resource_station<EnumA, EnumB>::setLanguaje(language arg)
{
	switch (arg) {
		case language::EN:  stg = en_pack; break;
		case language::ZH:  stg = zh_pack; break;
		case language::SP:  stg = sp_pack; break;
		default: stg = zh_pack; break;
	}
}

template<typename EnumA, typename EnumB>
inline std::wstring resource_station<EnumA, typename EnumB>::to_wstring(std::string str)
{
	using convert_t = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.from_bytes(str);
}

#endif