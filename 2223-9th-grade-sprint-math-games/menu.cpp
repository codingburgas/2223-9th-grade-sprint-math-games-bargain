#include "raylib.h"
#include "Header.h"

void menu()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu");

    Image image = LoadImage("titleGame-removebg-preview.png");
    ImageResize(&image, 400, 200);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);


        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 50, WHITE);
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 300, 200, 50 }))
        {

            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 40) / 2, 300, 40, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {

                CloseWindow();
                countdown();
                
            }
        }
        else
        {

            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, 300, 20, GRAY);
        }
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 360, 200, 50 }))
        {

            DrawText("Exit", screenWidth / 2 - MeasureText("Exit", 40) / 2, 360, 40, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {

                CloseWindow();
            }
        }
        else
        {

            DrawText("Exit", screenWidth / 2 - MeasureText("Exit", 20) / 2, 360, 20, GRAY);
        }

        EndDrawing();
    }
    



}