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

	float multiply1 = 1360.f / WIDTH;
	//float multiply2 = sf::VideoMode::getDesktopMode().height * (1360.f / sf::VideoMode::getDesktopMode().width);
	float multiply2 = 764.2f;
	this->view = new sf::View();
	this->viewSize.x = (winStyle != 8) ? WIDTH * multiply1 : (1360.f);
	this->viewSize.y = (winStyle != 8) ? HEIGHT * multiply1 : (multiply2);
	//std::cout << "multiply2:  " << multiply2 << std::endl;
	this->view->setCenter(sf::Vector2f(682.5f, 382.5f));
	this->view->setSize(this->viewSize);

}

game_window::~game_window()
{
	std::cout << "delete game window" << std::endl;
}

void game_window::winEvents(sf::Event event)
{
	mouse_pos = sf::Mouse::getPosition(*this);

	if (event.type == sf::Event::Closed)
		this->close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		this->close();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad8))
		this->view->move(sf::Vector2f(0.0f, -1.5f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
		this->view->move(sf::Vector2f(0.0f, 1.5f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5))
		this->view->rotate(5.f);

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
		pause = !pause;

	if (event.type == sf::Event::MouseMoved) {
		activeCursor = true;
		this->setMouseCursorVisible(activeCursor);
	}

	if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickMoved) {
		activeCursor = false;
		this->setMouseCursorVisible(activeCursor);
	}
}
