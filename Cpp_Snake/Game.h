#pragma once

#include <functional>
#include <vector>

#include "Food.h"
#include "Snake.h"

class Game {
private:
    int windowSize, fps;
    float tickRateMs;
    int gridSizeMult;
    int cellSize;
    Snake snake;
    int gridItemSize;

    deque<Direction> directionBuffer;
    void updateDirectionBuffer(Direction dir);

    Food food;

public:
    Game(int windowSize, int FPS, int gridSizeMult, float tickRateMs);

    int getWindowSize() const;
    int getFPS() const;
    float getTickRateMs() const;

    void draw();
    void move();

    void getDirectionInput();

    void drawTitle(const char *title) const;
    void drawButton(const char *buttonTitle, const function<void()> &onClick);
};
