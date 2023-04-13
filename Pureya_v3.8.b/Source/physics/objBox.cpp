#include "physics/objBox.h"

objBox::objBox()
{
}

objBox::objBox(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id)
	: square(arg, position, size), id(id)
{
}

objBox::~objBox()
{
}

void objBox::update(sf::Event event, sf::Time deltaTime)
{
	collisionDetection();
    square::update(event, deltaTime);
}

void objBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    square::draw(target, states);
}

void objBox::collisionDetection()
{
    bool ver = false;
    bool hor = false;

    if (active.size() > 0) {
        if (direction != sf::Vector2f(0.f, 0.f)) {
            for (int i = 0; i < active.size(); i++) {
                if (!hor) {
                    if (!(getCorner().y < all_ABbox[active[i]]->getNexPosition().y ||
                        getPosition().y > all_ABbox[active[i]]->getNexCorner().y)) {
                        hor = true;
                        //std::cout << "2" << std::endl;
                    }
                }
                if (!ver) {
                    if (!(getPosition().x > all_ABbox[active[i]]->getNexCorner().x ||
                        getCorner().x < all_ABbox[active[i]]->getNexPosition().x)) {
                        ver = true;
                        //std::cout << "1" << std::endl;
                    }
                }

            }
            if (hor) direction.x += direction.x * -1.f;
            if (ver) direction.y += direction.y * -1.f;
        }

        drawABox.setOutlineColor(color2);
    }
    else {
        drawABox.setOutlineColor(color1);
    }

    this->active.clear();
}
