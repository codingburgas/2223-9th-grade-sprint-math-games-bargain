#include "raylib.h"
#include "Header.h"

void menu()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu");

    Image image = LoadImage("logoGame-removebg-preview.png");
    ImageResize(&image, 450, 380);
    Texture2D texture = LoadTextureFromImage(image);
    Texture2D background = LoadTexture("../assets/menu-bg.png");
    

    UnloadImage(image);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 50, WHITE);

        // Start Game Button
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 300, 200, 50 }))
        {
            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 40) / 2, 300, 40, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
                countdown();
            }
        }
        else
        {
            DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, 300, 20, RED);
        }

        // Options Button
        if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 360, 200, 50 }))
        {
            DrawText("Options", screenWidth / 2 - MeasureText("Options", 40) / 2, 360, 40, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
        else
        {
            DrawText("Options", screenWidth / 2 - MeasureText("Options", 20) / 2, 360, 20, RED);
        }

        // Exit Button
        if (CheckCollisionPointRec(GetMousePosition(), { 0, screenHeight - 40, 200, 50 }))
        {
            DrawText("Exit", 20, screenHeight - 40, 40, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
        else
        {
            DrawText("Exit", 20, screenHeight - 40, 20, RED);
        }

        DrawText("BARGAIN TEAM @ 2023", screenWidth - 125, screenHeight - 15, 10, WHITE);
        EndDrawing();
    }
    



}