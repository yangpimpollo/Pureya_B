#include "physics/obj_box.h"
#include "game_core.h"

obj_box::obj_box()
{
}

obj_box::obj_box(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id)
	: app(&arg), position(position), size(size), id(id)
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
    r5.setRadius(5.f);
    r5.setOrigin(sf::Vector2f(5.f, 5.f));
    r5.setFillColor(color3);
}

obj_box::~obj_box()
{
}

void obj_box::update(sf::Event event, sf::Time deltaTime)
{
    collisionDetection();

    sf::Vector2i pixelPos = app->window->getMousePosition();
    mousePos = app->window->mapPixelToCoords(pixelPos);

    inR1 = (magnitude(r1.getPosition() - mousePos) < 3.f) ? true : false;
    inR2 = (magnitude(r2.getPosition() - mousePos) < 3.f) ? true : false;
    inR3 = (magnitude(r3.getPosition() - mousePos) < 3.f) ? true : false;
    inR4 = (magnitude(r4.getPosition() - mousePos) < 3.f) ? true : false;
    inR5 = (magnitude(r5.getPosition() - mousePos) < 5.f) ? true : false;
    inBox = (mousePos.x > getPosition().x && mousePos.x < getCorner().x&&
        mousePos.y > getPosition().y && mousePos.y < getCorner().y) ? true : false;


    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (!click) {
            click = true;
            
            if (inR1) { click_mode = 1; }
            else if (inR2) { click_mode = 2; }
            else if (inR3) { click_mode = 3; }
            else if (inR4) { click_mode = 4; }
            else if (inR5) { click_mode = 5; }
            else if (inBox) { click_mode = 0; }
            else { click_mode = 6; }

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
    z_buffer = getCorner().y + delta_zbuff;

    drawABox.setSize(size);
    drawABox.setPosition(this->position);

    sf::Vector2f center = position + size / 2.f;
    
    r1.setPosition(position);
    r2.setPosition(sf::Vector2f(position.x + size.x, position.y));
    r3.setPosition(getCorner());
    r4.setPosition(sf::Vector2f(position.x, position.y + size.y));
    r5.setPosition(sf::Vector2f(center.x, z_buffer));
    lineL[0] = sf::Vertex(center - sf::Vector2f(5.f, 5.f));
    lineL[1] = sf::Vertex(center + sf::Vector2f(5.f, 5.f));
    lineR[0] = sf::Vertex(center - sf::Vector2f(5.f, -5.f));
    lineR[1] = sf::Vertex(center + sf::Vector2f(5.f, -5.f));
}

void obj_box::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(drawABox);
    if (selected) {      
        target.draw(r1);
        target.draw(r2);
        target.draw(r3);
        target.draw(r4);
        target.draw(r5);
        target.draw(lineL, 2, sf::Lines);
        target.draw(lineR, 2, sf::Lines);
    }
}

void obj_box::collisionDetection()
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

void obj_box::clickPress()
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
        delta_zbuff0 = delta_zbuff;
        mosPoss0 = mousePos;
        break;
    case 6:
        selected = false;
        break;
    }
}

void obj_box::StatusMode()
{
    // hover mode ....

    if (inR1) { r1.setFillColor(color1); }else { r1.setFillColor(color3); }
    if (inR2) { r2.setFillColor(color1); }else { r2.setFillColor(color3); }
    if (inR3) { r3.setFillColor(color1); }else { r3.setFillColor(color3); }
    if (inR4) { r4.setFillColor(color1); }else { r4.setFillColor(color3); }
    if (inR5) { r5.setFillColor(color1); }else { r5.setFillColor(color3); }

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
        case 5: {
            delta_zbuff = delta_zbuff0 + delta.y;
        }   break;
        case 6:
            break;
        }
    }
}

void obj_box::clickRelease()
{
}
