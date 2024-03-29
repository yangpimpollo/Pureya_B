#pragma once
#ifndef SCENE_MANAGER_H_INCLUDED
#define SCENE_MANAGER_H_INCLUDED

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "game_core.h"
#include "prime/load_mode.h"
#include "prime/scene.h"
#include "scene/sc_Physics1.h"
#include "scene/sc_Physics2.h"
//#include "scene/sc_splash.h"

//class game_core;

namespace gameScenes
{
	enum index
	{
		load = 0,
		splash = 1,
		main_menu = 2,
		scene1 = 3,
		scene2 = 4,
		scene3 = 5
	};
};

class scene_Manager : public sf::Drawable
{
public:
	scene_Manager(game_core& arg);
	~scene_Manager();
	void update(sf::Event event, sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void changeScene(gameScenes::index arg);
	inline scene* getActiveScene() { return active_scene; }

private:
	game_core* app;
	scene* active_scene;

	int current_scene = 0;

};

inline scene_Manager::scene_Manager(game_core& arg) : app(&arg)
{
	//this->active_scene = new load_mode(*app);
	//this->active_scene = new sc_Physics1(*app);
	this->active_scene = new sc_Physics2(*app);
}

inline scene_Manager::~scene_Manager()
{
	//delete active_scene;
	active_scene->destroy();
	std::cout << "delete scene manager" << std::endl;
}

inline void scene_Manager::update(sf::Event event, sf::Time deltaTime)
{
	this->active_scene->update(event, deltaTime);
}

inline void scene_Manager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*active_scene);
}

inline void scene_Manager::changeScene(gameScenes::index arg)
{
}


#endif