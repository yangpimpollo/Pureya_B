#include "scene/sc_Physics1.h"
#include "game_core.h"

sc_Physics1::sc_Physics1(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 220));

	b1 = objBox(*app, sf::Vector2f(300.f, 300.f), sf::Vector2f(50.f, 50.f));
	aabbSystem.includeToScene(b1);
	b2 = objBox(*app, sf::Vector2f(850.f, 330.f), sf::Vector2f(250.f, 150.f));
	b2.setID("door13");
	aabbSystem.includeToScene(b2);
	b3 = objBox(*app, sf::Vector2f(90.f, 100.f), sf::Vector2f(51.f, 280.f));
	b3.setID("portal8");
	aabbSystem.includeToScene(b3);

	/*aa1 = object_A(*app);
	aabbSystem.includeToScene(aa1);*/

}

sc_Physics1::~sc_Physics1()
{
	std::cout << "delete sc_Physics1" << std::endl;
}

void sc_Physics1::update(sf::Event event, sf::Time deltaTime)
{
	
	this->b2.move(app->joyControl->getLjoystick());
	this->aabbSystem.update(event, deltaTime);
	
	this->b1.update(event, deltaTime);
	this->b2.update(event, deltaTime);
	this->b3.update(event, deltaTime);

	//this->aa1.update(event, deltaTime);
	
}

void sc_Physics1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	target.draw(this->b1);
	target.draw(this->b2);
	target.draw(this->b3);

	//target.draw(this->aa1);
}

void sc_Physics1::destroy(){ sc_Physics1::~sc_Physics1(); }
