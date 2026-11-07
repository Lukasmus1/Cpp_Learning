#include "Snake.h"

float Snake::getCubeSizeOffsetMultiplier() const {
    return cubeSizeOffsetMultiplier;
}

void Snake::setSize(const float cubeSize) {
    size = cubeSize;
}

void Snake::addCube(const int x, const int y) {
    body.emplace_back(x, y);
}

const vector<pair<int, int>>& Snake::getBody() {
    return body;
}
