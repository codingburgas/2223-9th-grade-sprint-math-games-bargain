#include "raylib.h"
#include "Header.h"

void menu(int highScore)
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    bool inOptions = 0;
    short inGameQuestions = 10;
    short difficulty = 1;
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
                    countdown(timeInGame, inGameQuestions);
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
            // High score
            if (CheckCollisionPointRec(GetMousePosition(), { 0, 10, 150, 20 }))
            {
                DrawText("CLICK TO RESET", 10, 10, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    highScore = 0;
                }
            }
            else
            {
                DrawText(TextFormat("High score: %d", highScore), 10,  10, 20, RED);
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
            DrawText("Overall settings", screenWidth / 2 - 190, 80, 50, BLUE);

            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 140, 150, 200, 50 }))
            {
                if (difficulty == 1)
                    DrawText("Difficulty: Easy", screenWidth / 2 - 140, 150, 40, WHITE);
                else if (difficulty == 2)
                    DrawText("Difficulty: Normal", screenWidth / 2 - 140, 150, 40, WHITE);
                else if (difficulty == 3)
                    DrawText("Difficulty: Hard", screenWidth / 2 - 140, 150, 40, WHITE);
                else if (difficulty == 4)
                    DrawText("Difficulty: Custom", screenWidth / 2 - 140, 150, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    difficulty++;
                    if (difficulty == 2)
                    {
                        inGameQuestions = 15;
                        timeInGame = 60.0f;
                    }
                    if (difficulty == 3)
                    {
                        inGameQuestions = 20;
                        timeInGame = 30.0f;
                    }
                    if (difficulty > 3)
                    {
                        difficulty = 1;
                        inGameQuestions = 10;
                        timeInGame = 60.0f;
                    }
                    if (difficulty == 1)
                    {
                        inGameQuestions = 10;
                        timeInGame = 60.0f;
                    }
                }
            }
            else
            {
                if(difficulty == 1)
                    DrawText("Difficulty: Easy", screenWidth / 2 - 140, 150, 40, RED);
                else if(difficulty == 2)
                    DrawText("Difficulty: Normal", screenWidth / 2 - 140, 150, 40, RED);
                else if (difficulty == 3)
                    DrawText("Difficulty: Hard", screenWidth / 2 - 140, 150, 40, RED);
                else if (difficulty == 4)
                    DrawText("Difficulty: Custom", screenWidth / 2 - 140, 150, 40, RED);
            }

            DrawText("Custom settings", screenWidth / 2 - 185, 220, 50, BLUE);

            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 80, 280, 200, 40 }))
            {
                DrawText(TextFormat("Time: %.0fs",timeInGame), screenWidth / 2 - 80, 280, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    difficulty = 4;
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
                DrawText(TextFormat("Time: %.0fs", timeInGame), screenWidth / 2 - 80, 280, 40, RED);
            }
            if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 - 115, 320, 200, 40 }))
            {
                DrawText(TextFormat("Questions: %d", inGameQuestions), screenWidth / 2 - 115, 320, 40, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    difficulty = 4;
                    if (inGameQuestions < 20)
                    {
                        inGameQuestions++;
                    }
                    else if (inGameQuestions >= 20)
                    {
                        inGameQuestions = 5;
                    }
                }
            }
            else
            {
                DrawText(TextFormat("Questions: %d", inGameQuestions), screenWidth / 2 - 115, 320, 40, RED);
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