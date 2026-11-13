#include "Snake.h"

#include <iostream>

float Snake::getCubeSizeOffsetMultiplier() const {
    return cubeSizeOffsetMultiplier;
}

void Snake::setSize(const int cubeSize) {
    size = cubeSize;
}

int Snake::getSize() const {
    return size;
}

void Snake::addBodyPart(const int x, const int y) {
    body.emplace_back(x, y);
}

const deque<pair<int, int>>& Snake::getBody() {
    return body;
}

const pair<int, int> & Snake::getHead() {
    return body.front();
}

void Snake::moveBody() {
    pair<int, int> dir;
    switch (direction) {
        case Direction::UP:
            dir = {0, -1};
            break;
        case Direction::DOWN:
            dir = {0, 1};
            break;
        case Direction::LEFT:
            dir = {-1, 0};
            break;
        case Direction::RIGHT:
            dir = {1, 0};
            break;
        case Direction::NONE:
            throw std::invalid_argument("Direction in Snake.h is NONE");
    }

    // New head is old head + dir
    body.emplace_front(body.begin()->first + dir.first, body.begin()->second + dir.second);

    if (shouldGrow) {
        shouldGrow = false;
        return;
    }

    body.pop_back();
}

Direction Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(const Direction dir) {
    this->direction = dir;
}

