#include "Game.h"
#include "raylib.h"

int main()
{
    Game game(800, 120, 40, 100);

    InitWindow(game.getWindowSize(), game.getWindowSize(), "Snake");
    SetTargetFPS(game.getFPS());

    float timer = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        game.getDirectionInput();
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