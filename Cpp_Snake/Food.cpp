#include "Food.h"

void Food::generateRandomPos(const int gridSize){
    int posX = 0;
    int posY = 0;
    do {
        posX = rand() % gridSize;
        posY = rand() % gridSize;
    } while (ranges::find(snakeBody->begin(), snakeBody->end(), {posX, posY} ) != snakeBody->end());

    pos = {posX, posY};
}

void Food::drawFood(const int size, const int cellSize) const {
    //Apple Body
    int cellSizeOffset = cellSize / 2;
    int posX = pos.first * cellSize + cellSizeOffset;
    int posY = pos.second * cellSize + cellSizeOffset;
    DrawCircle(posX, posY, size / 2, RED);
}

pair<int, int> & Food::getPos() {
    return pos;
}

Food::Food(const deque<pair<int, int>>* snakeBody) : snakeBody(snakeBody) {}
