#include "raylib.h"
#include "Header.h"

void menu()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);


        DrawText("Code the Bomb", screenWidth / 2 - MeasureText("Code the Bomb", 80) / 2, 80, 80, WHITE);
        DrawText("the", screenWidth / 2 - MeasureText("the", 80) / 2, 80, 80, MAROON);
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 240, 200, 50 }))
        {

            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 40) / 2, 240, 40, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {

                CloseWindow();
                game();


            }
        }
        else
        {

            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, 240, 20, GRAY);
        }
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 300, 200, 50 }))
        {

            DrawText("Options", screenWidth / 2 - MeasureText("Options", 40) / 2, 300, 40, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {


            }
        }
        else
        {

            DrawText("Options", screenWidth / 2 - MeasureText("Options", 20) / 2, 300, 20, GRAY);
        }

        EndDrawing();
    }
    



}