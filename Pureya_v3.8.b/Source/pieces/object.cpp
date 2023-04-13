#include "pieces/object.h"
#include "game_core.h"

object::object()
{
}

object::object(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id)
	: square(arg, position, size), id(id)
{
	drawABox.setFillColor(sf::Color::White);
	drawABox.setOutlineThickness(0.f);
}

object::~object()
{
}

void object::update(sf::Event event, sf::Time deltaTime)
{
	drawABox.setTexture(&obj_texture);
	square::update(event, deltaTime);
}

void object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	square::draw(target, states);
}
