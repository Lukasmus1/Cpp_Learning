#include "Game.h"

#include <iostream>
#include <ostream>

#include "raylib.h"

Game::Game(const int size, const int fps, const int gridSizeMult, const float tickRateMs) :
    windowSize(size),
    fps(fps),
    tickRateMs(tickRateMs * 0.001f),
    gridSizeMult(gridSizeMult),
    cellSize(size / gridSizeMult),
    food(&snake.getBody())
{
    // Calculating in float and casting the result as int
    const int cubeSize = static_cast<int>(static_cast<float>(cellSize) * snake.getCubeSizeOffsetMultiplier());
    gridItemSize = cubeSize;

    const int startCoords = gridSizeMult / 2;
    snake.addBodyPart(startCoords, startCoords);

    food.generateRandomPos(gridSizeMult);
}

int Game::getWindowSize() const {
    return windowSize;
}

int Game::getFPS() const {
    return fps;
}

float Game::getTickRateMs() const {
    return tickRateMs;
}

void Game::draw() {
    // Reset
    ClearBackground(BLACK);

    // Draw Food
    food.drawFood(gridItemSize, cellSize);

    // Draw body
    for (auto bodyCell: snake.getBody()) {
        const int posX = bodyCell.first * cellSize;
        const int posY = bodyCell.second * cellSize;

        DrawRectangle(posX, posY, gridItemSize, gridItemSize, WHITE);
    }
}

void Game::move() {
    if (!directionBuffer.empty()) {
        snake.setDirection(directionBuffer.front());
        directionBuffer.pop_front();
    }

    snake.moveBody();

    // Collision Checks
    // Apple
    const pair<int, int>& snakeHead = snake.getHead();
    if (snakeHead.first == food.getPos().first && snakeHead.second == food.getPos().second) {
        snake.shouldGrow = true;

        food.generateRandomPos(gridSizeMult);
    }

    // Borders
    //if (snakeHead.first > )
}

void Game::updateDirectionBuffer(const Direction dir) {
    // If the buffer is larger than 3 don't queue it
    // If the direction is the same as the lastest one don't queue it
    if (directionBuffer.size() > 3 || (!directionBuffer.empty() && dir == directionBuffer.back())) {
        return;
    }

    directionBuffer.push_back(dir);
}

void Game::getDirectionInput() {
    //The second check forbids the snake from making 180° turns

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        if ((directionBuffer.empty() && snake.getDirection() != Direction::DOWN) || (!directionBuffer.empty() && directionBuffer.front() != Direction::DOWN))
            updateDirectionBuffer(Direction::UP);
    }
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        if ((directionBuffer.empty() && snake.getDirection() != Direction::UP) || (!directionBuffer.empty() && directionBuffer.front() != Direction::UP))
            updateDirectionBuffer(Direction::DOWN);
    }
    else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if ((directionBuffer.empty() && snake.getDirection() != Direction::RIGHT) || (!directionBuffer.empty() && directionBuffer.front() != Direction::RIGHT))
            updateDirectionBuffer(Direction::LEFT);
    }
    else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if ((directionBuffer.empty() && snake.getDirection() != Direction::LEFT) || (!directionBuffer.empty() && directionBuffer.front() != Direction::LEFT))
            updateDirectionBuffer(Direction::RIGHT);
    }
}
