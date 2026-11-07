#pragma once
#include <vector>

using namespace std;
class Snake {
private:
    vector<pair<int, int>> body;
    float size = 0;
    float cubeSizeOffsetMultiplier = 0.9;
public:
    float getCubeSizeOffsetMultiplier() const;
    void setSize(float cubeSize);
    void addCube(int x, int y);
    const vector<pair<int, int>>& getBody();
};
