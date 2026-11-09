#pragma once

#include <vector>

#include "Snake.h"

class Game {
private:
    int windowSize, fps;
    float tickRateMs;
    int gridSizeMult;
    int cellSize;
    Snake snake;

    deque<Direction> directionBuffer;
    void updateDirectionBuffer(Direction dir);

public:
    Game(int windowSize, int FPS, int gridSizeMult, float tickRateMs);

    int getWindowSize() const;
    int getFPS() const;
    float getTickRateMs() const;

    void draw();
    void move();

    void getDirectionInput();
};
