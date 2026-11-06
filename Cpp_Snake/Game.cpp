#include "Game.h"

Game::Game(const int w, const int h, const int fps) {
    Game::width = w;
    Game::height = h;
    Game::fps = fps;
}

int Game::GetWidth() const {
    return width;
}

int Game::GetHeight() const {
    return height;
}

int Game::GetFPS() const {
    return fps;
}
