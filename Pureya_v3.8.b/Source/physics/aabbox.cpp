#include "physics/aabbox.h"
#include "game_core.h"

aabbox::aabbox()
{
}

aabbox::aabbox(game_core& arg, sf::Vector2f position, sf::Vector2f size)
	: app(&arg), position(position), size(size)
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
    r1.setRadius(3.f);
    r1.setOrigin(sf::Vector2f(3.f,3.f));
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
    
    //r5.setRadius(3.f);
    //r5.setOrigin(sf::Vector2f(3.f, 3.f));
    //r5.setFillColor(color3);
    
}

aabbox::~aabbox()
{
}

void aabbox::update(sf::Event event, sf::Time deltaTime)
{
    //float m = all_ABbox[0]->getNexCorner().y;
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
                        getCorner().x < all_ABbox[active[i]]->getNexPosition().x )) {
                        ver = true;
                        //std::cout << "1" << std::endl;
                    }
                }
                
            }
            if (hor) direction.x += direction.x * -1.f;
            if (ver) direction.y += direction.y * -1.f;
        }
        //else {
            //direction += direction * -1.f;
        //}
        
        drawABox.setOutlineColor(color2);
    }
    else {
        drawABox.setOutlineColor(color1);
    }
    //sf::Vector2i pixelPos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
    sf::Vector2i pixelPos = app->window->getMousePosition();
    sf::Vector2f mousePos = app->window->mapPixelToCoords(pixelPos);
    bool inBox = (mousePos.x > getPosition().x && mousePos.x < getCorner().x &&
                  mousePos.y > getPosition().y && mousePos.y < getCorner().y )? true : false;

    //*--------------------------------------------------*/
    bool inR1 = (magnitude(r1.getPosition() - mousePos) < 3.f) ? true : false;

    if (inR1) {
        r1.setFillColor(color1);
    }
    else {
        r1.setFillColor(color3);
    }
    /*--------------------------------------------------**/

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        
        selected = false;
        selR1 = false;
        if (inBox && !clic1 && !inR1) {
            clic1 = true;
            
            mosPoss0 = mousePos - position;
            std::cout << "click & select" << std::endl;
        }

        if (inR1 && !clic1) {
            clic1 = true;
            r1.setFillColor(color1);
            std::cout << "click R1" << std::endl;
        }
        
    }
    
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (clic1) {
            clic1 = false; 
            selected = true;
            selR1 = true;
            std::cout << "released click" << std::endl;
        }
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        std::cout << "c+c+c" << std::endl;
        this->size += sf::Vector2f(2.f, 2.f);
        drawABox.setSize(size);
    }

    


   /* if (inBox) {
        drawABox.setOutlineColor(color3);      
    }*/

    if (selected) {
        drawABox.setOutlineColor(color3);
    }

    if (clic1 && selR1) {
        drawABox.setOutlineColor(color3);
    }

    if (clic1) { position = mousePos - mosPoss0; }

    center = position + size / 2.f;
    this->setPosition(position + (direction*speed));
    drawABox.setPosition(this->position);


    r1.setPosition(position);
    r2.setPosition(sf::Vector2f(position.x + size.x, position.y));
    r3.setPosition(getCorner());
    r4.setPosition(sf::Vector2f(position.x, position.y + size.y));

    lineL[0] = sf::Vertex(center - sf::Vector2f(5.f, 5.f));
    lineL[1] = sf::Vertex(center + sf::Vector2f(5.f, 5.f));
    lineR[0] = sf::Vertex(center - sf::Vector2f(5.f, -5.f));
    lineR[1] = sf::Vertex(center + sf::Vector2f(5.f, -5.f));

    this->active.clear();
}

void aabbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(drawABox);
    if (selected) {
        target.draw(r1);
        target.draw(r2);
        target.draw(r3);
        target.draw(r4);
        //target.draw(r5);
        target.draw(lineL, 2, sf::Lines);
        target.draw(lineR, 2, sf::Lines);
    }

}

//inline void aabbox::move(sf::Vector2f arg){ this->direction = normalize(arg); }
//inline void aabbox::setPosition(sf::Vector2f arg){ this->position = arg; }
