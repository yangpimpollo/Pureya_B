#include "prime/game_window.h"
#include "game_core.h"

game_window::game_window(game_core& arg) : app(&arg)
{
	int WIDTH = app->res->getSet(settings::WHIDTH);
	int HEIGHT = app->res->getSet(settings::HEIGHT);
	int winStyle = app->res->getSet(settings::winStyle);
	std::wstring TITLE = app->res->getStg(global::stg::title);
	
	sf::ContextSettings settings; settings.antialiasingLevel = 8;
	sf::Image cursorImg = app->res->getTexture(global::res::cursor).copyToImage();
	cursor.loadFromPixels(cursorImg.getPixelsPtr(), sf::Vector2u(20, 20), sf::Vector2u(0, 0));

	this->create(sf::VideoMode(WIDTH, HEIGHT), TITLE, winStyle, settings);
	this->setIcon(64, 64, sf::Image(app->res->getTexture(global::res::icon).copyToImage()).getPixelsPtr());
	this->setMouseCursor(cursor);

	if (sf::Joystick::isConnected(0)) activeCursor = false;
	this->setMouseCursorVisible(activeCursor);
}

game_window::~game_window()
{
	std::cout << "delete game window" << std::endl;
}

void game_window::winEvents(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		this->close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		this->close();

	if (event.type == sf::Event::MouseMoved) {
		activeCursor = true;
		this->setMouseCursorVisible(activeCursor);
	}

	if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickMoved) {
		activeCursor = false;
		this->setMouseCursorVisible(activeCursor);
	}
}

void game_window::setWinView()
{
}
