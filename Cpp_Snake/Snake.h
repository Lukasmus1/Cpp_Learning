#pragma once

#include <deque>
#include "Direction.h"

using namespace std;
class Snake {
private:
    deque<pair<int, int>> body;
    int size = 0;
    float cubeSizeOffsetMultiplier = 0.9;
    Direction direction = Direction::RIGHT;

public:
    [[nodiscard]] float getCubeSizeOffsetMultiplier() const;
    void setSize(int cubeSize);
    int getSize() const;

    void addBodyPart(int x, int y);
    const deque<pair<int, int>>& getBody();
    const pair<int, int>& getHead();
    void deleteBody();
    void moveBody();

    void grow();

    bool shouldGrow = false;

    [[nodiscard]] Direction getDirection() const;
    void setDirection(Direction dir);
};
