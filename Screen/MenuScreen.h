#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace Sutoku {
class MenuScreen : public Screen {
   public:
    MenuScreen();

    void handleInput(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
   private:
    sf::Sprite Menu;
};
}  // namespace Sutoku

#endif