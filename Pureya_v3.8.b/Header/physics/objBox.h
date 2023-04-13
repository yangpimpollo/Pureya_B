#pragma once
#ifndef OBJBOX_H_INCLUDED
#define OBJBOX_H_INCLUDED

#include "physics/square.h"

class objBox : public square
{
public:
	objBox();
	objBox(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id = "none");
	~objBox();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline std::string getID() { return id; }
	inline sf::Vector2f getNexPosition() { return position + (direction * speed); }
	inline sf::Vector2f getNexCorner() { return position + size + (direction * speed); }

	inline void setID(std::string arg) { id = arg; }

	inline void setAllBox(std::vector<objBox*>& all_ABbox_arg) { all_ABbox = all_ABbox_arg; }
	inline void addActiveCollision(int arg) { active.push_back(arg); }

protected:
	std::vector<int> active;
	std::vector<objBox*> all_ABbox;

private:

	std::string id;


	//   ...  temporal funtions ........

	void collisionDetection();


};





#endif