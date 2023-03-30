#include "pieces/box_control.h"
#include "game_core.h"

box_control::box_control()
{
}

box_control::box_control(game_core& arg) 
	: app(&arg)
{
	r1.setRadius(50.f);
	r1.setOrigin(sf::Vector2f(50.f, 50.f));
	r1.setFillColor(color1);
	r1.setPosition(sf::Vector2f(400.f, 300.f));
}

box_control::~box_control()
{
}

void box_control::update(sf::Event event, sf::Time deltaTime)
{
	sf::Vector2i pixelPos = app->window->getMousePosition();
	sf::Vector2f mousePos = app->window->mapPixelToCoords(pixelPos);

	bool inR1 = (magnitude(r1.getPosition() - mousePos) < 50.f) ? true : false;

	if (inR1) {
		r1.setFillColor(color2);
	}else {
		r1.setFillColor(color1);
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (inR1 && !clic1) {
			clic1 = true;
			mosPoss0 = mousePos - position;
			r1.setFillColor(color1);
			//std::cout << "r11111" << std::endl;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (clic1) {
			clic1 = false;
			selected = true;
			std::cout << "released click" << std::endl;
		}
	}

	if (clic1) { position = mousePos - mosPoss0; }

	r1.setPosition(position);
}

void box_control::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(r1);
}
