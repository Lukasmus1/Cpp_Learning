#include "Game.h"
#include "raylib.h"
#include "StateMachine.h"

int main()
{
    Game game(800, 120, 20, 100);

    InitWindow(game.getWindowSize(), game.getWindowSize(), "Snake");
    SetTargetFPS(game.getFPS());

    float timer = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch (StateMachine::getInstance().getState()) {
            case States::MENU:
                game.drawTitle("Snake");
                game.drawButton("Play", []()-> void {StateMachine::getInstance().switchState(States::GAME);});
                break;
            case States::GAME:
                game.getDirectionInput();
                game.draw();

                timer += GetFrameTime();
                if (timer >= game.getTickRateMs()) {
                    game.move();
                    timer = 0;
                }
                break;
            case States::GAME_OVER:
                game.drawTitle("Game\nOver");
                game.drawButton("Retry", []()-> void {StateMachine::getInstance().switchState(States::GAME);});
                break;
            case States::NONE:
                throw "State NONE should never be used";
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
