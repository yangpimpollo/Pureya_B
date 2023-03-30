#include "scene/sc_particle.h"
#include "game_core.h"


sc_particle::sc_particle(game_core& arg) : app(&arg)
{
	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 255));

	bigbox.setSize(sf::Vector2f(500.f, 500.f));
	bigbox.setPosition(432.5f, 132.5f);
	bigbox.setFillColor(sf::Color::Transparent);
	bigbox.setOutlineThickness(1.5f);
	bigbox.setOutlineColor(sf::Color::Color(17, 78, 191, 255));

	p1 = particle(20.f, 600.f, 200.f);
}

sc_particle::~sc_particle()
{
	std::cout << "delete sc_particle" << std::endl;
}

void sc_particle::update(sf::Event event, sf::Time deltaTime)
{
	p1.update(event, deltaTime);
}

void sc_particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	target.draw(this->bigbox);
	target.draw(this->p1);
}

void sc_particle::destroy() { sc_particle::~sc_particle(); }