#pragma once

#include "Snake.h"

class Game {
private:
    int windowSize, fps;
    float tickRateMs;
    int gridSizeMult;
    int cellSize;
    Snake snake;
public:
    Game(int windowSize, int FPS, int gridSizeMult, float tickRateMs);

    int getWindowSize() const;
    int getFPS() const;
    float getTickRateMs() const;

    void draw();
    void move();
};
