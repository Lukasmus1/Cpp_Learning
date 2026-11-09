#include "Game.h"
#include "raylib.h"

int main()
{
    Game game(800, 60, 20);

    InitWindow(game.getWindowSize(), game.getWindowSize(), "Snake");

    SetTargetFPS(game.getFPS());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        game.draw();
        game.move();
        EndDrawing();

        WaitTime(0.1);
    }

    CloseWindow();

    return 0;
}