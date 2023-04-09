#include "scene/sc_Physics2.h"
#include "game_core.h"

sc_Physics2::sc_Physics2(game_core& arg) : app(&arg)
{
	this->res = new resource_station<sc_Physics2_res::res, sc_Physics2_res::stg>("sc_Physics2_res");

	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 220));

	obj1 = obj_box(*app, sf::Vector2f(682.5f, 412.5f), sf::Vector2f(125.f, 125.f));
	obj1.setTexture(res->getTexture(sc_Physics2_res::res::tex1));
	aabbSystem.includeToScene(obj1);

	b1.setSize(sf::Vector2f(125.f, 125.f));
	b1.setPosition(100.f, 100.f);
	//b1.setFillColor(sf::Color::Transparent);
	b1.setOutlineThickness(1.f);
	b1.setOutlineColor(sf::Color(64, 224, 208));
	
	load1Tex.loadFromFile("../res/sc_Physics2_res/grass03.png");
	b1.setTexture(&load1Tex);
	//b1.setTexture(&res->getTexture(sc_Physics2_res::res::tex1));

}

sc_Physics2::~sc_Physics2()
{
	std::cout << "delete sc_Physics2" << std::endl;
}

void sc_Physics2::update(sf::Event event, sf::Time deltaTime)
{
	
	obj1.move(app->joyControl->getLjoystick());

	this->aabbSystem.update(event, deltaTime);

	this->obj1.update(event, deltaTime);
	//obj1.setTexture(res->getTexture(sc_Physics2_res::res::tex1));
}

void sc_Physics2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	target.draw(this->obj1);
	target.draw(this->b1);
}

void sc_Physics2::destroy() { sc_Physics2::~sc_Physics2(); }
