#pragma once

#include "Snake.h"

class Game {
private:
    int windowSize, fps;
    int gridSizeMult;
    int cellSize;
    Snake snake;
public:
    Game(int windowSize, int FPS, int gridSizeMult);

    int getWindowSize() const;
    int getFPS() const;

    void draw();
    void move();
};
