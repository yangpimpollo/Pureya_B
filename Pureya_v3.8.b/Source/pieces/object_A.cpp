#include "pieces/object_A.h"
#include "game_core.h"

object_A::object_A()
{

}

object_A::object_A(game_core& arg) : aabbox(arg, sf::Vector2f(300.f, 300.f), sf::Vector2f(100.f, 100.f))
{


}

object_A::~object_A()
{
}

void object_A::update(sf::Event event, sf::Time deltaTime)
{
	for (int i = 0; i < active.size(); i++) {
		if (all_ABbox[active[i]]->getID() == "door13") {
			std::cout << "door13" << std::endl;
		}
		if (all_ABbox[active[i]]->getID() == "portal8") {
			std::cout << "portal8" << std::endl;
		}
	}
	aabbox::update(event, deltaTime);
}

void object_A::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	aabbox::draw(target, states);
}

void object_A::render()
{
	
}

void object_A::destroy()
{
}
