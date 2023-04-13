#include "physics/square.h"
#include "game_core.h"

square::square()
{
}

square::square(game_core& arg, sf::Vector2f position, sf::Vector2f size)
	: app(&arg), position(position), size(size)
{
    drawABox.setSize(size);
    drawABox.setPosition(position);
    drawABox.setFillColor(sf::Color::Transparent);
    drawABox.setOutlineThickness(1.f);
    drawABox.setOutlineColor(color1);

    r1.setRadius(3.f);
    r1.setOrigin(sf::Vector2f(3.f, 3.f));
    r1.setFillColor(color3);
    r2.setRadius(3.f);
    r2.setOrigin(sf::Vector2f(3.f, 3.f));
    r2.setFillColor(color3);
    r3.setRadius(3.f);
    r3.setOrigin(sf::Vector2f(3.f, 3.f));
    r3.setFillColor(color3);
    r4.setRadius(3.f);
    r4.setOrigin(sf::Vector2f(3.f, 3.f));
    r4.setFillColor(color3);
}

square::~square()
{
}

void square::update(sf::Event event, sf::Time deltaTime)
{
    sf::Vector2i pixelPos = app->window->getMousePosition();
    mousePos = app->window->mapPixelToCoords(pixelPos);

    inR1 = (magnitude(r1.getPosition() - mousePos) < 3.f) ? true : false;
    inR2 = (magnitude(r2.getPosition() - mousePos) < 3.f) ? true : false;
    inR3 = (magnitude(r3.getPosition() - mousePos) < 3.f) ? true : false;
    inR4 = (magnitude(r4.getPosition() - mousePos) < 3.f) ? true : false;
    inBox = (mousePos.x > getPosition().x && mousePos.x < getCorner().x&&
        mousePos.y > getPosition().y && mousePos.y < getCorner().y) ? true : false;


    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (!click) {
            click = true;

            if (inR1) { click_mode = 1; }
            else if (inR2) { click_mode = 2; }
            else if (inR3) { click_mode = 3; }
            else if (inR4) { click_mode = 4; }
            else if (inBox) { click_mode = 0; }
            else { click_mode = 5; }

            clickPress();
            //std::cout << "click: " << getID() << std::endl;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (click) {
            click = false;
            //std::cout << "rel" << std::endl;
        }
    }
    StatusMode();

    setPosition(position + (direction * speed));

    drawABox.setSize(size);
    drawABox.setPosition(this->position);

    sf::Vector2f center = position + size / 2.f;

    r1.setPosition(position);
    r2.setPosition(sf::Vector2f(position.x + size.x, position.y));
    r3.setPosition(getCorner());
    r4.setPosition(sf::Vector2f(position.x, position.y + size.y));
    lineL[0] = sf::Vertex(center - sf::Vector2f(5.f, 5.f));
    lineL[1] = sf::Vertex(center + sf::Vector2f(5.f, 5.f));
    lineR[0] = sf::Vertex(center - sf::Vector2f(5.f, -5.f));
    lineR[1] = sf::Vertex(center + sf::Vector2f(5.f, -5.f));
}

void square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(drawABox);
    if (selected) {
        target.draw(r1);
        target.draw(r2);
        target.draw(r3);
        target.draw(r4);
        target.draw(lineL, 2, sf::Lines);
        target.draw(lineR, 2, sf::Lines);
    }
}

void square::clickPress()
{
    switch (click_mode) {
    case 0:
        selected = true;
        mosPoss0 = mousePos - position;
        break;
    case 1: case 2: case 3: case 4:
        position0 = position;
        mosPoss0 = mousePos;
        size0 = size;
        break;
    case 5:
        selected = false;
        break;
    }
}

void square::StatusMode()
{
    // hover mode ....

    if (inR1) { r1.setFillColor(color1); }
    else { r1.setFillColor(color3); }
    if (inR2) { r2.setFillColor(color1); }
    else { r2.setFillColor(color3); }
    if (inR3) { r3.setFillColor(color1); }
    else { r3.setFillColor(color3); }
    if (inR4) { r4.setFillColor(color1); }
    else { r4.setFillColor(color3); }

    // ...............
    sf::Vector2f delta = mousePos - mosPoss0;

    if (click) {
        switch (click_mode) {
        case 0:
            position = delta;
            break;
        case 1: {
            if ((size0 - delta).x > 10.f && (size0 - delta).y > 10.f) {
                position = mousePos;
                size = size0 - delta;
            }
        }   break;
        case 2: {
            if ((size0 + delta).x > 10.f && (size0 - delta).y > 10.f) {
                position = position0 + sf::Vector2f(0.f, delta.y);
                size = size0 + sf::Vector2f(delta.x, -delta.y);
            }
        }   break;
        case 3: {
            if ((size0 + delta).x > 10.f && (size0 + delta).y > 10.f) {
                size = size0 + delta;
            }
        }   break;
        case 4: {
            if ((size0 - delta).x > 10.f && (size0 + delta).y > 10.f) {
                position = position0 + sf::Vector2f(delta.x, 0.f);
                size = size0 + sf::Vector2f(-delta.x, delta.y);
            }
        }   break;
        case 5:
            break;
        }
    }
}

void square::clickRelease()
{
}
