#include "physics/objTex.h"


objTex::objTex()
{
}

objTex::objTex(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id)
	: square(arg, position, size), id(id)
{
	drawABox.setFillColor(sf::Color::White);
	drawABox.setOutlineThickness(0.f);
}

objTex::~objTex()
{
}

void objTex::update(sf::Event event, sf::Time deltaTime)
{
	drawABox.setTexture(&obj_texture);
	square::update(event, deltaTime);
}

void objTex::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	square::draw(target, states);
	if (selected) target.draw(r5);
}
