#include "prime/debug_mode.h"
#include "game_core.h"

debug_mode::debug_mode(game_core& arg) : app(&arg)
{
	fps_txt.setFont(app->res->getFont(global::res::mamelon));
	fps_txt.setCharacterSize(25);
	fps_txt.setFillColor(sf::Color::Red);
	fps_txt.setPosition(40.f, 30.f);

	mouse_X.setFont(app->res->getFont(global::res::mamelon));
	mouse_X.setCharacterSize(16);
	mouse_X.setFillColor(sf::Color::Red);
	mouse_X.setPosition(40.f, 65.f);

	mouse_Y.setFont(app->res->getFont(global::res::mamelon));
	mouse_Y.setCharacterSize(16);
	mouse_Y.setFillColor(sf::Color::Red);
	mouse_Y.setPosition(40.f, 85.f);

	NjoyX.setFont(app->res->getFont(global::res::mamelon));
	NjoyX.setCharacterSize(16);
	NjoyX.setFillColor(sf::Color::Red);
	NjoyX.setPosition(40.f, 105.f);

	NjoyY.setFont(app->res->getFont(global::res::mamelon));
	NjoyY.setCharacterSize(16);
	NjoyY.setFillColor(sf::Color::Red);
	NjoyY.setPosition(40.f, 125.f);

	lang_test.setFont(app->res->getFont(global::res::mamelon));
	lang_test.setCharacterSize(60);
	lang_test.setFillColor(sf::Color::Red);
	lang_test.setPosition(100.f, 300.f);
	lang_test.setString(app->res->getStg(global::stg::title));
}

debug_mode::~debug_mode()
{
	std::cout << "delete debug mode" << std::endl;
}

void debug_mode::update(sf::Event event, sf::Time deltaTime)
{
	//this->debug_toggle = app->m_resourceHolder.string.getSettings()[6];
	sf::Vector2i pixelPos = app->window->getMousePosition();
	sf::Vector2f worldPos = app->window->mapPixelToCoords(pixelPos);

	std::string x = std::to_string((int)worldPos.x);
	std::string y = std::to_string((int)worldPos.y);
	this->mouse_X.setString("x: " + x);
	this->mouse_Y.setString("y: " + y);

	this->NjoyX.setString("Njoy_x: " + std::to_string(app->joyControl->getLjoystick().x));
	this->NjoyY.setString("Njoy_y: " + std::to_string(app->joyControl->getLjoystick().y));



	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P) {
		//std::cout << "P" << std::endl;
		app->res->setLanguaje(language::EN);
		lang_test.setString(app->res->getStg(global::stg::title));
	}
		
}

void debug_mode::render()
{
	app->window->draw(this->fps_txt);
	app->window->draw(this->mouse_X);
	app->window->draw(this->mouse_Y);
	app->window->draw(this->NjoyX);
	app->window->draw(this->NjoyY);
	//app->window->draw(this->lang_test);
}

void debug_mode::set_fps(int arg)
{
	this->fps_txt.setString("fps: " + std::to_string(arg));
}
