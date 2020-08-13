#include "MenuScreen.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Game/Game.h"
#include "GameScreen.h"

using namespace Sutoku;

sf::Texture menu;

const std::string menu_address("Resource/menu.png");
MenuScreen::MenuScreen() {
    sf::sleep(sf::seconds(1));
    menu.loadFromFile(menu_address);
    Menu.setTexture(menu);
    Menu.setPosition(position_);
}

void MenuScreen::handleInput(sf::RenderWindow& window) {
    static sf::Mouse mouse;
    if (mouse.isButtonPressed(mouse.Left)) {
        auto mouse_position = mouse.getPosition(window);
        int mouse_x = mouse_position.x, mouse_y = mouse_position.y;
        bool flag = false;
        if (mouse_x >= 60 && mouse_x <= 460) {
            if (mouse_y >= 240 && mouse_y <= 340)
                flag = true, Game::difficulty = 0;
            if (mouse_y >= 350 && mouse_y <= 450)
                flag = true, Game::difficulty = 1;
            if (mouse_y >= 460 && mouse_y <= 560)
                flag = true, Game::difficulty = 2;
            if (mouse_y >= 570 && mouse_y <= 670)
                flag = true, Game::difficulty = 3;
            if (flag)
                Game::Screen = std::make_shared<GameScreen>();
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}

void MenuScreen::update() {}

void MenuScreen::render(sf::RenderWindow& window) {
    window.draw(Menu);
}