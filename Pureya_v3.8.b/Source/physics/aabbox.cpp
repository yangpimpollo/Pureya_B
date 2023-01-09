#include "physics/aabbox.h"

aabbox::aabbox()
{
}

aabbox::aabbox(float x, float y, float w, float h, bool solid)
	: x(x), y(y), w(w), h(h), solid(solid)
{
    drawABox.setSize(sf::Vector2f(w, h));
    drawABox.setPosition(x, y);
    drawABox.setFillColor(sf::Color::Transparent);
    drawABox.setOutlineThickness(1.f);
    drawABox.setOutlineColor(color1);
}

aabbox::~aabbox()
{
}

void aabbox::update(sf::Event event, sf::Time deltaTime)
{
    this->setPosition(x, y);
}

void aabbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(drawABox);
}

void aabbox::move(float _x, float _y){ this->setPosition(x, y);  }

void aabbox::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    drawABox.setPosition(this->x, this->y);
}
