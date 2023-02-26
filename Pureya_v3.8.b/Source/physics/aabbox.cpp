#include "physics/aabbox.h"

aabbox::aabbox()
{
}

aabbox::aabbox(sf::Vector2f position, sf::Vector2f size)
	: position(position), size(size)
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
    //arg->push_back(this);
    
}

aabbox::~aabbox()
{
}

void aabbox::update(sf::Event event, sf::Time deltaTime)
{
    float m = all_ABbox[0]->getNexCorner().y;
    bool ver = false;
    bool hor = false;

    if (active.size() > 0) {
        for (int i = 0; i < active.size(); i++) {
            if (!ver) {
                if (!(getPosition().x > all_ABbox[active[i]]->getNexCorner().x ||
                    getCorner().x < all_ABbox[active[i]]->getNexPosition().x ||
                    getNexCorner().y < all_ABbox[active[i]]->getNexPosition().y ||
                    getNexPosition().y > all_ABbox[active[i]]->getNexCorner().y)) {
                    ver = true;
                }
            }
            if (!hor) {
                if (!(getNexPosition().x > all_ABbox[active[i]]->getNexCorner().x ||
                    getNexCorner().x < all_ABbox[active[i]]->getNexPosition().x ||
                    getCorner().y < all_ABbox[active[i]]->getNexPosition().y ||
                    getPosition().y > all_ABbox[active[i]]->getNexCorner().y)) {
                    hor = true;
                }
            }             
        }
        if(hor) direction.x += direction.x * -1.f;
        if(ver) direction.y += direction.y * -1.f;

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
