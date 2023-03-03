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
        else {
            direction += direction * -1.f;
        }
        
        drawABox.setOutlineColor(color2);
    }
    else {
        drawABox.setOutlineColor(color1);
    }

    sf::Vector2i pixelPos = app->window->getMousePosition();
    sf::Vector2f mousePos = app->window->mapPixelToCoords(pixelPos);
    bool inBox = (mousePos.x > getPosition().x && mousePos.x < getCorner().x &&
                  mousePos.y > getPosition().y && mousePos.y < getCorner().y )? true : false;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (inBox && !clic1) {
            clic1 = true;
            mosPoss0 = mousePos - position;
            std::cout << "selected" << std::endl;
        }
    }
    
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (clic1) {
            clic1 = false;
            std::cout << "NO selected" << std::endl;
        }
    }





    if (inBox) {
        drawABox.setOutlineColor(color3);      
    }

    if (clic1) { position = mousePos - mosPoss0; }

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
