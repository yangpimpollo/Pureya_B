#include "scene/sc_Physics1.h"
#include "game_core.h"

sc_Physics1::sc_Physics1(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 255));

	b1 = aabbox(*app, sf::Vector2f(300.f, 300.f), sf::Vector2f(50.f, 50.f));
	aabbSystem.includeToScene(b1);
	b2 = aabbox(*app, sf::Vector2f(850.f, 330.f), sf::Vector2f(250.f, 150.f));
	aabbSystem.includeToScene(b2);
	b3 = aabbox(*app, sf::Vector2f(90.f, 100.f), sf::Vector2f(51.f, 280.f));
	aabbSystem.includeToScene(b3);

	c1 = aabbox(*app, sf::Vector2f(200.f, 300.f), sf::Vector2f(100.f, 100.f));
	aabbSystem.includeToScene(c1);
	c2 = aabbox(*app, sf::Vector2f(450.f, 230.f), sf::Vector2f(100.f, 150.f));
	aabbSystem.includeToScene(c2);
	c3 = aabbox(*app, sf::Vector2f(150.f, 600.f), sf::Vector2f(200.f, 50.f));
	aabbSystem.includeToScene(c3);
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
	this->b3.update(event, deltaTime);
	this->c1.update(event, deltaTime);
	this->c2.update(event, deltaTime);
	this->c3.update(event, deltaTime);
	
	
}

void sc_Physics1::render()
{
	app->window->draw(this->back);
	app->window->draw(this->b1);
	app->window->draw(this->b2);
	app->window->draw(this->b3);
	app->window->draw(this->c1);
	app->window->draw(this->c2);
	app->window->draw(this->c3);
}

void sc_Physics1::destroy(){ sc_Physics1::~sc_Physics1(); }
