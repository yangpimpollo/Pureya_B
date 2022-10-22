#include "pieces/particle.h"

particle::particle()
{
}

particle::particle(float r, float x, float y) : radius(r), px(x), py(y)
{
	circle.setRadius(radius);
	circle.setPosition(px, py);
	circle.setFillColor(sf::Color::Color(64, 224, 208, 255));
	//circle.setOutlineThickness(1.5f);
	//circle.setOutlineColor(sf::Color::Color(17, 78, 191, 255));
}

particle::~particle()
{
}

void particle::update(sf::Event event, sf::RenderWindow& window)
{
}

void particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle);
}
