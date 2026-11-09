#include <iostream>
#include <ostream>

#include "Game.h"
#include "raylib.h"

int main()
{
    Game game(800, 120, 20, 250);

    InitWindow(game.getWindowSize(), game.getWindowSize(), "Snake");
    SetTargetFPS(game.getFPS());

    float timer = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        game.draw();

        timer += GetFrameTime();
        if (timer >= game.getTickRateMs()) {
            game.move();
            timer = 0;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}