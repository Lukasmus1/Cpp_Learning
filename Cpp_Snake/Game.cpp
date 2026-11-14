#include "Game.h"

#include <functional>
#include <iostream>

#include "raylib.h"
#include "StateMachine.h"

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

    setup();
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

void Game::drawScore() {
    // Divide by 20 is eyeballing the best look
    DrawText(("Score: " + to_string(snake.getBody().size() - 1)).c_str(), 0, 0, windowSize / 25, WHITE);
}

void Game::draw() {
    // Draw Food
    food.drawFood(gridItemSize, cellSize);

    // Draw body
    for (auto bodyCell: snake.getBody()) {
        const int posX = bodyCell.first * cellSize;
        const int posY = bodyCell.second * cellSize;

        DrawRectangle(posX, posY, gridItemSize, gridItemSize, WHITE);
    }

    // Draw score periodically
    drawScore();
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

        // Update score instantly
        drawScore();
    }

    // Borders
    if (snakeHead.first > gridSizeMult || snakeHead.first < 0 || snakeHead.second > gridSizeMult || snakeHead.second < 0) {
        gameOver();
    }

    // Body
    const deque<pair<int, int>> snakeBody = snake.getBody();
    for (int ind = 1; ind < snakeBody.size(); ++ind) {
        if (snakeBody[ind].first == snakeHead.first && snakeBody[ind].second == snakeHead.second) {
            gameOver();
        }
    }
}

void Game::setup() {
    if (!snake.getBody().empty())
        snake.deleteBody();

    const int startCoords = gridSizeMult / 2;
    snake.addBodyPart(startCoords, startCoords);

    food.generateRandomPos(gridSizeMult);
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

void Game::drawTitle(const char* title) const {
    const int textSize = windowSize / 4;
    const int textWidth = MeasureText(title, textSize);

    const int posX = windowSize / 2 - textWidth / 2;
    const int posY = windowSize / 2 - textWidth / 2;

    DrawText(title, posX, posY, textSize, WHITE);
}

void Game::drawButton(const char* buttonTitle, const function<void()>& onClick) {
    // All the const numbers here are done by eyeballing the measurements
    const float buttonWidth = windowSize / 2;
    const float buttonHeight = windowSize / 10;

    float posX = windowSize / 2 - buttonWidth / 2;
    float posY = windowSize / 1.2;

    Rectangle btnBounds = {posX, posY, buttonWidth, buttonHeight};
    Color buttonColor = WHITE;

    if (CheckCollisionPointRec(GetMousePosition(), btnBounds)) {
        buttonColor = GRAY;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            onClick();
        }
    }

    DrawRectangle(posX, posY, buttonWidth, buttonHeight, buttonColor);

    const int textSize = buttonHeight / 1.5;
    const int textWidth = MeasureText(buttonTitle, textSize);

    posX = posX + buttonWidth / 2 - textWidth / 2;
    posY += buttonHeight / 6;
    DrawText(buttonTitle, posX, posY, textSize, BLACK);
}

void Game::gameOver() {
    StateMachine::getInstance().switchState(States::GAME_OVER);
    setup();
}
