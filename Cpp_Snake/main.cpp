#include "Game.h"
#include "raylib.h"

int main()
{
    Game game(800, 600, 60);

    InitWindow(game.GetWidth(), game.GetHeight(), "Snake");

    SetTargetFPS(game.GetFPS());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}