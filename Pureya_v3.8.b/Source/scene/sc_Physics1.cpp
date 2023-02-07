#include "scene/sc_Physics1.h"
#include "game_core.h"

sc_Physics1::sc_Physics1(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 255));

	b1 = aabbox(sf::Vector2f(300.f, 300.f), sf::Vector2f(50.f, 50.f), true);
	aabbSystem.includeToScene(b1);
	b2 = aabbox(sf::Vector2f(400.f, 400.f), sf::Vector2f(50.f, 50.f), true);
	aabbSystem.includeToScene(b2);
}

sc_Physics1::~sc_Physics1()
{
	std::cout << "delete sc_Physics1" << std::endl;
}

void sc_Physics1::update(sf::Event event, sf::Time deltaTime)
{
	this->b1.move(app->joyControl->getLjoystick());

	this->aabbSystem.update(event, deltaTime);
	this->b1.update(event, deltaTime);
	this->b2.update(event, deltaTime);
	
}

void sc_Physics1::render()
{
	app->window->draw(this->back);
	app->window->draw(this->b1);
	app->window->draw(this->b2);
}

void sc_Physics1::destroy(){ sc_Physics1::~sc_Physics1(); }
