#include "scene/sc_Physics1.h"
#include "game_core.h"

sc_Physics1::sc_Physics1(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 220));

	b1 = aabbox(*app, sf::Vector2f(300.f, 300.f), sf::Vector2f(50.f, 50.f));
	aabbSystem.includeToScene(b1);
	b2 = aabbox(*app, sf::Vector2f(850.f, 330.f), sf::Vector2f(250.f, 150.f));
	b2.setID("door13");
	aabbSystem.includeToScene(b2);
	b3 = aabbox(*app, sf::Vector2f(90.f, 100.f), sf::Vector2f(51.f, 280.f));
	b3.setID("portal8");
	aabbSystem.includeToScene(b3);

	aa1 = object_A(*app);
	aabbSystem.includeToScene(aa1);

	//c1 = aabbox(*app, sf::Vector2f(200.f, 300.f), sf::Vector2f(100.f, 100.f));
	//aabbSystem.includeToScene(c1);
	//c2 = aabbox(*app, sf::Vector2f(450.f, 230.f), sf::Vector2f(100.f, 150.f));
	//aabbSystem.includeToScene(c2);
	//c3 = aabbox(*app, sf::Vector2f(150.f, 600.f), sf::Vector2f(200.f, 50.f));
	//aabbSystem.includeToScene(c3);
	circle = box_control(*app);
}

sc_Physics1::~sc_Physics1()
{
	std::cout << "delete sc_Physics1" << std::endl;
}

void sc_Physics1::update(sf::Event event, sf::Time deltaTime)
{
	
	this->aa1.move(app->joyControl->getLjoystick());
	this->aabbSystem.update(event, deltaTime);
	
	//this->b1.update(event, deltaTime);
	//this->b2.update(event, deltaTime);
	//this->b3.update(event, deltaTime);

	this->aa1.update(event, deltaTime);
	//this->c1.update(event, deltaTime);
	//this->c2.update(event, deltaTime);
	//this->c3.update(event, deltaTime);
	//this->circle.update(event, deltaTime);
	
}

void sc_Physics1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	//target.draw(this->b1);
	//target.draw(this->b2);
	//target.draw(this->b3);

	target.draw(this->aa1);
	//target.draw(this->c1);
	//target.draw(this->c2);
	//target.draw(this->c3);
	//target.draw(this->circle);
}

void sc_Physics1::destroy(){ sc_Physics1::~sc_Physics1(); }
