#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Screen/Screen.h"

namespace Sutoku {

class Game {
   public:
    Game();
    void run();

    void handleInput();
    void update();
    void render();

    static const int Width = 1152;
    static const int Height = 720;
    static int difficulty;

    static std::shared_ptr<Screen> Screen;

   private:
    sf::RenderWindow window_;
    sf::Music bgMusic_;
    static const sf::Time TimePerFrame;
    void bgm_init();
};

}  // namespace Sutoku

#endif