#pragma once
#include <deque>
#include <utility>
#include "raylib.h"

using namespace std;
class Food {
private:
    pair<int, int> pos;

    const deque<pair<int, int>>* snakeBody;

public:
    Food(const deque<pair<int, int>>* snakeBody);

    void generateRandomPos(int gridSize);

    void drawFood(int size, int cellSize) const;
};
