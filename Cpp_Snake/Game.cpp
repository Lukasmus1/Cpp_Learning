#include "Game.h"

#include <iostream>
#include <ostream>

#include "raylib.h"

Game::Game(const int size, const int fps, const int gridSizeMult) :
    windowSize(size),
    fps(fps),
    gridSizeMult(gridSizeMult),
    cellSize(size / gridSizeMult)
{
    // Calculating in float and casting the result as int
    const int cubeSize = static_cast<int>(static_cast<float>(cellSize) * snake.getCubeSizeOffsetMultiplier());
    snake.setSize(cubeSize);

    const int startCoords = gridSizeMult / 2;
    snake.addBodyPart(startCoords, startCoords);
}

int Game::getWindowSize() const {
    return windowSize;
}

int Game::getFPS() const {
    return fps;
}

void Game::draw() {
    // Reset
    ClearBackground(BLACK);

    // Draw body
    for (auto bodyCell: snake.getBody()) {
        const int posX = bodyCell.first * cellSize;
        const int posY = bodyCell.second * cellSize;

        DrawRectangle(posX, posY, snake.getSize(), snake.getSize(), WHITE);
    }
}

void Game::move() {
    snake.moveBody();
}
