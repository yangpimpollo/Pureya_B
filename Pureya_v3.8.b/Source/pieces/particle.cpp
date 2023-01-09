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

void particle::update(sf::Event event, sf::Time deltaTime)
{
	if ((px) < 432.5f || (px + radius*2) > 932.5f) dx *= -1.f;
	if ((py) < 132.5f || (py + radius*2) > 632.5f) dy *= -1.f;

	px += dx * 305.f * deltaTime.asSeconds();
	py += dy * 305.f * deltaTime.asSeconds();

	circle.setPosition(px, py);
}

void particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle);
}
