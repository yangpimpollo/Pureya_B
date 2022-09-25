#include "prime/load_mode.h"
#include "game_core.h"


load_mode::load_mode(game_core& arg) : app(&arg)
{
    this->res = new resource_station<load_res::res, load_res::stg>("load_res");
    back.setSize(sf::Vector2f(1365.f, 765.f));
    back.setPosition(0.f, 0.f);
    back.setFillColor(sf::Color::Color(245, 51, 87, 255));

    load_txt.setFont(app->res->getFont(global::res::mamelon));
    load_txt.setCharacterSize(30);
    load_txt.setFillColor(sf::Color::Black);
    load_txt.setString(res->getStg(load_res::stg::loading));
    load_txt.setPosition(550.f, 500.f);

    load1.setSize(sf::Vector2f(125.f, 125.f));
    load1.setPosition(682.5f, 412.5f);
    load1.setTexture(&res->getTexture(load_res::res::load1));
    load1.setOrigin(62.5f, 62.5f);

    load2.setSize(sf::Vector2f(125.f, 134.f));
    load2.setPosition(620.f, 341.f);
    load2.setTexture(&res->getTexture(load_res::res::load2));

}

load_mode::~load_mode()
{
    delete res;
    std::cout << "delete load mode" << std::endl;
}

void load_mode::update(sf::Event event, sf::Time deltaTime)
{
    totalTime += deltaTime;

    if (totalTime >= (sf::microseconds(5555))) {
        if (angle < 360.f) {
            angle += 1;
        }
        else {
            angle = 0;
        }
        totalTime -= sf::microseconds(5555);
    }

    load1.setRotation(-angle);
}

void load_mode::render()
{
    app->window->draw(this->back);
    app->window->draw(this->load_txt);
    app->window->draw(this->load1);
    app->window->draw(this->load2);
}

void load_mode::destroy() { load_mode::~load_mode(); }