#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Hello Raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello World from Raylib + CLion!", 170, 280, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}