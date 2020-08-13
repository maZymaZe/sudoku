#include "Game.h"

#include <SFML/Graphics.hpp>
#include <memory>

#include "Screen/MenuScreen.h"

using namespace Sutoku;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 4.f);
int Game::difficulty = 0;
std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

Game::Game() : window_(sf::VideoMode(Game::Width, Game::Height), "Sutoku") {
    bgm_init();
}

void Game::handleInput() {
    sf::Event event;

    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_.close();
    }
    Game::Screen->handleInput(window_);
}
void Game::update() {
    Game::Screen->update();
}
void Game::render() {
    window_.clear();
    Game::Screen->render(window_);
    window_.display();
}
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window_.isOpen()) {
        window_.setSize(sf::Vector2u(Game::Width, Game::Height));

        sf::Time delta = clock.restart();
        timeSinceLastUpdate += delta;

        while (timeSinceLastUpdate > Game::TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            handleInput();
            update();
        }
        render();
    }
}