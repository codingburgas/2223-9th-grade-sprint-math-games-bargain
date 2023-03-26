#include "raylib.h"
#include "Header.h"

void menu()
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    bool inOptions = 0;
    float timeInGame = 60.0f;
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
       



        ///////////////// IN MAIN MENU
        if (!(inOptions))
        {
            DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 50, WHITE);
            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 300, 200, 50 }))
            {
                DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 40) / 2, 300, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    CloseWindow();
                    countdown(timeInGame);
                }
            }
            else
            {
                DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, 300, 20, RED);
            }

            // Options Button
            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 360, 200, 50 }))
            {
                DrawText("Options", screenWidth / 2 - MeasureText("Options", 40) / 2, 360, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    inOptions = 1;
                }
            }
            else
            {
                DrawText("Options", screenWidth / 2 - MeasureText("Options", 20) / 2, 360, 20, RED);
            }

            // Exit Button
            if (CheckCollisionPointRec(GetMousePosition(), { 0, screenHeight - 40, 200, 50 }))
            {
                DrawText("Exit", 20, screenHeight - 40, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    CloseWindow();
                }
            }
            else
            {
                DrawText("Exit", 20, screenHeight - 40, 20, RED);
            }
        }





        ///////////////// IN OPTIONS
        else
        {
            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 100, 100, 200, 60 }))
            {
                DrawText(TextFormat("Time: %.0fs",timeInGame), screenWidth / 2 - 130, 100, 60, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    if (timeInGame < 300)
                    {
                        timeInGame += 10;
                    }
                    else if (timeInGame >= 300)
                    {
                        timeInGame = 30;
                    }
                }
            }
            else
            {
                DrawText(TextFormat("Time: %.0fs", timeInGame), screenWidth / 2 - 130, 100, 60, RED);
            }


            // Back Button
            if (CheckCollisionPointRec(GetMousePosition(), { 0, screenHeight - 40, 200, 50 }))
            {
                DrawText("Back", 20, screenHeight - 40, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    inOptions = 0;
                }
            }
            else
            {
                DrawText("Back", 20, screenHeight - 40, 20, RED);
            }
        }
        

        DrawText("BARGAIN TEAM @ 2023", screenWidth - 125, screenHeight - 15, 10, WHITE);
        EndDrawing();
    }
    



}