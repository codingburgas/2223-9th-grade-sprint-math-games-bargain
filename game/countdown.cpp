#include "raylib.h"
#include "Header.h"

void countdown(float setTime, int inGameQuestions)
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Game");
    Texture2D background = LoadTexture("../assets/menu-bg.png");

    float time = 0.0f;
    float timeLeft = 0.0f;
    while (!WindowShouldClose()) {
        DrawTexture(background, 0, 0, WHITE);
        float currentTime = (float)GetTime();
            timeLeft = 7.0f - (currentTime - time);

            if (timeLeft >= 5.5f) {
                DrawText("Ready!", screenWidth / 2 - 150, screenHeight / 2 - 40, 100, RAYWHITE);
            }
            else if (timeLeft <= 6.0f && timeLeft >= 0.5f) {
                DrawText(TextFormat("%.0f", timeLeft), screenWidth / 2 - 30, screenHeight / 2 - 40, 100, RAYWHITE);
            }
            else if (timeLeft <= 0.5f) {
                DrawText("Go!", screenWidth / 2 - 75, screenHeight / 2 - 40, 100, RAYWHITE);
            }
            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                game(setTime, inGameQuestions);
            }
        BeginDrawing();
        ClearBackground(BLACK);
 
        EndDrawing();
    }
}