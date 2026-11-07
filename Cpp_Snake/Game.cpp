#include "Game.h"
#include "raylib.h"

Game::Game(const int size, const int fps, const int gridSizeMult) :
    windowSize(size),
    fps(fps),
    gridSizeMult(gridSizeMult),
    cellSize(size / gridSizeMult)
{
    const float cubeSize = static_cast<float>(cellSize) * snake.getCubeSizeOffsetMultiplier();
    snake.setSize(cubeSize);

    const int startCoords = gridSizeMult / 2;
    snake.addCube(startCoords, startCoords);
}

int Game::GetWindowSize() const {
    return windowSize;
}

int Game::GetFPS() const {
    return fps;
}

void Game::Draw() {
    for (auto bodyCell: snake.getBody()) {
        const int posX = bodyCell.first * cellSize;
        const int posY = bodyCell.second * cellSize;

        DrawRectangle(posX, posY, cellSize, cellSize, WHITE);
    }
}
