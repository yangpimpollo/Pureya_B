#include "scene/sc_Physics2.h"
#include "game_core.h"

sc_Physics2::sc_Physics2(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 220));

	b1 = obj_box(*app, sf::Vector2f(300.f, 300.f), sf::Vector2f(50.f, 50.f));
}

sc_Physics2::~sc_Physics2()
{
	std::cout << "delete sc_Physics2" << std::endl;
}

void sc_Physics2::update(sf::Event event, sf::Time deltaTime)
{
	b1.update(event, deltaTime);
}

void sc_Physics2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	target.draw(this->b1);
}

void sc_Physics2::destroy() { sc_Physics2::~sc_Physics2(); }
