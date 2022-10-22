#include "game_core.h"

game_core::game_core()
{
}

game_core::~game_core()
{
	delete window;
    delete scene_mng;
    delete debug;
    delete res;
}

void game_core::start()
{
    std::cout << "start pureya_v3.8.b" << std::endl;
	do {
		init();
		cicles();
	} while (this->resetRequest);
	std::cout << "end of cycle" << std::endl;
}

void game_core::init()
{
    delete window;
    delete scene_mng;
    delete debug;
    delete res;

	this->resetRequest = false;
    this->res = new resource_station<global::res, global::stg>("global_res");
    this->debug = new debug_mode(*this);
    this->scene_mng = new scene_Manager(*this);
	this->window = new game_window(*this);
}

void game_core::cicles()
{
    this->joyControl = new joystick();

	const int _fps = 60;
	sf::Time update_time = sf::microseconds(1000000 / _fps);
	sf::Clock clock;

	sf::Time ref_update = clock.getElapsedTime();
	sf::Time ref_counter = clock.getElapsedTime();

	sf::Time time_elapsed;
	sf::Time delta;

    fps = 0;
    while (this->window->isOpen())
    {
        sf::Time cycle_start = clock.getElapsedTime();
        time_elapsed = cycle_start - ref_update;
        ref_update = cycle_start;

        delta += time_elapsed;

        sf::Event event;
        while (this->window->pollEvent(event))
        {
            this->window->winEvents(event);
        }
        this->joyControl->update();

        update(event, time_elapsed);
        while (delta >= update_time) {
            render();
            fps++;
            delta -= update_time;
        }

        if (clock.getElapsedTime() - ref_counter > sf::microseconds(1000000)) {
            debug->set_fps(fps);
            fps = 0;
            ref_counter = clock.getElapsedTime();
        }
    }
}

void game_core::update(sf::Event event, sf::Time deltaTime)
{
    this->debug->update(event, deltaTime);
    if (!this->window->getPauseStatus()) {
        this->scene_mng->update(event, deltaTime);
    }
}

void game_core::render()
{
    this->window->clear(sf::Color::Black);
    this->window->setWinView();
    this->scene_mng->render();
    this->debug->render();
    this->window->display();
}
