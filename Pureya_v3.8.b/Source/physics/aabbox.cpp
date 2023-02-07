#include "physics/aabbox.h"

aabbox::aabbox()
{
}

aabbox::aabbox(sf::Vector2f position, sf::Vector2f size, bool solid)
	: position(position), size(size), solid(solid)
{
    drawABox.setSize(size);
    drawABox.setPosition(position);
    drawABox.setFillColor(sf::Color::Transparent);
    drawABox.setOutlineThickness(1.f);
    drawABox.setOutlineColor(color1);

    //sf::Vector2f A = sf::Vector2f(2.f, 3.f);
    //sf::Vector2f B = sf::Vector2f(3.f, 0.f);
    //sf::Vector2f C = (A + B) * 2.f;

    //std::cout << "sum vector: " << C.x << "|" << C.y << std::endl;

}

aabbox::~aabbox()
{
}

void aabbox::update(sf::Event event, sf::Time deltaTime)
{
    if (active.size() > 0) {
        //direction= sf::Vector2f(0.f, 0.f);
        drawABox.setOutlineColor(color2);
    }
    else {
        drawABox.setOutlineColor(color1);
    }
    this->setPosition(position + (direction*speed));
    drawABox.setPosition(this->position);

    this->active.clear();
}

void aabbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(drawABox);
}

//inline void aabbox::move(sf::Vector2f arg){ this->direction = normalize(arg); }
//inline void aabbox::setPosition(sf::Vector2f arg){ this->position = arg; }
