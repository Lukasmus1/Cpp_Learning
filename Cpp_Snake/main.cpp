#include "Game.h"
#include "raylib.h"

int main()
{
    Game game(800, 60, 20);

    InitWindow(game.GetWindowSize(), game.GetWindowSize(), "Snake");

    SetTargetFPS(game.GetFPS());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}