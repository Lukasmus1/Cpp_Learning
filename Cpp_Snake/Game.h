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
    void setup();
    int finalScore = 0;

    deque<Direction> directionBuffer;
    void updateDirectionBuffer(Direction dir);

    Food food;

    void drawScore();

public:
    Game(int windowSize, int FPS, int gridSizeMult, float tickRateMs);

    int getWindowSize() const;
    int getFPS() const;
    float getTickRateMs() const;

    void draw();
    void drawFinalScore() const;
    void move();

    void getDirectionInput();

    void drawTitle(const char *title) const;
    void drawButton(const char *buttonTitle, const function<void()> &onClick);

    void gameOver();
};
