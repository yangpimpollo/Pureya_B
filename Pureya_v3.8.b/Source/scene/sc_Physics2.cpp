#include "scene/sc_Physics2.h"
#include "game_core.h"

sc_Physics2::sc_Physics2(game_core& arg) : app(&arg)
{
	this->res = new resource_station<sc_Physics2_res::res, sc_Physics2_res::stg>("sc_Physics2_res");
	this->objStation = new object_station(*app, res->getTextureArray(), "sc_Physics2_obj");

	back.setSize(sf::Vector2f(1365.f, 765.f));
	back.setPosition(0.f, 0.f);
	back.setFillColor(sf::Color::Color(0, 0, 25, 220));

	A1 = objTex(*app, sf::Vector2f(682.5f, 412.5f), sf::Vector2f(125.f, 125.f));
	A1.setTexture(res->getTexture(sc_Physics2_res::res(0)));


	//SS1 = objShape(*app, sf::Vector2f(682.5f, 412.5f), sf::Vector2f(65.f, 65.f));
	//SS1.setTexture(res->getTexture(sc_Physics2_res::res::tex1));
	//aabbSystem.includeToScene(*SS1.getObjBox());

	//SS2 = objShape(*app, sf::Vector2f(100.5f, 200.5f), sf::Vector2f(65.f, 65.f));
	//SS2.setTexture(res->getTexture(sc_Physics2_res::res::tex2));
	//aabbSystem.includeToScene(*SS2.getObjBox());

	//B1 = objBox(*app, sf::Vector2f(300.f, 300.f), sf::Vector2f(100.f, 450.f));
	//aabbSystem.includeToScene(B1);


}

sc_Physics2::~sc_Physics2()
{
	std::cout << "delete sc_Physics2" << std::endl;
}

void sc_Physics2::update(sf::Event event, sf::Time deltaTime)
{
	
	//A1.move(app->joyControl->getLjoystick());
	//SS1.move(app->joyControl->getLjoystick());

	this->aabbSystem.update(event, deltaTime);

	A1.update(event, deltaTime);
	objStation->update(event, deltaTime);
	//SS1.update(event, deltaTime);
	//SS2.update(event, deltaTime);
	//B1.update(event, deltaTime);

}

void sc_Physics2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->back);
	target.draw(this->A1);
	target.draw(this->objStation);
	//target.draw(this->SS1);
	//target.draw(this->SS2);

	target.draw(this->aabbSystem);
}

void sc_Physics2::destroy() { sc_Physics2::~sc_Physics2(); }
