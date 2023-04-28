#include "prime/object_station.h"
#include "game_core.h"

object_station::object_station()
{
}

object_station::object_station(game_core& arg, std::vector<sf::Texture> texArray, std::string name)
	: app(&arg), texArray(texArray), name(name)
{
	std::cout << "load scene objects" << std::endl;
	readObjects();
}

object_station::~object_station()
{
	std::cout << "delete " << name << " objects" << std::endl;
}

void object_station::update(sf::Event event, sf::Time deltaTime)
{
	for (int i = 0; i < all_TexBox.size(); i++) {
		all_TexBox[i].update(event, deltaTime);
	}
	float d = all_TexBox[2].getZbuffer();
}

//void object_station::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
	//std::vector<std::pair <float, int>> intervals;
	//float d = all_TexBox[2].getZbuffer();


	//for (int i = 0; i < all_TexBox.size(); i++) {
	//	intervals.push_back(std::make_pair(all_TexBox[i].getZbuffer(), i));
	//}

	//for (const auto& value : all_TexBox) {
	//	target.draw(value);
	//}
//
//
//}

void object_station::readObjects()
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
		//float b = std::stof(s_array[5]);
		//float t = std::stoi(s_array[6]);

		objTex obj = objTex(*app, post, size, s_array[7]);
		obj.setZbuffer(std::stof(s_array[5]));
		obj.setTexture(texArray[std::stoi(s_array[6])]);
		all_TexBox.push_back(obj);

		getline(initFile, datatext);
	}



	initFile.close();
}
