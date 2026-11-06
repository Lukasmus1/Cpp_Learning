#pragma once

class Game {
private:
    int width, height, fps;
public:
    Game(int width, int height, int FPS);

    int GetWidth() const;
    int GetHeight() const;
    int GetFPS() const;
};
