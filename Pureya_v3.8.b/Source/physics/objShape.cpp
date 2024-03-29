#include "physics/objShape.h"

objShape::objShape()
{
}

objShape::objShape(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id)
	: objTex(arg, position, size, id)
{
	collision_box = objBox(arg, (position + rel_collisionboxPos), collisionboxSize);
}

objShape::~objShape()
{
}

void objShape::update(sf::Event event, sf::Time deltaTime)
{
	if (collision_box.getSelected()) {
		objTex::setEditMode(false);
		rel_collisionboxPos = collision_box.getPosition() - position;
	}
	else {
		objTex::setEditMode(true);
		if (objTex::getSelected()) {
			collision_box.setPosition(objTex::getPosition() + rel_collisionboxPos);
		}
	}

	objTex::setPosition(collision_box.getPosition() - rel_collisionboxPos);

	collision_box.update(event, deltaTime);
	objTex::update(event, deltaTime);
	
}

void objShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	objTex::draw(target, states);
}


